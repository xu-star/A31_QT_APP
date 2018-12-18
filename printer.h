#ifndef PRINTER_H
#define PRINTER_H

#include <QWidget>
#include <GlobalVarible.h>
namespace Ui {
class Printer;
}

class Printer : public QWidget
{
    Q_OBJECT
    
public:
    explicit Printer(QWidget *parent = 0);
    ~Printer();
    
public:
  // void show_image(QString filename1);

public:
    QString filenameString;
    QString filename;
    uchar sheet;
    void init();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    //void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void slot_ScroolWidget(int value);

    void on_pushButton_6_clicked();
    void fromRootdialog(void);
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::Printer *ui;
};

#endif // PRINTER_H
