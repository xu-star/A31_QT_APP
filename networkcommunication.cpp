#include "networkcommunication.h"
NetworkCommunication::NetworkCommunication(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&NetworkCommunicationThread);
    NetworkCommunicationThread.start();
}
void NetworkCommunication::networkCommunicationStart()
{
    qDebug() << "NetworkCommunicationThread thread start";
    NetworkLinkFlag = false;
    aliveCount = 1;
    timer5000ms=new QTimer;
    tcpSocket = new QTcpSocket;
    connect(timer5000ms,SIGNAL(timeout()),this,SLOT(timerFuncXS()));
    connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(revServerData()));
    connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(disConnectDO()));
    NetworkConnects();
    timer5000ms->start(1000);

    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    ServerIp = configIniRead->value("baseinfo/ServerIp").toString();
    ServerPort = configIniRead->value("baseinfo/ServerPort").toInt();
    UDPServerIp = configIniRead->value("baseinfo/UDPServerIp").toString();
    UDPServerPort = configIniRead->value("baseinfo/UDPServerPort").toInt();
    delete configIniRead;

    //SendtoTCP = "ST,NT0+10.000kg0D0A";
}
void NetworkCommunication::NetworkConnects()
{
    tcpSocket->abort(); //取消已有的连接
    tcpSocket->connectToHost(ServerIp,ServerPort); //连接到主机，这里从界面获取主机地址和端口号
    //tcpSocket->connectToHost("192.168.1.10",102); //连接到主机，这里从界面获取主机地址和端口号
    tcpSocket->waitForConnected(2000); //waitting 2000ms
    //qDebug() << "NetworkCommunication connect waiting>>>>>>>>"<< tcpSocket->state();
    if(tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        //qDebug() << "NetworkCommunication connect success!!!!!!!!!!!!!";
        //ctlPLCHandle(startCmdBuf1,true);
    }
    else
    {
        //qDebug() << "NetworkCommunication connect fail?????????????????" ;
    }
}
void NetworkCommunication::timerFuncXS()
{
    if(aliveCount > 2)
    {
        aliveCount = 0;
        NetworkLinkFlag = false;
        NetworkConnects();
    }
    aliveCount++ ;
    if (aliveCount<=1)
    NetworkSend(SendtoTCPUDP);
  //  qDebug() << "aliveCount"<<aliveCount;
}
void NetworkCommunication::revServerData()
{
    int revLen;
    QByteArray recBuf;
    recBuf = tcpSocket->readAll();
    revLen = recBuf.size();
    //qDebug() << "NetworkCommunication receive len:" << revLen << "data:" << recBuf;//.toHex();
    aliveCount = 0;
}
void NetworkCommunication::disConnectDO()
{
    NetworkLinkFlag = false;
    NetworkConnects();
}
void NetworkCommunication::NetworkSend(QByteArray sendBuf)
{
    int Tx_len=0;
    Tx_len = sendBuf.size();

    tcpSocket->write(sendBuf,Tx_len);
    if(tcpSocket->waitForBytesWritten() == false)
    {

    }
    //qDebug() << "NetworkCommunication send    len:" << Tx_len << "data:" << sendBuf.toHex();
}
void NetworkCommunication::receiveFromSetting()
{
    qDebug()<<"receiveFromSetting!!!!!!!!!!!!!!!!";
    QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    ServerIp = configIniRead->value("baseinfo/ServerIp").toString();
    ServerPort = configIniRead->value("baseinfo/ServerPort").toInt();
    UDPServerIp = configIniRead->value("baseinfo/UDPServerIp").toString();
    UDPServerPort = configIniRead->value("baseinfo/UDPServerPort").toInt();
    delete configIniRead;
    disConnectDO();
}
