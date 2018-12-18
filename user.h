#ifndef USER_H
#define USER_H
#include "cali.h"
#include <QWidget>
#include "usermodify.h"
namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT
    
public:
    explicit User(QWidget *parent = 0);
    ~User();
 //   UserModify *Um;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::User *ui;
};

#endif // USER_H
