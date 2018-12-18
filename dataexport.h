#ifndef DATAEXPORT_H
#define DATAEXPORT_H

#include <QWidget>
#include <GlobalVarible.h>
#include <QFileSystemModel>
#include <QFileInfo>
namespace Ui {
class DataExport;
}

class DataExport : public QWidget
{
    Q_OBJECT

public:
    explicit DataExport(QWidget *parent = 0);
    ~DataExport();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();
    void dataExportSlot();
    void fromRootdialog(void);
    void on_pushButton_3_clicked();

private:
    Ui::DataExport *ui;
public:
    void mysql_open();
signals:
   void dataExportcsv();
   void dataExportxls();
private:
   QFileSystemModel *model;
   QTimer *dataExportTimer;
   bool modelFreeFlag;
   bool upgradeFlag;
};

#endif // DATAEXPORT_H

