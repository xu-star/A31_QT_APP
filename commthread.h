#ifndef COMMTHREAD_H
#define COMMTHREAD_H

#include <QObject>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
//#include <QDir>
#include <QDate>
#include "printport.h"

class commthread : public QObject
{
    Q_OBJECT
public:
    explicit commthread(QObject *parent = 0);
    
signals:
    void SendCodeDataToOther();
public:
    PrintPort *myCom1;
    QTimer *obotimer;
    QTimer *CommTimer;
    void init(void );
public slots:
    void commthreadstart();
    void commTimer();
   
    void sendMsg();
    void BaudRateUpdateFor232();
    void BaudRateUpdateFor485();
    void StopBitsUpdateFor232();
    void StopBitsUpdateFor485();
    void ParityUpadateFor232();
    void ParityUpadateFor485();
    void DataBitsUpdateFor232();
    void DataBitsUpdateFor485();
    void TmodeUpdateFor232(void);
    void CommTypeUpdate();
    void SendModbus(void);
    void SendCodeData(void);
    void PrintNet(void);
private:
    QThread m_thread;
    
};

#endif // COMMTHREAD_.
