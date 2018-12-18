#ifndef PRINTTHREAD_H
#define PRINTTHREAD_H

#include <QObject>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
//#include <QDir>
#include <QDate>
#include "printport.h"

class Printthread : public QObject
{
    Q_OBJECT
public:
    explicit Printthread(QObject *parent = 0);
    
signals:
public:
    PrintPort *myCom;
   // QTimer *obotimer;
    void init_print(void );
public slots:
     void printthreadstart();
     void printmyrecord();
     void printDaily();
     void printMonth();
     void printAll();
     void printProduct();
     void PrintProductSenior();
     void printUser();
     void printUserSenior();
    //void QrComm();
    void printnet();
    void printSqlSheet();
private:
    QThread p_thread;

};

#endif // PRINTTHREAD_H
