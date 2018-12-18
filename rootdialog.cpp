#include "rootdialog.h"
#include "ui_rootdialog.h"

//#include "mode.h"
rootdialog::rootdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rootdialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(QRect(0,0,800,480));
    this->setStyleSheet("background-color:black;");
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_2->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_3->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_4->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_5->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_6->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_7->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_8->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->label_9->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->stackedWidget->setCurrentIndex(0);
    tempCali =new cali;
    tempTimer = new QTimer;
    confSet=new configSetting;
    printer =new Printer;
    //mode = new Mode;
    business = new Business;
    wx=new MainWindow;
    about = new About;
    
    mysqlsheet = new mysqlSheet;
    dataexport = new DataExport;
    UserSet = new User;

    ethernetHttp = new EthernetHttp;
    QTimer::singleShot(6000,ethernetHttp,SLOT(ethernetHttpInit()));
    connect(ethernetHttp,SIGNAL(SetZeroSignal()),this,SLOT(SetZeroSlot()),Qt::AutoConnection);
    connect(ethernetHttp,SIGNAL(KTareSignal()),this,SLOT(KTareSlot()),Qt::AutoConnection);
    connect(ethernetHttp,SIGNAL(Qr_CodeSignal()),business,SLOT(Qr_CodeSlot()),Qt::AutoConnection);
    connect(ethernetHttp,SIGNAL(PayedSuccess()),business,SLOT(PaySuccessSlot()),Qt::AutoConnection);
    connect(confSet,SIGNAL(syncParameterSignal()),ethernetHttp,SLOT(syncParameterSlot()),Qt::AutoConnection);
    connect(ethernetHttp,SIGNAL(updateEditLocalSignal()),confSet,SLOT(updateParameterSlot()),Qt::AutoConnection);
    connect(ethernetHttp,SIGNAL(updateEditMeterageSignal()),confSet,SLOT(updateParameterSlot()),Qt::AutoConnection);
    connect(confSet,SIGNAL(updateApplicationSignal()),ethernetHttp,SLOT(updateApplicationSlot()),Qt::AutoConnection);
    connect(ethernetHttp,SIGNAL(httpDownstateSignal(int)),confSet,SLOT(httpDownstateSlot(int)),Qt::AutoConnection);
    /*  remotemysql = new remoteMysql;
    QTimer::singleShot(0,remotemysql,SLOT(remoteMysqlStart()));
    connect(business,SIGNAL(sendToRemoteMysql(QString,QString,QString,QString,QString,QString)),remotemysql,SLOT(receiveFromBusiness(QString,QString,QString,QString,QString,QString)));

    networkCommunication = new NetworkCommunication;
    QTimer::singleShot(0,networkCommunication,SLOT(networkCommunicationStart()));
    connect(confSet,SIGNAL(sendTONetwork()),networkCommunication,SLOT(receiveFromSetting()));

    udpCommunition = new UDPCommunication;
    QTimer::singleShot(0,udpCommunition,SLOT(udpThreadStart()));
*/
    comm = new commthread;
    QTimer::singleShot(0,comm,SLOT(commthreadstart()));

    print = new Printthread;
    QTimer::singleShot(0,print,SLOT(printthreadstart()));
    
    connect(comm,SIGNAL(SendCodeDataToOther()),business,SLOT(RecCodeData()));
    connect(comm,SIGNAL(SendCodeDataToOther()),ethernetHttp,SLOT(RecCodeDataSlot()));
    #ifdef arm
   /*adThread = new AdThread;
    QTimer::singleShot(0,adThread,SLOT(Adinit()));

    loadBig = new LoadBig;
    QTimer::singleShot(0,loadBig,SLOT(Biginit()));

    connect(confSet,SIGNAL(adspeedsignal()),adThread,SLOT(adspeedSlot()));*/
    #endif
    connect(dataexport,SIGNAL(dataExportcsv()),mysqlsheet,SLOT(dataOutputcsv()));
    connect(dataexport,SIGNAL(dataExportxls()),mysqlsheet,SLOT(dataOutputxls()));

    
    connect(confSet,SIGNAL(TmodeChangeFor232()),comm,SLOT(TmodeUpdateFor232()));
    connect(confSet,SIGNAL(CommTypeChange()),comm,SLOT(CommTypeUpdate()));
    connect(confSet,SIGNAL(BaudRateChangeFor232()),comm,SLOT(BaudRateUpdateFor232()));
    connect(confSet,SIGNAL(BaudRateChangeFor485()),comm,SLOT(BaudRateUpdateFor485()));
    connect(confSet,SIGNAL(ParityChangeFor232()),comm,SLOT(ParityUpadateFor232()));
    connect(confSet,SIGNAL(ParityChangeFor485()),comm,SLOT(ParityUpadateFor485()));
    connect(confSet,SIGNAL(StopBitsChangeFor232()),comm,SLOT(StopBitsUpdateFor232()));
    connect(confSet,SIGNAL(StopBitsChangeFor485()),comm,SLOT(StopBitsUpdateFor485()));
    connect(confSet,SIGNAL(DataBitsChangeFor232()),comm,SLOT(DataBitsUpdateFor232()));
    connect(confSet,SIGNAL(DataBitsChangeFor485()),comm,SLOT(DataBitsUpdateFor485()));
    connect(wx,SIGNAL(printnetsignal()),print,SLOT(printnet()));
    connect(wx,SIGNAL(printnetsignal()),comm,SLOT(PrintNet()));
    connect(mysqlsheet,SIGNAL(PrintDailySignal()),print,SLOT(printDaily()));
    connect(mysqlsheet,SIGNAL(PrintMonthSignal()),print,SLOT(printMonth()));
    connect(mysqlsheet,SIGNAL(PrintAllSignal()),print,SLOT(printAll()));
    connect(mysqlsheet,SIGNAL(PrintProductSignal()),print,SLOT(printProduct()));
    connect(mysqlsheet,SIGNAL(PrintProductSeniorSignal()),print,SLOT(PrintProductSenior()));
    connect(mysqlsheet,SIGNAL(PrintUserSignal()),print,SLOT(printUser()));
    connect(mysqlsheet,SIGNAL(PrintUserSeniorSignal()),print,SLOT(printUserSenior()));
    connect(mysqlsheet,SIGNAL(PrintSqlSignal()),print,SLOT(printSqlSheet()));
    connect(business,SIGNAL(printrecord()),print,SLOT(printmyrecord()));

  //  connect (tempTimer,SIGNAL(timeout()),SLOT(keyScan()));


    //connect(mode,SIGNAL(changeTolimit()),this,SLOT(receiveFormMode()));
    //connect(mode,SIGNAL(changeToBusiness()),this,SLOT(receiveFormMode1()));
    //connect(mode,SIGNAL(changeToRootdialog()),this,SLOT(receiveFormMode2()));
    tempTimer->start(100);

    connect(this,SIGNAL(sendToBusiness()),business,SLOT(fromRootdialog()));
    connect(this,SIGNAL(sendToConfigsetting()),confSet,SLOT(fromRootdialog()));
    connect(this,SIGNAL(sentToMainwindow()),wx,SLOT(fromRootdialog()));
    connect(this,SIGNAL(sentToMainwindowzero()),wx,SLOT(fromRootdialogzero()));
    connect(this,SIGNAL(sentToMainwindowtare()),wx,SLOT(fromRootdialogtare()));
    //connect(this,SIGNAL(sendToMode()),mode,SLOT(fromRootdialog()));
    connect(this,SIGNAL(sendToPrinter()),printer,SLOT(fromRootdialog()));

    connect(this,SIGNAL(sendToSheet()),mysqlsheet,SLOT(fromRootdialog()));
    connect(this,SIGNAL(sendToAbout()),about,SLOT(fromRootdialog()));
    connect(this,SIGNAL(sendToUsers()),UserSet,SLOT(on_pushButton_10_clicked()));
    connect(this,SIGNAL(sendToDataExport()),dataexport,SLOT(fromRootdialog()));
    connect(this,SIGNAL(sendToClose()),this,SLOT(closeDialog()));

    // tempCali->Initial();

    
    connect(business,SIGNAL(sendtoRootdialog()),this,SLOT(changetoRootDialog()));
    connect(wx,SIGNAL(sendtoRootdialog()),this,SLOT(changemaintoRootdialog()));
    //connect(business,SIGNAL(QrChange()),this,SLOT(QrComm()));
    //myCom = new PrintPort();

    //connect(myCom,SIGNAL(hasdata()),this,SLOT(SendModbus()));
    //close
    pushButton_blur = new QPushButton(this);
    pushButton_reboot= new QPushButton(this);
    pushButton_poweroff= new QPushButton(this);
    connect(pushButton_reboot,SIGNAL(clicked()),this,SLOT(reboot()));
    connect(pushButton_poweroff,SIGNAL(clicked()),this,SLOT(poweroff()));
    connect(pushButton_blur,SIGNAL(clicked()),this,SLOT(closeDialog()));

    pushButton_blur->setFocusPolicy(Qt::NoFocus);
    pushButton_blur->setStyleSheet("border-image: url(:/A31/A31/35_all/21.bmp);");
    pushButton_blur->setText(tr("点击任意\n\n界面返回"));
    pushButton_blur->setStyleSheet(" font: 20pt \"宋体\";color: rgb(220, 220, 220);");
    pushButton_blur->hide();
    pushButton_blur->setGeometry(0,0,800,480);

    //connect(pushButton_blur,SIGNAL(clicked()),this,SLOT(closeDialog()));


    //pushButton_reboot= new QPushButton(this);
    pushButton_reboot->setFocusPolicy(Qt::NoFocus);
    pushButton_reboot->setGeometry(85,100,250,250);
    pushButton_reboot->setText(tr("重新启动"));
    pushButton_reboot->setStyleSheet("border-style: solid;border-radius:20px;background-color: rgb(0, 170, 127); font: 20pt \"黑体\";color: rgb(255, 248, 248);");
    //connect(pushButton_reboot,SIGNAL(clicked()),this,SLOT(reboot()));
    //pushButton_poweroff= new QPushButton(this);
    pushButton_poweroff->setFocusPolicy(Qt::NoFocus);
    pushButton_reboot->hide();
    pushButton_poweroff->setGeometry(466,100,250,250);

    //pushButton_poweroff->setGeometry(583,284,200,200);
    pushButton_poweroff->setText(tr("关闭电源"));
    pushButton_poweroff->setStyleSheet("border-style: solid;border-radius:20px;background-color: rgb(212, 37, 66); font: 20pt \"黑体\";color: rgb(255, 248, 248);");
    pushButton_poweroff->hide();

    Decp=0;
    
    initLocal();
    
    if(quanxian==3)
        ui->pushButton_2->setEnabled(false);
    
}
void rootdialog::SetZeroSlot()
{
    tempCali->SetZero(ZeroKeyVal);
}
void rootdialog::KTareSlot()
{
    tempCali->KTare();
}
rootdialog::~rootdialog()
{
    delete ui;
}
void rootdialog::changetoRootDialog()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void rootdialog::changemaintoRootdialog()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void rootdialog::on_pushButton_clicked()
{
    beep_start;

    wx->show();
    //wx->main_init();
}

void rootdialog::on_pushButton_5_clicked()
{
    beep_start;
    printer->show();
}

void rootdialog::on_pushButton_7_clicked()
{
    beep_start;
    //mode->show();
    // ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(0);
    business->show();
}

void rootdialog::on_pushButton_2_clicked()
{
    beep_start;
    //confSet=new configSetting;
    confSet->show();
}

void rootdialog::on_pushButton_4_clicked()
{
    beep_start;
    mysqlsheet->show();
}

void rootdialog::on_pushButton_8_clicked()
{
    beep_start;
    about->show();
}

void rootdialog::on_pushButton_3_clicked()
{
    beep_start;
    qDebug() << "on_pushButton_3_clicked";
    UserSet->show();
}

void rootdialog::on_pushButton_6_clicked()
{
    beep_start;
    qDebug() << "on_pushButton_6_clicked";
    dataexport->show();
}

void rootdialog::on_pushButton_9_clicked()
{
    beep_start;
    //close->show();

    //pushButton_blur = new QPushButton(this);
    //pushButton_blur->setFocusPolicy(Qt::NoFocus);
    //pushButton_blur->setStyleSheet("border-image: url(:/A31/A31/35_all/background1.png);");
    pushButton_blur->show();
    //pushButton_blur->setGeometry(0,0,800,480);
    //connect(pushButton_blur,SIGNAL(clicked()),this,SLOT(closeDialog()));
    //pushButton_reboot= new QPushButton(this);
    /*pushButton_reboot->setFocusPolicy(Qt::NoFocus);
    pushButton_reboot->setGeometry(133,100,200,200);
    pushButton_reboot->setText(tr("重新启动"));
    pushButton_reboot->setStyleSheet("border-style: solid;border-radius:20px;background-color: rgb(0, 170, 127); font: 20pt \"黑体\";color: rgb(255, 248, 248);");
    //connect(pushButton_reboot,SIGNAL(clicked()),this,SLOT(reboot()));
    //pushButton_poweroff= new QPushButton(this);
    pushButton_poweroff->setFocusPolicy(Qt::NoFocus);*/
    pushButton_reboot->show();
    /*pushButton_poweroff->setGeometry(499,100,200,200);
    //pushButton_poweroff->setGeometry(583,284,200,200);
    pushButton_poweroff->setText(tr("关闭电源"));
    pushButton_poweroff->setStyleSheet("border-style: solid;border-radius:20px;background-color: rgb(212, 37, 66); font: 20pt \"黑体\";color: rgb(255, 248, 248);");
    */
    pushButton_poweroff->show();
    //connect(pushButton_poweroff,SIGNAL(clicked()),this,SLOT(poweroff()));

}
void rootdialog::closeDialog()
{
    beep_start;
    pushButton_blur->hide();
    pushButton_poweroff->hide();
    pushButton_reboot->hide();
}
void rootdialog::reboot()
{
    beep_start;
    system("reboot");
}
void rootdialog::poweroff()
{
    beep_start;
    system("poweroff");
}
/*void rootdialog::init(void)
{


    //Tmode_232=MODE_CONTINUE;
    //Tmode_485=MODE_MODBUS;
    TotfnBusiness=0;
    AutoAcc=1;
    b_PrintCompany=1;
    PrintFontSize=2;
    PrintFontSize2=2;
    PrintCodeType=0;
    PrintCodeHeight=0;
    //Addr=1;
    //Unit=1;
    //PrintMode=0
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    Tmode_232=configIniRead->value("baseinfo/Tmode232").toInt();
    BaudRate_232 =configIniRead->value("baseinfo/BaudRate232").toInt();
    DataBits_232=configIniRead->value("baseinfo/DataBits232").toInt();
    StopBits_232=configIniRead->value("baseinfo/StopBits232").toInt();
    ParityMode_232=configIniRead->value("baseinfo/Parity232").toInt();

    Tmode_485=configIniRead->value("baseinfo/Tmode485").toInt();
    BaudRate_485 = configIniRead->value("baseinfo/BaudRate485").toInt();
    DataBits_485=configIniRead->value("baseinfo/DataBits485").toInt();
    StopBits_485=configIniRead->value("baseinfo/StopBits485").toInt();
    ParityMode_485=configIniRead->value("baseinfo/Parity485").toInt();
    Addr=configIniRead->value("baseinfo/Addr").toInt();
    
    
    PrintLq=configIniRead->value("baseinfo/PrintLq").toInt();
    b_Save=configIniRead->value("baseinfo/b_Save").toInt();
    PrintCodeType=configIniRead->value("baseinfo/PrintCodeType").toInt();
    b_PrintStable=configIniRead->value("baseinfo/b_PrintStable").toInt();
    b_PrintRetZero=configIniRead->value("baseinfo/b_PrintRetZero").toInt();
    PrintLableSize=configIniRead->value("baseinfo/PrintLableSize").toInt();

    PrintCompanyName=configIniRead->value("baseinfo/PrintCompanyName").toString();
    CompanyWebsite=configIniRead->value("baseinfo/CompanyWebsite").toString();
    CompanyLabel=configIniRead->value("baseinfo/CompanyLabel").toString();
    CompanyTel=configIniRead->value("baseinfo/CompanyTel").toString();
    CompanyAddr=configIniRead->value("baseinfo/CompanyAddr").toString();


    PrintMode=configIniRead->value("baseinfo/PrintMode").toInt();
    Totfn=configIniRead->value("baseinfo/Totfn").toInt();
    Totfa=configIniRead->value("baseinfo/Totfa").toFloat();
    delete configIniRead;


    if(PrintCodeHeight>2)PrintCodeHeight=0;
    if(PrintCodeType>2)PrintCodeType=0;
    if((Addr<1)||(Addr>127))Addr=1;
    
}*/

void rootdialog::initLocal(void)
{
    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    LocalIp = configIniRead->value("baseinfo/LocalIp").toString();
    QString Gateway = configIniRead->value("baseinfo/Gateway").toString();
    delete configIniRead;

    QString tempGateway = "route add default gw "+Gateway;
    std::string str1 = tempGateway.toStdString();
    const char* ch1 = str1.c_str();

    QString tempIP = "ifconfig eth0 "+LocalIp;
    std::string str = tempIP.toStdString();
    const char* ch = str.c_str();
#ifdef arm
    system(ch);
    system(ch1);
#endif
}
void rootdialog::receiveFormMode()
{
    on_pushButton_clicked();
}

void rootdialog::receiveFormMode1()
{
    business->show();
}
void rootdialog::receiveFormMode2(void)
{
    //this->close();
}
void rootdialog::keyScan(void)
{
    //tempCali->KeyScan();
    if(loginflag!=1)
        return;
    tempCali->KeyScan();
    /* if(KeyNumb==0)
     PIN_PC10_L;
     else
         PIN_PC10_H;*/

    if((KeyNumb==97))
    {
        beepflag=1;
        KeyNumb=0;
        PIN_PB25_L;
        emit sentToMainwindow();
        emit sendToConfigsetting();
        //emit sendToMode();
        emit sendToPrinter();
        emit sendToBusiness();

        emit sendToSheet();
        emit sendToAbout();
        emit sendToDataExport();
        emit sendToClose();
        emit sendToUsers();

    }
    if(KeyNumb==54)
    {
        beepflag=1;
        PIN_PB25_L;
        wx->show();
        KeyNumb=0;
    }
    if(KeyNumb==42)
    {
        beepflag=1;
        // tempCali->KTare();
        emit sentToMainwindowtare();
        KeyNumb=0;
    }
    if(KeyNumb==29)
    {
        beepflag=1;
        //tempCali->SetZero(ZeroKeyVal);
        emit sentToMainwindowzero();
        KeyNumb=0;
    }
    if(quanxian==3)
    { ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }
    if(quanxian==2)
        ui->pushButton_3->setEnabled(false);
}


/*void rootdialog::printmyrecord()
{
    qDebug() << "printmyrecord" << endl;
    myCom->printwrite2();
    productCashNum=0;
    //myCom->Price2UartData(5.6);
}


void rootdialog::printDaily()
{
    qDebug() << "printDailyReport" << endl;
    myCom->PrintDailyReport();
}

void rootdialog::printMonth()
{
    qDebug() << "printMonthReport" << endl;
    myCom->PrintMonthReport();
}

void rootdialog::printAll()
{
   qDebug() << "printAllReport" << endl;
    myCom->PrintAllReport();
}

void rootdialog::printProduct()
{
   qDebug() << "printProductReport" << endl;
    myCom->PrintProductReport();
}

void rootdialog::PrintProductSenior()
{
   qDebug() << "printProductSeniorReport" << endl;
    myCom->PrintProductSeniorReport();
}

void rootdialog::printUser()
{
   qDebug() << "printUserReport" << endl;
    myCom->PrintUserReport();
}

void rootdialog::printUserSenior()
{
   qDebug() << "printUserSeniorReport" << endl;
    myCom->PrintUserSeniorReport();
}

void rootdialog::QrComm()
{
    qDebug() << "QrComm" << endl;
    //myCom->printwrite2();
    //productCashNum=0;
    myCom->Price2UartData(0.01);
}

void rootdialog::printnet()
{
    qDebug() << "printnet" << endl;
    myCom->printwrite();
    //productCashNum=0;
    //myCom->Price2UartData(0.01);
}*/

/*void rootdialog::BaudRateUpdateFor232()
{
    qDebug()<<"baudrate update";
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    BaudRate_232 = configIniRead->value("baseinfo/BaudRate232").toInt();
    delete configIniRead;
    //BaudRate_232=(BaudRateType)ui->comboBox_4->currentIndex();
    myCom->uart2_init(BaudRate_232,DataBits_232,ParityMode_232,StopBits_232,0,10);
}

void rootdialog::DataBitsUpdateFor232()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    DataBits_232 = configIniRead->value("baseinfo/DataBits232").toInt();
    delete configIniRead;
    myCom->uart2_init(BaudRate_232,DataBits_232,ParityMode_232,StopBits_232,0,10);
}

void rootdialog::ParityUpadateFor232()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    ParityMode_232 =configIniRead->value("baseinfo/Parity232").toInt();
    delete configIniRead;
    myCom->uart2_init(BaudRate_232,DataBits_232,ParityMode_232,StopBits_232,0,10);
}

void rootdialog::StopBitsUpdateFor232()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    StopBits_232 =configIniRead->value("baseinfo/StopBits232").toInt();
    delete configIniRead;
    myCom->uart2_init(BaudRate_232,DataBits_232,ParityMode_232,StopBits_232,0,10);
}*/

/*void rootdialog::BaudRateUpdateFor485()
{
    myCom->uart3_init(BaudRate_485,DataBits_485,ParityMode_485,StopBits_485,0,10);
}

void rootdialog::ParityUpadateFor485()
{
    myCom->uart3_init(BaudRate_485,DataBits_485,ParityMode_485,StopBits_485,0,10);
}

void rootdialog::DataBitsUpdateFor485()
{
    myCom->uart3_init(BaudRate_485,DataBits_485,ParityMode_485,StopBits_485,0,10);
}

void rootdialog::StopBitsUpdateFor485()
{
    myCom->uart3_init(BaudRate_485,DataBits_485,ParityMode_485,StopBits_485,0,10);
}


void rootdialog::SendModbus()
{
    myCom->LoadUart3Com();
}*/

void rootdialog::on_pushButton_10_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(0);
    wx->show();
}

void rootdialog::on_pushButton_13_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(0);
    business->show();
}
