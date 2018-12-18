#ifndef NETWORKCOMMUNICATION_H
#define NETWORKCOMMUNICATION_H

#include <QObject>
#include <QTimer>
#include <QTcpSocket>
#include <QThread>
#include <QSettings>
#include <GlobalVarible.h>
class NetworkCommunication : public QObject
{
    Q_OBJECT
public:
    explicit NetworkCommunication(QObject *parent = 0);

signals:

public slots:
    void networkCommunicationStart();
    void timerFuncXS();
    void revServerData();
    void disConnectDO();
    void receiveFromSetting();
public:
    void NetworkConnects();
    void NetworkSend(QByteArray sendBuf);

private:
    QThread NetworkCommunicationThread;
    QTcpSocket *tcpSocket;
    QTimer *timer5000ms;
    bool NetworkLinkFlag;
    int aliveCount;

};

#endif // NETWORKCOMMUNICATION_H
