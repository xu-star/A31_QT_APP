#ifndef USERLOGINDIALOG_H
#define USERLOGINDIALOG_H
#include "cali.h"
#include "adthread.h"
#include <QDialog>

namespace Ui {
class UserLoginDialog;
}

class UserLoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserLoginDialog(QWidget *parent = 0);
    ~UserLoginDialog();
    cali *callogin;
    
private slots:
    void on_pBlogin_clicked();

    void on_pBquit_clicked();

private:
    Ui::UserLoginDialog *ui;
private:
    // AdThread *adThread;
    int tempeep;
};

#endif // USERLOGINDIALOG_H
