#include "ethernethttp.h"

EthernetHttp::EthernetHttp(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&m_threadhttp);
    m_threadhttp.start();
}

void EthernetHttp::ethernetHttpInit()
{
    interface = "";
    TokenData = "";
    StateCode = 0;
    TerminalPlusFlag  = false;
    AccountFlag = true;
    AccountFlag1 = true;
    receiveStates = true;
    Auth_Code="";

    UnifiedOrderFlag = false;
    PreCreateFlag = false;
    //RequestPayment = false;
    InsertRecordTimes = RecproductNum;
    m_pTimerhttp = new QTimer;
    tempTimer = new QTimer;
    connect(tempTimer,SIGNAL(timeout()),this,SLOT(ethernetHttpSlot1()));
    connect(m_pTimerhttp,SIGNAL(timeout()),this,SLOT(ethernetHttpSlot()));
    m_pTimerhttp->start(1000);
    tempTimer->start(1000);
    StartPosition = 0;
    DownLoadBlocksLength = 0;
    DownSuccessFlag =false;
    tempChar = 0;
    httpDownstate = 0;
    //system("ifconfig eth0 192.168.1.222");
    //system("route add default gw 192.168.1.1");
    nam = new QNetworkAccessManager(this);
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}
void EthernetHttp::ethernetHttpSlot1()
{
    if (receiveStates==false)
    {
        tempChar++;
    }
    if (receiveStates == true)
    {
        tempChar--;
    }
    if (tempChar>50)
    {
        tempChar=0;

        /*StartPosition = 0;
        DownLoadBlocksLength = 0;
        DownSuccessFlag =false;
        tempChar = 0;
        httpDownstate = 0;
        interface = "";
        TokenData = "";
        StateCode = 0;
        TerminalPlusFlag  = false;
        AccountFlag = true;
        AccountFlag1 = true;
        receiveStates = true;
        UnifiedOrderFlag = false;
        PreCreateFlag = false;
        InsertRecordTimes = RecproductNum;*/
    }
}
void EthernetHttp::ethernetHttpSlot()
{
    lock.lockForWrite();
    qDebug() <<"receiveStatesreceiveStatesreceiveStates"<<receiveStates;
    qDebug() <<"httpDownstatehttpDownstatehttpDownstate"<<httpDownstate;
    if (receiveStates == true)
    {
        //receiveStates = false;
        qDebug()<<"ethernetHttpSlot";
        if (TokenData == "")
        {
            qDebug()<<"TokenData"<<TokenData;
            getTokenFun();
            receiveStates = false;
        }
        else if (httpDownstate==1)
        {
            DownloadFile();
            receiveStates = false;
        }
        else if (DownSuccessFlag==true)
        {
            if (StartPosition>=DocLength)
            {
                qDebug()<<"DownloadFile success!!!!!!!!!!!!!!!!";
                //ui->progressBar->setValue(StartPosition+DownLoadBlocksLength);
                //ui->progressBar->setValue(DocLength);
                StartPosition = 0;
                DownLoadBlocksLength = 0;
                DownSuccessFlag=false;
                httpDownstate=3;
                emit httpDownstateSignal(httpDownstate);
            }
            else
            {
                //on_pushButton_17_clicked();

                DownloadFile();
                receiveStates = false;
            }
        }
        else if (AccountFlag == true)
        {
            AccountFlag = false;
            SYNCLocalFun();
            receiveStates = false;
        }
        else if (AccountFlag1 == true)
        {
            AccountFlag1 = false;
            SYNCRunFun();
            receiveStates = false;
        }
        else if (httpDownstate!=6)
        {
            if (TerminalPlusFlag == false)
            {
                TerminalPlusFlag  = true;
                TerminalPlusFun();
                receiveStates = false;
            }
            else
            {
                TerminalPlusFlag = false;
                if (PayACK == true)
                {
                    //PayACK = false;
                    //支付允许(1-允许) *A31收到该置位后，应当发起支付下单URL的post请求
                    if (OrderBusiness == true)
                    {
                        OrderBusiness = false;
                        QDateTime time = QDateTime::currentDateTime();
                        QString str = time.toString("yyyyMMddhhmmss");
                        out_trade_no = "A31"+str;
                        goods = Rec[InsertRecordTimes-1].RecproductName;
                    }
                    if (PayType==1)
                    {
                        UnifiedOrderFun();
                        receiveStates = false;
                    }
                    if (PayType==2)
                    {
                        PreCreateFun();
                        receiveStates = false;
                    }
                }
                else if (UnifiedOrderFlag==true)
                {
                    GetItemsBySQLFun();
                    receiveStates = false;
                }
                else if (PreCreateFlag == true)
                {
                    GetItemsBySQLFun();
                    receiveStates = false;
                }
                else if ((RecordACK == true)&&(InsertRecordTimes>0))
                {
                    qDebug()<<"InsertRecordTimes"<<InsertRecordTimes;
                    InsertRecordTimes--;
                    qDebug()<<"InsertRecordTimes"<<InsertRecordTimes;
                    //NetWeight = Rec[InsertRecordTimes-1].Recweight;
                    //goods = Rec[InsertRecordTimes-1].RecproductName;
                    //goodsID = Rec[InsertRecordTimes-1].RecCode;
                    //unitprice = Rec[InsertRecordTimes-1].RecproductPrice;
                    NetWeight = Rec[InsertRecordTimes].Recweight;
                    goods = Rec[InsertRecordTimes].RecproductName;
                    goodsID = Rec[InsertRecordTimes].RecCode;
                    unitprice = Rec[InsertRecordTimes].RecproductPrice;
                    qDebug()<<"Rec[InsertRecordTimes].Recweight"<<Rec[InsertRecordTimes].Recweight;
                    qDebug()<<"Rec[InsertRecordTimes].RecproductName"<<Rec[InsertRecordTimes].RecproductName;
                    qDebug()<<"Rec[InsertRecordTimes].RecCode"<<Rec[InsertRecordTimes].RecCode;
                    qDebug()<<"Rec[InsertRecordTimes].RecproductPrice"<<Rec[InsertRecordTimes].RecproductPrice;
                    InsertRecordFun();
                    receiveStates = false;
                }
                else if (ParametersSYNCMeterage == true)
                {
                    //A31收到该置位后，应当发起计量参数同步URL的post请求
                    SYNCMeterageFun();
                    receiveStates = false;
                }
                else if (ParametersEditMeterage == true)
                {
                    //A31收到该置位后，应当发起计量参数编辑URL的post请求
                    EditMeterageFun();
                    receiveStates = false;
                }
                else if (ParametersSYNCLocal == true)
                {
                    //A31收到该置位后，应当发起本机参数同步URL的post请求
                    SYNCLocalFun();
                    receiveStates = false;
                }
                else if (ParametersEditLocal == true)
                {
                    //A31收到该置位后，应当发起本机参数编辑URL的post请求
                    EditLocalFun();
                    receiveStates = false;
                }
                else if (ParametersSYNCRun == true)
                {
                    //A31收到该置位后，应当发起运行参数同步URL的post请求
                    SYNCRunFun();
                    receiveStates = false;
                }
                else if (ParametersEditRun == true)
                {
                    //A31收到该置位后，应当发起运行参数编辑URL的post请求
                    EditRunFun();
                    receiveStates = false;
                }
            }
        }
    }
    lock.unlock();
}

void EthernetHttp::replyFinished(QNetworkReply* reply)
{
    receiveStates = true;
    lock.lockForWrite();
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
                qDebug()<< "TerminalPlus11111111111111";
                QVariantMap receiveData = result["Data"].toMap();
                int ResultCode = receiveData["ResultCode"].toInt();
                if (ResultCode==0)
                {
                    qDebug()<<"receive TerminalPlus data success!!!";
                }
                else if (ResultCode==1)
                {
                    qDebug()<<"The TerminalPlus command number does not exist!!!";
                }
                else if (ResultCode==2)
                {
                    qDebug()<<"Database operation failed!!!";
                }
                else if (ResultCode==3)
                {
                    qDebug()<<"The data format is incorrect!!!";
                }

                bool SetZero = receiveData["SetZero"].toBool();
                if (SetZero==true)
                {
                    //发送信号执行置零操作
                    emit SetZeroSignal();
                }

                bool KTare = receiveData["KTare"].toBool();
                if (KTare == true)
                {
                    //发送信号执行除皮操作
                    emit KTareSignal();
                }
                PayACK = receiveData["PayACK"].toBool();
                RecordACK = receiveData["RecordACK"].toBool();
                ParametersSYNCMeterage = receiveData["ParametersSYNCMeterage"].toBool();
                ParametersEditMeterage = receiveData["ParametersEditMeterage"].toBool();
                ParametersSYNCLocal = receiveData["ParametersSYNCLocal"].toBool();
                ParametersEditLocal = receiveData["ParametersEditLocal"].toBool();
                ParametersSYNCRun = receiveData["ParametersSYNCRun"].toBool();
                ParametersEditRun = receiveData["ParametersEditRun"].toBool();

            }
            if (interface == "SYNCMeterage")
            {
                qDebug()<< "SYNCMeterage222222222222222";
                //int ResultCode = result["Data"].["ResultCode"];//
            }
            if (interface == "InsertRecord")
            {
                qDebug()<< "InsertRecord999999999999999";
                if (InsertRecordTimes==0)
                {
                    workRecordInsert = false;
                }
            }
            if (interface == "EditMeterage")
            {
                qDebug()<< "EditMeterage33333333333333";
                QVariantMap receiveData = result["Data"].toMap();
                int ResultCode = receiveData["ResultCode"].toInt();
                if (ResultCode==0)
                {
                    qDebug()<<"receive EditMeterage data success!!!";
                    if (receiveData["CalibrateZero"].toInt()>0)
                    {
                        //AD_Zero = receiveData["CalibrateZero"].toInt();////此数值不可修改
                    }
                    if (receiveData["CalibrateRate"].toFloat()>0)
                    {
                        Rri = receiveData["CalibrateRate"].toFloat();
                    }
                    if (receiveData["Range"].toFloat()>0)
                    {
                        CalFull = receiveData["Range"].toFloat();
                    }
                    if (receiveData["NonlineaCorrection"].toFloat()>0)
                    {
                        //非线性修正值(待添加)
                    }
                    if (receiveData["ADCode"].toInt()>0)
                    {
                        CurData = receiveData["ADCode"].toInt();
                    }
                    if (receiveData["LastCalibrationTime"].toString()!="")
                    {
                        //最后一次标定时间(待添加)
                    }
                    if (receiveData["CalibrationTimes"].toInt()>0)
                    {
                        //标定次数(待添加)
                    }
                    if (receiveData["Division"].toInt()>0)
                    {
                        Rati = receiveData["Division"].toInt();
                    }
                    if (receiveData["Point"].toInt()>0)
                    {
                        Point = receiveData["Point"].toInt();
                    }
                    if (receiveData["InitialZero"].toInt()>0)
                    {
                        OnZero = receiveData["InitialZero"].toInt();
                    }
                    if (receiveData["ManualZero"].toInt()>0)
                    {
                        ZeroKeyVal = receiveData["ManualZero"].toInt();
                    }
                    if (receiveData["ZeroTrackingSpeed"].toInt()>0)
                    {
                        //ZeroKeyVal = receiveData["ZeroTrackingSpeed"].toInt();
                        //零位跟踪速度(待添加)
                    }
                    if (receiveData["ZeroTrackingRange"].toInt()>0)
                    {
                        Zono = receiveData["ZeroTrackingRange"].toInt();
                    }
                    if (receiveData["FilteringAlgorithm"].toInt()>0)
                    {
                        FilterStep = receiveData["FilteringAlgorithm"].toInt();
                    }
                    if (receiveData["BoundaryStrength"].toInt()>0)
                    {
                        StableTime = receiveData["BoundaryStrength"].toInt();
                    }
                    if (receiveData["stabilize"].toInt()>0)
                    {
                        StableRange = receiveData["stabilize"].toInt();
                    }
                    if (receiveData["StabilizeFlag"].toBool())
                    {
                        //b_Stable = receiveData["StabilizeFlag"].toBool();//此数值不可修改
                    }
                    if (receiveData["NetFlag"].toBool())
                    {
                        //b_Net = receiveData["NetFlag"].toBool();//此数值不可修改
                    }
                    if (receiveData["ZeroFlag"].toBool())
                    {
                        //b_Zero = receiveData["ZeroFlag"].toBool();//此数值不可修改
                    }
                    if (receiveData["ADSpeed"].toInt())
                    {
                        //FilterStep = receiveData["ADSpeed"].toInt();//FilterStep>3?1:0);//AD速率(0,10HZ;1,80HZ)
                    }
                    if (receiveData["Alarm"].toInt())
                    {
                        //Alarm = receiveData["Alarm"].toInt();//(待添加)
                    }
                    if (receiveData["AutoSetZero"].toInt())
                    {
                        //Alarm = receiveData["AutoSetZero"].toInt();//(待添加)
                        //允许开机置零（0:不允许，1：允许）
                    }
                    if (receiveData["Unit"].toInt())
                    {
                        Unit = receiveData["Unit"].toInt();//(待添加)
                    }
                    if (receiveData["PrintRound"].toInt())
                    {
                        //PrintRound = receiveData["PrintRound"].toInt();//(待添加)
                    }
                    emit updateEditMeterageSignal();
                }
                else if (ResultCode==1)
                {
                    qDebug()<<"The EditMeterage command number does not exist!!!";
                }
                else if (ResultCode==2)
                {
                    qDebug()<<"EditMeterage Database operation failed!!!";
                }
                else if (ResultCode==3)
                {
                    qDebug()<<"The EditMeterage data format is incorrect!!!";
                }

                qDebug()<< "EditMeterage333333333333333";
            }
            if (interface == "SYNCLocal")
            {
                qDebug()<< "SYNCLocal444444444444444444";
            }
            if (interface == "EditLocal")
            {
                qDebug()<< "EditLocal555555555555555555";

                qDebug()<< "EditLocal---------------";
                QVariantMap receiveData = result["Data"].toMap();
                int ResultCode = receiveData["ResultCode"].toInt();
                if (ResultCode==0)
                {
                    qDebug()<<"receive EditLocal data success!!!";

                    if (receiveData["CurrentTime"].toString()!="")
                    {
                        //QString CurrentTime = receiveData["CurrentTime"].toString();
                    }
                    if (receiveData["A31Version"].toString()!="")
                    {
                        A31Version = receiveData["A31Version"].toString();
                    }
                    if (receiveData["A31Description"].toString()!="")
                    {
                        QString A31Description = receiveData["A31Description"].toString();
                    }
                    if (receiveData["LocalIp"].toString()!="")
                    {
                        LocalIp = receiveData["LocalIp"].toString();
                    }
                    if (receiveData["TCPServerIp"].toString()!="")
                    {
                        ServerIp = receiveData["TCPServerIp"].toString();
                    }
                    if (receiveData["TCPServerPort"].toInt())
                    {
                        ServerPort = receiveData["TCPServerPort"].toInt();
                    }
                    if (receiveData["UDPServerIp"].toString()!="")
                    {
                        UDPServerIp = receiveData["UDPServerIp"].toString();
                    }
                    if (receiveData["UDPServerPort"].toInt())
                    {
                        UDPServerPort = receiveData["UDPServerPort"].toInt();
                    }
                    if (receiveData["Gateway"].toString()!="")
                    {
                        QString Gateway = receiveData["Gateway"].toString();
                    }
                    if (receiveData["MACaddress"].toString()!="")
                    {
                        QString MACaddress = receiveData["MACaddress"].toString();
                    }
                    if (receiveData["DNSsever"].toString()!="")
                    {
                        QString DNSsever = receiveData["DNSsever"].toString();
                    }
                    if (receiveData["WSSSID"].toString()!="")
                    {
                        QString WSSSID = receiveData["WSSSID"].toString();
                    }
                    if (receiveData["wirelessNetmask"].toString()!="")
                    {
                        QString wirelessNetmask = receiveData["wirelessNetmask"].toString();
                    }
                    if (receiveData["staticGatemay"].toString()!="")
                    {
                        QString staticGatemay = receiveData["staticGatemay"].toString();
                    }
                    if (receiveData["staticIp"].toString()!="")
                    {
                        QString staticIp = receiveData["staticIp"].toString();
                    }

                    if (receiveData["NETPPort"].toString()!="")
                    {
                        QString NETPPort = receiveData["NETPPort"].toString();
                    }
                    //fvalue = receiveData["BatteryVoltage"].toString();//電池電量不可修改
                    if (receiveData["Brightness"].toInt())
                    {
                        LedLight = (uchar)receiveData["Brightness"].toInt();//
                    }
                    if (receiveData["BaudRate_232"].toInt())
                    {
                        BaudRate_232 = (uchar)receiveData["BaudRate_232"].toInt();
                    }
                    if (receiveData["DataBits_232"].toInt())
                    {
                        DataBits_232 = (uchar)receiveData["DataBits_232"].toInt();
                    }
                    if (receiveData["ParityMode_232"].toInt())
                    {
                        ParityMode_232 = (uchar)receiveData["ParityMode_232"].toInt();
                    }
                    if (receiveData["StopBits_232"].toInt())
                    {
                        StopBits_232 = (uchar)receiveData["StopBits_232"].toInt();
                    }
                    if (receiveData["Tmode_232"].toInt())
                    {
                        Tmode_232 = (uchar)receiveData["Tmode_232"].toInt();
                    }
                    if (receiveData["BaudRate_485"].toInt())
                    {
                        BaudRate_485 = (uchar)receiveData["BaudRate_485"].toInt();
                    }
                    if (receiveData["DataBits_485"].toInt())
                    {
                        DataBits_485 = (uchar)receiveData["DataBits_485"].toInt();
                    }
                    if (receiveData["ParityMode_485"].toInt())
                    {
                        ParityMode_485 = (uchar)receiveData["ParityMode_485"].toInt();
                    }
                    if (receiveData["Tmode_485"].toInt())
                    {
                        Tmode_485 = (uchar)receiveData["Tmode_485"].toInt();
                    }
                    if (receiveData["Addr_485"].toInt())
                    {
                        Addr = (uchar)receiveData["Addr_485"].toInt();
                    }
                    if (receiveData["PrintMode"].toInt())
                    {
                        PrintMode = (uchar)receiveData["PrintMode"].toInt();
                    }
                    if (receiveData["PrintLq"].toFloat())
                    {
                        PrintLq = receiveData["PrintLq"].toFloat();
                    }
                    if (receiveData["b_PrintRetZero"].toInt())
                    {
                        b_PrintRetZero = (uchar)receiveData["b_PrintRetZero"].toInt();
                    }
                    if (receiveData["b_PrintStable"].toInt())
                    {
                        b_PrintStable = (uchar)receiveData["b_PrintStable"].toInt();
                    }
                    if (receiveData["b_Save"].toInt())
                    {
                        b_Save = (uchar)receiveData["b_Save"].toInt();
                    }
                    if (receiveData["b_PrintAuto"].toInt())
                    {
                        b_PrintAuto = (uchar)receiveData["b_PrintAuto"].toInt();
                    }
                    if (receiveData["PrintLableSize"].toInt())
                    {
                        PrintLableSize = (uchar)receiveData["PrintLableSize"].toInt();
                    }
                    if (receiveData["PrintCodeType"].toInt())
                    {
                        PrintCodeType = (uchar)receiveData["PrintCodeType"].toInt();
                    }
                    //PrintLeadZero = receiveData["PrintLeadZero"].toChar();//还未用到
                    if (receiveData["PrintCompanyName"].toString()!="")
                    {
                        PrintCompanyName = receiveData["PrintCompanyName"].toString();
                    }
                    if (receiveData["PrintCompanyWebsite"].toString()!="")
                    {
                        CompanyWebsite = receiveData["PrintCompanyWebsite"].toString();
                    }
                    if (receiveData["PrintCompanyAddr"].toString()!="")
                    {
                        CompanyAddr = receiveData["PrintCompanyAddr"].toString();
                    }
                    if (receiveData["PrintCompanyTel"].toString()!="")
                    {
                        CompanyTel = receiveData["PrintCompanyTel"].toString();
                    }
                    if (receiveData["PrintCompanyLabel"].toString()!="")
                    {
                        CompanyLabel = receiveData["PrintCompanyLabel"].toString();
                    }
                    emit updateEditLocalSignal();
                }
                else if (ResultCode==1)
                {
                    qDebug()<<"The EditLocal command number does not exist!!!";
                }
                else if (ResultCode==2)
                {
                    qDebug()<<"EditLocal Database operation failed!!!";
                }
                else if (ResultCode==3)
                {
                    qDebug()<<"The EditLocal data format is incorrect!!!";
                }

                qDebug()<< "EditLocal555555555555555555";
            }
            if (interface == "SYNCRun")
            {
                qDebug()<< "SYNCRun66666666666666666666";
            }
            if (interface == "EditRun")
            {
                qDebug()<< "EditRun777777777777777777777";

                qDebug()<< "EditRun---------------";
                QVariantMap receiveData = result["Data"].toMap();
                int ResultCode = receiveData["ResultCode"].toInt();
                if (ResultCode==0)
                {
                    qDebug()<<"receive EditRun data success!!!";

                }
                else if (ResultCode==1)
                {
                    qDebug()<<"The EditRun command number does not exist!!!";
                }
                else if (ResultCode==2)
                {
                    qDebug()<<"EditRun Database operation failed!!!";
                }
                else if (ResultCode==3)
                {
                    qDebug()<<"The EditRun data format is incorrect!!!";
                }

                qDebug()<< "EditRun777777777777777777777";
            }
            if (interface == "UnifiedOrder")
            {
                qDebug()<< "UnifiedOrder888888888888888888";
                QVariantMap UnifiedOrderData = result["Data"].toMap();
                int ResultCode = UnifiedOrderData["ResultCode"].toInt();
                if (ResultCode==0)
                {
                    RequestPayment = false;
                    UnifiedOrderFlag = true;
                    qDebug()<<"receive UnifiedOrder data success!!!";
                    Qrstr = UnifiedOrderData["Qr_Code"].toString();
                    qDebug()<<"-------------Qrstr---------------"<<Qrstr;
                    emit Qr_CodeSignal();
                }
                else if (ResultCode==1)
                {
                    qDebug()<<"The UnifiedOrder command number does not exist!!!";
                }
                else if (ResultCode==2)
                {
                    qDebug()<<"UnifiedOrder Database operation failed!!!";
                }
                else if (ResultCode==3)
                {
                    qDebug()<<"The UnifiedOrder data format is incorrect!!!";
                }
            }
            if (interface == "GetItemsBySQL")
            {
                qDebug()<< "GetItemsBySQL99999999999999999";
                QVariantList GetItemsBySQLData = result["Data"].toList();
                if (GetItemsBySQLData.isEmpty())
                {
                    qDebug()<< "GetItemsBySQL  failed failed failed failed !!!!";
                    return;
                }
                QVariantMap GetItemsBySQLTest = GetItemsBySQLData.at(0).toMap();
                Payed = GetItemsBySQLTest["Payed"].toBool();
                if (Payed == true)
                {
                    emit PayedSuccess();
                    workRecordInsert = true;
                    UnifiedOrderFlag = false;
                    PreCreateFlag = false;
                }

                qDebug()<< "Payed99999999999999999000000000"<<Payed;

            }
            if (interface == "PreCreate")
            {
                qDebug()<< "PreCreateCCCCCCCCCCCCCCCCCCCCC";
                QVariantMap PreCreateData = result["Data"].toMap();
                int ResultCode = PreCreateData["ResultCode"].toInt();
                if (ResultCode==0)
                {
                    RequestPayment = false;
                    PreCreateFlag = true;
                    qDebug()<<"receive PreCreate data success!!!";
                    Qrstr = PreCreateData["Qr_Code"].toString();
                    qDebug()<<"-------------Qrstr---------------"<<Qrstr;
                    emit Qr_CodeSignal();
                }
                else if (ResultCode==1)
                {
                    qDebug()<<"The PreCreate command number does not exist!!!";
                }
                else if (ResultCode==2)
                {
                    qDebug()<<"PreCreate Database operation failed!!!";
                }
                else if (ResultCode==3)
                {
                    qDebug()<<"The PreCreate data format is incorrect!!!";
                }

            }
            if (interface == "GetPageItemsBySQL")
            {
                qDebug()<< "GetPageItemsBySQLBBBBBBBBBBBBBBB";//
                int TotalRows = result["TotalRows"].toInt();
                if (TotalRows>0)
                {
                    qDebug()<< "GetPageItemsBySQLBBBBBBBBBBBBBBB"<<TotalRows;
                    QVariantList GetPageItemsBySQLData = result["Data"].toList();
                    GetPageItemsBySQLTest = GetPageItemsBySQLData.at(0).toMap();
                    //Payed = GetPageItemsBySQLTest["Payed"].toBool();
                    DocLength = GetPageItemsBySQLTest["DocLength"].toInt();
                    httpDownstate = 1;
                    emit httpDownstateSignal(httpDownstate);
                }
                else
                {
                    qDebug()<<"there is no need to update";
                    httpDownstate = 2;
                    emit httpDownstateSignal(httpDownstate);
                }
            }
            if (interface == "DownloadFile")
            {
                qDebug()<< "DownloadFileCCCCCCCCCCCCCCCCCC";//
                QVariantMap DownloadFileData = result["Data"].toMap();
                //QString DownloadFileDatas = DownloadFileData["Blocks"].toString();
                if (StartPosition==0)
                {
                    system("rm /root/MyDownload/A31");
                }

                QFile file("/root/MyDownload/A31");
                if (file.open(QIODevice::ReadWrite /*| QIODevice::Text*/| QIODevice::Append))
                {

                    //QTextStream stream(&file);
                    QByteArray fileWriteData = (QByteArray::fromBase64(DownloadFileData["Blocks"].toByteArray()));
                    //stream << file_write;
                    file.write(fileWriteData);
                    qDebug()<<"fromBase64fromBase64fromBase64fromBase64fromBase64"<<QByteArray::fromBase64(DownloadFileData["Blocks"].toByteArray()).length();
                    //qDebug()<<"fromBase64fromBase64fromBase64fromBase64fromBase64"<<(QByteArray::fromBase64(DownloadFileData["Blocks"].toByteArray()))<<endl;
                    DownLoadBlocksLength = QByteArray::fromBase64(DownloadFileData["Blocks"].toByteArray()).length();

                    file.close();
                }
                DownSuccessFlag =true;
                /*
                qDebug()<<"fromBase64fromBase64fromBase64fromBase64fromBase64"<<QByteArray::fromBase64(DownloadFileData["Blocks"].toByteArray()).length();
                DownLoadBlocksLength = QByteArray::fromBase64(DownloadFileData["Blocks"].toByteArray()).length();
                DownSuccessFlag =true;
*/
            }
            if (interface == "micropay")
            {
                qDebug()<< "micropayMMMMMMMMMMMMMMMMMMMMMM";
                QVariantMap receiveData = result["Data"].toMap();
                int ResultCode = receiveData["ResultCode"].toInt();
                if (ResultCode==0)
                {
                    RequestPayment = false;
                    //PreCreateFlag = true;
                    emit PayedSuccess();
                    qDebug()<<"receive micropay data success!!!";
                }
                else if (ResultCode==1)
                {
                    qDebug()<<"The micropay command number does not exist!!!";
                }
                else if (ResultCode==2)
                {
                    qDebug()<<"Database operation failed!!!";
                }
                else if (ResultCode==3)
                {
                    qDebug()<<"The data format is incorrect!!!";
                }
            }
            if (interface == "Alipay")
            {
                qDebug()<< "AlipayNNNNNNNNNNNNNNNNNNNNNNN";
                QVariantMap receiveData = result["Data"].toMap();
                int ResultCode = receiveData["ResultCode"].toInt();
                if (ResultCode==0)
                {
                    RequestPayment = false;
                    //PreCreateFlag = true;
                    emit PayedSuccess();
                    qDebug()<<"receive Alipay data success!!!";
                }
                else if (ResultCode==1)
                {
                    qDebug()<<"The Alipay command number does not exist!!!";
                }
                else if (ResultCode==2)
                {
                    qDebug()<<"Database operation failed!!!";
                }
                else if (ResultCode==3)
                {
                    qDebug()<<"The data format is incorrect!!!";
                }
            }
            if (interface == "closeorder")
            {
                qDebug()<< "closeorderAAAAAAAAAAAAAAAAAAAAA";
            }
        }
        else
        {
            qDebug()<< "send req httpRegister failed"<<ResultCode;
            httpDownstate = 4;
        }

    } // Some http error received
    else
    {
        qDebug()<<"GetCurrentTime handle errors here";
        QVariant statusCodeV = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        //statusCodeV是HTTP服务器的相应码，reply->error()是Qt定义的错误码，可以参考QT的文档
        qDebug( "GetCurrentTime found error ....code: %d %d\n", statusCodeV.toInt(), (int)reply->error());
        qDebug()<<reply->errorString();
        httpDownstate = 5;
    }
    reply->deleteLater();
#endif
    lock.unlock();
}

void EthernetHttp::getTokenFun()
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
void EthernetHttp::TerminalPlusFun()
{

    interface = "TerminalPlus";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/TerminalPlus"));

    qDebug()<<"b_Stableb_Stableb_Stableb_Stableb_Stable"<<b_Stable;
    if (b_Stable>0)
    {
        StateCode &= ~(1<<0);
    }
    else
    {
        StateCode |= 1<<0;
    }
    if (canNotSerzero)
    {
        canNotSerzero = false;
        StateCode |= 1<<1;
    }
    else
    {
        StateCode &= ~(1<<1);
    }
    if (canNotKTare)
    {
        canNotKTare = false;
        StateCode |= 1<<2;
    }
    else
    {
        StateCode &= ~(1<<2);
    }
    if (RequestPayment)
    {
        StateCode |= 1<<3;
    }
    else
    {
        StateCode &= ~(1<<3);
        //PayType = 0;
    }
    if (workRecordInsert)//work record insert
    {
        //workRecordInsert =false;
        StateCode |= 1<<4;
    }
    else
    {
        StateCode &= ~(1<<4);
        RecordSerial=0;
    }
    if (lowBatteryFlag)
    {
        StateCode |= 1<<5;
    }
    else
    {
        StateCode &= ~(1<<5);
    }
    if (hardwareProblem)
    {
        hardwareProblem =false;
        StateCode |= 1<<6;
    }
    else
    {
        StateCode &= ~(1<<6);
    }

    QVariantMap dataMap;
    dataMap.insert("Device_Info",Device_Info);
    dataMap.insert("NetWeight",Net);
    dataMap.insert("StateCode",StateCode);
    dataMap.insert("PayType",PayType);
    dataMap.insert("RecordSerial",RecordSerial);

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

void EthernetHttp::SYNCMeterageFun()
{
    interface = "SYNCMeterage";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/SYNCMeterage"));
    //qint8
    QVariantMap dataMap;
    dataMap.insert("RID",RID);
    dataMap.insert("Device_Info",Device_Info);
    dataMap.insert("Seq",Seq);

    dataMap.insert("CalibrateZero",AD_Zero);//标定零点
    dataMap.insert("CalibrateRate",Rri);//标定标率
    dataMap.insert("Range",CalFull);//标定满量程
    dataMap.insert("NonlineaCorrection",1.05);//非线性修正值(待添加)
    dataMap.insert("ADCode",CurData);//AD码值
    dataMap.insert("LastCalibrationTime","2018-10-18 16:04:30");//最后一次标定时间(待添加)
    dataMap.insert("CalibrationTimes",2);//标定次数(待添加)
    dataMap.insert("Division",Rati);//分度值(1,2,5,10,20,50)
    dataMap.insert("Point",Point);//小数位
    dataMap.insert("InitialZero",OnZero);//初始零位
    dataMap.insert("ManualZero",ZeroKeyVal);//手动零位
    dataMap.insert("ZeroTrackingSpeed",3);//零位跟踪速度(待添加)
    dataMap.insert("ZeroTrackingRange",Zono);//零位跟踪范围
    dataMap.insert("FilteringAlgorithm",FilterStep);//滤波算法
    dataMap.insert("BoundaryStrength",StableTime);//滤波强度
    dataMap.insert("stabilize",StableRange);//稳定调节
    dataMap.insert("StabilizeFlag",b_Stable);//稳定标志
    dataMap.insert("NetFlag",b_Net);//净重标志
    dataMap.insert("ZeroFlag",b_Zero);//零位标志
    dataMap.insert("ADSpeed",FilterStep>3?1:0);//AD速率(0,10HZ;1,80HZ)
    dataMap.insert("Alarm",2);//零点过低报警(0:不报警，1：报警)(类型不对应)
    dataMap.insert("AutoSetZero",3);//允许开机置零（0:不允许，1：允许）
    dataMap.insert("Unit",Unit);
    dataMap.insert("PrintRound",4);
    dataMap.insert("ExtMeterage1",true);
    dataMap.insert("ExtMeterage2",true);
    dataMap.insert("ExtMeterage3",1);
    dataMap.insert("ExtMeterage4",2);
    dataMap.insert("ExtMeterage5",3);
    dataMap.insert("ExtMeterage6",4);
    dataMap.insert("ExtMeterage7",5);
    dataMap.insert("ExtMeterage8",6);
    dataMap.insert("TareWeight",Tare);
    dataMap.insert("ExtMeterage10",1);
    dataMap.insert("ExtMeterage11","terwr");
    dataMap.insert("ExtMeterage12","stritwretrwng");
    dataMap.insert("Remark","Remark213");
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
void EthernetHttp::EditMeterageFun()
{
    interface = "EditMeterage";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/EditMeterage"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info",Device_Info);

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

void EthernetHttp::SYNCLocalFun()
{
    interface = "SYNCLocal";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/SYNCLocal"));
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");

    QVariantMap dataMap;
    dataMap.insert("RID",RID);
    dataMap.insert("Device_Info",Device_Info);
    dataMap.insert("Seq",Seq);

    dataMap.insert("CurrentTime",current_date);
    dataMap.insert("A31Version",A31Version);
    dataMap.insert("A31Description","A31Description");
    dataMap.insert("LocalIP",LocalIp);//本机IP地址
    dataMap.insert("TCPServerIp",ServerIp);
    dataMap.insert("TCPServerPort",ServerPort);
    dataMap.insert("UDPServerIp",UDPServerIp);
    dataMap.insert("UDPServerPort",UDPServerPort);
    dataMap.insert("Gateway","192.168.1.1");
    dataMap.insert("netmask","255.255.255.0");
    dataMap.insert("MACaddress","00:0c:29:dc:36:26");
    dataMap.insert("DNSsever","192.168.1.1");
    dataMap.insert("WSSSID","yaohua");
    dataMap.insert("wirelessNetmask","255.255.255.0");
    dataMap.insert("staticGatemay","192.168.1.1");
    dataMap.insert("staticIp","192.168.1.112");
    dataMap.insert("NETPPort","1120");
    dataMap.insert("BatteryVoltage",(int)fvalue);
    dataMap.insert("Brightness",LedLight);
    dataMap.insert("BaudRate_232",BaudRate_232);
    dataMap.insert("DataBits_232",DataBits_232);
    dataMap.insert("ParityMode_232",ParityMode_232);
    dataMap.insert("StopBits_232",StopBits_232);
    dataMap.insert("Tmode_232",Tmode_232);
    dataMap.insert("BaudRate_485",BaudRate_485);
    dataMap.insert("DataBits_485",DataBits_485);
    dataMap.insert("ParityMode_485",ParityMode_485);
    dataMap.insert("StopBits_485",StopBits_485);
    dataMap.insert("Tmode_485",Tmode_485);
    dataMap.insert("Addr_485",Addr);
    dataMap.insert("PrintMode",PrintMode);
    dataMap.insert("PrintLq",PrintLq);
    dataMap.insert("b_PrintRetZero",b_PrintRetZero);
    dataMap.insert("b_PrintStable",b_PrintStable);
    dataMap.insert("b_Save",b_Save);
    dataMap.insert("b_PrintAuto",b_PrintAuto);
    dataMap.insert("PrintLableSize",PrintLableSize);
    dataMap.insert("PrintCodeType",PrintCodeType);
    dataMap.insert("PrintLeadZero",1);//此变量没有找到
    dataMap.insert("PrintCompanyName","上海耀华称重系统有限公司");
    dataMap.insert("PrintCompanyWebsite",CompanyWebsite);
    dataMap.insert("PrintCompanyAddr",CompanyAddr);
    dataMap.insert("PrintCompanyTel",CompanyTel);
    dataMap.insert("PrintCompanyLabel",CompanyLabel);
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
    dataMap.insert("NetWeight",Net);
    dataMap.insert("StateCode",StateCode);//StateCode
    dataMap.insert("PayType",PayType);
    dataMap.insert("RecordSerial",RecordSerial);
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

void EthernetHttp::EditLocalFun()
{
    interface = "EditLocal";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/EditLocal"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info",Device_Info);

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

void EthernetHttp::SYNCRunFun()
{
    interface = "SYNCRun";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/SYNCRun"));

    QVariantMap dataMap;
    dataMap.insert("RID",RID);
    dataMap.insert("Device_Info",Device_Info);
    dataMap.insert("Seq",Seq);

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

void EthernetHttp::EditRunFun()
{
    interface = "EditRun";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Parameters/EditRun"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info",Device_Info);

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

void EthernetHttp::InsertRecordFun()
{
    interface = "InsertRecord";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Record/InsertRecord"));

    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss");
    QString timeStart =str;
    QString timeEnd =str;

    QVariantMap dataMap;
    dataMap.insert("RID",RID);
    dataMap.insert("Device_Info",Device_Info);
    dataMap.insert("Seq",Seq);

    dataMap.insert("TerminalName","A310010");
    dataMap.insert("RecordType",1);//记录类型：1-商业，2-计数，3-检重（上下限）秤，4-动物（畜牧）秤
    dataMap.insert("classesID",1);//交易笔数
    dataMap.insert("RecordSerial",InsertRecordTimes+1);//流水号（每次加1）
    dataMap.insert("timeStart",timeStart);
    dataMap.insert("timeEnd",timeEnd);
    dataMap.insert("NetWeight",NetWeight);//净重
    dataMap.insert("TareWeight",NetWeight);//皮重
    dataMap.insert("unit",Unit);//重量单位
    dataMap.insert("point",Point);//重量小数点位数
    dataMap.insert("goods",goods);//物品描述
    dataMap.insert("customer","yaohua");//客户描述
    dataMap.insert("Remark","delicious");//备注
    dataMap.insert("operatorID",operatorID);//操作员ID
    dataMap.insert("goodsID",goodsID);//物品ID
    dataMap.insert("photo1",1);
    dataMap.insert("Photo2",2);
    dataMap.insert("unitprice",unitprice);//单价
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

void EthernetHttp::UnifiedOrderFun()
{
    interface = "UnifiedOrder";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/OnlinePay/Wechat/UnifiedOrder"));

    QVariantMap dataMap;
    //dataMap.insert("RID",RID);
    dataMap.insert("Device_Info",Device_Info);
    //dataMap.insert("Seq",Seq);
    dataMap.insert("appid","2018");
    dataMap.insert("goods_detail",goods);
    dataMap.insert("out_trade_no",out_trade_no);
    //dataMap.insert("total_amount",Rectotal_money);
    dataMap.insert("total_amount",0.01);

    //    dataMap.insert("appid","2018");
    //    dataMap.insert("body","good");
    //    dataMap.insert("out_trade_no","1");
    //    dataMap.insert("total_fee","31");
    //    dataMap.insert("Closed",true);
    //    dataMap.insert("ClosedBy","0");
    //    dataMap.insert("ClosedName","0");
    //    dataMap.insert("ClosedOn","0");
    //    dataMap.insert("Payed",true);
    //    dataMap.insert("PayedBy","0");
    //    dataMap.insert("PayedName","0");
    //    dataMap.insert("PayedOn","0");
    //    dataMap.insert("Remark","1");
    //QVariantList ChangeList;
    //ChangeList.append("ChangeListgssfdjhffd");
    //dataMap.insert("ChangeList",ChangeList);


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
void EthernetHttp::GetItemsBySQLFun()
{
    interface = "GetItemsBySQL";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/Payment/GetItemsBySQL"));

    QString temp = "t.out_trade_no='"+out_trade_no+"'";

    QVariantMap dataMap;
    dataMap.insert("SQL",temp);

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json GetItemsBySQL"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void EthernetHttp::closeorderFun()
{
    interface = "closeorder";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/OnlinePay/Wechat/closeorder"));

    QVariantMap dataMap;
    dataMap.insert("closeorder","0");
    dataMap.insert("appid","2018");
    dataMap.insert("out_trade_no",out_trade_no);

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

void EthernetHttp::syncParameterSlot()
{
    SYNCLocalFun();
    SYNCMeterageFun();
}

void EthernetHttp::GetPageItemsBySQL()
{
    interface = "GetPageItemsBySQL";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/FileExtend/GetPageItemsBySQL"));

    QVariantMap dataMap;
    //dataMap.insert("SQL","t.FromBill='S20.Bas.Entity.SyncLocalExtend' And t.FromHRID='A31' And t.DocName='201703291652163901.jpg' And t.RID='1810300008'");
    dataMap.insert("SQL","t.FromBill='S20.Bas.Entity.SyncLocalExtend' And t.FromHRID='A31' And t.DocName='A12'");
    //dataMap.insert("SQL","");S20.Bas.Entity.SyncLocalExtend
    dataMap.insert("PageSize",2);
    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json GetPageItemsBySQL"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void EthernetHttp::DownloadFile()
{
    DownSuccessFlag =false;
    httpDownstate = 6;
    interface = "DownloadFile";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/FileExtend/DownloadFile"));

    //GetPageItemsBySQLTest;
    //QVariantMap dataMap;
    StartPosition = StartPosition + DownLoadBlocksLength;
    GetPageItemsBySQLTest.insert("IsFirst",false);
    GetPageItemsBySQLTest.insert("LocalFile","");
    GetPageItemsBySQLTest.insert("StartPosition",StartPosition);
    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(GetPageItemsBySQLTest, &ok);
    qDebug()<<"json DownloadFile"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}

void EthernetHttp::updateApplicationSlot()
{
    GetPageItemsBySQL();
}

void EthernetHttp::PreCreateFun()
{
    interface = "PreCreate";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/OnlinePay/Alipay/PreCreate"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info",Device_Info);
    dataMap.insert("appid","2018");
    dataMap.insert("goods_detail",goods);
    dataMap.insert("out_trade_no",out_trade_no);
    //dataMap.insert("total_amount",Rectotal_money);
    dataMap.insert("total_amount",0.01);

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json PreCreate"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}
void EthernetHttp::micropayFun()
{
    interface = "micropay";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/OnlinePay/Wechat/micropay"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info",Device_Info);
    dataMap.insert("appid","2018");
    dataMap.insert("goods_detail",goods);
    dataMap.insert("out_trade_no",out_trade_no);
    dataMap.insert("Auth_Code",Auth_Code);
    dataMap.insert("total_amount",0.01);

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json micropay"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}
void EthernetHttp::AlipayFun()
{
    interface = "Alipay";
    request.setUrl(QUrl("http://54.174.130.220:18010/api/OnlinePay/Alipay/pay"));

    QVariantMap dataMap;
    dataMap.insert("Device_Info",Device_Info);
    dataMap.insert("appid","2018");
    dataMap.insert("goods_detail",goods);
    dataMap.insert("out_trade_no",out_trade_no);
    dataMap.insert("Auth_Code",Auth_Code);
    dataMap.insert("total_amount",0.01);

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(dataMap, &ok);
    qDebug()<<"json Alipay"<<json;

    request.setRawHeader("Authorization",TokenData.toUtf8());//服务器要求的数据头部
    request.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    request.setHeader(QNetworkRequest::ContentLengthHeader, json.length());
    QNetworkReply* reply = nam->post(request, json);
    reply->ignoreSslErrors();
}
void EthernetHttp::RecCodeDataSlot()
{
    Auth_Code = QRcodeTemp;
    //qDebug()<<"Auth_Code----------------------------"<<Auth_Code;
    //qDebug()<<"Auth_Code.length()-------------------"<<Auth_Code.length();

    if (QRcodeType==1)
    {
        //微信扫码成功 支付中
        micropayFun();
        receiveStates = false;
    }
    else if (QRcodeType==2)
    {
        //支付宝扫码成功 支付中
        AlipayFun();
        receiveStates = false;
    }
    else
    {
        //无效码!!!

    }
    //AlipayFun();
}
