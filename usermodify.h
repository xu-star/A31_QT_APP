#ifndef USERMODIFY_H
#define USERMODIFY_H
#include "cali.h"
#include <QDialog>

namespace Ui {
class UserModify;
}

class UserModify : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserModify(QWidget *parent = 0);
    ~UserModify();

    
private slots:
    void on_buttonBox_accepted();

    void on_radioButton_1_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

private:
    Ui::UserModify *ui;
};

#endif // USERMODIFY_H
