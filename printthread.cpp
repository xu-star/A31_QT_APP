#include "printthread.h"

Printthread::Printthread(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&p_thread);
    p_thread.start();
}

void Printthread::printthreadstart()
{
    qDebug() <<"Printhread start!!";
    myCom = new PrintPort();
    //obotimer = new QTimer(this);


    init_print();
    //connect(myCom,SIGNAL(hasdata()),this,SLOT(SendModbus()));

    
    QString portName = "/dev/ttyS0" ;
    

   
    myCom->openPort(portName,
                    4,
                    0,
                    0,
                    0,
                    0,10);
 
    
}

void Printthread::init_print()
{

}




void Printthread::printmyrecord()
{
    qDebug() << "printmyrecord" << endl;
    myCom->printwrite2();
    //productCashNum=0;
    //myCom->Price2UartData(5.6);
}


void Printthread::printDaily()
{
    qDebug() << "printDailyReport" << endl;
    myCom->PrintDailyReport();
}

void Printthread::printMonth()
{
    qDebug() << "printMonthReport" << endl;
    myCom->PrintMonthReport();
}

void Printthread::printAll()
{
   qDebug() << "printAllReport" << endl;
    myCom->PrintAllReport();
}

void Printthread::printProduct()
{
   qDebug() << "printProductReport" << endl;
    myCom->PrintProductReport();
}

void Printthread::PrintProductSenior()
{
   qDebug() << "printProductSeniorReport" << endl;
    myCom->PrintProductSeniorReport();
}

void Printthread::printUser()
{
   qDebug() << "printUserReport" << endl;
    myCom->PrintUserReport();
}

void Printthread::printUserSenior()
{
   qDebug() << "printUserSeniorReport" << endl;
    myCom->PrintUserSeniorReport();
}



void Printthread::printnet()
{
    qDebug() << "printnet" << endl;
    myCom->printwrite();
    //productCashNum=0;
    
}

void Printthread::printSqlSheet()
{
    qDebug() << "printSqlSheet" << endl;
    myCom->PrintSqlSheet();
}