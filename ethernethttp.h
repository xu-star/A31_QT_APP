#ifndef ETHERNETHTTP_H
#define ETHERNETHTTP_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QDebug>
#include "./json/serializer.h"
#include "./json/parser.h"
#include <QNetworkRequest>
#include <QThread>
#include <GlobalVarible.h>
#include <business.h>
#include "mainwindow.h"
#include <QReadWriteLock>
class EthernetHttp : public QObject
{
    Q_OBJECT
public:
    explicit EthernetHttp(QObject *parent = 0);

signals:
    void SetZeroSignal();
    void KTareSignal();
    void Qr_CodeSignal();
    void PayedSuccess();
    void updateEditLocalSignal();
    void updateEditMeterageSignal();
    void httpDownstateSignal(int state);
public slots:
    void replyFinished(QNetworkReply* reply);
    void ethernetHttpInit();
    void ethernetHttpSlot();
    void ethernetHttpSlot1();
    void syncParameterSlot();
    void GetPageItemsBySQL();
    void DownloadFile();
    void updateApplicationSlot();
    void RecCodeDataSlot();
private:
    QNetworkAccessManager *nam;
    QNetworkRequest request;
    QThread m_threadhttp;
    QTimer *m_pTimerhttp;
    QTimer *tempTimer;
    int StateCode;
    bool PayACK;
    bool RecordACK;
    bool ParametersSYNCMeterage;
    bool ParametersEditMeterage;
    bool ParametersSYNCLocal;
    bool ParametersEditLocal;
    bool ParametersSYNCRun;
    bool ParametersEditRun;
    bool TerminalPlusFlag;
    bool AccountFlag;
    bool AccountFlag1;
    bool AccountFlag2;
    bool UnifiedOrderFlag;
    bool PreCreateFlag;
    bool Payed;
    float NetWeight;
    QString goods;
    int goodsID;
    QString unitprice;
    QVariantMap GetPageItemsBySQLTest;
    int DownLoadBlocksLength;
    bool DownSuccessFlag;
    QReadWriteLock lock;
    bool receiveStates;
    uchar tempChar;
public:
    void getTokenFun();
    void TerminalPlusFun();
    void SYNCMeterageFun();
    void EditMeterageFun();
    void SYNCLocalFun();
    void EditLocalFun();
    void SYNCRunFun();
    void EditRunFun();
    void InsertRecordFun();
    void UnifiedOrderFun();
    void GetItemsBySQLFun();
    void closeorderFun();

    void PreCreateFun();
    void micropayFun();
    void AlipayFun();
};

#endif // ETHERNETHTTP_H
