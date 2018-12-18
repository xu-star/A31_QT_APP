#include "configsetting.h"
#include "ui_configsetting.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include "rootdialog.h"
configSetting::configSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::configSetting)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(100);

    connect(ui->verticalScrollBar,SIGNAL(valueChanged(int)),this,SLOT(slot_ScroolWidget(int)));
    if(quanxian==2)
        ui->toolButton_5->setEnabled(false);

    ui->progressBar->setValue(0);
    ui->stackedWidget->setCurrentIndex(0);

}

configSetting::~configSetting()
{
    delete ui;
}
void configSetting::on_pushButton_68_clicked()
{
    beep_start;
    int new_year=(ui->year->text()).toInt()+1;
    ui->year->setText(QString::number(new_year));
}

void configSetting::updateParameterSlot()
{
    calcf.ArgSave();
    calcf.ArgRead();
    ConfigSave();
}
void configSetting::on_toolButton_5_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(4);
  //ui->label_3->setEnabled(false);
  //ui->label_4->setEnabled(false);
    ui->label_4->setEnabled(false);
  //ui->label_5->setEnabled(false);
    ui->label_6->setEnabled(false);
  //ui->label_7->setEnabled(false);
    ui->label_8->setText("00000");
    ui->pushButton->setEnabled(false);
    ui->pushButton_35->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
}

void configSetting::on_toolButton_7_clicked()
{
    bool flag;
    flag = true;
    beep_start;
    PIN_PB25_L;
#ifdef arm
    emit syncParameterSignal();
    calcf.ArgSave();
    calcf.ArgRead();

#endif
    ConfigSave();
    //    qDebug()<<"ui->stackedWidget_2->currentIndex()"<<ui->stackedWidget_2->currentIndex();
    //    qDebug()<<"ui->stackedWidget_3->currentIndex()"<<ui->stackedWidget_3->currentIndex();
    //    qDebug()<<"ui->stackedWidget_4->currentIndex()"<<ui->stackedWidget_4->currentIndex();
    //    qDebug()<<"ui->stackedWidget_5->currentIndex()"<<ui->stackedWidget_5->currentIndex();
    //    qDebug()<<"ui->stackedWidget->currentIndex()"<<ui->stackedWidget->currentIndex();
    if (((ui->stackedWidget->currentIndex()==0)&&(ui->stackedWidget_2->currentIndex()==0))||
            ((ui->stackedWidget->currentIndex()==1)&&(ui->stackedWidget_3->currentIndex()==0))||
            ((ui->stackedWidget->currentIndex()==2)&&(ui->stackedWidget_4->currentIndex()==0))||
            ((ui->stackedWidget->currentIndex()==3)&&(ui->stackedWidget_6->currentIndex()==0))||
            ((ui->stackedWidget->currentIndex()==4)&&(ui->stackedWidget_7->currentIndex()==0))||
            ((ui->stackedWidget->currentIndex()==5)&&(ui->stackedWidget_5->currentIndex()==0)))
    {
        this->close();
    }
    if ((ui->stackedWidget_2->currentIndex()==0)&&(ui->stackedWidget->currentIndex()==0)&&(ui->stackedWidget_3->currentIndex()==0)&&(ui->stackedWidget_4->currentIndex()==0)&&(ui->stackedWidget_5->currentIndex()==0)&&(ui->stackedWidget_6->currentIndex()==0))
    {
        this->close();
        //qDebug()<<"back!!!!!!66666666666!!!!!!!!!!!!!";
    }
    if (ui->stackedWidget_2->currentIndex()==1)
    {
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->label_17->setText("基本信息");
        flag = false;
        //qDebug()<<"ui->stackedWidget_2->currentIndex()==1";

    }
    else if (ui->stackedWidget_2->currentIndex()==2)
    {
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->label_17->setText("基本信息");
        flag = false;
        //qDebug()<<"ui->stackedWidget_2->currentIndex()==2";

    }
    else if (ui->stackedWidget_2->currentIndex()==3)
    {
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->label_17->setText("基本信息");
        flag = false;
        qDebug()<<"ui->stackedWidget_2->currentIndex()==3";

    }
    else if (ui->stackedWidget_2->currentIndex()==4)
    {
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->label_17->setText("基本信息");
        flag = false;
        //qDebug()<<"ui->stackedWidget_2->currentIndex()==4";

    }
    else if ((ui->stackedWidget_3->currentIndex()==0)&&(ui->stackedWidget_4->currentIndex()==0)&&(ui->stackedWidget_5->currentIndex()==0)&&(ui->stackedWidget_6->currentIndex()==0))
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_17->setText("基本信息");
        flag = false;
        //qDebug()<<"ui->stackedWidget_3->currentIndex()==0";

    }
    if (ui->stackedWidget_3->currentIndex()==1)
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        qDebug()<<"ui->stackedWidget_3->currentIndex()==1";
        ui->label_29->setText("重力加速度");
    }
    else if ((ui->stackedWidget_3->currentIndex()==2))
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_29->setText("时间设置");
        //flag = false;
    }
    else if ((ui->stackedWidget_3->currentIndex()==3))
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_29->setText("语言设置");
        //flag = false;
    }
    else if ((ui->stackedWidget_3->currentIndex()==4))
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_29->setText("亮度");
        //flag = false;
    }
    else if ((ui->stackedWidget_3->currentIndex()==5))
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_29->setText("触摸屏校正");
        //flag = false;
    }
    else if ((ui->stackedWidget_3->currentIndex()==6))
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_29->setText("应用软件更新");
        //flag = false;
    }
    else if ((ui->stackedWidget_3->currentIndex()==7))
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_29->setText("系统属性");
        //flag = false;
    }
    else if ((ui->stackedWidget_3->currentIndex()==8))
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_29->setText("设置密码");
        //flag = false;系统属性设置密码
    }
    else if ((ui->stackedWidget_3->currentIndex()==9))
    {
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_29->setText("其它");
        //flag = false;系统属性设置密码
    }

    if (ui->stackedWidget_4->currentIndex()==1)
    {
        ui->stackedWidget_4->setCurrentIndex(0);
        ui->label_32->setText("重力加速度");
    }
    else if ((ui->stackedWidget_4->currentIndex()==2))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==3))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==4))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==2))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==5))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==6))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==7))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==8))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==9))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_4->currentIndex()==10))
    {
        ui->stackedWidget_4->setCurrentIndex(0);
    }

    if (ui->stackedWidget_5->currentIndex()==1)
    {
        ui->stackedWidget_5->setCurrentIndex(0);
        //ui->label_32->setText("重力加速度");
    }
    else if ((ui->stackedWidget_5->currentIndex()==2))
    {
        ui->stackedWidget_5->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_5->currentIndex()==3))
    {
        ui->stackedWidget_5->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_5->currentIndex()==4))
    {
        ui->stackedWidget_5->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_5->currentIndex()==5))
    {
        ui->stackedWidget_5->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_5->currentIndex()==6))
    {
        ui->stackedWidget_5->setCurrentIndex(4);
    }
    else if ((ui->stackedWidget_5->currentIndex()==7))
    {
        ui->stackedWidget_5->setCurrentIndex(0);
    }
    else if((ui->stackedWidget_5->currentIndex()==8))
    {
        ui->stackedWidget_5->setCurrentIndex(0);
    }
    else if((ui->stackedWidget_5->currentIndex()==9))
    {
        ui->stackedWidget_5->setCurrentIndex(0);
    }
    if (ui->stackedWidget_6->currentIndex()==1)
    {
        ui->stackedWidget_6->setCurrentIndex(0);
        //ui->label_32->setText("重力加速度");
    }
    else if ((ui->stackedWidget_6->currentIndex()==4))
    {
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else if ((ui->stackedWidget_6->currentIndex()==5))
    {
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else if ((ui->stackedWidget_6->currentIndex()==6))
    {
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else if ((ui->stackedWidget_6->currentIndex()==7))
    {
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else if ((ui->stackedWidget_6->currentIndex()==8))
    {
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else if ((ui->stackedWidget_6->currentIndex()==9))
    {
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else if ((ui->stackedWidget_6->currentIndex()==10))
    {
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else if((ui->stackedWidget_6->currentIndex()==11))
    {
        ui->stackedWidget_6->setCurrentIndex(3);
    }
    else if ((ui->stackedWidget_6->currentIndex()==2))
    {
        ui->stackedWidget_6->setCurrentIndex(0);
    }
    else if ((ui->stackedWidget_6->currentIndex()==3))
    {
        ui->stackedWidget_6->setCurrentIndex(0);
    }
    if (ui->stackedWidget->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->label_17->setText("基本信息");
        qDebug()<<"ui->stackedWidget->currentIndex()==4";
    }
    if ((ui->stackedWidget_2->currentIndex()==0)&&(flag==true)&&(ui->stackedWidget->currentIndex()==0))
    {
        this->close();
        qDebug()<<"back!!!!!!!!!!!!!!!!!!!";
        flag=false;
    }
    //    qDebug()<<"ui->stackedWidget_2->currentIndex()"<<ui->stackedWidget_2->currentIndex();
    //    qDebug()<<"ui->stackedWidget_3->currentIndex()"<<ui->stackedWidget_3->currentIndex();
    //    qDebug()<<"ui->stackedWidget_4->currentIndex()"<<ui->stackedWidget_4->currentIndex();
    //    qDebug()<<"ui->stackedWidget_5->currentIndex()"<<ui->stackedWidget_5->currentIndex();
    //    qDebug()<<"ui->stackedWidget->currentIndex()"<<ui->stackedWidget->currentIndex();

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
}

void configSetting::on_toolButton_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(0);
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    PrintCompanyName = configIniRead->value("baseinfo/PrintCompanyName").toString();
    CompanyAddr=configIniRead->value("baseinfo/CompanyAddr").toString();
    CompanyTel=configIniRead->value("baseinfo/CompanyTel").toString();
    CompanyWebsite=configIniRead->value("baseinfo/CompanyWebsite").toString();
    CompanyLabel=configIniRead->value("baseinfo/CompanyLabel").toString();
    delete configIniRead;

    ui->textEdit_2->setText(PrintCompanyName);
    ui->textEdit_3->setText(CompanyAddr);
    ui->textEdit_4->setText(CompanyTel);
    ui->textEdit_5->setText(CompanyWebsite);
    ui->textEdit_6->setText(CompanyLabel);
    //ui->lineEdit_7->setText(UDPServerIp);
    // ui->lineEdit_8->setText(QString::number(UDPServerPort));
}
void configSetting::timerUpdate()
{
    // CurData=calcf.RD1232();
    CurData= AdData;
    QString temp = QString::number(CurData);
    ui->label_8->setText(temp);
    ui->label_98->setText(temp);
    ui->label_102->setText(temp);
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    ui->label_date->setText(str);
    if(quanxian==2)
        ui->toolButton_5->setEnabled(false);
    QString max1 =  QString::number(Full);
    QString min1 =  QString::number(Rati*20);
    QString dtemp1 =  QString::number(Rati);
    ui->label_12->setText(max1);
    ui->label_10->setText(min1);
    ui->label_26->setText(dtemp1);

    ui->progressBar->setValue(StartPosition);
}

void configSetting::on_pushButton_3_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(0);
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    PrintCompanyName = configIniRead->value("baseinfo/PrintCompanyName").toString();
    CompanyAddr=configIniRead->value("baseinfo/CompanyAddr").toString();
    CompanyTel=configIniRead->value("baseinfo/CompanyTel").toString();
    CompanyWebsite=configIniRead->value("baseinfo/CompanyWebsite").toString();
    CompanyLabel=configIniRead->value("baseinfo/CompanyLabel").toString();
    delete configIniRead;

    ui->textEdit_2->setText(PrintCompanyName);
    ui->textEdit_3->setText(CompanyAddr);
    ui->textEdit_4->setText(CompanyTel);
    ui->textEdit_5->setText(CompanyWebsite);
    ui->textEdit_6->setText(CompanyLabel);
    ui->label_17->setText("用户信息");
}

void configSetting::on_pushButton_4_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->label_17->setText("设备编号");
}

void configSetting::on_pushButton_5_clicked()
{
    beep_start;
    //ui->stackedWidget_2->setCurrentIndex(3);
    //ui->label_17->setText("小数点设置");
    PIN_PB25_H;
    QMessageBox::StandardButton rb=QMessageBox::information(this, tr("换纸程序"), tr("执行换纸程序"), QMessageBox::Cancel);
    if(rb == QMessageBox::Cancel)
    {
        qDebug()<<"QMessageBox::Cancel";
        PIN_PB25_L;
    }

}

/*void configSetting::on_pushButton_6_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(4);
    ui->label_17->setText("称重模式");
}*/
void configSetting::slot_ScroolWidget(int value)
{
    double p=static_cast<double>(value)/static_cast<double>(ui->verticalScrollBar->maximum());
    //ui->widget->move(0,-(ui->widget->height()-350)*p);
    ui->widget_2->move(0,-(ui->widget_2->height()-350)*p);
}

void configSetting::on_toolButton_2_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_3->setCurrentIndex(0);
}

/*void configSetting::on_pushButton_7_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(1);
    ui->label_29->setText("重力加速度");
}*/

void configSetting::on_pushButton_8_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->label_29->setText("时间设置");
}



void configSetting::on_pushButton_9_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(3);
    ui->label_29->setText("语言设置");

    ui->comboBox->clear();
    QStringList CompletedList;
    CompletedList<<tr("中文")<<tr("英文")<<tr("西班牙语")<<tr("俄语")<<tr("德语")<<tr("法语")<<tr("日文")<<tr("韩语");
    ui->comboBox->addItems(CompletedList);

}

void configSetting::on_pushButton_10_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(4);
    ui->label_29->setText("亮度");
    //   int templed;
    qDebug()<<"LedLight"<<LedLight;
    switch (LedLight)
    {
    case 1:
        ui->radioButton_56->setChecked(true);
        ui->radioButton_56->setFocus();
        break;
    case 2:
        ui->radioButton_60->setChecked(true);
        ui->radioButton_60->setFocus();
        break;
    case 3:
        ui->radioButton_58->setChecked(true);
        ui->radioButton_58->setFocus();
        break;
    case 4:
        ui->radioButton_57->setChecked(true);
        ui->radioButton_57->setFocus();
        break;
    case 5:
        ui->radioButton_61->setChecked(true);
        ui->radioButton_61->setFocus();
        break;
    case 6:
        ui->radioButton_59->setChecked(true);
        ui->radioButton_59->setFocus();
        break;
    case 7:
        ui->radioButton_62->setChecked(true);
        ui->radioButton_62->setFocus();
        break;
defult:
        ui->radioButton_62->setChecked(true);
        ui->radioButton_62->setFocus();
        break;
    }
}

void configSetting::on_pushButton_11_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(5);
    ui->label_29->setText("触摸屏校正");
}

void configSetting::on_pushButton_13_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(6);
    ui->label_29->setText("应用软件更新");
}

/*void configSetting::on_pushButton_14_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(7);
    ui->label_29->setText("系统属性");
}
*/
/*void configSetting::on_pushButton_15_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(8);
    ui->label_29->setText("设置密码");
}*/

/*void configSetting::on_pushButton_17_clicked()
{
    beep_start;
    ui->stackedWidget_3->setCurrentIndex(9);
    ui->label_29->setText("其它");
}*/

void configSetting::on_toolButton_3_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(2);
    ui->stackedWidget_4->setCurrentIndex(0);
}

/*void configSetting::on_pushButton_25_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(1);
    ui->label_32->setText("量程模式");
}*/

void configSetting::on_pushButton_26_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(2);
    ui->label_32->setText("校正单位");
    qDebug()<<"Unit"<<Unit;
    switch (Unit)
    {
    case 1:
        ui->radioButton_12->setChecked(true);
        ui->radioButton_12->setFocus();
        break;
    case 2:
        ui->radioButton_13->setChecked(true);
        ui->radioButton_13->setFocus();
        break;
    case 3:
        ui->radioButton_11->setChecked(true);
        ui->radioButton_11->setFocus();
        break;
defult:
        ui->radioButton_12->setChecked(true);
        ui->radioButton_12->setFocus();
        break;
    }

}

void configSetting::on_pushButton_27_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(3);
    ui->label_32->setText("小数点");
    qDebug()<<"Point"<<Point;
    switch (Point)
    {
    case 0:
        ui->radioButton_19->setChecked(true);
        ui->radioButton_19->setFocus();
        break;
    case 1:
        ui->radioButton_18->setChecked(true);
        ui->radioButton_18->setFocus();
        break;
    case 2:
        ui->radioButton_17->setChecked(true);
        ui->radioButton_17->setFocus();
        break;
    case 3:
        ui->radioButton_16->setChecked(true);
        ui->radioButton_16->setFocus();
        break;
    case 4:
        ui->radioButton_20->setChecked(true);
        ui->radioButton_20->setFocus();
        break;
defult:
        ui->radioButton_19->setChecked(true);
        ui->radioButton_19->setFocus();
        break;
    }
}

void configSetting::on_pushButton_28_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(4);
    ui->label_32->setText("满量程");
    ui->lineEdit_11->setText(QString::number(CalFull,'f',Point));
    //temp=QString::number(Net,'f',Point);
}

/*void configSetting::on_pushButton_29_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(5);
    ui->label_32->setText("最小标定重量限制");
}*/

void configSetting::on_pushButton_30_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(6);
    ui->label_32->setText("分度值");
    /*qDebug()<<"Rati11111111111111111111111111111111111111"<<Rati;
    ui->comboBox_2->clear();
    QStringList CompletedList;
    CompletedList<<tr("1")<<tr("2")<<tr("5")<<tr("10")<<tr("20")<<tr("50")<<tr("100")<<tr("200");
    ui->comboBox_2->addItems(CompletedList);
    qDebug()<<"Rati"<<Rati;
    switch (Rati)
    {
    case 1:
        ui->comboBox_2->setCurrentIndex(0);
        break;
    case 2:
        ui->comboBox_2->setCurrentIndex(1);
        break;
    case 5:
        ui->comboBox_2->setCurrentIndex(2);
        break;
    case 10:
        ui->comboBox_2->setCurrentIndex(3);
        break;
    case 20:
        ui->comboBox_2->setCurrentIndex(4);
        break;
    case 50:
        ui->comboBox_2->setCurrentIndex(5);
        break;
    case 100:
        ui->comboBox_2->setCurrentIndex(6);
        break;
    case 200:
        ui->comboBox_2->setCurrentIndex(7);
        break;
defult:
        ui->comboBox_2->setCurrentIndex(0);
        break;
    }*/
    qDebug()<<"Rati"<<Rati;
    switch(Rati)
    {
    case 1:
        ui->radioButton_29->setChecked(true);
        ui->radioButton_29->setFocus();
        break;
    case 2:
        ui->radioButton_30->setChecked(true);
        ui->radioButton_30->setFocus();
        break;
    case 5:
        ui->radioButton_34->setChecked(true);
        ui->radioButton_34->setFocus();
        break;
    case 10:
        ui->radioButton_21->setChecked(true);
        ui->radioButton_21->setFocus();
        break;
    case 20:
        ui->radioButton_54->setChecked(true);
        ui->radioButton_54->setFocus();
        break;
    case 50:
        ui->radioButton_38->setChecked(true);
        ui->radioButton_38->setFocus();
        break;
    case 100:
        ui->radioButton_55->setChecked(true);
        ui->radioButton_55->setFocus();
        break;
defult:
        ui->radioButton_29->setChecked(true);
        ui->radioButton_29->setFocus();
        break;
    }

}

void configSetting::on_pushButton_31_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(7);
    ui->label_32->setText("自动归零");
    // OnZero=3;
    qDebug()<<"OnZero"<<OnZero;
    switch (OnZero)
    {
    case 6:
        ui->radioButton_28->setChecked(true);
        ui->radioButton_28->setFocus();
        break;
    case 1:
        ui->radioButton_25->setChecked(true);
        ui->radioButton_25->setFocus();
        break;
    case 2:
        ui->radioButton_23->setChecked(true);
        ui->radioButton_23->setFocus();
        break;
    case 3:
        ui->radioButton_24->setChecked(true);
        ui->radioButton_24->setFocus();
        break;
    case 4:
        ui->radioButton_26->setChecked(true);
        ui->radioButton_26->setFocus();
        break;
    case 5:
        ui->radioButton_27->setChecked(true);
        ui->radioButton_27->setFocus();
        break;
defult:
        ui->radioButton_28->setChecked(true);
        ui->radioButton_28->setFocus();
        break;
    }
}

void configSetting::on_pushButton_32_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(8);
    ui->label_32->setText("手动归零");
    //  ZeroKeyVal=2;
    qDebug()<<"ZeroKeyVal"<<ZeroKeyVal;
    switch(ZeroKeyVal)
    {
    case 6:
        ui->radioButton_36->setChecked(true);
        ui->radioButton_36->setFocus();
        break;
    case 1:
        ui->radioButton_37->setChecked(true);
        ui->radioButton_37->setFocus();
        break;
    case 2:
        ui->radioButton_33->setChecked(true);
        ui->radioButton_33->setFocus();
        break;
    case 3:
        ui->radioButton_31->setChecked(true);
        ui->radioButton_31->setFocus();
        break;
    case 4:
        ui->radioButton_32->setChecked(true);
        ui->radioButton_32->setFocus();
        break;
    case 5:
        ui->radioButton_35->setChecked(true);
        ui->radioButton_35->setFocus();
        break;
defult:
        ui->radioButton_36->setChecked(true);
        ui->radioButton_36->setFocus();
        break;
    }
}

void configSetting::on_pushButton_33_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(9);
    ui->label_32->setText("零位跟踪");
    qDebug()<<"Zono"<<Zono;
    switch(Zono)
    {
    case 6:
        ui->radioButton_44->setChecked(true);
        ui->radioButton_44->setFocus();
        break;
    case 1:
        ui->radioButton_41->setChecked(true);
        ui->radioButton_41->setFocus();
        break;
    case 2:
        ui->radioButton_39->setChecked(true);
        ui->radioButton_39->setFocus();
        break;
    case 3:
        ui->radioButton_40->setChecked(true);
        ui->radioButton_40->setFocus();
        break;
    case 4:
        ui->radioButton_42->setChecked(true);
        ui->radioButton_42->setFocus();
        break;
    case 5:
        ui->radioButton_43->setChecked(true);
        ui->radioButton_43->setFocus();
        break;
defult:
        ui->radioButton_44->setChecked(true);
        ui->radioButton_44->setFocus();
        break;
    }
}

/*void configSetting::on_pushButton_34_clicked()
{
    beep_start;
    ui->stackedWidget_4->setCurrentIndex(10);
    ui->label_32->setText("扣重操作");
}*/

void configSetting::on_toolButton_6_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget_5->setCurrentIndex(0);
}

void configSetting::on_pushButton_49_clicked()
{
    beep_start;
    int index;
    ui->stackedWidget_5->setCurrentIndex(1);
    ui->label_76->setText("Com1");

    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    index=configIniRead->value("baseinfo/Tmode232").toInt();
    ui->comboBox_3->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/BaudRate232").toInt();
    ui->comboBox_4->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/DataBits232").toInt();
    ui->comboBox_6->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/StopBits232").toInt();
    ui->comboBox_7->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/Parity232").toInt();
    ui->comboBox_5->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/CommType232").toInt();
    ui->comboBox_14->setCurrentIndex(index);
    delete configIniRead;
    /* ui->comboBox_3->clear();
    QStringList CompletedList;
    CompletedList<<tr("关闭")<<tr("打印")<<tr("连续发送")<<tr("问答")<<tr("稳定");
    ui->comboBox_3->addItems(CompletedList);

    ui->comboBox_4->clear();
    CompletedList.clear();
    CompletedList<<tr("600")<<tr("1200")<<tr("2400")<<tr("4800")<<tr("9600")<<tr("19200")<<tr("38400")<<tr("115200");
    ui->comboBox_4->addItems(CompletedList);

    ui->comboBox_6->clear();
    //QStringList CompletedList;
    CompletedList.clear();
    CompletedList<<tr("6")<<tr("7")<<tr("8");
    ui->comboBox_6->addItems(CompletedList);

    ui->comboBox_7->clear();
    //QStringList CompletedList;
    CompletedList.clear();
    CompletedList<<tr("1")<<tr("2");
    ui->comboBox_7->addItems(CompletedList);*/

}

void configSetting::on_pushButton_48_clicked()
{
    beep_start;
    int index;
    ui->stackedWidget_5->setCurrentIndex(2);
    ui->label_76->setText("Com2");

    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    index=configIniRead->value("baseinfo/Tmode485").toInt();
    ui->comboBox_10->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/BaudRate485").toInt();
    ui->comboBox_8->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/DataBits485").toInt();
    ui->comboBox_12->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/StopBits485").toInt();
    ui->comboBox_9->setCurrentIndex(index);
    index=configIniRead->value("baseinfo/Parity485").toInt();
    ui->comboBox_11->setCurrentIndex(index);
    Addr=configIniRead->value("baseinfo/Addr").toInt();
    if((Addr<1)||(Addr>127))Addr=1;
    ui->lineEdit_10->setText(QString::number(Addr));
    delete configIniRead;

    /*ui->comboBox_10->clear();
    QStringList CompletedList;
    CompletedList<<tr("关闭")<<tr("打印")<<tr("连续发送")<<tr("问答")<<tr("稳定");
    ui->comboBox_10->addItems(CompletedList);

    ui->comboBox_8->clear();
    CompletedList.clear();
    CompletedList<<tr("600")<<tr("1200")<<tr("2400")<<tr("4800")<<tr("9600")<<tr("19200")<<tr("38400")<<tr("115200");
    ui->comboBox_8->addItems(CompletedList);

    ui->comboBox_12->clear();
    //QStringList CompletedList;
    CompletedList.clear();
    CompletedList<<tr("6")<<tr("7")<<tr("8");
    ui->comboBox_12->addItems(CompletedList);

    ui->comboBox_9->clear();
    //QStringList CompletedList;
    CompletedList.clear();
    CompletedList<<tr("1")<<tr("2");
    ui->comboBox_9->addItems(CompletedList);*/
}

void configSetting::on_pushButton_47_clicked()
{
    beep_start;
    ui->stackedWidget_5->setCurrentIndex(3);
    ui->label_76->setText("照相机");
}

void configSetting::on_pushButton_50_clicked()
{
    beep_start;
    ui->stackedWidget_5->setCurrentIndex(4);
    ui->label_76->setText("服务器");
}

void configSetting::on_pushButton_51_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(3);
    switch (PrintLableSize)
    {
    case 0:
        ui->radioButton_66->setChecked(true);
        // ui->radioButton_66->setFocus();
        break;
    case 1:
        ui->radioButton_67->setChecked(true);
        // ui->radioButton_67->setFocus();
        break;
        /*case 2:
        ui->radioButton_68->setChecked(true);
        break;*/

        /*  defult:
        ui->radioButton_67->setChecked(true);
        break;*/
    }

    switch (PrintCodeType)
    {
    case 0:
        ui->radioButton_65->setChecked(true);
        // ui->radioButton_65->setFocus();
        break;
    case 1:
        ui->radioButton_64->setChecked(true);
        break;
    case 2:
        ui->radioButton_68->setChecked(true);
        //ui->radioButton_64->setFocus();
        break;


        /*defult:
        ui->radioButton_65->setChecked(true);
        break;*/
    }
    
    switch (b_PrintStable)
    {
    case 0:
        ui->radioButton_71->setChecked(true);
        // ui->radioButton_71->setFocus();
        break;
    case 1:
        ui->radioButton_72->setChecked(true);
        // ui->radioButton_72->setFocus();
        break;


        /*defult:
        ui->radioButton_71->setChecked(true);
        break;*/
    }

    switch (b_PrintRetZero)
    {
    case 0:
        ui->radioButton_70->setChecked(true);
        // ui->radioButton_70->setFocus();
        break;
    case 1:
        ui->radioButton_69->setChecked(true);
        //ui->radioButton_69->setFocus();
        break;


        /*defult:
        ui->radioButton_70->setChecked(true);
        break;*/
    }
    switch (b_Save)
    {
    case 0:
        ui->radioButton_73->setChecked(true);
        break;
    case 1:
        ui->radioButton_74->setChecked(true);
        break;
    case 2:
        ui->radioButton_77->setChecked(true);
        break;
        /*defult:
        ui->radioButton_73->setChecked(true);
        break;*/
    }

    switch (b_PrintHeader)
    {
    case 0:
        ui->radioButton_75->setChecked(true);
        break;
    case 1:
        ui->radioButton_76->setChecked(true);
        break;


        
    }

    ui->lineEdit_12->setText(QString::number(PrintLq));

}

void configSetting::on_toolButton_4_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_6->setCurrentIndex(0);
}

void configSetting::on_pushButton_38_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(1);
    ui->label_75->setText("滤波强度");
    qDebug()<<"FilterStep"<<FilterStep;
    switch (FilterStep)
    {
    case 1:
        ui->radioButton_46->setChecked(true);
        break;
    case 2:
        ui->radioButton_49->setChecked(true);
        break;
    case 3:
        ui->radioButton_48->setChecked(true);
        break;
    case 4:
        ui->radioButton_47->setChecked(true);
        break;
defult:
        ui->radioButton_49->setChecked(true);
        break;
    }
}

/*void configSetting::on_pushButton_37_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(2);
    ui->label_75->setText("称重单位");

}*/

void configSetting::on_pushButton_2_clicked()
{
    beep_start;
    ui->stackedWidget_7->setCurrentIndex(1);
    //ui->label_3->setEnabled(false);
    ui->label_36->setEnabled(false);
    ui->label_38->setEnabled(false);
    //ui->label_97->setEnabled(false);
    //ui->label_6->setEnabled(false);
    //ui->label_7->setEnabled(false);
    AD_Zero=calcf.RD1232();
    Start_Zero=AD_Zero;
    QString temp = QString::number(AD_Zero);
    ui->label_8->setText(temp);
    ui->pushButton_39->setEnabled(false);
    ui->pushButton_40->setEnabled(false);
    //ui->textEdit->setEnabled(false);
}
void configSetting::on_pushButton_41_clicked()
{

}

void configSetting::on_pushButton_36_clicked()
{
    beep_start;
    QString temp2=ui->lineEdit_2->text();
    Adload=temp2.toFloat();
    if (Adload<CalFull*0.01)
    {
        QMessageBox::critical(this, tr("错误"), tr("加载砝码过小"), QMessageBox::Yes, QMessageBox::Yes);
        return;

    }
    else if(Adload>CalFull)
    {
        QMessageBox::critical(this, tr("错误"), tr("超出满量程"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    ui->stackedWidget_7->setCurrentIndex(2);
    //ui->label_3->setEnabled(false);
    ui->label_103->setEnabled(false);
    ui->label_106->setEnabled(false);
    //ui->label_97->setEnabled(false);
    //ui->label_6->setEnabled(false);
    //ui->label_7->setEnabled(false);
    //ui->label_8->setText("00000");
    ui->pushButton_41->setEnabled(false);
    ui->pushButton_42->setEnabled(false);
    //ui->textEdit->setEnabled(false);
    ui->lineEdit_4->setText(temp2);

}

void configSetting::on_pushButton_40_clicked()
{
    //ui->stackedWidget_7->setCurrentIndex(0);
    //ui->lab

}

void configSetting::on_pushButton_43_clicked()
{
    beep_start;
    ui->stackedWidget_7->setCurrentIndex(0);
    //ui->label_3->setEnabled(false);
    ui->label_3->setEnabled(true);
    ui->label_4->setEnabled(false);
    //ui->label_5->setEnabled(false);
    ui->label_6->setEnabled(false);
    //ui->label_7->setEnabled(false);
    // ui->label_8->setText("00000");
    //ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_35->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    CurData=calcf.RD1232();
    Rri=Adload*10.0/(CurData-AD_Zero);
    if(Unit==2)
    {
        Rri=Rri/2.20462;
    }
    else if(Unit==3)
    {
        Rri=Rri/1000;
    }
    Start_Zero=AD_Zero;
    //ui->label_111->setText("标定完成");
    //sleep(3);
    //ui->label_111->hide();
    calcf.ArgSave1();//biaolv  biaodinglingdian
    calcf.ArgRead1();//

}

void configSetting::on_pushButton_69_clicked()
{
    beep_start;
    int new_year=(ui->year->text()).toInt()-1;
    ui->year->setText(QString::number(new_year));
}

void configSetting::on_pushButton_80_clicked()
{
    beep_start;
    if(ui->month->text().toInt()<12)
    {
        int new_month=(ui->month->text()).toInt()+1;
        ui->month->setText(QString::number(new_month));
    }
    else
        ui->month->setText(QString::number(1));
}

void configSetting::on_pushButton_81_clicked()
{
    beep_start;
    if(ui->date->text().toInt()<31)
    {
        int new_date=(ui->date->text()).toInt()+1;
        ui->date->setText(QString::number(new_date));
    }
    else
        ui->date->setText(QString::number(1));
}

void configSetting::on_pushButton_82_clicked()
{
    beep_start;
    if(ui->hour->text().toInt()<23)
    {
        int new_hour=(ui->hour->text()).toInt()+1;
        ui->hour->setText(QString::number(new_hour));
    }
    else
        ui->hour->setText(QString::number(0));
}

void configSetting::on_pushButton_83_clicked()
{
    beep_start;
    if(ui->minute->text().toInt()<59)
    {
        int new_minute=(ui->minute->text()).toInt()+1;
        ui->minute->setText(QString::number(new_minute));
    }
    else
        ui->minute->setText(QString::number(0));
}

void configSetting::on_pushButton_84_clicked()
{
    beep_start;
    if(ui->second->text().toInt()<59)
    {
        int new_second=(ui->second->text()).toInt()+1;
        ui->second->setText(QString::number(new_second));
    }
    else
        ui->second->setText(QString::number(0));
}

void configSetting::on_pushButton_85_clicked()
{
    beep_start;
    if(ui->month->text().toInt()>1)
    {
        int new_month=(ui->month->text()).toInt()-1;
        ui->month->setText(QString::number(new_month));
    }
    else
        ui->month->setText(QString::number(12));
}

void configSetting::on_pushButton_92_clicked()
{
    beep_start;
    if(ui->date->text().toInt()>1)
    {
        int new_date=(ui->date->text()).toInt()-1;
        ui->date->setText(QString::number(new_date));
    }
    else
        ui->date->setText(QString::number(31));
}

void configSetting::on_pushButton_93_clicked()
{
    beep_start;
    if(ui->hour->text().toInt()>0)
    {
        int new_hour=(ui->hour->text()).toInt()-1;
        ui->hour->setText(QString::number(new_hour));
    }
    else
        ui->hour->setText(QString::number(23));
}

void configSetting::on_pushButton_94_clicked()
{
    beep_start;
    if(ui->minute->text().toInt()>0)
    {
        int new_minute=(ui->minute->text()).toInt()-1;
        ui->minute->setText(QString::number(new_minute));
    }
    else
        ui->minute->setText(QString::number(59));
}

void configSetting::on_pushButton_95_clicked()
{
    beep_start;
    if(ui->second->text().toInt()>0)
    {
        int new_second=(ui->second->text()).toInt()-1;
        ui->second->setText(QString::number(new_second));
    }
    else
        ui->second->setText(QString::number(59));
}

void configSetting::on_pushButton_44_clicked()
{
    beep_start;
    QString str = "date -s \"" +ui->year->text()+"-"+ui->month->text() + "-" + ui->date->text()+ " "+ui->hour->text() + ":" + ui->minute->text() + ":" + ui->second->text()+"\" &";

    //qDebug()<<"str"<<str;
    system(str.toLatin1().data());

    //将系统时间写入RTC
    system("hwclock -w &");
}

void configSetting::on_pushButton_42_clicked()
{

}

void configSetting::on_pushButton_35_clicked()
{
    //123456
}
void configSetting::fromRootdialog(void)
{
    beep_start;
    this->close();
}



void configSetting::on_comboBox_6_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/DataBits232",ui->comboBox_6->currentIndex());

    delete configIniRead;
    DataBits_232=ui->comboBox_6->currentIndex();
    emit DataBitsChangeFor232();
}

void configSetting::on_comboBox_7_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/StopBits232",ui->comboBox_7->currentIndex());

    delete configIniRead;
    StopBits_232=ui->comboBox_7->currentIndex();
    emit StopBitsChangeFor232();
}



void configSetting::on_comboBox_4_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/BaudRate232",ui->comboBox_4->currentIndex());

    delete configIniRead;
    BaudRate_232=ui->comboBox_4->currentIndex();
    emit BaudRateChangeFor232();
}

void configSetting::on_comboBox_5_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/Parity232",ui->comboBox_5->currentIndex());

    delete configIniRead;
    ParityMode_232=ui->comboBox_5->currentIndex();
    emit ParityChangeFor232();
}

void configSetting::on_comboBox_8_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/BaudRate485",ui->comboBox_8->currentIndex());

    delete configIniRead;
    BaudRate_485=ui->comboBox_8->currentIndex();
    emit BaudRateChangeFor485();
}

void configSetting::on_comboBox_11_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/Parity485",ui->comboBox_11->currentIndex());

    delete configIniRead;
    ParityMode_485=ui->comboBox_11->currentIndex();
    emit ParityChangeFor485();
}

void configSetting::on_comboBox_12_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/DataBits485",ui->comboBox_12->currentIndex());

    delete configIniRead;
    DataBits_485=ui->comboBox_12->currentIndex();
    emit DataBitsChangeFor485();
}

void configSetting::on_comboBox_9_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/StopBits485",ui->comboBox_9->currentIndex());

    delete configIniRead;
    StopBits_485=ui->comboBox_9->currentIndex();
    emit StopBitsChangeFor485();
}

void configSetting::on_comboBox_3_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/Tmode232",ui->comboBox_3->currentIndex());
    delete configIniRead;
    Tmode_232=ui->comboBox_3->currentIndex();
    emit TmodeChangeFor232();
}

void configSetting::on_comboBox_10_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/Tmode485",ui->comboBox_10->currentIndex());

    delete configIniRead;
    Tmode_485=ui->comboBox_10->currentIndex();
    //emit TmodeChangeFor485();
}


void configSetting::on_pushButton_46_clicked()
{
    beep_start;
    QString CalFulltemp=ui->lineEdit_11->text();
    CalFull=CalFulltemp.toFloat();
}

void configSetting::on_pushButton_53_clicked()
{
    beep_start;
    ui->stackedWidget_5->setCurrentIndex(6);
    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    ServerIp = configIniRead->value("baseinfo/ServerIp").toString();
    ServerPort = configIniRead->value("baseinfo/ServerPort").toInt();

    UDPServerIp = configIniRead->value("baseinfo/UDPServerIp").toString();
    UDPServerPort = configIniRead->value("baseinfo/UDPServerPort").toInt();
    delete configIniRead;

    ui->lineEdit_5->setText(ServerIp);
    ui->lineEdit_6->setText(QString::number(ServerPort));
    ui->lineEdit_7->setText(UDPServerIp);
    ui->lineEdit_8->setText(QString::number(UDPServerPort));
}

void configSetting::on_pushButton_45_clicked()
{
    beep_start;
    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/ServerIp",ui->lineEdit_5->text());
    configIniRead->setValue("baseinfo/ServerPort",ui->lineEdit_6->text());
    configIniRead->setValue("baseinfo/UDPServerIp",ui->lineEdit_7->text());
    configIniRead->setValue("baseinfo/UDPServerPort",ui->lineEdit_8->text());
    delete configIniRead;
    //qDebug()<<"send to network!!!!!!!!!!!!!!!!!!!";
    emit sendTONetwork();
}
/*void configSetting::on_comboBox_2_activated(const QString &arg1)
{

}

void configSetting::on_comboBox_2_currentIndexChanged(const QString &arg1)
{

}

void configSetting::on_comboBox_2_currentIndexChanged(int index)
{
   //QString temp=ui->comboBox_2->currentText();
  //  Rati=temp.toInt();
  //  qDebug()<<" Rati22222222222222222222222"<< Rati;//
}
*/
void configSetting::on_pushButton_54_clicked()
{
    beep_start;
    ui->stackedWidget_5->setCurrentIndex(7);

    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    LocalIp = configIniRead->value("baseinfo/LocalIp").toString();
    QString Gateway = configIniRead->value("baseinfo/Gateway").toString();
    delete configIniRead;

    ui->lineEdit_9->setText(LocalIp);
    ui->lineEdit_13->setText(Gateway);
}

void configSetting::on_toolButton_8_clicked()
{
    beep_start;
    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/LocalIp",ui->lineEdit_9->text());
    configIniRead->setValue("baseinfo/Gateway",ui->lineEdit_13->text());
    delete configIniRead;
    LocalIp=ui->lineEdit_9->text();
    QString Gateway=ui->lineEdit_13->text();
    QString tempGateway = "route add default gw "+Gateway;
    std::string str1 = tempGateway.toStdString();
    const char* ch1 = str1.c_str();

    QString tempIP = "ifconfig eth0 "+ui->lineEdit_9->text();
    std::string str = tempIP.toStdString();
    const char* ch = str.c_str();
    system(ch);
    system(ch1);
}

void configSetting::on_pushButton_55_clicked()
{
    beep_start;
    ui->stackedWidget_7->setCurrentIndex(0);
    //ui->label_3->setEnabled(false);
    ui->label_3->setEnabled(true);
    ui->label_4->setEnabled(false);
    //ui->label_5->setEnabled(false);
    ui->label_6->setEnabled(false);
    //ui->label_7->setEnabled(false);
    // ui->label_8->setText("00000");
    //ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_35->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);

}

void configSetting::on_pushButton_56_clicked()
{
    beep_start;
    ui->stackedWidget_7->setCurrentIndex(1);
    //ui->label_3->setEnabled(false);
    ui->label_36->setEnabled(false);
    ui->label_38->setEnabled(false);
    //ui->label_97->setEnabled(false);
    //ui->label_6->setEnabled(false);
    //ui->label_7->setEnabled(false);
    AD_Zero=calcf.RD1232();
    QString temp = QString::number(AD_Zero);
    ui->label_8->setText(temp);
    ui->pushButton_39->setEnabled(false);
    ui->pushButton_40->setEnabled(false);
    //ui->textEdit->setEnabled(false);
}

/*void configSetting::on_horizontalSlider_actionTriggered(int action)
{
    //qDebug()<<"on_horizontalSlider_actionTriggered!!!!!!!!!!!!!!!!!"<<action;
}

void configSetting::on_horizontalSlider_valueChanged(int value)
{
    beep_start;
    qDebug()<<"on_horizontalSlider_valueChanged!!!!!!!!!!!!!!!!!"<<value;
    //LedLight = value;
    if (value>=85)
    {
         LedLight = 7;
        system("echo 7 >> /sys/class/backlight/backlight/brightness");
    }
    else if (value>=71)
    {
         LedLight = 6;
        system("echo 6 >> /sys/class/backlight/backlight/brightness");
    }
    else if (value>=57)
    {
        LedLight = 5;
        system("echo 5 >> /sys/class/backlight/backlight/brightness");
    }
    else if (value>=43)
    {
        LedLight = 4;
        system("echo 4 >> /sys/class/backlight/backlight/brightness");
    }
    else if (value>=29)
    {
        LedLight = 3;
        system("echo 3 >> /sys/class/backlight/backlight/brightness");
    }
    else if (value>=15)
    {
        LedLight = 2;
        system("echo 2 >> /sys/class/backlight/backlight/brightness");
    }
    else
    {
        LedLight = 1;
        system("echo 1 >> /sys/class/backlight/backlight/brightness");
    }

}
*/
void configSetting::on_radioButton_12_toggled(bool checked)
{
    // beep_start;
    //qDebug()<<"111111111111111111111111111"<<checked;
    if(checked==true)
    {
        beep_start;
        Unit=1;
        qDebug()<<"unit"<<Unit;
    }
}

void configSetting::on_radioButton_13_toggled(bool checked)
{
    //  beep_start;
    if(checked==true)
    {
        beep_start;
        Unit=2;
        qDebug()<<"unit"<<Unit;
    }
}

void configSetting::on_radioButton_11_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        Unit=3;
        qDebug()<<"unit"<<Unit;
    }
}

void configSetting::on_radioButton_19_toggled(bool checked)
{
    // beep_start;
    if(checked==true)
    {
        beep_start;
        Point=0;
        qDebug()<<"Point"<<Point;
    }
}

void configSetting::on_radioButton_18_toggled(bool checked)
{
    // beep_start;
    if(checked==true)
    {
        beep_start;
        Point=1;
        qDebug()<<"Point"<<Point;
    }
}

void configSetting::on_radioButton_17_toggled(bool checked)
{
    //  beep_start;
    if(checked==true)
    {
        beep_start;
        Point=2;
        qDebug()<<"Point"<<Point;
    }
}

void configSetting::on_radioButton_16_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        Point=3;
        qDebug()<<"Point"<<Point;
    }
}

void configSetting::on_radioButton_20_toggled(bool checked)
{
    // beep_start;
    if(checked==true)
    {
        beep_start;
        Point=4;
        qDebug()<<"Point"<<Point;
    }
}



void configSetting::on_radioButton_28_toggled(bool checked)
{
    // beep_start;
    if(checked==true)
    {
        beep_start;
        OnZero=6;
        qDebug()<<"OnZero"<<OnZero;
    }

}

void configSetting::on_radioButton_25_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        OnZero=1;
        qDebug()<<"OnZero"<<OnZero;
    }
}

void configSetting::on_radioButton_23_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        OnZero=2;
        qDebug()<<"OnZero"<<OnZero;
    }
}

void configSetting::on_radioButton_24_toggled(bool checked)
{
    // beep_start;
    if(checked==true)
    {
        beep_start;
        OnZero=3;
        qDebug()<<"OnZero"<<OnZero;
    }
}

void configSetting::on_radioButton_26_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        OnZero=4;
        qDebug()<<"OnZero"<<OnZero;
    }
}

void configSetting::on_radioButton_27_toggled(bool checked)
{
    // beep_start;
    if(checked==true)
    {
        beep_start;
        OnZero=5;
        qDebug()<<"OnZero"<<OnZero;
    }
}

void configSetting::on_radioButton_36_toggled(bool checked)
{
    // beep_start;
    if(checked==true)
    {
        beep_start;
        ZeroKeyVal=6;
        qDebug()<<"ZeroKeyVal"<<ZeroKeyVal;
    }
}

void configSetting::on_radioButton_37_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        ZeroKeyVal=1;
        qDebug()<<"ZeroKeyVal"<<ZeroKeyVal;
    }
}

void configSetting::on_radioButton_33_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        ZeroKeyVal=2;
        qDebug()<<"ZeroKeyVal"<<ZeroKeyVal;
    }
}

void configSetting::on_radioButton_31_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        ZeroKeyVal=3;
        qDebug()<<"ZeroKeyVal"<<ZeroKeyVal;
    }
}

void configSetting::on_radioButton_32_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        ZeroKeyVal=4;
        qDebug()<<"ZeroKeyVal"<<ZeroKeyVal;
    }
}

void configSetting::on_radioButton_35_toggled(bool checked)
{
    //beep_start;
    if(checked==true)
    {
        beep_start;
        ZeroKeyVal=5;
        qDebug()<<"ZeroKeyVal"<<ZeroKeyVal;
    }
}

void configSetting::on_radioButton_44_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Zono=6;
        qDebug()<<"Zono"<<Zono;
    }
}

void configSetting::on_radioButton_41_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Zono=1;
        qDebug()<<"Zono"<<Zono;
    }
}

void configSetting::on_radioButton_39_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Zono=2;
        qDebug()<<"Zono"<<Zono;
    }
}

void configSetting::on_radioButton_40_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Zono=3;
        qDebug()<<"Zono"<<Zono;
    }
}

void configSetting::on_radioButton_42_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Zono=4;
        qDebug()<<"Zono"<<Zono;
    }
}

void configSetting::on_radioButton_43_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Zono=5;
        qDebug()<<"Zono"<<Zono;
    }
}

void configSetting::on_lineEdit_10_textChanged(const QString &arg1)
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/Addr",ui->lineEdit_10->text());
    delete configIniRead;
    Addr=(ui->lineEdit_10->text()).toInt();
    if((Addr<1)||(Addr>127))Addr=1;

}


void configSetting::on_radioButton_46_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        FilterStep=1;
        //ADS1232_SET_SPS10;
        qDebug()<<"FilterStep"<<FilterStep;
        emit adspeedsignal();
    }
}

void configSetting::on_radioButton_49_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        FilterStep=2;
        //ADS1232_SET_SPS10;
        qDebug()<<"FilterStep"<<FilterStep;
        emit adspeedsignal();
    }
}

void configSetting::on_radioButton_48_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        FilterStep=3;
        //ADS1232_SET_SPS10;
        qDebug()<<"FilterStep"<<FilterStep;
        emit adspeedsignal();
    }
}

void configSetting::on_radioButton_47_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        FilterStep=4;
        //ADS1232_SET_SPS80;
        qDebug()<<"FilterStep"<<FilterStep;
        emit adspeedsignal();


    }
}

void configSetting::on_radioButton_38_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Rati=50;
        qDebug()<<"Rati"<<Rati;
    }
}

void configSetting::on_radioButton_29_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Rati=1;
        qDebug()<<"Rati"<<Rati;
    }
}

void configSetting::on_radioButton_30_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Rati=2;
        qDebug()<<"Rati"<<Rati;
    }
}

void configSetting::on_radioButton_34_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Rati=5;
        qDebug()<<"Rati"<<Rati;
    }
}

void configSetting::on_radioButton_21_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Rati=10;
        qDebug()<<"Rati"<<Rati;
    }
}

void configSetting::on_radioButton_54_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Rati=20;
        qDebug()<<"Rati"<<Rati;
    }
}

void configSetting::on_radioButton_55_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        Rati=100;
        qDebug()<<"Rati"<<Rati;
    }
}

void configSetting::on_radioButton_56_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        LedLight=1;
        system("echo 1 >> /sys/class/backlight/backlight/brightness");
        qDebug()<<"LedLight"<<LedLight;
    }
}

void configSetting::on_radioButton_60_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        LedLight=2;
        system("echo 2 >> /sys/class/backlight/backlight/brightness");
        qDebug()<<"LedLight"<<LedLight;
    }
}

void configSetting::on_radioButton_58_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        LedLight=3;
        system("echo 3 >> /sys/class/backlight/backlight/brightness");
        qDebug()<<"LedLight"<<LedLight;
    }
}

void configSetting::on_radioButton_57_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        LedLight=4;
        system("echo 4 >> /sys/class/backlight/backlight/brightness");
        qDebug()<<"LedLight"<<LedLight;
    }
}

void configSetting::on_radioButton_61_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        LedLight=5;
        system("echo 5 >> /sys/class/backlight/backlight/brightness");
        qDebug()<<"LedLight"<<LedLight;
    }
}

void configSetting::on_radioButton_59_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        LedLight=6;
        system("echo 6 >> /sys/class/backlight/backlight/brightness");
        qDebug()<<"LedLight"<<LedLight;
    }
}

void configSetting::on_radioButton_62_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        LedLight=7;
        system("echo 7 >> /sys/class/backlight/backlight/brightness");
        qDebug()<<"LedLight"<<LedLight;
    }
}

void configSetting::on_pushButton_18_clicked()
{

    beep_start;
    //system("/opt/forlinx_qt4.8/bin/TouchscreenTest -qws&");
    system("source /etc/qt_env.sh&");
    //./opt/forlinx_qt4.8/bin/TouchscreenTest -qws&
    system("/opt/forlinx_qt4.8/bin/TouchscreenTest -qws&");
    system("ts_calibrate&");
    system("ps -ef | grep A12 | grep -v grep | cut -c 3-5 | xargs kill -9&");
}

void configSetting::on_pushButton_57_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(4);
    switch (PrintCodeType)
    {
    case 0:
        ui->radioButton_65->setChecked(true);
        ui->radioButton_65->setFocus();
        break;
    case 1:
        ui->radioButton_64->setChecked(true);
        ui->radioButton_64->setFocus();
        break;
    case 2:
        ui->radioButton_68->setChecked(true);
        ui->radioButton_68->setFocus();
        break;
        
    }
}

void configSetting::on_pushButton_58_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(5);
    switch (PrintLableSize)
    {
    case 0:
        ui->radioButton_66->setChecked(true);
        ui->radioButton_66->setFocus();
        break;
    case 1:
        ui->radioButton_67->setChecked(true);
        ui->radioButton_67->setFocus();
        break;

    }
}

void configSetting::on_pushButton_59_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(6);


    switch (b_PrintRetZero)
    {
    case 0:
        ui->radioButton_70->setChecked(true);
        ui->radioButton_70->setFocus();
        break;
    case 1:
        ui->radioButton_69->setChecked(true);
        ui->radioButton_69->setFocus();
        break;


        /*defult:
        ui->radioButton_70->setChecked(true);
        break;*/
    }

}

void configSetting::on_pushButton_60_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(7);
    switch (b_PrintStable)
    {
    case 0:
        ui->radioButton_71->setChecked(true);
        ui->radioButton_71->setFocus();
        break;
    case 1:
        ui->radioButton_72->setChecked(true);
        ui->radioButton_72->setFocus();
        break;


        /*defult:
        ui->radioButton_71->setChecked(true);
        break;*/
    }

}

void configSetting::on_pushButton_61_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(8);
}

void configSetting::on_pushButton_62_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(9);
}

void configSetting::on_pushButton_63_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(10);
    switch (b_Save)
    {
    case 0:
        ui->radioButton_73->setChecked(true);
        ui->radioButton_73->setFocus();
        break;
    case 1:
        ui->radioButton_74->setChecked(true);
        ui->radioButton_74->setFocus();
        break;
    case 2:
        ui->radioButton_77->setChecked(true);
        ui->radioButton_77->setFocus();
        break;

        
    }
}

void configSetting::on_radioButton_73_toggled(bool checked)
{

    if(checked==true)
    {
        beep_start;
        b_Save=0;
        qDebug()<<"b_Save"<<b_Save;
    }
}

void configSetting::on_radioButton_74_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        b_Save=1;
        qDebug()<<"b_Save"<<b_Save;
    }
}

void configSetting::on_radioButton_69_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        b_PrintRetZero=1;
        qDebug()<<"b_PrintRetZero"<<b_PrintRetZero;
    }
}

void configSetting::on_radioButton_70_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        b_PrintRetZero=0;
        qDebug()<<"b_PrintRetZero"<<b_PrintRetZero;
    }
}

void configSetting::on_radioButton_71_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        b_PrintStable=0;
        qDebug()<<"b_PrintStable"<<b_PrintStable;
    }
}

void configSetting::on_radioButton_72_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        b_PrintStable=1;
        qDebug()<<"b_PrintStable"<<b_PrintStable;
    }
}

void configSetting::on_lineEdit_12_textChanged(const QString &arg1)
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintLq",ui->lineEdit_12->text());
    delete configIniRead;
    PrintLq=(ui->lineEdit_12->text()).toInt();
}

void configSetting::on_radioButton_66_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        PrintLableSize=0;
        qDebug()<<"PrintLableSize"<<PrintLableSize;
    }
}

void configSetting::on_radioButton_67_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        PrintLableSize=1;
        qDebug()<<"PrintLableSize"<<PrintLableSize;
    }
}

/*void configSetting::on_radioButton_68_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        PrintLableSize=2;
        qDebug()<<"PrintLableSize"<<PrintLableSize;
    }
}*/

void configSetting::on_radioButton_64_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        PrintCodeType=1;
        qDebug()<<"PrintCodeType"<<PrintCodeType;
    }
}

void configSetting::on_radioButton_65_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        PrintCodeType=0;
        qDebug()<<"PrintCodeType"<<PrintCodeType;
    }
}

void configSetting::on_textEdit_2_textChanged()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintCompanyName",ui->textEdit_2->toPlainText());
    delete configIniRead;
    PrintCompanyName=(ui->textEdit_2->toPlainText());

}

void configSetting::on_textEdit_5_textChanged()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/CompanyWebsite",ui->textEdit_5->toPlainText());
    delete configIniRead;
    CompanyWebsite=(ui->textEdit_5->toPlainText());
}

void configSetting::ConfigSave(void)
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);

    configIniRead->setValue("baseinfo/PrintLq",PrintLq);
    configIniRead->setValue("baseinfo/b_Save",b_Save);
    configIniRead->setValue("baseinfo/PrintCodeType",PrintCodeType);
    configIniRead->setValue("baseinfo/b_PrintStable",b_PrintStable);
    configIniRead->setValue("baseinfo/b_PrintRetZero",b_PrintRetZero);
    configIniRead->setValue("baseinfo/PrintLableSize",PrintLableSize);
    configIniRead->setValue("baseinfo/b_PrintHeader",b_PrintHeader);

    configIniRead->setValue("baseinfo/CommType",CommType);
    configIniRead->setValue("baseinfo/CommType232",CommType232);
    configIniRead->setValue("baseinfo/Tmode232",Tmode_232);
    configIniRead->setValue("baseinfo/BaudRate232",BaudRate_232);
    configIniRead->setValue("baseinfo/DataBits232",DataBits_232);
    configIniRead->setValue("baseinfo/StopBits232",StopBits_232);
    configIniRead->setValue("baseinfo/Parity232",ParityMode_232);

    configIniRead->setValue("baseinfo/Addr",Addr);
    configIniRead->setValue("baseinfo/Tmode485",Tmode_485);
    configIniRead->setValue("baseinfo/BaudRate485",BaudRate_485);
    configIniRead->setValue("baseinfo/DataBits485",DataBits_485);
    configIniRead->setValue("baseinfo/StopBits485",StopBits_485);
    configIniRead->setValue("baseinfo/Parity485",ParityMode_485);

    configIniRead->setValue("baseinfo/PrintCompanyName",PrintCompanyName);
    configIniRead->setValue("baseinfo/CompanyAddr",CompanyAddr);
    configIniRead->setValue("baseinfo/CompanyTel",CompanyTel);
    configIniRead->setValue("baseinfo/CompanyWebsite",CompanyWebsite);
    configIniRead->setValue("baseinfo/CompanyLabel",CompanyLabel);
    
    
    delete configIniRead;


}

void configSetting::on_radioButton_68_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        PrintCodeType=2;
        qDebug()<<"PrintCodeType"<<PrintCodeType;
    }

}

void configSetting::on_textEdit_3_textChanged()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/CompanyAddr",ui->textEdit_3->toPlainText());
    delete configIniRead;
    CompanyAddr=(ui->textEdit_3->toPlainText());

}

void configSetting::on_textEdit_4_textChanged()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/CompanyTel",ui->textEdit_4->toPlainText());
    delete configIniRead;
    CompanyTel=(ui->textEdit_4->toPlainText());

}

void configSetting::on_textEdit_6_textChanged()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/CompanyLabel",ui->textEdit_6->toPlainText());
    delete configIniRead;
    CompanyLabel=(ui->textEdit_6->toPlainText());

}

void configSetting::on_pushButton_64_clicked()
{
    beep_start;
    ui->stackedWidget_6->setCurrentIndex(11);
    switch (b_PrintHeader)
    {
    case 0:
        ui->radioButton_75->setChecked(true);
        ui->radioButton_75->setFocus();
        break;
    case 1:
        ui->radioButton_76->setChecked(true);
        ui->radioButton_76->setFocus();
        break;

    }

}

void configSetting::on_radioButton_75_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        b_PrintHeader=0;
        qDebug()<<"b_PrintHeader"<<b_PrintHeader;
    }
}

void configSetting::on_radioButton_76_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        b_PrintHeader=1;
        qDebug()<<"b_PrintHeader"<<b_PrintHeader;
    }

}

void configSetting::on_pushButton_19_clicked()
{
    emit updateApplicationSignal();
}
void configSetting::httpDownstateSlot(int httpstate)
{
    ui->progressBar->setRange(0,DocLength);
}

void configSetting::on_radioButton_77_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        b_Save=2;
        qDebug()<<"b_Save"<<b_Save;
    }
}

void configSetting::on_comboBox_14_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/CommType232",ui->comboBox_14->currentIndex());
    delete configIniRead;
    CommType232=ui->comboBox_14->currentIndex();
}

void configSetting::on_pushButton_65_clicked()
{
    beep_start;
    int index;
    ui->stackedWidget_5->setCurrentIndex(8);
    ui->label_76->setText("Com3");
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    index=configIniRead->value("baseinfo/CommType").toInt();
    ui->comboBox_15->setCurrentIndex(index);

    delete configIniRead;
}

void configSetting::on_comboBox_15_currentIndexChanged(int index)
{
    beep_start;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/CommType",ui->comboBox_15->currentIndex());
    delete configIniRead;
    CommType=ui->comboBox_15->currentIndex();
    emit CommTypeChange();
}

void configSetting::on_pushButton_66_clicked()
{
    beep_start;
    ui->stackedWidget_5->setCurrentIndex(9);

    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    PatternOfPayment = configIniRead->value("baseinfo/PatternOfPayment").toInt();
    delete configIniRead;

    switch (PatternOfPayment)
    {
    case 1:
        ui->radioButton_78->setChecked(true);
        ui->radioButton_78->setFocus();
        break;
    case 2:
        ui->radioButton_79->setChecked(true);
        ui->radioButton_79->setFocus();
        break;
    }
}


void configSetting::on_radioButton_78_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        PatternOfPayment=1;
        qDebug()<<"PatternOfPayment"<<PatternOfPayment;
    }

    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PatternOfPayment",PatternOfPayment);
    delete configIniRead;
}


void configSetting::on_radioButton_79_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        PatternOfPayment=2;
        qDebug()<<"PatternOfPayment"<<PatternOfPayment;
    }

    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PatternOfPayment",PatternOfPayment);
    delete configIniRead;
}
