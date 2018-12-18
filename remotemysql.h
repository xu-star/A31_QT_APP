#ifndef REMOTEMYSQL_H
#define REMOTEMYSQL_H

#include <QObject>
#include <QThread>
#include "GlobalVarible.h"
#include <QMessageBox>
class remoteMysql : public QObject
{
    Q_OBJECT
public:
    explicit remoteMysql(QObject *parent = 0);

signals:

public slots:
    void remoteMysqlStart();
    void remoteMysqltimerFuncXS();
    void receiveFromBusiness(QString userID,QString productName,QString productPrice,QString productWeight,QString productDsc,QString productID);
private:
    QThread remoteMysqlThread;
    QSqlDatabase db1;
    QTimer *timer3000ms;
    QSqlQuery query;

};

#endif // REMOTEMYSQL_H
