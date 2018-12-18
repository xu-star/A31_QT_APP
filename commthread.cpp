#include "commthread.h"

commthread::commthread(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&m_thread);
    m_thread.start();
}

void commthread::commthreadstart()
{
    qDebug() <<"Commthread start!!";
    myCom1 = new PrintPort();
    obotimer = new QTimer(this);
    CommTimer =new QTimer(this);
	
    init();
    connect(myCom1,SIGNAL(hasdata()),this,SLOT(SendModbus()));
    connect(myCom1,SIGNAL(hasCodeData()),this,SLOT(SendCodeData()));
    QString portName1 = "/dev/ttyS1" ;
   
    QString portName3 = "/dev/ttyS3" ;
    QString portName4 = "/dev/ttyS2" ;

    /*myCom1->openPort_Rd(portName1,
                    4,
                    0,
                    0,
                    0,
                    0,10);*/
    myCom1->openPort1(portName1,
                    8,
                    0,
                    0,
                    0,
                    0,10);
   myCom1->openPort2(portName3,
                     BaudRate_232,
                     DataBits_232,
                     ParityMode_232,
                     StopBits_232,
                     0,10);
   myCom1->openPort3(portName4,
                     BaudRate_485,
                     DataBits_485,
                     ParityMode_485,
                     StopBits_485,
                     0,10);
    connect(CommTimer, SIGNAL(timeout()), this, SLOT(commTimer()));
    connect(obotimer, SIGNAL(timeout()), this, SLOT(sendMsg()));
   // CommTimer.start(300);
     obotimer->start(200);
}

void commthread::commTimer()
{
   myCom1->LoadUart1Com();
   //myCom1->LoadRdCom();
}


void commthread::sendMsg()
{
    myCom1->LoadUart2Com();
}
void commthread::SendCodeData()
{
    emit SendCodeDataToOther();
}
void commthread::BaudRateUpdateFor232()
{
    qDebug()<<"baudrate update";
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    BaudRate_232 = configIniRead->value("baseinfo/BaudRate232").toInt();
    delete configIniRead;
    //BaudRate_232=(BaudRateType)ui->comboBox_4->currentIndex();
    myCom1->uart2_init(BaudRate_232,DataBits_232,ParityMode_232,StopBits_232,0,10);
}

void commthread::DataBitsUpdateFor232()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    DataBits_232 = configIniRead->value("baseinfo/DataBits232").toInt();
    delete configIniRead;
    myCom1->uart2_init(BaudRate_232,DataBits_232,ParityMode_232,StopBits_232,0,10);
}

void commthread::ParityUpadateFor232()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    ParityMode_232 =configIniRead->value("baseinfo/Parity232").toInt();
    delete configIniRead;
    myCom1->uart2_init(BaudRate_232,DataBits_232,ParityMode_232,StopBits_232,0,10);
}

void commthread::StopBitsUpdateFor232()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    StopBits_232 =configIniRead->value("baseinfo/StopBits232").toInt();
    delete configIniRead;
    myCom1->uart2_init(BaudRate_232,DataBits_232,ParityMode_232,StopBits_232,0,10);
}

void commthread::TmodeUpdateFor232()
{
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    Tmode_232 =configIniRead->value("baseinfo/Tmode232").toInt();
    delete configIniRead;
    if((Tmode_232==2)||(Tmode_232==3))
    {
        if(obotimer->isActive())
        {
            obotimer->stop();
        }
    }
    else if(Tmode_232!=3)
    {
        if(!obotimer->isActive())
            obotimer->start(200);
    }
}

void commthread::CommTypeUpdate()
{
     if(CommType==0)
    {
       if(!CommTimer->isActive())
            CommTimer->start(300);
	   myCom1->uart1_init(4,0,0,0,0,10);
    }
    else if(CommType==1)
    {
	 if(CommTimer->isActive())        
            CommTimer->stop();  
	 myCom1->uart1_init(8,0,0,0,0,10);
    }
	myCom1->Uart1Recv();
}

void commthread::BaudRateUpdateFor485()
{
    myCom1->uart3_init(BaudRate_485,DataBits_485,ParityMode_485,StopBits_485,0,10);
}

void commthread::ParityUpadateFor485()
{
    myCom1->uart3_init(BaudRate_485,DataBits_485,ParityMode_485,StopBits_485,0,10);
}

void commthread::DataBitsUpdateFor485()
{
    myCom1->uart3_init(BaudRate_485,DataBits_485,ParityMode_485,StopBits_485,0,10);
}

void commthread::StopBitsUpdateFor485()
{
    myCom1->uart3_init(BaudRate_485,DataBits_485,ParityMode_485,StopBits_485,0,10);
}


void commthread::SendModbus()
{
    myCom1->LoadUart3Com();
}
void commthread::PrintNet()
{
     qDebug() << "printnetLP180" << endl;
   if(Tmode_232==3)
	  myCom1->printwriteLP180();
	
}
void commthread::init(void)
{

    
    //Tmode_232=MODE_CONTINUE;
    //Tmode_485=MODE_MODBUS;
    TotfnBusiness=0;
    AutoAcc=1;
    b_PrintCompany=1;
   // b_PrintHeader=1;
    PrintFontSize=2;
    PrintFontSize2=2;
    PrintCodeType=0;
    PrintCodeHeight=0;
    //Addr=1;
    //Unit=1;
    //PrintMode=0	
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    CommType=configIniRead->value("baseinfo/CommType").toInt();
    CommType232=configIniRead->value("baseinfo/CommType232").toInt();
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
    b_PrintHeader=configIniRead->value("baseinfo/b_PrintHeader").toInt();
    PrintCodeType=configIniRead->value("baseinfo/PrintCodeType").toInt();
    b_PrintStable=configIniRead->value("baseinfo/b_PrintStable").toInt();
    b_PrintRetZero=configIniRead->value("baseinfo/b_PrintRetZero").toInt();
    PrintLableSize=configIniRead->value("baseinfo/PrintLableSize").toInt();
   
    PrintCompanyName=configIniRead->value("baseinfo/PrintCompanyName").toString();
    CompanyWebsite=configIniRead->value("baseinfo/CompanyWebsite").toString();
    CompanyLabel=configIniRead->value("baseinfo/CompanyLabel").toString();
    CompanyTel=configIniRead->value("baseinfo/CompanyTel").toString();
    CompanyAddr=configIniRead->value("baseinfo/CompanyAddr").toString();
	
	
    //PrintMode=configIniRead->value("baseinfo/PrintMode").toInt();
    Totfn=configIniRead->value("baseinfo/Totfn").toInt();
    Totfa=configIniRead->value("baseinfo/Totfa").toFloat();

    Totfnc=configIniRead->value("baseinfo/Totfnc").toInt();
    Totfac=configIniRead->value("baseinfo/Totfac").toInt();
	
    LastWt=configIniRead->value("baseinfo/LastWt").toFloat();
    LastTime=configIniRead->value("baseinfo/LastTime").toInt();
    delete configIniRead;

   
	if(PrintCodeHeight>2)PrintCodeHeight=0;
    if(PrintCodeType>2)PrintCodeType=0;
	if((Addr<1)||(Addr>127))Addr=1;
       if(CommType232>1) CommType232=0;
	  if(CommType>1) CommType=0; 
}

