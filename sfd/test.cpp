#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAuthenticator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nam = new QNetworkAccessManager(this);
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

    CalibrateZero = 111;
    CalibrateRate = 111.112;
    Range = 111.113;
    NonlineaCorrection=111.114;
    ADCode=123456;
    LastCalibrationTime="2018-10-18 10:41:00";
    CalibrationTimes=8;
    Division=1;
    Point=2;
    InitialZero=3;
    ManualZero=1;
    ZeroTrackingSpeed=2;
    ZeroTrackingRange=3;
    FilteringAlgorithm=4;
    BoundaryStrength=5;
    stabilize=1;
    StabilizeFlag=true;
    NetFlag=true;
    ZeroFlag=true;
    ADSpeed=true;
    Alarm=true;
    AutoSetZero=true;
    Unit=true;
    PrintRound=true;
    ExtMeterage1=true;
    ExtMeterage2=true;
    ExtMeterage3=2;
    ExtMeterage4=3;
    ExtMeterage5=221;
    ExtMeterage6=222;
    ExtMeterage7=223;
    ExtMeterage8=224;
    TareWeight=1.001;
    ExtMeterage10=1.10102;
    ExtMeterage11="ExtMeterage11";
    ExtMeterage12="ExtMeterage12";
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::replyFinished(QNetworkReply* reply)
{

#if 1
    // Reading attributes of the reply
    // e.g. the HTTP status code
    QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    // Or the target URL if it was a redirect:
    //QVariant redirectionTargetUrl = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    //bool isSuccess = false;
    if (reply->error() == QNetworkReply::NoError)
    {
        QVariantMap result;
        QByteArray bytes = reply->readAll();

        QJson::Parser parser;
        bool ok;

        result = parser.parse(bytes, &ok).toMap();
        if (!ok) {
            qDebug()<<"HTTP_Req An error occurred during parsing"<<bytes;
        }
        else {
            //isSuccess = true;
        }

        QString string = QString::fromUtf8(bytes);
        qDebug()<<"statusCodeV"<<statusCodeV;

        qDebug()<<"string11111111"<<string;

        bool ResultCode = result["Success"].toBool();
        if(ResultCode == true)
        {
            if (interface == "Token")
            {
                //isSuccess = true;
                qDebug()<< "Token0000000000000000000";
                TokenData="bearer "+result["Data"].toString();
                //qDebug()<< "TokenData=============="<<TokenData;
            }
            if (interface == "TerminalPlus")
            {
                //isSuccess = true;
                qDebug()<< "TerminalPlus11111111111111";
                //qDebug()<< "TokenData****************"<<TokenData;
            }
            if (interface == "SYNCMeterage")
            {
                qDebug()<< "SYNCMeterage222222222222222";
                //int ResultCode = result["Data"].["ResultCode"];//
            }
            if (interface == "InsertRecord")
            {
                qDebug()<< "InsertRecord999999999999999";
            }
            if (interface == "EditMeterage")
            {
                qDebug()<< "EditMeterage333333333333333";
            }
            if (interface == "SYNCLocal")
            {
                qDebug()<< "SYNCLocal444444444444444444";
            }
            if (interface == "EditLocal")
            {
                qDebug()<< "EditLocal555555555555555555";
            }
            if (interface == "SYNCRun")
            {
                qDebug()<< "SYNCRun66666666666666666666";
            }
            if (interface == "EditRun")
            {
                qDebug()<< "EditRun777777777777777777777";
            }
            if (interface == "UnifiedOrder")
            {
                qDebug()<< "UnifiedOrder888888888888888888";
            }
            if (interface == "closeorder")
            {
                qDebug()<< "closeorderAAAAAAAAAAAAAAAAAAAAA";
            }
        }
        else
        {
            qDebug()<< "send req httpRegister failed"<<ResultCode;
        }

    } // Some http error received
    else
    {
        qDebug()<<"GetCurrentTime handle errors here";
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        qDebug( "GetCurrentTime found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
        qDebug()<<reply->errorString();
    }
    reply->deleteLater();
#endif
}


void MainWindow::on_pushButton_clicked()
{
    interface = "Token";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Account/Token"));

    QString userName = "A310010";
    QString Password = "";
    QVariantMap dataMap;
    dataMap.insert("UserName",userName);
    dataMap.insert("Password",Password);
//    dataMap.insert("UserName","A310010");
//    dataMap.insert("Password","");
    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json Token"<<json;

    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());

    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();

}

void MainWindow::on_pushButton_2_clicked()
{

    interface = "TerminalPlus";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/TerminalPlus"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info","201810080006");
    dataMap.insert("NetWeight",101);
    dataMap.insert("StateCode",201);
    dataMap.insert("PayType",31);
    dataMap.insert("RecordSerial",41);

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json TerminalPlus"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_3_clicked()
{
    interface = "SYNCMeterage";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/SYNCMeterage"));

    QVariantMap dataMap;
    dataMap.insert("RID","10001");
    dataMap.insert("Device_Info","201810080006");
    dataMap.insert("Seq","20001");

    dataMap.insert("CalibrateZero",1);
    dataMap.insert("CalibrateRate",1);
    dataMap.insert("Range",1);
    dataMap.insert("NonlineaCorrection",1);
    dataMap.insert("ADCode",1);
    dataMap.insert("LastCalibrationTime","2018-10-18 16:04:30");
    dataMap.insert("CalibrationTimes",2);
    dataMap.insert("Division",2);
    dataMap.insert("Point",3);
    dataMap.insert("InitialZero",1);
    dataMap.insert("ManualZero",2);
    dataMap.insert("ZeroTrackingSpeed",3);
    dataMap.insert("ZeroTrackingRange",1);
    dataMap.insert("FilteringAlgorithm",2);
    dataMap.insert("BoundaryStrength",3);
    dataMap.insert("stabilize",1);
    dataMap.insert("StabilizeFlag",true);
    dataMap.insert("NetFlag",true);
    dataMap.insert("ZeroFlag",true);
    dataMap.insert("ADSpeed",1);
    dataMap.insert("Alarm",2);
    dataMap.insert("AutoSetZero",3);
    dataMap.insert("Unit",3);
    dataMap.insert("PrintRound",4);
    dataMap.insert("ExtMeterage1",true);
    dataMap.insert("ExtMeterage2",true);
    dataMap.insert("ExtMeterage3",1);
    dataMap.insert("ExtMeterage4",3);
    dataMap.insert("ExtMeterage5",3);
    dataMap.insert("ExtMeterage6",4);
    dataMap.insert("ExtMeterage7",5);
    dataMap.insert("ExtMeterage8",6);
    dataMap.insert("TareWeight",31);
    dataMap.insert("ExtMeterage10",1);
    dataMap.insert("ExtMeterage11","terwr");
    dataMap.insert("ExtMeterage12","stritwretrwng");
    dataMap.insert("Remark","Remark213");
    /*dataMap.insert("CalibrateZero",CalibrateZero);
    dataMap.insert("CalibrateRate",CalibrateRate);
    dataMap.insert("Range",Range);
    dataMap.insert("NonlineaCorrection",NonlineaCorrection);
    dataMap.insert("ADCode",ADCode);
    dataMap.insert("LastCalibrationTime",LastCalibrationTime);
    dataMap.insert("CalibrationTimes",CalibrationTimes);
    dataMap.insert("Division",Division);
    dataMap.insert("Point",Point);
    dataMap.insert("InitialZero",InitialZero);
    dataMap.insert("ManualZero",ManualZero);
    dataMap.insert("ZeroTrackingSpeed",ZeroTrackingSpeed);
    dataMap.insert("ZeroTrackingRange",ZeroTrackingRange);
    dataMap.insert("FilteringAlgorithm",FilteringAlgorithm);
    dataMap.insert("BoundaryStrength",BoundaryStrength);
    dataMap.insert("stabilize",stabilize);
    dataMap.insert("StabilizeFlag",StabilizeFlag);
    dataMap.insert("NetFlag",NetFlag);
    dataMap.insert("ZeroFlag",ZeroFlag);
    dataMap.insert("ADSpeed",ADSpeed);
    dataMap.insert("Alarm",Alarm);
    dataMap.insert("AutoSetZero",AutoSetZero);
    dataMap.insert("Unit",0);
    dataMap.insert("PrintRound",0);
    dataMap.insert("ExtMeterage1",ExtMeterage1);
    dataMap.insert("ExtMeterage2",ExtMeterage2);
    dataMap.insert("ExtMeterage3",ExtMeterage3);
    dataMap.insert("ExtMeterage4",ExtMeterage4);
    dataMap.insert("ExtMeterage5",ExtMeterage5);
    dataMap.insert("ExtMeterage6",ExtMeterage6);
    dataMap.insert("ExtMeterage7",ExtMeterage7);
    dataMap.insert("ExtMeterage8",ExtMeterage8);
    dataMap.insert("TareWeight",TareWeight);
    dataMap.insert("ExtMeterage10",ExtMeterage10);
    dataMap.insert("ExtMeterage11",ExtMeterage11);
    dataMap.insert("ExtMeterage12",ExtMeterage12);
    dataMap.insert("Remark","Remark");*/
    QVariantList ChangeList;
    ChangeList.append("ChangeListgsfd");
    dataMap.insert("ChangeList",ChangeList);
    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json SYNCMeterage"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_9_clicked()
{
    interface = "InsertRecord";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Record/InsertRecord"));

    QVariantMap dataMap;
    dataMap.insert("RID","10001");
    dataMap.insert("Device_Info","201810080005");
    dataMap.insert("Seq","20001");

    dataMap.insert("TerminalName","A310010");
    dataMap.insert("RecordType",0);
    dataMap.insert("classesID",1);
    dataMap.insert("RecordSerial",1);
    dataMap.insert("timeStart","2018-10-19 08:50:00");
    dataMap.insert("timeEnd","2018-10-19 08:51:00");
    dataMap.insert("NetWeight",31);
    dataMap.insert("TareWeight",31);
    dataMap.insert("unit",0);
    dataMap.insert("point",1);
    dataMap.insert("goods","apple");
    dataMap.insert("customer","yaohua");
    dataMap.insert("Remark","delicious");
    dataMap.insert("operatorID",1);
    dataMap.insert("goodsID",2001);
    dataMap.insert("photo1",1);
    dataMap.insert("Photo2",2);
    dataMap.insert("unitprice","4.5");
    dataMap.insert("extname1","true");
    dataMap.insert("extname2","1");
    dataMap.insert("extname3","2");
    dataMap.insert("extname4","3");
    dataMap.insert("extname5","3");
    dataMap.insert("extname6","4");
    dataMap.insert("extname7","true");
    dataMap.insert("extname8","true");
    dataMap.insert("extvalue1","1");
    dataMap.insert("extvalue2","3");
    dataMap.insert("extvalue3","3");
    dataMap.insert("extvalue4","4");
    dataMap.insert("extvalue5","5");
    dataMap.insert("extvalue6","6");
    dataMap.insert("extvalue7","31");
    dataMap.insert("extvalue8","1");

    //QVariantList ChangeList;
    //ChangeList.append("ChangeListgsfd");
    //dataMap.insert("ChangeList",ChangeList);
    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json InsertRecord"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_4_clicked()
{
    interface = "EditMeterage";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/EditMeterage"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info","201810080006");

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json EditMeterage"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_5_clicked()
{
    interface = "SYNCLocal";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/SYNCLocal"));

    QVariantMap dataMap;
    dataMap.insert("RID","10001");
    dataMap.insert("Device_Info","201810080005");
    dataMap.insert("Seq","20001");

    dataMap.insert("CurrentTime","2018-10-19 09:24:00");
    dataMap.insert("A31Version","V1.002");
    dataMap.insert("A31Description","dsf");
    dataMap.insert("LocalIP","192.168.1.111");
    dataMap.insert("TCPServerIp","54.174.130.220");
    dataMap.insert("TCPServerPort","18010");
    dataMap.insert("UDPServerIp","54.174.130.220");
    dataMap.insert("UDPServerPort","18010");
    dataMap.insert("Gateway","192.168.1.1");
    dataMap.insert("netmask","255.255.255.0");
    dataMap.insert("MACaddress","00:0c:29:dc:36:26");
    dataMap.insert("DNSsever","192.168.1.1");
    dataMap.insert("WSSSID","yaohua");
    dataMap.insert("wirelessNetmask","255.255.255.0");
    dataMap.insert("staticGatemay","192.168.1.1");
    dataMap.insert("staticIp","192.168.1.112");
    dataMap.insert("NETPPort","1120");
    dataMap.insert("BatteryVoltage",20);
    dataMap.insert("Brightness",4);
    dataMap.insert("BaudRate_232",0);
    dataMap.insert("DataBits_232",1);
    dataMap.insert("ParityMode_232",2);
    dataMap.insert("StopBits_232",1);
    dataMap.insert("Tmode_232",2);
    dataMap.insert("BaudRate_485",0);
    dataMap.insert("DataBits_485",1);
    dataMap.insert("ParityMode_485",2);
    dataMap.insert("StopBits_485",2);
    dataMap.insert("Tmode_485",1);
    dataMap.insert("Addr_485",1);
    dataMap.insert("PrintMode",0);
    dataMap.insert("PrintLq",0);
    dataMap.insert("b_PrintRetZero",0);
    dataMap.insert("b_PrintStable",0);
    dataMap.insert("b_Save",0);
    dataMap.insert("b_PrintAuto",0);
    dataMap.insert("PrintLableSize",0);
    dataMap.insert("PrintCodeType",1);
    dataMap.insert("PrintLeadZero",1);
    dataMap.insert("PrintCompanyName","上海耀华称重系统有限公司");
    dataMap.insert("PrintCompanyWebsite","http://www.yaohua.com.cn/");
    dataMap.insert("PrintCompanyAddr","上海市浦东新区上南路4059号");
    dataMap.insert("PrintCompanyTel","400-168-3190");
    dataMap.insert("PrintCompanyLabel","0");
    dataMap.insert("IOEnable",true);
    dataMap.insert("IOinput1",true);
    dataMap.insert("IOinput2",true);
    dataMap.insert("IOoutput1",true);
    dataMap.insert("IOoutput2",true);
    dataMap.insert("IOoutput3",true);
    dataMap.insert("IOoutput4",true);
    dataMap.insert("LargeScreenEnable",true);
    dataMap.insert("UsbHostEnable",true);
    dataMap.insert("UsbDeviceEnable",true);
    dataMap.insert("LANEnable",true);
    dataMap.insert("WiFiEnable",true);
    dataMap.insert("ExtLocal1",true);
    dataMap.insert("ExtLocal2",true);
    dataMap.insert("ExtLocal3",0);
    dataMap.insert("ExtLocal4",0);
    dataMap.insert("ExtLocal5",0);
    dataMap.insert("ExtLocal6",0);
    dataMap.insert("ExtLocal7",0);
    dataMap.insert("ExtLocal8",0);
    dataMap.insert("ExtLocal9",0);
    dataMap.insert("ExtLocal10",0);
    dataMap.insert("ExtLocal11","0");
    dataMap.insert("ExtLocal12","31");
    dataMap.insert("Remark","1");
    dataMap.insert("NetWeight",31);
    dataMap.insert("StateCode",0);
    dataMap.insert("PayType",0);
    dataMap.insert("RecordSerial",0);
    dataMap.insert("LastHeartBeat","0");
    dataMap.insert("IsOnline",true);
    QVariantList ChangeList;
    ChangeList.append("ChangeListgssfdjhffd");
    dataMap.insert("ChangeList",ChangeList);

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json SYNCLocal"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_6_clicked()
{
    interface = "EditLocal";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/EditLocal"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info","201810080006");

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json EditLocal"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_7_clicked()
{
    interface = "SYNCRun";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/SYNCRun"));

    QVariantMap dataMap;
    dataMap.insert("RID","10001");
    dataMap.insert("Device_Info","201810080005");
    dataMap.insert("Seq","20001");

    dataMap.insert("ExtRun1","2018-10-19 09:24:00");
    dataMap.insert("ExtRun2","V1.002");
    dataMap.insert("ExtRun3",0);
    dataMap.insert("ExtRun4",0);
    dataMap.insert("ExtRun5",0);
    dataMap.insert("ExtRun6",0);
    dataMap.insert("ExtRun7",0);
    dataMap.insert("ExtRun8",0);
    dataMap.insert("ExtRun9",0);
    dataMap.insert("ExtRun10",0);
    dataMap.insert("ExtRun11","0");
    dataMap.insert("ExtRun12","0");
    dataMap.insert("Remark","1");
    QVariantList ChangeList;
    ChangeList.append("ChangeListgssfdjhffd");
    dataMap.insert("ChangeList",ChangeList);


    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json SYNCRun"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_8_clicked()
{
    interface = "EditRun";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/EditRun"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info","201810080006");

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json EditRun"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_10_clicked()
{
    interface = "UnifiedOrder";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/OnlinePay/Wechat/UnifiedOrder"));

    QVariantMap dataMap;
    dataMap.insert("RID","10001");
    dataMap.insert("Device_Info","201810080005");
    dataMap.insert("Seq","20001");

    dataMap.insert("appid","2018");
    dataMap.insert("body","good");
    dataMap.insert("out_trade_no","1");
    dataMap.insert("total_fee","31");
    dataMap.insert("Closed",true);
    dataMap.insert("ClosedBy","0");
    dataMap.insert("ClosedName","0");
    dataMap.insert("ClosedOn","0");
    dataMap.insert("Payed",true);
    dataMap.insert("PayedBy","0");
    dataMap.insert("PayedName","0");
    dataMap.insert("PayedOn","0");
    dataMap.insert("Remark","1");
    QVariantList ChangeList;
    ChangeList.append("ChangeListgssfdjhffd");
    dataMap.insert("ChangeList",ChangeList);


    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json UnifiedOrder"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void MainWindow::on_pushButton_12_clicked()
{
    interface = "closeorder";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/OnlinePay/Wechat/closeorder"));

    QVariantMap dataMap;
    dataMap.insert("closeorder","0");
    dataMap.insert("appid","2018");
    dataMap.insert("out_trade_no","1");

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json closeorder"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}
