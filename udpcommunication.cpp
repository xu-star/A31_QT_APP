#include "udpcommunication.h"

UDPCommunication::UDPCommunication(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&udpThread);
    udpThread.start();
}

void UDPCommunication::udpThreadStart()
{
    qDebug() << "udpThreadStart thread start";

    udpSocket = new QUdpSocket;

    UDPTimer =new QTimer;
    connect(UDPTimer,SIGNAL(timeout()),this,SLOT(udpTimer()));
    UDPTimer->start(1000);

}

void UDPCommunication::udpTimer()
{
    QString tempGross = "ST,NT0"+QString::number(Gross)+".00kg0D0A";
    QByteArray datagram=tempGross.toLatin1();
    //QByteArray datagram = "ST,NT0+10.000kg0D0A";
    //udpSocket->writeDatagram(datagram.data(),QHostAddress("192.168.1.10"),103);
    //udpSocket->writeDatagram(SendtoTCPUDP.data(),UDPServerIp,UDPServerPort);
    udpSocket->writeDatagram(datagram.data(),QHostAddress(UDPServerIp),103);
}
