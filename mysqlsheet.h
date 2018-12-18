#ifndef MYSQLSHEET_H
#define MYSQLSHEET_H

#include <QWidget>
#include <GlobalVarible.h>
#include <QDate>
#include <QMessageBox>
#include <QDialogButtonBox>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
//#include "printport.h"
//#include "cali.h"
namespace Ui {
class mysqlSheet;
}

class mysqlSheet : public QWidget
{
    Q_OBJECT
    
public:
    explicit mysqlSheet(QWidget *parent = 0);
    ~mysqlSheet();
    
private slots:
    void on_toolButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_toolButton_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_11_clicked();

    void on_toolButton_12_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_13_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_14_clicked();

    void on_toolButton_15_clicked();

    void on_toolButton_16_clicked();

    void on_toolButton_17_clicked();

    void on_toolButton_18_clicked();

    void on_toolButton_19_clicked();

    void on_toolButton_20_clicked();

    void on_toolButton_21_clicked();

    void on_toolButton_22_clicked();

    void fromRootdialog(void);
    void on_toolButton_23_clicked();

    void on_toolButton_24_clicked();

    void on_toolButton_25_clicked();

    void on_toolButton_26_clicked();

    void on_toolButton_27_clicked();

    void on_toolButton_28_clicked();

    void on_toolButton_29_clicked();

private:
    Ui::mysqlSheet *ui;
public:
    void sqlinit();
    void sqlinsert();

public:
    QSqlDatabase db;
    QSqlQuery query,query1;
    int thepage,pages;
    QString thepages;
    QSqlQueryModel *model;
    QString condition,conditionNum;
signals:
 void PrintDailySignal();
 void PrintMonthSignal();
 void PrintAllSignal();
 void PrintProductSignal();
 void PrintUserSignal();
 void PrintUserSeniorSignal();
 void PrintProductSeniorSignal();
 void PrintSqlSignal();
public slots:
    void dataOutputcsv();
    void dataOutputxls();
};
#endif // MYSQLSHEET_H

