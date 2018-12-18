#ifndef BUSINESS_H
#define BUSINESS_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <GlobalVarible.h>
#include "cali.h"
#include "showproduct.h"
#include <QMessageBox>
extern bool RequestPayment;
extern bool workRecordInsert;
extern bool PaySuccess;
extern QString out_trade_no;
extern unsigned char PayType;
extern  int RecordSerial;
extern QString Device_Info;
extern QString RID;
extern QString Seq;
namespace Ui {
class Business;
}

class Business : public QWidget
{
    Q_OBJECT
    
public:
    explicit Business(QWidget *parent = 0);
    ~Business();
signals:
   void printrecord();
   void QrChange();
   void sendToRemoteMysql(QString userID,QString productName,QString productPrice,QString productWeight,QString productDsc,QString productID);
    void sendtoRootdialog();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();
    void keyJudje(void);
    void on_pushButton_30_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_31_clicked();

    void on_toolButton_13_clicked();

    void on_pushButton_40_clicked();

    void on_toolButton_12_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_41_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_42_clicked();

    void on_pushButton_43_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_44_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_50_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_55_clicked();

private:
    Ui::Business *ui;
     QTimer *Timer;
     //QStandardItemModel  *model;
    //signals:
    //void changeToBusiness(void);
public:
    //void keyPressEvent(QKeyEvent * event);
    //void keyReleaseEvent(QKeyEvent * event);
    QTimer *longPushbuttonTimer;
    bool keyJudjeFlag;
    float temptotalcash;
    float tempdis;
public:
    void structData_init(void);
    void GenerateQRcode(QString tempstr);
    void delete_array();
    void pushbutton_show_and_hide();
public slots:
    void TimerSlot();
    void fromRootdialog(void);
    void Qr_CodeSlot();
    void PaySuccessSlot();
    void RecCodeData();
};

#endif // BUSINESS_H
