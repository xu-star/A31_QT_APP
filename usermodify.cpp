#include "usermodify.h"
#include "ui_usermodify.h"

UserModify::UserModify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserModify)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    QString tempstr2 = "User"+temp+"/modify";
    UserName = configIniRead->value(tempstr).toString();
    UserPassword = configIniRead->value(tempstr1).toString();
    quanxiantemp=configIniRead->value(tempstr2).toInt();
    delete configIniRead;

    qDebug()<<"UserName"<<UserName<<"UserPassword"<<UserPassword;

    ui->lineEditUsername->setText(UserName);
    ui->lineEditPassword->setText(UserPassword);
    if(quanxiantemp==1)
    ui->radioButton_1->setChecked(true);
    else if(quanxiantemp==2)
        ui->radioButton_2->setChecked(true);
    else
        ui->radioButton_3->setChecked(true);
}

UserModify::~UserModify()
{
    delete ui;
}

void UserModify::on_buttonBox_accepted()
{
    beep_start;
    QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
    QString tempstr2 = "User"+temp+"/modify";

    qDebug()<<temp<<tempstr<<tempstr1<<tempstr2;
    QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    configIniRead->setValue(tempstr, ui->lineEditUsername->text());
    configIniRead->setValue(tempstr1, ui->lineEditPassword->text());
    configIniRead->setValue(tempstr2, quanxiantemp);

    delete configIniRead;
}

void UserModify::on_radioButton_1_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        quanxiantemp=1;
        qDebug()<<"quanxian"<<quanxian;
    }
}

void UserModify::on_radioButton_2_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        quanxiantemp=2;
        qDebug()<<"quanxian"<<quanxian;
    }
}

void UserModify::on_radioButton_3_toggled(bool checked)
{
    if(checked==true)
    {
        beep_start;
        quanxiantemp=3;
        qDebug()<<"quanxian"<<quanxian;
    }
}
