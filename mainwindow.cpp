#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rootdialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTime>
int aaa;
bool lowBatteryFlag;
bool hardwareProblem;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    hardwareProblem = false;
    //cal.Initial();
    ui->lcdNet->setNumDigits(7);
    ui->lcdNet->setFrameShape(QFrame::NoFrame);
    ui->lcdNet1->setNumDigits(7);
    ui->lcdNet1->setFrameShape(QFrame::NoFrame);
    ui->lcdGross->setNumDigits(7);
    ui->lcdGross->setFrameShape(QFrame::NoFrame);
    ui->lcdTare->setNumDigits(7);
    ui->lcdTare->setFrameShape(QFrame::NoFrame);
    ui->lcdNet->installEventFilter(this);
    ui->lcdNet1->installEventFilter(this);
    ui->label_21->installEventFilter(this);
    ui->label_23->installEventFilter(this);
    ui->label_38->installEventFilter(this);
    ui->label_43->installEventFilter(this);
    ColorFlag = true;
    ColorFlagX = true;
    ColorFlagY = true;
    ColorFlagZ = true;
    maxflag = false;
    mixflag = false;
    countflag=false;
    Accflag=false;
    CountTare=0;
    xiaxian1 = "上限\n\n";
    shangxian1 = "下限\n\n";
    jishu="计数/采样\n\n";
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(QRect(0,0,800,480));
    GrossWeight=0;
    QString tempStr ;
    if(Unit==1)
        tempStr = "kg";
    else if(Unit==2)
        tempStr = "lb";
    else
        tempStr = "g";
    //QString xiaxian2 =  QString::number(HighValue);
    QString xiaxian2 =  QString::number(HighValue,'f',Point);
    // QString shangxian2 =QString::number(LowValue);
    QString shangxian2 =  QString::number(LowValue,'f',Point);
   // QString jishu2 =QString::number(sam,'f',Point+2);
    QString jishu2 =QString::number(sam);
    QString ljzl =QString::number(Totfa);
    QString ljcs =QString::number(Totfn);
     ui->label_43->setText("总重:"+ljzl+"\n\n"+"次数:"+ljcs);

    ui->label_21->setText(xiaxian1+xiaxian2+tempStr);
    ui->label_23->setText(shangxian1+shangxian2+tempStr);
    ui->label_22->setText("合格");
    ui->label_38->setText(jishu+jishu2+tempStr+"/个");

    QString max =  QString::number(Full);
    //QString min =  QString::number(Rati*20);
    //QString dtemp =  QString::number(Rati);
    QString dtemp =  QString::number(SjRati);
    ui->label_9->setText(max);
    ui->label_10->setText("20e");
    ui->label_24->setText(dtemp);
    //setOrientation(Qt::Horizontal);
    //  ui->progressBar->setMaximum(1000);
    // ui->progressBar->setMinimum(0);
    //ui->progressBar->setValue(30);

    //ui->progressBar
    /*AdData=cal.RD1232();
    if(FilterStep==1)
        cal.AdFilter();
    else if(FilterStep==2)
        cal.AdFilter1();
    else if(FilterStep==3)
        cal.AdFilter2();
    else
        cal.AdFilter();
    cal.CalWeigh();*/

    //b_ykj=0;
    pingTimer.start(200);
    count=0;
    connect(&pingTimer,SIGNAL(timeout()),this,SLOT(pingTimerSlot()));

    pingTimer1.start(1500);
    count1=0;
    connect(&pingTimer1,SIGNAL(timeout()),this,SLOT(pingTimerSlot1()));

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(50);
    numKeyboard = new NumKeyboard;
    connect(numKeyboard,SIGNAL(sendToMainwindow(QString)),this,SLOT(setMaxAndMix(QString)));

   /* ui->pushButton_13->setText(tr("打印"));
    ui->pushButton_14->setText(tr("除皮"));
    ui->pushButton_15->setText(tr("归零"));*/
    switch(LedLight)
    {
    case 1:
        system("echo 1 >> /sys/class/backlight/backlight/brightness");
        break;
    case 2:
        system("echo 2 >> /sys/class/backlight/backlight/brightness");
        break;
    case 3:
        system("echo 3 >> /sys/class/backlight/backlight/brightness");
        break;
    case 4:
        system("echo 4 >> /sys/class/backlight/backlight/brightness");
        break;
    case 5:
        system("echo 5 >> /sys/class/backlight/backlight/brightness");
        break;
    case 6:
        system("echo 6 >> /sys/class/backlight/backlight/brightness");
        break;
    case 7:
        system("echo 7 >> /sys/class/backlight/backlight/brightness");
        break;
    }
    if(FilterStep==4)
        ADS1232_SET_SPS80;
    else
        ADS1232_SET_SPS10;

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::main_init(void)
{
    /*   fd_ads1232 = open("/dev/ads1232", O_RDWR | O_NONBLOCK);
    //ADS1232_SET_SPS80;
      ADS1232_SET_SPS10;
      qDebug()<<"count"<<count;*/
}
void MainWindow::pingTimerSlot()
{


    if(fvalue>2700)
    {
        ui->label_battery->show();
        ui->label_battery_2->hide();
        ui->label_battery_3->hide();
        ui->label_battery_4->hide();
    }
    else if(fvalue>2600)
    {
        ui->label_battery->hide();
        ui->label_battery_2->show();
        ui->label_battery_3->hide();
        ui->label_battery_4->hide();
    }
    else if(fvalue>2500)
    {
        ui->label_battery->hide();
        ui->label_battery_2->hide();
        ui->label_battery_3->show();
        ui->label_battery_4->hide();
    }
    else
    {
        lowBatteryFlag =true;
        ui->label_battery->hide();
        ui->label_battery_2->hide();
        ui->label_battery_3->hide();
        ui->label_battery_4->show();
    }


    if(b_Zero)
        ui->label_6->show();
    else
        ui->label_6->hide();
    if(b_Stable)
        ui->label_7->show();
    else
        ui->label_7->hide();
    if(b_Net)
        ui->label_17->show();
    else
        ui->label_17->hide();
    if(sam!=0)
    {

        ui->label_12->hide();
        ui->label_18->hide();
        ui->label_19->hide();
        ui->label_28->hide();

        ui->label_26->hide();
        ui->label_27->hide();
        ui->label_29->hide();
        ui->label_36->hide();

        ui->label_31->hide();
        ui->label_33->hide();
        ui->label_35->hide();
        ui->label_37->hide();

        ui->label_39->show();
        ui->label_40->show();
        ui->label_41->show();
        ui->label_42->show();
    }
    else
    {
        cal.ZTrace(Zono);
        ui->label_39->hide();
        ui->label_40->hide();
        ui->label_41->hide();
        ui->label_42->hide();
        if(Unit==1)
        {
            ui->label_12->show();
            ui->label_18->show();
            ui->label_19->show();
            ui->label_28->show();
            ui->label_26->hide();
            ui->label_27->hide();
            ui->label_29->hide();
            ui->label_36->hide();
            ui->label_31->hide();
            ui->label_33->hide();
            ui->label_35->hide();
            ui->label_37->hide();
        }
        else if(Unit==2)
        {
            ui->label_12->hide();
            ui->label_18->hide();
            ui->label_19->hide();
            ui->label_28->hide();
            ui->label_26->show();
            ui->label_27->show();
            ui->label_29->show();
            ui->label_36->show();
            ui->label_31->hide();
            ui->label_33->hide();
            ui->label_35->hide();
            ui->label_37->hide();
        }
        else
        {
            ui->label_12->hide();
            ui->label_18->hide();
            ui->label_19->hide();
            ui->label_28->hide();
            ui->label_26->hide();
            ui->label_27->hide();
            ui->label_29->hide();
            ui->label_36->hide();
            ui->label_31->show();
            ui->label_33->show();
            ui->label_35->show();
            ui->label_37->show();
        }
    }
    if((LowValue==0&&HighValue==0))
    {
        if (ColorFlag)
        {
            /* ui->label_99->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_2->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_12->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_14->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_15->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_16->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_20->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_18->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_19->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_26->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_27->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_29->setStyleSheet("background-color:rgb(255, 170, 0)");
          //  ui->label_36->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_31->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_33->setStyleSheet("background-color:rgb(255, 170, 0)");
            ui->label_35->setStyleSheet("background-color:rgb(255, 170, 0)");
         //   ui->label_37->setStyleSheet("background-color:rgb(255, 170, 0)");*/
            if(sam==0)
            {
            ui->lcdGross->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->lcdNet->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->lcdTare->setStyleSheet("background-color:rgb(0, 170, 127)");

            ui->label_99->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_2->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_12->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_14->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_15->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_16->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_20->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_18->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_19->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_26->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_27->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_29->setStyleSheet("background-color:rgb(0, 170, 127)");
            //  ui->label_36->setStyleSheet("background-color:rgb(127, 170, 0)");
            ui->label_31->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_33->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_35->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_39->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_40->setStyleSheet("background-color:rgb(0, 170, 127)");
            ui->label_41->setStyleSheet("background-color:rgb(0, 170, 127)");
            //   ui->label_37->setStyleSheet("background-color:rgb(127, 170, 0)");
            }
            else
            {
                ui->lcdGross->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->lcdNet->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->lcdTare->setStyleSheet("background-color:rgb(85, 170, 200)");

                ui->label_99->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_2->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_12->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_14->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_15->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_16->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_20->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_18->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_19->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_26->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_27->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_29->setStyleSheet("background-color:rgb(85, 170, 200)");
                //  ui->label_36->setStyleSheet("background-color:rgb(127, 170, 0)");
                ui->label_31->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_33->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_35->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_39->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_40->setStyleSheet("background-color:rgb(85, 170, 200)");
                ui->label_41->setStyleSheet("background-color:rgb(85, 170, 200)");

            }

            qDebug()<<"1111111111111111";
            ColorFlag=false;
            ColorFlagX=true;
            ColorFlagY=true;
            ColorFlagZ=true;
        }
    }
    else
    {
        if(Net>HighValue)
        {
            if (ColorFlagX)
            {
                ui->lcdGross->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->lcdNet->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->lcdTare->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_99->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_2->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_12->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_14->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_15->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_16->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_20->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_18->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_19->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_26->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_27->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_29->setStyleSheet("background-color:rgb(212, 37, 66);");
                //     ui->label_36->setStyleSheet("background-color:rgb(66, 37, 212);");
                ui->label_31->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_33->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_35->setStyleSheet("background-color:rgb(212, 37, 66);");
                ui->label_39->setStyleSheet("background-color:rgb(212, 37, 66)");
                ui->label_40->setStyleSheet("background-color:rgb(212, 37, 66)");
                ui->label_41->setStyleSheet("background-color:rgb(212, 37, 66)");
                //     ui->label_37->setStyleSheet("background-color:rgb(66, 37, 212);");
                qDebug()<<"222222222222222222";
                ColorFlag = true;
                ColorFlagX = false;
                ColorFlagY = true;
                ColorFlagZ = true;
            }
        }
        else if((Net<LowValue)&&(Net>0))
        {
            if (ColorFlagY)
            {
                ui->lcdGross->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->lcdNet->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->lcdTare->setStyleSheet("background-color:rgb(241, 156, 31);");

                ui->label_99->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_2->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_12->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_14->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_15->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_16->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_20->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_18->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_19->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_26->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_27->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_29->setStyleSheet("background-color:rgb(241, 156, 31);");
                //      ui->label_36->setStyleSheet("background-color:rgb(31, 156, 241);");
                ui->label_31->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_33->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_35->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_39->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_40->setStyleSheet("background-color:rgb(241, 156, 31);");
                ui->label_41->setStyleSheet("background-color:rgb(241, 156, 31);");
                //     ui->label_37->setStyleSheet("background-color:rgb(241, 156, 31);");
                qDebug()<<"333333333333333333333";
                ColorFlag = true;
                ColorFlagX = true;
                ColorFlagY = false;
                ColorFlagZ = true;
            }
        }
        else
        {
            if (ColorFlagZ)
            {
                /* ui->label_99->setStyleSheet("background-color:rgb(255, 170, 255);");
                ui->label_2->setStyleSheet("background-color:rgb(255, 170, 255);");
                ui->label_12->setStyleSheet("background-color:rgb(255, 170, 255);");
                ui->label_14->setStyleSheet("background-color:rgb(255, 170, 255);");
                ui->label_15->setStyleSheet("background-color:rgb(255, 170, 255);");
                ui->label_16->setStyleSheet("background-color:rgb(255, 170, 255);");
                ui->label_20->setStyleSheet("background-color:rgb(255, 170, 255);");
                ui->label_18->setStyleSheet("background-color:rgb(255, 170, 255);");
                ui->label_19->setStyleSheet("background-color:rgb(255, 170, 255);");

                ui->label_26->setStyleSheet("background-color:rgb(255, 170, 255)");
                ui->label_27->setStyleSheet("background-color:rgb(255, 170, 255)");
                ui->label_29->setStyleSheet("background-color:rgb(255, 170, 255)");
            //    ui->label_36->setStyleSheet("background-color:rgb(255, 170, 255)");
                ui->label_31->setStyleSheet("background-color:rgb(255, 170, 255)");
                ui->label_33->setStyleSheet("background-color:rgb(255, 170, 255)");
                ui->label_35->setStyleSheet("background-color:rgb(255, 170, 255)");
            //    ui->label_37->setStyleSheet("background-color:rgb(255, 170, 255)");*/
                ui->lcdGross->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->lcdNet->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->lcdTare->setStyleSheet("background-color:rgb(0, 170, 127)");

                ui->label_99->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_2->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_12->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_14->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_15->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_16->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_20->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_18->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_19->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_26->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_27->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_29->setStyleSheet("background-color:rgb(0, 170, 127)");
                //  ui->label_36->setStyleSheet("background-color:rgb(127, 170, 0)");
                ui->label_31->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_33->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_35->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_39->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_40->setStyleSheet("background-color:rgb(0, 170, 127)");
                ui->label_41->setStyleSheet("background-color:rgb(0, 170, 127)");
                //   ui->label_37->setStyleSheet("background-color:rgb(127, 170, 0)");
                qDebug()<<"4444444444444444444";
                ColorFlag = true;
                ColorFlagX = true;
                ColorFlagY = true;
                ColorFlagZ = false;
            }
        }
    }


    QString tempGross = "ST,NT0"+QString::number(Gross)+".00kg0D0A";
    SendtoTCPUDP = tempGross.toAscii();
    //QByteArray::number()
    //qDebug()<<"count"<<count<<"temp"<<temp;

}
void MainWindow::pingTimerSlot1()
{
    //count1++;
    if(count1==1000)
    {
        count1=0;
    }
    //ui->progressBar->setValue(count);
    //  ui->progressBar->setValue(10*count1);

    // qDebug()<<"count1"<<count1;
    QString max =  QString::number(Full);
    //QString min =  QString::number(Rati*20);
    QString dtemp =  QString::number(SjRati);
    ui->label_9->setText(max);
    //ui->label_10->setText(min);
    ui->label_10->setText("20e");
    ui->label_24->setText(dtemp);
    xiaxian1 = "上限\n\n";
    shangxian1 = "下限\n\n";
    QString tempStr = "";
    if(Unit==1)
        tempStr = "kg";
    else if(Unit==2)
        tempStr = "lb";
    else
        tempStr = "g";
    //  QString xiaxian2 =  QString::number(HighValue);
    // QString shangxian2 =QString::number(LowValue);
    QString xiaxian2 =  QString::number(HighValue,'f',Point);
    QString shangxian2 =  QString::number(LowValue,'f',Point);
  //  QString jishu2 =QString::number(sam,'f',Point+2);
     QString jishu2 =QString::number(sam);
     QString ljzl =QString::number(Totfa);
     QString ljcs =QString::number(Totfn);
    ui->label_43->setText("总重:"+ljzl+"\n\n"+"次数:"+ljcs);
    ui->label_21->setText(xiaxian1+xiaxian2+tempStr);
    ui->label_23->setText(shangxian1+shangxian2+tempStr);
    ui->label_38->setText(jishu+jishu2+tempStr+"/个");
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{

    if (obj == ui->lcdNet)//指定某个QLabelshangxian1
    {
        // beep_start;
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                ui->stackedWidget->setCurrentIndex(1);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->lcdNet1)//指定某个QLabel
    {
        // beep_start;
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                qDebug()<<"ui->label_2 is clicked";
                ui->stackedWidget->setCurrentIndex(0);
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->label_21)//指定某个QLabel
    {
        // beep_start;
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                beep_start;
                qDebug()<<"ui->label_21 is clicked";
                //ui->stackedWidget->setCurrentIndex(0);
                // numKeyboard = new NumKeyboard;
                numKeyboard->setWindowModality(Qt::ApplicationModal);

                numKeyboard->show();
                numKeyboard->move(QPoint(150,100));
                //this->setEnabled(false);
                // ui->stackedWidget->setEnabled(false);
                maxflag = true;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->label_23)//指定某个QLabel
    {
        //beep_start;
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                beep_start;
                qDebug()<<"ui->label_23 is clicked";
                //ui->stackedWidget->setCurrentIndex(0);
                //numKeyboard = new NumKeyboard;
                numKeyboard->setWindowModality(Qt::ApplicationModal);

                numKeyboard->show();
                numKeyboard->move(QPoint(150,100));
                mixflag = true;

                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->label_38)//指定某个QLabel
    {
        //beep_start;
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                beep_start;
                qDebug()<<"ui->label_38 is clicked";
                //ui->stackedWidget->setCurrentIndex(0);
                // numKeyboard = new NumKeyboard;
                numKeyboard->setWindowModality(Qt::ApplicationModal);

                numKeyboard->show();
                numKeyboard->move(QPoint(450,100));
                countflag = true;

                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if (obj == ui->label_43)//指定某个QLabel
    {
        //beep_start;
        if (event->type() == QEvent::MouseButtonPress)//mouse button pressed
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(mouseEvent->button() == Qt::LeftButton)
            {
                beep_start;
                qDebug()<<"ui->label_38 is clicked";
               //QMessageBox::warning(NULL, "警告", "是否清空累计", QMessageBox::Yes, QMessageBox::No);
               QMessageBox::StandardButton rb=QMessageBox::information(this, tr("警告"), tr("是否清空累计"), QMessageBox::No,QMessageBox::Yes);
               if(rb == QMessageBox::Yes)
               {
                 qDebug()<<"QMessageBox::是";
				 if(sam==0)
				 	{
                  Totfa=0;
                  Totfn=0;
			QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/Totfa",Totfa);
   configIniRead->setValue("baseinfo/Totfn",Totfn);
   
    delete configIniRead;
				 	}
				 else
				 	{
				 	 Totfac=0;
                  Totfnc=0;
			QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/Totfac",Totfac);
   configIniRead->setValue("baseinfo/Totfnc",Totfnc);
   
    delete configIniRead;
				 	}
               }
               else if(rb == QMessageBox::No)
               {
                 qDebug()<<"QMessageBox::否";

               }
                Accflag = true;

                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        // pass the event on to the parent class
        return QMainWindow::eventFilter(obj, event);
    }
}
void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->label_date->setText(str);
    ui->label_date_2->setText(str);
    QString temp="";
    QString temp1="";
    QString temp2="";

    TimDly2--;
    if(TimDly2<=0)
        TimDly2=0;
    TimStab++;
    if(TimStab>20)TimStab=20;
    if(sam==0)
    {
        temp=QString::number(Net,'f',Point);
        temp1=QString::number(Gross,'f',Point);
        temp2=QString::number(Tare,'f',Point);
    }
    else
    {
        temp=QString::number(CountNet);
        temp1=QString::number(CountGross);
        temp2=QString::number(CountTare);
    }
    //  qDebug()<<"MainWindowRtai111111111111111111111111111111111111111111"<<Rati;

    if(Gross>CalFull+9*SjRati)
    {
        //ui->label_99->setText("OL");
        ui->lcdNet->display("OL");
        ui->lcdNet1->display("OL");
        // ui->label_3->setText("OL");
        ui->lcdGross->display("OL");
        // ui->label_16->setText("OL");
        ui->lcdTare->display("OL");
    }
    else if(Gross<-20*SjRati)
    {

        //ui->label_99->setText("OL");
        ui->lcdNet->display("LO");
        ui->lcdNet1->display("LO");
        // ui->label_3->setText("OL");
        ui->lcdGross->display("LO");
        // ui->label_16->setText("OL");
        ui->lcdTare->display("LO");
    }
    else
    {
        //ui->label_99->setText(temp);
        ui->lcdNet->display(temp);
        //ui->label_3->setText(temp);
        ui->lcdNet1->display(temp);
        ui->lcdGross->display(temp1);
        //ui->label_16->setText(temp1);
        ui->lcdTare->display(temp2);
    }
    // ui->label_20->setText(temp2);
}

/*void MainWindow::on_pushButton_10_clicked()
{
    qDebug()<<"on_pushButton_10_clicked is clicked";
}
*/
/*void MainWindow::on_pushButton_clicked()
{
    qDebug()<<"on_pushButton_clicked is clicked";

}*/


void MainWindow::on_pushButton_5_clicked()
{
    beep_start;
    emit sendtoRootdialog();
    this->close();
}
void MainWindow::setMaxAndMix(QString maxmin)
{
    if (maxflag)
    {
        //beep_start;
        ui->label_21->setText(xiaxian1+maxmin+"kg");
        maxflag=false;
        // ui->stackedWidget->setEnabled(true);
        //this->setEnabled(true);
        QString Hightemp=maxmin;
        HighValue=Hightemp.toFloat();
        qDebug()<<"HighValue"<<HighValue;
        qDebug()<<"maxmin"<<maxmin;
        qDebug()<<"Hightemp"<<Hightemp;
        if(HighValue>99999)HighValue=0;
        if (HighValue==0)
        {
            QMessageBox::critical(this, tr("错误"), tr("请重新输入"), QMessageBox::Yes, QMessageBox::Yes);
            HighValue=0;
            LowValue=0;
        }
    }

    //HighValue=maxmin;

    if (mixflag)
    {
        //beep_start;
        ui->label_23->setText(shangxian1+maxmin+"kg");
        mixflag=false;
        QString Lowtemp=maxmin;
        LowValue=Lowtemp.toFloat();
        if(LowValue>99999)LowValue=0;
        if (LowValue==0)
        {
            QMessageBox::critical(this, tr("错误"), tr("请重新输入"), QMessageBox::Yes, QMessageBox::Yes);
            HighValue=0;
            LowValue=0;
        }

    }
    if (countflag)
    {
        //beep_start;
        ui->label_38->setText(jishu+maxmin+"kg/个");
        countflag=false;
        //QString Counttemp=maxmin;
        Counttemp=maxmin.toLong();
        if(Counttemp>99999)
        {
            Counttemp=0;
            QMessageBox::critical(this, tr("错误"), tr("请重新输入"), QMessageBox::Yes, QMessageBox::Yes);
        }
        if(Counttemp==0)
            sam=0;
        else
            sam=Net/Counttemp;
        ColorFlag=true;
        ColorFlagX=true;
        ColorFlagY=true;
        ColorFlagZ=true;
    }

    cal.ArgSave();
    cal.ArgRead();
    xiaxian1 = "上限\n\n";
    shangxian1 = "下限\n\n";
    QString tempStr = "";
     if (countflag)
          tempStr = "个";
     else
     {
    if(Unit==1)
        tempStr = "kg";
    else if(Unit==2)
        tempStr = "lb";
    else
        tempStr = "g";
     }
  //  QString xiaxian2 =  QString::number(HighValue);
  //  QString shangxian2 =QString::number(LowValue);
   QString xiaxian2 =  QString::number(HighValue,'f',Point);
   QString shangxian2 =  QString::number(LowValue,'f',Point);
   // QString jishu2 =QString::number(sam,'f',Point+2);
     QString jishu2 =QString::number(sam);

    ui->label_21->setText(xiaxian1+xiaxian2+tempStr);
    ui->label_23->setText(shangxian1+shangxian2+tempStr);
    ui->label_38->setText(jishu+jishu2+tempStr+"/个");
    qDebug()<<"setMaxAndMix";

}
void MainWindow::on_pushButton_7_clicked()
{
    beep_start;
    cal.SetZero(ZeroKeyVal);
}
void MainWindow::fromRootdialog(void)
{

    this->close();
    /*emit sentToMainwindow();
    emit sendToConfigsetting();
    //emit sendToMode();
    emit sendToPrinter();
    emit sendToBusiness();

    emit sendToSheet();
    emit sendToAbout();
    emit sendToDataExport();
    emit sendToClose();
    emit sendToUsers();*/

    //else if(KeyNumb==31)

}
void MainWindow::fromRootdialogtare(void)
{
     // ui->lcdNet->uninstallEventFilter(this);
    //ui->lcdNet1->uninstallEventFilter(this);
cal.KTare();
  //ui->lcdNet->installEventFilter(this);
  //ui->lcdNet1->installEventFilter(this);
}
void MainWindow::fromRootdialogzero(void)
{
      //ui->lcdNet->uninstallEventFilter(this);
      //ui->lcdNet1->uninstallEventFilter(this);
 cal.SetZero(ZeroKeyVal);
  // ui->lcdNet->installEventFilter(this);
  // ui->lcdNet1->installEventFilter(this);
}
void MainWindow::on_pushButton_11_clicked()
{
    beep_start;
    cal.KTare();
}

void MainWindow::on_pushButton_9_clicked()
{
    beep_start;
   if(!b_Print) emit printnetsignal();
}
void MainWindow::on_label_21_linkActivated(const QString &link)
{

}

void MainWindow::on_pushButton_13_clicked()
{
    beep_start;
   if(!b_Print) emit printnetsignal();
}

void MainWindow::on_pushButton_14_clicked()
{
    beep_start;
    cal.KTare();
}

void MainWindow::on_pushButton_15_clicked()
{
    beep_start;
    cal.SetZero(ZeroKeyVal);
}

void MainWindow::on_label_99_linkActivated(const QString &link)
{

}

void MainWindow::on_lcdNet_overflow()
{
     ui->stackedWidget->setCurrentIndex(1);
}
