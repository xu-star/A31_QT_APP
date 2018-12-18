#include "user.h"
#include "ui_user.h"
User::User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
//    UserModify *Um;
//    Um = new UserModify;
}

User::~User()
{
    delete ui;

}

void User::on_pushButton_clicked()
{
beep_start;
    usernumb=1;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
  /*  QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}
void User::on_pushButton_1_clicked()
{
beep_start;
    usernumb=2;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
  /*  QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_2_clicked()
{
beep_start;
    usernumb=3;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
 /*  QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_3_clicked()
{
    beep_start;
    usernumb=4;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
 /*   QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_4_clicked()
{
    beep_start;
    usernumb=5;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
  /*  QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_5_clicked()
{
    beep_start;
    usernumb=6;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
  /*  QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_6_clicked()
{
    beep_start;
    usernumb=7;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
    /*QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_7_clicked()
{
    beep_start;
    usernumb=8;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
   /* QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_8_clicked()
{
    beep_start;
    usernumb=9;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
 /*  QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_9_clicked()
{
    beep_start;
    usernumb=10;
    UserModify *Um;
    Um = new UserModify;
    Um->show();
  /*  QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;*/
}

void User::on_pushButton_10_clicked()
{
    beep_start;
    close();
}
