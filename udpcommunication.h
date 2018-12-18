#ifndef UDPCOMMUNICATION_H
#define UDPCOMMUNICATION_H

#include <QObject>
#include <QTimer>
#include <QUdpSocket>
#include <QThread>
#include <GlobalVarible.h>
class UDPCommunication : public QObject
{
    Q_OBJECT
public:
    explicit UDPCommunication(QObject *parent = 0);

signals:

public slots:
    void udpTimer();
    void udpThreadStart();
private:
    QTimer *UDPTimer;
    QUdpSocket *udpSocket;
    QThread udpThread;
public:
};

#endif // UDPCOMMUNICATION_H
