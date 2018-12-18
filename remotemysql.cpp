#include "remotemysql.h"

remoteMysql::remoteMysql(QObject *parent) :
    QObject(parent)
{
    this->moveToThread(&remoteMysqlThread);
    remoteMysqlThread.start();
}

void remoteMysql::remoteMysqlStart()
{
    qDebug() << "remoteMysqlThread thread start";
    timer3000ms=new QTimer;

    /*if(QSqlDatabase::contains("mysql")){
        db1 = QSqlDatabase::database("mysql");
    }else{
        db1=QSqlDatabase::addDatabase("QMYSQL","mysql");
        db1.setHostName("192.168.1.2");
        db1.setDatabaseName("weight");
        db1.setUserName("root");
        db1.setPassword("123456");
        query = QSqlQuery(db1);
    }*/

    db1 = QSqlDatabase::addDatabase("QMYSQL","mysql");
    //db1 = QSqlDatabase::addDatabase("QMYSQL","mysql_connection");
    //db1 = QSqlDatabase::addDatabase("QMYSQL");
    db1.setHostName("192.168.1.2");
    db1.setUserName("root");
    db1.setPassword("123456");
    db1.setDatabaseName("weight");
    query = QSqlQuery(db1);
    if (!db1.open())
    {
        //QMessageBox::warning(this,"QMYSQL","open error");
        qDebug()<< "remoteMysqlStart open"<<db1.lastError().text();
        return;
    }
    //QSqlQuery query;
    bool flag = query.exec(
                "create table IF NOT EXISTS productData(RecordID int unsigned not null primary key auto_increment,userID char not null,productNum int unsigned not null,productName VARCHAR(30) not null, productPrice real not null, productWeight real not null,productDescribe VARCHAR(30) null,created_at timestamp not NULL DEFAULT CURRENT_TIMESTAMP) CHARSET=utf8;");

    //if (query.exec(sql))
    if (flag)
    {
        qDebug() << "db1 creat table ok";
    }
    else
    {
        QSqlError error = query.lastError();
        qDebug()<< "remoteMysqlStart creat table"<< error.text();/*db2.lastError().text();*/
        //QMessageBox::warning(this,"create error", QString("the error is:")+error.databaseText());
    }

    connect(timer3000ms,SIGNAL(timeout()),this,SLOT(remoteMysqltimerFuncXS()));
    timer3000ms->start(3000);
}

void remoteMysql::remoteMysqltimerFuncXS()
{
    qDebug() << "remoteMysqlThread remoteMysqltimerFuncXS run";
}
void remoteMysql::receiveFromBusiness(QString userID,QString productName,QString productPrice,QString productWeight,QString productDsc,QString productID)
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << time.toLocalTime();
    qDebug()<<"userID"<<userID<<"productName"<<productName<<"productPrice"<<productPrice<<"productWeight"<<productWeight<<"productDsc"<<productDsc<<"userID"<<userID;
    QString str = QString("insert into productData (userID,productNum,productName,productPrice,productWeight,productDescribe,created_at) "
                          "values('%1', '%2', '%3', '%4', '%5','%6',now());")
            .arg(userID.toLatin1().data()).arg(productID.toInt()).arg(productName).arg(productPrice.toFloat()).arg(productWeight.toFloat()).arg(productDsc);

    //qDebug()<<"str"<<str;

    bool ret = query.exec(str);
    if (ret)
    {
        qDebug() << "db1 insert ok!!!!!!";
    }
    else
    {
        qDebug()<<"db1 insert failed!!!!!!";
    }
}
