#ifndef ADTHREAD_H
#define ADTHREAD_H
#include "cali.h"
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QObject>


class AdThread : public QObject
{
    Q_OBJECT
public:
    explicit AdThread(QObject *parent = 0);
    
signals:
public:
      cali Adcal;
public slots:
    void Adinit();
    void AdSlot();
     void AdSlot1();
     void adspeedSlot();

private:
    QThread ad_thread;
    QTimer LogTimer;
    QTimer LogTimer1;
    
};

#endif // ADTHREAD_H
