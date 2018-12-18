#ifndef BUZZER_H
#define BUZZER_H

#include <QObject>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
//#include <QDir>
#include <QDate>
#include "printport.h"

class buzzer : public QObject
{
    Q_OBJECT
public:
    explicit buzzer(QObject *parent = 0);
    
signals:
public:
    int fd_buzzer;
    void buzzerscan();
public slots:
    void buzzerthreadstart();
    //void buzzerTimer();
private:
    QThread m_thread;
    QTimer BuzzerTimer;
public slots:
    
};

#endif // BUZZER_H
