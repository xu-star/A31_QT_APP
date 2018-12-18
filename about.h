#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include "GlobalVarible.h"
namespace Ui {
class About;
}

class About : public QWidget
{
    Q_OBJECT
    
public:
    explicit About(QWidget *parent = 0);
    ~About();
    
private slots:
    void on_pushButton_clicked();
    void fromRootdialog(void);
private:
    Ui::About *ui;
};

#endif // ABOUT_H
