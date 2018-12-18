#include "adthread.h"

AdThread::AdThread(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&ad_thread);
    b_ykj=0;
     Adcal.Initial();
    ad_thread.start();

}
void AdThread::Adinit()
{
    qDebug() <<"AdThread thread start!!";
    connect(&LogTimer, SIGNAL(timeout()), this, SLOT(AdSlot()));
    connect(&LogTimer1, SIGNAL(timeout()), this, SLOT(AdSlot1()));
      if(FilterStep==4)
    LogTimer.start(10);
          else
    LogTimer.start(60);
    LogTimer1.start(10000);
}

void AdThread::AdSlot()
{
    AdData=Adcal.RD1232();
    if(b_newad){
    if(FilterStep==1)
        Adcal.AdFilter();
    else if(FilterStep==2)
        Adcal.AdFilter1();
    else if(FilterStep==3)
        Adcal.AdFilter2();
    else
        Adcal.AdFilter();
    Adcal.CalWeigh();
    Adcal.Load_Big();
    if(!b_ykj){
    Adcal.StartZero(OnZero);
    Start_Zero=AD_Zero;
    b_ykj=1;
    }
    }

}
void AdThread::AdSlot1()
{

    Adcal.BtRead();
}
void AdThread::adspeedSlot()
{
    LogTimer.stop();
    if(FilterStep==4)
    {
  ADS1232_SET_SPS80;
  LogTimer.start(10);
    qDebug() <<"AdThread thread start 10ms!!";
    }
 else
    {
  ADS1232_SET_SPS10;
  LogTimer.start(60);
    qDebug() <<"AdThread thread start 100ms!!";
}
}
