#include "mainwindow.h"
#include "userlogindialog.h"
#include <QApplication>
#include "rootdialog.h"
#include "./TestInput_Cursor/inputmethod.h"
#include "GlobalVarible.h"
#include <QTextCodec>
#include "networkcommunication.h"
//#include "login.h"
#include "cali.h"
#include "remotemysql.h"
#include "adthread.h"
#include "loadbig.h"
#include <QWSServer>
QString TokenData;
QString interface;
PRODUCT_INFO productInfor[20];
PRODUCT_INFO currentproductInfor;
PRODUCT_INFOCash productInforCash[20];
float currentWeight;
int productNum;
int tempProductNumIndex;
int productCashNum;
float total_money;
float totalmoney_print;
Time RecTime;
Time RecTimeLimit;//kevin
Report RecDaily;
Report RecMonth;
Report RecAll;
Report RecProduct;
Report RecUser;
int RecproductNum;
float Rectotal_money;
Record Rec[20];
SqlRecord Sql;
uint TotfnBusiness;
//int Unit;
int fd_gpio;
int operatorID;
QString ServerIp;
int ServerPort;
QByteArray SendtoTCPUDP;
QString UDPServerIp;
int UDPServerPort;
QString LocalIp;
QString A31Version;
QString A31SN;
unsigned char Year;
unsigned char Month;
unsigned char Day;
unsigned char Hour;
unsigned char Minute;
unsigned char Second;
unsigned char Decp;
uchar CommType;
uchar CommType232;
uchar Tmode_232;
uchar Tmode_485;
uchar BaudRate_232,BaudRate_485;
uchar DataBits_232,DataBits_485;
uchar  ParityMode_232,ParityMode_485;
uchar StopBits_232,StopBits_485;
unsigned char InsertRecordTimes;
uchar httpDownstate;
int StartPosition;
int DocLength;
QString QRcodeTemp;
bool QRcodeFlag;
int PatternOfPayment;
QString Auth_Code;
int QRcodeType;
//#define arm
int main(int argc, char *argv[])
{

    QApplication::addLibraryPath("/opt/forlinx_qt4.8/plugins/");
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));//chinese
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));//chinese
    QApplication a(argc, argv);
    //QWSServer::setCursorVisible(false);
    A31SN="67282800";
    A31Version="V1.002";
    QRcodeTemp = "";
    PatternOfPayment =1;//1扫码支付,2显示付款码
    QRcodeType = 0;

    b_Print=0;
    b_Print1=0;
    b_Ylj=0;
    b_Ydy=0;
    b_Ydy1=0;
    CodeLength=0;
    QSettings *configIniRead = new QSettings("/A31config.ini", QSettings::IniFormat);
    int i=0;
    bool productNumFlag;
    productNumFlag=false;
    #ifdef arm
    /*fd_gpio  = open("/dev/sama5d2-gpio", O_RDWR| O_NONBLOCK );
    if (fd_gpio  < 0)
    {

        perror("open err");
        exit(1);
    }
    //PIN_PB25_H;
    PIN_PD6_H;
    PIN_PA30_H;*/
    #endif
    for (i=0;i<20;i++)
    {
        QString temp = QString::number(i+1);
        QString tempstr = "product"+temp+"/code";
        QString tempstr1 = "product"+temp+"/name";
        QString tempstr2 = "product"+temp+"/price";
        QString tempstr3= "product"+temp+"/origin";
        QString tempstr4 = "product"+temp+"/describe";
        qDebug() << tempstr;
        if (configIniRead->value(tempstr).toInt()==0)
        {
            //qDebug() << "configIniRead->value(\"product2/code\").toString()"<<configIniRead->value("product2/code").toString();
            productNum=i;
            qDebug() << "i==========="<<i;
            qDebug() << "productNum==========="<<productNum;
            //break;
            productNumFlag=true;
        }
        if (!productNumFlag)
        {
            productInfor[i].productCode=configIniRead->value(tempstr).toInt();
            productInfor[i].productName=configIniRead->value(tempstr1).toString();
            productInfor[i].productPrice=configIniRead->value(tempstr2).toFloat();
            productInfor[i].productOrigin=configIniRead->value(tempstr3).toString();
            productInfor[i].productDescribe=configIniRead->value(tempstr4).toString();

            qDebug() <<"productInfor[i].productCode"<<productInfor[i].productCode;
            qDebug() <<"productInfor[i].productName"<<productInfor[i].productName;
            qDebug() <<"productInfor[i].productPrice"<<productInfor[i].productPrice;
            qDebug() <<"productInfor[i].productOrigin"<<productInfor[i].productOrigin;
            qDebug() <<"productInfor[i].productDescribe"<<productInfor[i].productDescribe;
        }
        if (productNumFlag)
        {
            break;
        }
    }
    currentproductInfor = productInfor[0];
    qDebug() <<"currentproductInfor.productCode"<<currentproductInfor.productCode;
    qDebug() <<"currentproductInfor.productName"<<currentproductInfor.productName;
    qDebug() <<"currentproductInfor.productPrice"<<currentproductInfor.productPrice;
    qDebug() <<"currentproductInfor.productOrigin"<<currentproductInfor.productOrigin;
    qDebug() <<"currentproductInfor.productDescribe"<<currentproductInfor.productDescribe;
    delete configIniRead;
    UserLoginDialog login;
    login.show();
    QInputContext *im = new InputMethod();
    a.setInputContext( im );

    rootdialog m;
    if(login.exec()==QDialog::Accepted)
    {
        //rootdialog m;
        loginflag=1;
        m.show();
        return a.exec();
    }
}
