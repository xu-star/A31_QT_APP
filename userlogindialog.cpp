#include "userlogindialog.h"
#include "ui_userlogindialog.h"
#include "./TestInput_Cursor/inputmethod.h"
#include <QTextCodec>
#include <QMessageBox>
UserLoginDialog::UserLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLoginDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    loginflag=0;
    beepflag=0;
    keyflag=false;
    callogin = new cali;
   //usleep(1000);
    tempeep=0;
  // #ifdef arm
 callogin->ArgRead();
    usleep(100);
    callogin->ArgRead1();
     usleep(100);
     if(iniep!=30)
     {
     callogin->ArgIni();
     callogin->ArgSave();
      usleep(100);
     callogin->ArgSave1();
      usleep(100);
     callogin->ArgRead();
      usleep(100);
     callogin->ArgRead1();
     }
  // #endif
    QSettings *configIniRead = new QSettings("/UserConfig.ini", QSettings::IniFormat);
    int i=0;
    //usernumb=1;
    for (i=0;i<10;i++)
    {
    QString temp = QString::number(i+1);
    //QString temp = QString::number(usernumb);
    QString tempstr = "User"+temp+"/name";
    QString tempstr1 = "User"+temp+"/password";
      QString tempstr2 = "User"+temp+"/modify";
    USN[i] = configIniRead->value(tempstr).toString();
    USP[i] = configIniRead->value(tempstr1).toString();
     USQ[i] = configIniRead->value(tempstr2).toString();

    qDebug()<<"USN"<<USN[i]<<"USP"<<USP[i]<<"USQ"<<USQ[i];
    }
    delete configIniRead;


    ui->lineEditpassword->setEchoMode(QLineEdit::Password);//password no show - zc
    //adThread = new AdThread;
   //QTimer::singleShot(0,adThread,SLOT(Adinit()));
}

UserLoginDialog::~UserLoginDialog()
{
    delete ui;
}

void UserLoginDialog::on_pBlogin_clicked()
{
    int j;
    int b_accept=0;
    beep_start;
    for (j=0;j<10;j++)
    {
        if(ui->lineEditUsername->text()==USN[j]&&ui->lineEditpassword->text()==USP[j])
        {
           b_accept=1;
           operatorID = USN[j].toInt();
           quanxian=USQ[j].toInt();
           qDebug()<<"quanxian"<<quanxian<<USP[j];
           break;
        }
    }
    if(ui->lineEditUsername->text()=="admin"&&ui->lineEditpassword->text()=="3190")
    {
       b_accept=1;
       quanxian=1;
       qDebug()<<"quanxian"<<quanxian;
    }
   // if((ui->lineEditUsername->text()==USN[0]&&ui->lineEditpassword->text()==USP[0])||(ui->lineEditUsername->text()==USN[1]&&ui->lineEditpassword->text()==USP[1]))
    if(b_accept)
        accept();
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("用户名或密码错误"),QMessageBox::Yes);
        ui->lineEditUsername->clear();
        ui->lineEditpassword->clear();
        ui->lineEditUsername->setFocus();
    }

}

void UserLoginDialog::on_pBquit_clicked()
{
   // close();
}
