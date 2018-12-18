#ifndef ROOTDIALOG_H
#define ROOTDIALOG_H
#include "printer.h"
#include <QDialog>
#include "mainwindow.h"
#include "configsetting.h"
#include "business.h"
#include "cali.h"
#include "printport.h"
#include <GlobalVarible.h>
#include "dataexport.h"
#include "user.h"
#include "remotemysql.h"
#include "networkcommunication.h"
#include "udpcommunication.h"
#include "commthread.h"
#include "buzzer.h"
#include "adthread.h"
#include "loadbig.h"
#include "userlogindialog.h"
#include "printthread.h"
#include "ethernethttp.h"

namespace Ui {
class rootdialog;
}

class rootdialog : public QDialog
{
    Q_OBJECT

public:
    explicit rootdialog(QWidget *parent = 0);
    ~rootdialog();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

private slots:
    void receiveFormMode(void);
    void receiveFormMode1(void);
    void receiveFormMode2(void);
    void keyScan(void);
    /*void BaudRateUpdateFor485();
    void StopBitsUpdateFor232();
    void StopBitsUpdateFor485();
    void ParityUpadateFor232();
    void ParityUpadateFor485();
    void DataBitsUpdateFor232();
    void DataBitsUpdateFor485();
    void TmodeUpdateFor232(void);
    void SendModbus(void);*/
    //void TmodeUpdateFor485(void);
    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();
    void changetoRootDialog();
    void changemaintoRootdialog();
public slots:
    void closeDialog();
    void reboot();
    void poweroff();
public:
    void initLocal(void);
    void showBusiness(void);


private:
    Ui::rootdialog *ui;
public:
    int i;
    //PrintPort *myCom;
    MainWindow *wx;
    configSetting *confSet;
    Printer *printer;
    //Mode *mode;
    Business *business;
    cali* tempCali;
    QTimer *tempTimer;
    //QTimer *obotimer;
    About *about;
    User *UserSet;
    mysqlSheet *mysqlsheet;
    DataExport *dataexport;
signals:
    void sentToMainwindow(void);
    void sentToMainwindowzero(void);
    void sentToMainwindowtare(void);
    void sendToConfigsetting(void);
    //void sendToMode(void);
    void sendToPrinter(void);
    void sendToBusiness(void);
    void sendToSheet(void);
    void sendToAbout(void);
    void sendToDataExport(void);
    void sendToClose(void);
    void sendToUsers(void);
private:
    /*remoteMysql *remotemysql;
    NetworkCommunication *networkCommunication;
    UDPCommunication *udpCommunition;*/
    EthernetHttp *ethernetHttp;
    commthread *comm;
    Printthread *print;
  // buzzer *bell;

    QPushButton *pushButton_reboot;
    QPushButton *pushButton_poweroff;
    QPushButton *pushButton_blur;
  //  buzzer *bell;
   AdThread *adThread;
    LoadBig *loadBig;
private slots:
   void SetZeroSlot();
   void KTareSlot();



};

#endif // ROOTDIALOG_H
