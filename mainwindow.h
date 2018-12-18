#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QTextCodec>
#include "configsetting.h"
#include "numkeyboard.h"
extern int aaa;
extern bool lowBatteryFlag;
extern bool hardwareProblem;
#include "cali.h"
#include <GlobalVarible.h>
/***************************/
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <assert.h>
#include <linux/videodev2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/signal.h>
#include <linux/watchdog.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>
#define ADS1232_SET_SPS80		ioctl(fd_ads1232, 0, 1)
#define ADS1232_SET_SPS10		ioctl(fd_ads1232, 0, 0)*/
/***************************/
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QTimer pingTimer,pingTimer1;
    //unsigned int count;
    NumKeyboard *numKeyboard;
    bool maxflag;
    bool mixflag;
    bool countflag;
    bool Accflag;
    QString xiaxian1;
    QString shangxian1;
    QString jishu;
     QString jishu2;
    bool ColorFlag;
    bool ColorFlagX;
    bool ColorFlagY;
    bool ColorFlagZ;


public:
    long count;
    long Counttemp;
    int count1,GrossWeight;
    cali cal;
    void main_init(void);
    bool eventFilter(QObject *obj, QEvent *event);
public slots:
    void pingTimerSlot();
    void timerUpdate();
    void pingTimerSlot1();
    void fromRootdialog(void);
    void fromRootdialogzero(void);
    void fromRootdialogtare(void);

private slots:
  // void on_pushButton_10_clicked();
  //  void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void setMaxAndMix(QString maxmin);
     void on_pushButton_7_clicked();
     void on_pushButton_11_clicked();
     void on_pushButton_9_clicked();

     void on_label_21_linkActivated(const QString &link);

     void on_pushButton_13_clicked();

     void on_pushButton_14_clicked();

     void on_pushButton_15_clicked();

     void on_label_99_linkActivated(const QString &link);

     void on_lcdNet_overflow();

signals:
     void printnetsignal();
     void sendtoRootdialog();
};

#endif // MAINWINDOW_H
