#include "business.h"
#include "ui_business.h"

#include "qrcode/qrencode.h"
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QRectF>
#include <QImage>
#include <QPixmap>
#include <QTime>
bool RequestPayment;
bool workRecordInsert;
bool PaySuccess;
int RecordSerial;
QString Device_Info;
unsigned char PayType;
QString RID;
QString Seq;
QString out_trade_no;
bool OrderBusiness;
Business::Business(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Business)
{
    ui->setupUi(this);
    ui->lcd1->setNumDigits(7);
    ui->lcd1->setFrameShape(QFrame::NoFrame);
   // ui->lcd1->hide();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(QRect(0,0,800,480));

    Device_Info = "201810080002";//本机ID
    RequestPayment = false;
    workRecordInsert = false;
    PaySuccess =false;
    OrderBusiness=true;
    PayType = 0;  //0=备用,1=微信,2=支付宝,3=预付费卡
    RecordSerial = 0;//待插入工作记录的流水号

    RID="1810180001";
    Seq="0006";

    keyJudjeFlag=false;
    productCashNum=0;
    currentWeight=10;
    total_money=0;
    temptotalcash = 0;
    btemp=1;
    longPushbuttonTimer = new QTimer;
    connect(longPushbuttonTimer,SIGNAL(timeout()),this,SLOT(keyJudje()));
    //longPushbuttonTimer->start(500);
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    ui->label_8->setText(QString::number(0));
    Timer = new QTimer;
    Timer->start(100);
    connect(Timer,SIGNAL(timeout()),this,SLOT(TimerSlot()));
}

void Business::structData_init(void)
{
    int i =0;
    int j=0;
    for(i=0;i<20;i++)
    {
        for (j=0;j<5;j++)
        {
            //productInfor[j].
        }
    }
}

Business::~Business()
{
    delete ui;
}

void Business::TimerSlot()
{
    //QString temp = QString::number(Net);
   if(btemp==1)
      tempdis=Net;
    else
     tempdis=Gross;
    QString temp1=QString::number(tempdis,'f',Point);
    QString temp;
    QString tempStr = "";
    if(Unit==1)
        tempStr = "kg";
    else if(Unit==2)
        tempStr = "lb";
    else
        tempStr = "g";
    ui->label_59->setText(tempStr);
   /* if (Unit == 1)
    {
       temp = temp1 + "  kg";
    }
    else if (Unit==2)
    {
       temp = temp1 + "  lb";
    }
    else if (Unit==3)
    {
        temp = temp1 + "  g";
    }
    else
    {
        temp = temp1 + "  kg";
    }*/
    //ui->label_5->setText(temp);
    ui->lcd1->display(temp1);

    currentWeight = Net;
    float currentshowcash = currentWeight*currentproductInfor.productPrice;
    ui->label_6->setText(QString::number(currentshowcash));

    temptotalcash=0;
    for (int i=0;i<productCashNum;i++)
    {
        temptotalcash = productInforCash[productCashNum-1].money+temptotalcash;
    }
    /* qDebug()<<"currentproductInfor";
    qDebug() <<"currentproductInfor.productCode"<<currentproductInfor.productCode;
    qDebug() <<"currentproductInfor.productName"<<currentproductInfor.productName;
    qDebug() <<"currentproductInfor.productPrice"<<currentproductInfor.productPrice;
    qDebug() <<"currentproductInfor.productOrigin"<<currentproductInfor.productOrigin;
    qDebug() <<"currentproductInfor.productDescribe"<<currentproductInfor.productDescribe;*/
    QString tempstrTotalCash = QString::number(temptotalcash);
    ui->label_9->setText(tempstrTotalCash);
    //  qDebug()<<"temp";
}

void Business::fromRootdialog()
{
    this->close();
}
void Business::on_pushButton_clicked()
{
    beep_start;
    emit sendtoRootdialog();
    this->close();
    productCashNum=0;
}

void Business::on_pushButton_2_clicked()
{

}

void Business::on_pushButton_2_pressed()
{
    beep_start;
    keyJudjeFlag=false;
    longPushbuttonTimer->start(400);
}

void Business::on_pushButton_2_released()
{
    longPushbuttonTimer->stop();
    if (keyJudjeFlag)
    {
        qDebug() << "长按";
        ui->stackedWidget->setCurrentIndex(3);
        qDebug() << " ui->stackedWidget->setCurrentIndex(3);";

        /*ui->lineEdit->setText(QString::number(productInfor[0].productCode));
        ui->lineEdit_2->setText(productInfor[0].productName);
        ui->lineEdit_3->setText(QString::number(productInfor[0].productPrice));
        ui->lineEdit_4->setText(productInfor[0].productOrigin);
        //ui->lineEdit_5->setMaxLength(20);
        ui->lineEdit_5->setText(productInfor[0].productDescribe);*/

        ui->lineEdit->setEnabled(false);
        ui->lineEdit_2->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->lineEdit_5->setEnabled(false);
    }
    else
    {
        qDebug() << "短按";
        ui->stackedWidget->setCurrentIndex(1);

        if (productNum==1)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->hide();
            ui->pushButton_9->hide();
            ui->pushButton_10->hide();
            ui->pushButton_11->hide();
            ui->pushButton_12->hide();
            ui->pushButton_13->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==2)
        {
            //ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_8->show();
            ui->pushButton_9->hide();
            ui->pushButton_10->hide();
            ui->pushButton_11->hide();
            ui->pushButton_12->hide();
            ui->pushButton_13->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==3)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->hide();
            ui->pushButton_11->hide();
            ui->pushButton_12->hide();
            ui->pushButton_13->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==4)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->hide();
            ui->pushButton_12->hide();
            ui->pushButton_13->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==5)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->hide();
            ui->pushButton_13->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==6)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==7)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==8)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->hide();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==9)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==10)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==11)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->hide();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==12)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->hide();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==13)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);
            ui->pushButton_19->setText(productInfor[12].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->pushButton_20->hide();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==14)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);
            ui->pushButton_19->setText(productInfor[12].productName);
            ui->pushButton_20->setText(productInfor[13].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->pushButton_20->show();
            ui->pushButton_21->hide();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==15)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);
            ui->pushButton_19->setText(productInfor[12].productName);
            ui->pushButton_20->setText(productInfor[13].productName);
            ui->pushButton_21->setText(productInfor[14].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->pushButton_20->show();
            ui->pushButton_21->show();
            ui->pushButton_22->hide();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==16)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);
            ui->pushButton_19->setText(productInfor[12].productName);
            ui->pushButton_20->setText(productInfor[13].productName);
            ui->pushButton_21->setText(productInfor[14].productName);
            ui->pushButton_22->setText(productInfor[15].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->pushButton_20->show();
            ui->pushButton_21->show();
            ui->pushButton_22->show();
            ui->pushButton_23->hide();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==17)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);
            ui->pushButton_19->setText(productInfor[12].productName);
            ui->pushButton_20->setText(productInfor[13].productName);
            ui->pushButton_21->setText(productInfor[14].productName);
            ui->pushButton_22->setText(productInfor[15].productName);
            ui->pushButton_23->setText(productInfor[16].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->pushButton_20->show();
            ui->pushButton_21->show();
            ui->pushButton_22->show();
            ui->pushButton_23->show();
            ui->pushButton_24->hide();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==18)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);
            ui->pushButton_19->setText(productInfor[12].productName);
            ui->pushButton_20->setText(productInfor[13].productName);
            ui->pushButton_21->setText(productInfor[14].productName);
            ui->pushButton_22->setText(productInfor[15].productName);
            ui->pushButton_23->setText(productInfor[16].productName);
            ui->pushButton_24->setText(productInfor[17].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->pushButton_20->show();
            ui->pushButton_21->show();
            ui->pushButton_22->show();
            ui->pushButton_23->show();
            ui->pushButton_24->show();
            ui->pushButton_25->hide();
            ui->pushButton_26->hide();
        }
        if (productNum==19)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);
            ui->pushButton_19->setText(productInfor[12].productName);
            ui->pushButton_20->setText(productInfor[13].productName);
            ui->pushButton_21->setText(productInfor[14].productName);
            ui->pushButton_22->setText(productInfor[15].productName);
            ui->pushButton_23->setText(productInfor[16].productName);
            ui->pushButton_24->setText(productInfor[17].productName);
            ui->pushButton_25->setText(productInfor[18].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->pushButton_20->show();
            ui->pushButton_21->show();
            ui->pushButton_22->show();
            ui->pushButton_23->show();
            ui->pushButton_24->show();
            ui->pushButton_25->show();
            ui->pushButton_26->hide();
        }
        if (productNum==20)
        {
            ui->pushButton_7->setText(productInfor[0].productName);
            ui->pushButton_8->setText(productInfor[1].productName);
            ui->pushButton_9->setText(productInfor[2].productName);
            ui->pushButton_10->setText(productInfor[3].productName);
            ui->pushButton_11->setText(productInfor[4].productName);
            ui->pushButton_12->setText(productInfor[5].productName);
            ui->pushButton_13->setText(productInfor[6].productName);
            ui->pushButton_14->setText(productInfor[7].productName);
            ui->pushButton_15->setText(productInfor[8].productName);
            ui->pushButton_16->setText(productInfor[9].productName);
            ui->pushButton_17->setText(productInfor[10].productName);
            ui->pushButton_18->setText(productInfor[11].productName);
            ui->pushButton_19->setText(productInfor[12].productName);
            ui->pushButton_20->setText(productInfor[13].productName);
            ui->pushButton_21->setText(productInfor[14].productName);
            ui->pushButton_22->setText(productInfor[15].productName);
            ui->pushButton_23->setText(productInfor[16].productName);
            ui->pushButton_24->setText(productInfor[17].productName);
            ui->pushButton_25->setText(productInfor[18].productName);
            ui->pushButton_26->setText(productInfor[19].productName);

            ui->pushButton_8->show();
            ui->pushButton_9->show();
            ui->pushButton_10->show();
            ui->pushButton_11->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
            ui->pushButton_16->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
            ui->pushButton_19->show();
            ui->pushButton_20->show();
            ui->pushButton_21->show();
            ui->pushButton_22->show();
            ui->pushButton_23->show();
            ui->pushButton_24->show();
            ui->pushButton_25->show();
            ui->pushButton_26->show();
        }
    }
}
void Business::pushbutton_show_and_hide()
{

}

void Business::keyJudje(void)
{
    //qDebug() << "ui->pushButton_2->autoRepeat()"<<ui->pushButton_2->autoRepeat();
    keyJudjeFlag=true;
}

void Business::on_pushButton_30_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(0);
    productCashNum=0;
    totalmoney_print=0;
    ui->label_27->setText("");
}

void Business::on_pushButton_32_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(0);
}

void Business::on_pushButton_34_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(1);
}

void Business::on_pushButton_35_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Business::on_pushButton_38_clicked()
{
    beep_start;
    qDebug()<<"productNum!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<productNum;

    QString tempstrJudge="";
    for (int i = 0; i<productNum;i++)
    {
        tempstrJudge += QString::number(productInfor[i].productCode);
    }
    qDebug() <<"tempstrJudge"<<tempstrJudge<<"tempstrJudge.indexOf(ui->lineEdit_9->text())"<<tempstrJudge.indexOf(ui->lineEdit_9->text());
    /*if (!((ui->lineEdit_9->text().toInt()>productNum)&&(ui->lineEdit_9->text().toInt()<productNum+2))||(ui->lineEdit_9->text().toInt()>30))
    {
        QMessageBox::critical(this, tr("错误"), tr("请重新输入"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }*/
    if ((productNum==0)&&(ui->lineEdit_9->text()!="")&&(ui->lineEdit_6->text()!="")&&(ui->lineEdit_7->text()!=""))
    {

    }
    else if ((-1!=tempstrJudge.indexOf(ui->lineEdit_9->text()))||(ui->lineEdit_9->text()=="")||(ui->lineEdit_6->text()=="")||(ui->lineEdit_7->text()==""))
    {
        QMessageBox::critical(this, tr("错误"), tr("请重新输入"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    else
    {
        //qDebug()<<"else!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        //QMessageBox::critical(this, tr("错误"), tr("请重新输入"), QMessageBox::Yes, QMessageBox::Yes);
        //return;
    }
    qDebug()<<"productNum!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<productNum;
    productInfor[productNum].productCode=ui->lineEdit_9->text().toInt();
    productInfor[productNum].productName=ui->lineEdit_7->text();
    productInfor[productNum].productPrice=ui->lineEdit_6->text().toFloat();
    productInfor[productNum].productOrigin=ui->lineEdit_8->text();
    productInfor[productNum].productDescribe=ui->lineEdit_10->text();

    qDebug() <<"productInfor[i].productCode"<<productInfor[productNum].productCode;
    qDebug() <<"productInfor[i].productName"<<productInfor[productNum].productName;
    qDebug() <<"productInfor[i].productPrice"<<productInfor[productNum].productPrice;
    qDebug() <<"productInfor[i].productOrigin"<<productInfor[productNum].productOrigin;
    qDebug() <<"productInfor[i].productDescribe"<<productInfor[productNum].productDescribe;
    productNum++;

    qDebug()<<"productNum)))))))))))))))))"<<productNum;
    QString temp = QString::number(productNum);
    QString tempstr = "product"+temp+"/code";
    QString tempstr1 = "product"+temp+"/name";
    QString tempstr2 = "product"+temp+"/price";
    QString tempstr3= "product"+temp+"/origin";
    QString tempstr4 = "product"+temp+"/describe";

    QSettings *configIniRead = new QSettings("/A31config.ini", QSettings::IniFormat);
    configIniRead->setValue(tempstr, ui->lineEdit_9->text());
    configIniRead->setValue(tempstr1, ui->lineEdit_7->text());
    configIniRead->setValue(tempstr2, ui->lineEdit_6->text());
    configIniRead->setValue(tempstr3, ui->lineEdit_8->text());
    configIniRead->setValue(tempstr4, ui->lineEdit_10->text());
    //configIniRead->setValue();
    delete configIniRead;
    QMessageBox::information(this, tr("保存"), tr("已保存"), QMessageBox::Yes, QMessageBox::Yes);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Business::on_pushButton_7_clicked()
{
    beep_start;
    currentproductInfor = productInfor[0];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    QString tempstrcash = QString::number(currentproductInfor.productPrice*Net);
    ui->label_6->setText(tempstrcash);
}

void Business::on_pushButton_8_clicked()
{
    beep_start;
    currentproductInfor = productInfor[1];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_9_clicked()
{
    beep_start;
    currentproductInfor = productInfor[2];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_10_clicked()
{
    beep_start;
    currentproductInfor = productInfor[3];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_11_clicked()
{
    beep_start;
    currentproductInfor = productInfor[4];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_16_clicked()
{
    beep_start;
    currentproductInfor = productInfor[9];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_12_clicked()
{
    beep_start;
    currentproductInfor = productInfor[5];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_13_clicked()
{
    beep_start;
    currentproductInfor = productInfor[6];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_14_clicked()
{
    beep_start;
    currentproductInfor = productInfor[7];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_15_clicked()
{
    beep_start;
    currentproductInfor = productInfor[8];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_21_clicked()
{
    beep_start;
    currentproductInfor = productInfor[14];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_17_clicked()
{
    beep_start;
    currentproductInfor = productInfor[10];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_18_clicked()
{
    beep_start;
    currentproductInfor = productInfor[11];
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_19_clicked()
{
    beep_start;
    currentproductInfor = productInfor[12];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_20_clicked()
{
    beep_start;
    currentproductInfor = productInfor[13];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_26_clicked()
{
    beep_start;
    currentproductInfor = productInfor[19];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_22_clicked()
{
    beep_start;
    currentproductInfor = productInfor[15];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_23_clicked()
{
    beep_start;
    currentproductInfor = productInfor[16];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_24_clicked()
{
    beep_start;
    currentproductInfor = productInfor[17];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_25_clicked()
{
    beep_start;
    currentproductInfor = productInfor[18];
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_4->setText(currentproductInfor.productName);
    ui->label_2->setText( QString::number(currentproductInfor.productPrice));
    //ui->label_8->setText(QString::number(productNum));
}

void Business::on_pushButton_3_clicked()
{

    beep_start;
    productCashNum++;
    productInforCash[productCashNum-1].productCash=currentproductInfor;
    productInforCash[productCashNum-1].weight=currentWeight;
    productInforCash[productCashNum-1].money=productInforCash[productCashNum-1].productCash.productPrice*productInforCash[productCashNum-1].weight;

    qDebug()<<"productInforCash[productCashNum].productCash.productCode"<<productInforCash[productCashNum-1].productCash.productCode;
    qDebug()<<"productInforCash[productCashNum].productCash.productName;"<<productInforCash[productCashNum-1].productCash.productName;
    qDebug()<<"productInforCash[productCashNum].productCash.productOrigin"<<productInforCash[productCashNum-1].productCash.productOrigin;
    qDebug()<<"productInforCash[productCashNum].productCash.productPrice"<<productInforCash[productCashNum-1].productCash.productPrice;
    qDebug()<<"productInforCash[productCashNum].productCash.productDescribe"<<productInforCash[productCashNum-1].productCash.productDescribe;
    qDebug()<<"productInforCash[productCashNum].weight"<<productInforCash[productCashNum-1].weight;
    qDebug()<<"productInforCash[productCashNum].money"<<productInforCash[productCashNum-1].money;
    ui->label_8->setText(QString::number(productCashNum));
    //float temp
    // temptotalcash = productInforCash[productCashNum-1].money+temptotalcash;
    //QString tempstrTotalCash = QString::number(temptotalcash);
    //ui->label_9->setText(tempstrTotalCash);
}

void Business::on_pushButton_4_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(6);

    QStandardItemModel  *model= new QStandardItemModel();
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("产品代码"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("产品名称"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("产品单价"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("产品重量"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("产品金额"));
    //model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("姓名"));
    //ui->tableView->setModel();
    ui->tableView->setModel(model);
    //表头信息显示居左
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    //设置列宽不可变
    ui->tableView->horizontalHeader()->setResizeMode(0,QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0,160);
    ui->tableView->setColumnWidth(1,160);
    ui->tableView->setColumnWidth(3,160);
    ui->tableView->setColumnWidth(4,160);
    ui->tableView->setColumnWidth(5,160);
    qDebug()<<"on_pushButton_4_clicked";
    for(int i = 0; i < productCashNum; i++)
    {
        qDebug()<<"i"<<i<<"productCashNum"<<productCashNum;
        model->setItem(i,0,new QStandardItem(QString::number(productInforCash[i].productCash.productCode)));
        //设置字符颜色
        model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        //设置字符位置
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);

        model->setItem(i,1,new QStandardItem(productInforCash[i].productCash.productName));
        model->setItem(i,2,new QStandardItem(QString::number(productInforCash[i].productCash.productPrice)));
        model->setItem(i,3,new QStandardItem(QString::number(productInforCash[i].weight)));
        model->setItem(i,4,new QStandardItem(QString::number(productInforCash[i].money)));
        total_money = total_money + productInforCash[i].money;
        Rec[i].RecCode=productInforCash[i].productCash.productCode;
        Rec[i].RecproductName=productInforCash[i].productCash.productName;
        Rec[i].RecproductPrice=productInforCash[i].productCash.productPrice;
        Rec[i].Recweight=productInforCash[i].weight;
        Rec[i].Recmoney=productInforCash[i].money;
    }
	TotfnBusiness++;
    Rectotal_money=total_money;
    RecproductNum=productCashNum;
    InsertRecordTimes=productCashNum;
    //productCashNum=0;
    ui->label_28->setText(QString::number(total_money));
    totalmoney_print=total_money;
    total_money=0;
    temptotalcash=0;
    QTime current_time = QTime::currentTime();
    QDate current_date= QDate::currentDate();
    QDateTime time = QDateTime::currentDateTime();
    
    RecTime.Year   = (current_date.year())%100;
    RecTime.Month  = current_date.month();
    RecTime.Day= current_date.day();

    RecTime.Hour= current_time.hour();
    RecTime.Minute= current_time.minute();
    RecTime.Second= current_time.second();
    //emit QrChange();

}

void Business::on_pushButton_36_clicked()
{
    beep_start;
    if(!b_Print) emit printrecord();
    /*ui->stackedWidget->setCurrentIndex(0);
    ui->label_8->setText(QString::number(0));*/
}

void Business::on_pushButton_37_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(0);
    ui->label_8->setText(QString::number(0));
    productCashNum=0;
    qDebug()<<"productCashNum"<<productCashNum;
}

void Business::on_pushButton_39_clicked()
{
    beep_start;
    if (productCashNum==0)
    {
        QMessageBox::information(this, tr("警告"), tr("请选择商品!!!"));
    }
    else
    {
        RequestPayment = true;
        OrderBusiness = true;
        //    ui->stackedWidget->setCurrentIndex(4);
        ui->label_61->setText("等待扫码枪扫描......");
        ui->stackedWidget->setCurrentIndex(7);
        if (PatternOfPayment==1)
        {
            ui->pushButton_50->setStyleSheet("background-color:green;color:red");
            ui->pushButton_51->setStyleSheet("background-color:white;color:red");
            ui->stackedWidget_3->setCurrentIndex(0);
        }
        if (PatternOfPayment==2)
        {
            ui->pushButton_51->setStyleSheet("background-color:green;color:red");
            ui->pushButton_50->setStyleSheet("background-color:white;color:red");
            ui->stackedWidget_3->setCurrentIndex(1);
        }
    }
}

void Business::on_pushButton_27_clicked()
{
    beep_start;
    PayType = 1;
    qDebug() << "jinru weixinzhifu" << endl;
    ui->stackedWidget->setCurrentIndex(5);
    //sleep(10);
    //QTimer QrstrTimer;

    if (Qrstr!="")
    {
        GenerateQRcode(Qrstr);
    }
    qDebug() << "weixinzhifu" << endl;
}
void Business::PaySuccessSlot()
{
    ui->label_27->setText("支付成功");
    ui->label_61->setText("支付成功");
    Qrstr = "";
    //sleep(2);
    //ui->stackedWidget->setCurrentIndex(0);
}
void Business::Qr_CodeSlot()
{
    if (Qrstr!="")
    {
        GenerateQRcode(Qrstr);
    }
    qDebug() << "weixinzhifu  Qrstr" << Qrstr;
}

void Business::GenerateQRcode(QString tempstr)
{

    QRcode *qrcode;
    qrcode=QRcode_encodeString(tempstr.toStdString().c_str(),2,QR_ECLEVEL_Q,QR_MODE_8,1);
    qint32 temp_width=ui->label_27->width();
    qint32 temp_height=ui->label_27->height();
    qDebug()<<"temp_width="<<temp_width<<";temp_height="<<temp_height;

    qint32 qrcode_width=qrcode->width>0?qrcode->width:1;
    double scale_x=(double)temp_width/(double)qrcode_width;
    double scale_y=(double)temp_height/(double)qrcode_width;

    QImage mainimg=QImage(temp_width,temp_height,QImage::Format_ARGB32);
    QPainter painter(&mainimg);
    QColor background(Qt::white);
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0,0,temp_width,temp_height);
    QColor foreground(Qt::black);
    painter.setBrush(foreground);

    for(qint32 y=0;y<qrcode_width;y++)
    {
        for(qint32 x=0;x<qrcode_width;x++)
        {
            unsigned char b=qrcode->data[y*qrcode_width+x];
            //qDebug()<<"b======================"<<b;
            if(b &0x01)
            {
                QRectF r(x*scale_x,y*scale_y,scale_x,scale_y);
                painter.drawRects(&r,1);
            }
        }
    }

    QPixmap mainmap=QPixmap::fromImage(mainimg);
    ui->label_27->setPixmap(mainmap);
    ui->label_27->setVisible(true);
}

void Business::on_pushButton_31_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(3);

    ui->comboBox_2->clear();
    QStringList CompletedList;
    CompletedList.clear();
    int i = 0;
    for (i=0;i<productNum;i++)
    {
        //CompletedList<<QString::number(i+1);
        CompletedList<<QString::number(productInfor[i].productCode);
        qDebug()<<"CompletedList"<<CompletedList;
    }
    ui->comboBox_2->addItems(CompletedList);
}

void Business::on_toolButton_13_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(0);
}

void Business::on_pushButton_40_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(2);
}

void Business::on_toolButton_12_clicked()
{
    beep_start;
    QString tempProductID = ui->lineEdit_11->text();
    QString tempProductName = ui->lineEdit_12->text();
    QString tempProductPrice = ui->lineEdit_13->text();
    QString tempProductWeight = ui->lineEdit_14->text();
    QString tempProductDsc = ui->lineEdit_15->text();
    QString tempUserID = ui->lineEdit_16->text();

    emit sendToRemoteMysql(tempProductID,tempProductName,tempProductPrice,tempProductWeight,tempProductDsc,tempUserID);
    qDebug()<<"insert remotemysql!!!!!!!!!!";
}

void Business::on_pushButton_33_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(2);
    ui->comboBox->clear();
    QStringList CompletedList;
    CompletedList.clear();
    int i = 0;
    for (i=0;i<productNum;i++)
    {
        //CompletedList<<QString::number(i+1);
        CompletedList<<QString::number(productInfor[i].productCode);
        qDebug()<<"CompletedList"<<CompletedList;
    }
    ui->comboBox->addItems(CompletedList);
}

void Business::on_pushButton_41_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Business::on_comboBox_currentIndexChanged(int index)
{
    if (index >= 0 )
    {
        ui->lineEdit_17->setText(QString::number(productInfor[index].productCode));
        ui->lineEdit_20->setText(productInfor[index].productName);
        ui->lineEdit_19->setText(QString::number(productInfor[index].productPrice));
        ui->lineEdit_18->setText(productInfor[index].productOrigin);
        ui->lineEdit_21->setText(productInfor[index].productDescribe);
        tempProductNumIndex = index;
    }
}

void Business::on_pushButton_42_clicked()
{
    beep_start;
    if (ui->lineEdit_17->text().toInt()!=productInfor[tempProductNumIndex].productCode)
    {
        QMessageBox::critical(this, tr("错误"), tr("请重新输入"), QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    productInfor[tempProductNumIndex].productCode=ui->lineEdit_17->text().toInt();
    productInfor[tempProductNumIndex].productName=ui->lineEdit_20->text();
    productInfor[tempProductNumIndex].productPrice=ui->lineEdit_19->text().toFloat();
    productInfor[tempProductNumIndex].productOrigin=ui->lineEdit_18->text();
    productInfor[tempProductNumIndex].productDescribe=ui->lineEdit_21->text();

    QString temp = QString::number(tempProductNumIndex+1);
    QString tempstr = "product"+temp+"/code";
    QString tempstr1 = "product"+temp+"/name";
    QString tempstr2 = "product"+temp+"/price";
    QString tempstr3= "product"+temp+"/origin";
    QString tempstr4 = "product"+temp+"/describe";

    QSettings *configIniRead = new QSettings("/A31config.ini", QSettings::IniFormat);
    configIniRead->setValue(tempstr, ui->lineEdit_17->text());
    configIniRead->setValue(tempstr1, ui->lineEdit_20->text());
    configIniRead->setValue(tempstr2, ui->lineEdit_19->text());
    configIniRead->setValue(tempstr3, ui->lineEdit_18->text());
    configIniRead->setValue(tempstr4, ui->lineEdit_21->text());
    delete configIniRead;
    QMessageBox::information(this, tr("保存"), tr("已保存"), QMessageBox::Yes, QMessageBox::Yes);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Business::on_pushButton_43_clicked()
{
    beep_start;
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Business::on_comboBox_2_currentIndexChanged(int index)
{
    if (index >= 0 )
    {
        ui->lineEdit_23->setText(QString::number(productInfor[index].productCode));
        ui->lineEdit_24->setText(productInfor[index].productName);
        ui->lineEdit_22->setText(QString::number(productInfor[index].productPrice));
        ui->lineEdit_26->setText(productInfor[index].productOrigin);
        ui->lineEdit_25->setText(productInfor[index].productDescribe);
        tempProductNumIndex = index;
    }
}

void Business::on_pushButton_44_clicked()
{
    beep_start;
    QMessageBox::StandardButton rb=QMessageBox::information(this, tr("删除"), tr("删除"), QMessageBox::Cancel, QMessageBox::Yes);
    if(rb == QMessageBox::Cancel)
    {
        qDebug()<<"QMessageBox::Cancel";
    }
    else if (rb == QMessageBox::Yes)
    {
        qDebug()<<"QMessageBox::Yes";
        delete_array();
    }
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Business::delete_array()
{
    qDebug()<<"productNum"<<productNum;

    for (int i = tempProductNumIndex;i<productNum;i++)
    {
        productInfor[i].productCode=productInfor[i+1].productCode;
        productInfor[i].productDescribe=productInfor[i+1].productDescribe;
        productInfor[i].productName=productInfor[i+1].productName;
        productInfor[i].productOrigin=productInfor[i+1].productOrigin;
        productInfor[i].productPrice=productInfor[i+1].productPrice;
        qDebug()<<"tempProductNumIndex!!!!!!!!!!!!!"<<tempProductNumIndex<<"i"<<i;
        qDebug() <<"productInfor[tempProductNumIndex].productCode"<<productInfor[i].productCode;
        qDebug() <<"productInfor[tempProductNumIndex].productName"<<productInfor[i].productName;
        qDebug() <<"productInfor[tempProductNumIndex].productPrice"<<productInfor[i].productPrice;
        qDebug() <<"productInfor[tempProductNumIndex].productOrigin"<<productInfor[i].productOrigin;
        qDebug() <<"productInfor[tempProductNumIndex].productDescribe"<<productInfor[i].productDescribe;
    }
    productNum--;

    QSettings *configIniRead = new QSettings("/A31config.ini", QSettings::IniFormat);
    configIniRead->clear();
    for (int i = 0; i<productNum;i++)
    {
        QString temp = QString::number(i+1);
        QString tempstr = "product"+temp+"/code";
        QString tempstr1 = "product"+temp+"/name";
        QString tempstr2 = "product"+temp+"/price";
        QString tempstr3= "product"+temp+"/origin";
        QString tempstr4 = "product"+temp+"/describe";
        configIniRead->setValue(tempstr, productInfor[i].productCode);
        configIniRead->setValue(tempstr1, productInfor[i].productName);
        configIniRead->setValue(tempstr2, productInfor[i].productPrice);
        configIniRead->setValue(tempstr3, productInfor[i].productOrigin);
        configIniRead->setValue(tempstr4, productInfor[i].productDescribe);
    }
    delete configIniRead;
}


void Business::on_pushButton_6_clicked()
{
    btemp=1;
}

void Business::on_pushButton_5_clicked()
{
    btemp=0;
}

void Business::on_pushButton_28_clicked()
{
    beep_start;
    PayType = 2;
    qDebug() << "jinru Alipei zhifu" << endl;
    ui->stackedWidget->setCurrentIndex(5);
    //sleep(10);
    //QTimer QrstrTimer;

    if (Qrstr!="")
    {
        GenerateQRcode(Qrstr);
    }
    qDebug() << "zhifubao zhifu" << endl;
}

void Business::on_pushButton_50_clicked()
{
    ui->pushButton_50->setStyleSheet("background-color:green;color:red");
    //ui->pushButton_50->setStyleSheet("color:black");
    ui->pushButton_51->setStyleSheet("background-color:white;;color:red");
    //ui->pushButton_51->setStyleSheet("color:black");
    ui->stackedWidget_3->setCurrentIndex(0);
}

void Business::on_pushButton_51_clicked()
{
    ui->pushButton_51->setStyleSheet("background-color:green;color:red");
    ui->pushButton_50->setStyleSheet("background-color:white;color:red");
    //ui->pushButton_50->setStyleSheet("color:black");
    //ui->pushButton_51->setStyleSheet("color:black");
    ui->stackedWidget_3->setCurrentIndex(1);
}
void Business::RecCodeData()
{
    //ui->label_61->clear();等待扫码枪扫描......
    ui->label_61->setText("等待扫码枪扫描......");
    qDebug()<<"QRcodeTempAAAAAAAAAAAAAAAAAAAAAAAa"<<QRcodeTemp;
    //ui->label_61->setWordWrap(true);
    ui->label_61->setText(QRcodeTemp);
    //sleep(2);
    if (QRcodeType==1)
    {
        ui->label_61->setText("微信扫码成功 支付中...");
    }
    else if (QRcodeType==2)
    {
        ui->label_61->setText("支付宝扫码成功 支付中...");
    }
    else
    {
        ui->label_61->setText("无效码!!!");
    }
}

void Business::on_pushButton_52_clicked()
{
    beep_start;
    PayType = 1;
    qDebug() << "jinru weixinzhifu" << endl;
    ui->stackedWidget->setCurrentIndex(5);

    if (Qrstr!="")
    {
        GenerateQRcode(Qrstr);
    }
    qDebug() << "weixinzhifu" << endl;
}

void Business::on_pushButton_54_clicked()
{
    beep_start;
    PayType = 2;
    qDebug() << "jinru Alipei zhifu" << endl;
    ui->stackedWidget->setCurrentIndex(5);

    if (Qrstr!="")
    {
        GenerateQRcode(Qrstr);
    }
    qDebug() << "zhifubao zhifu" << endl;
}

void Business::on_pushButton_55_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
