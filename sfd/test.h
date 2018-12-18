#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QDebug>
#include "./json/serializer.h"
#include "./json/parser.h"
#include <QNetworkRequest>
#include <QTimer>
#include <QTime>
extern QString TokenData;
extern QString interface;

extern int CalibrateZero;
extern float CalibrateRate;
extern float Range;
extern float NonlineaCorrection;
extern int ADCode;
extern QString LastCalibrationTime;
extern int CalibrationTimes;
extern unsigned char Division;
extern unsigned char Point;
extern unsigned char InitialZero;
extern unsigned char ManualZero;
extern unsigned char ZeroTrackingSpeed;
extern unsigned char ZeroTrackingRange;
extern unsigned char FilteringAlgorithm;
extern unsigned char BoundaryStrength;
extern unsigned char stabilize;
extern bool StabilizeFlag;
extern bool NetFlag;
extern bool ZeroFlag;
extern bool ADSpeed;
extern bool Alarm;
extern bool AutoSetZero;
extern bool Unit;
extern bool PrintRound;
extern bool ExtMeterage1;
extern bool ExtMeterage2;
extern unsigned char ExtMeterage3;
extern unsigned char ExtMeterage4;
extern int ExtMeterage5;
extern int ExtMeterage6;
extern int ExtMeterage7;
extern int ExtMeterage8;
extern float TareWeight;
extern float ExtMeterage10;
extern QString ExtMeterage11;
extern QString ExtMeterage12;

namespace Ui {
class MainWindow;
}
class RESULT
{
public:
    bool isSuccess;
    QVariantMap Result;
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    QNetworkAccessManager *nam;
    QNetworkRequest request;
    bool TIMEOUT;

public slots:
    void replyFinished(QNetworkReply* reply);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_12_clicked();
};

#endif // MAINWINDOW_H
