#include "dataexport.h"
#include "ui_dataexport.h"
DataExport::DataExport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataExport)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    //model = new QFileSystemModel();
    modelFreeFlag = false;
    upgradeFlag = false;
    dataExportTimer = new QTimer;
    dataExportTimer->start(500);
    connect(dataExportTimer,SIGNAL(timeout()),this,SLOT(dataExportSlot()));
}

DataExport::~DataExport()
{
    delete ui;
}

void DataExport::on_pushButton_6_clicked()
{
    beep_start;
    this->close();
}

void DataExport::on_pushButton_2_clicked()
{
    beep_start;
    emit dataExportcsv();
    qDebug() <<"emit dataExportcsv();";
}
void DataExport::mysql_open()
{

}

void DataExport::on_pushButton_clicked()
{
    beep_start;
    emit dataExportxls();
}

void DataExport::on_pushButton_7_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(1);
#if 0
    //QFileSystemModel *model = new QFileSystemModel();
    model->setRootPath("/media");

    //QStringList nameFilter;
    //nameFilter << "*.cpp" << "*.h";
    model->setNameFilterDisables(false);
    //model->setNameFilters(nameFilter);/media/udisk
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index("/media"));
#else
    model = new QFileSystemModel();
    model->setRootPath("/media/udisk");
    //model->setRootPath("/media");
    //QStringList nameFilter;
    //nameFilter << "*.cpp" << "*.h";
    model->setNameFilterDisables(false);
    //model->setNameFilters(nameFilter);/media/udisk
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index("/media/udisk"));
    //ui->treeView->setRootIndex(model->index("/media"));
#endif
    ui->treeView->setColumnWidth(0,250);
    ui->treeView->setColumnWidth(1,60);
    ui->treeView->setColumnWidth(2,60);
    ui->treeView->setColumnWidth(3,60);
    ui->treeView->setColumnWidth(4,60);
    modelFreeFlag=true;
    //qDebug()<<"UUUUUUUUUUUUUUUUUUUUU";
}

void DataExport::on_pushButton_8_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(0);
}
void DataExport::dataExportSlot()//free memory
{
    if ((modelFreeFlag==true)&&(ui->stackedWidget->currentIndex()!=1))
    {
        qDebug()<<"delete model!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
        modelFreeFlag = false;
        delete model;
        model=NULL;
    }
    QFileInfo file("/media/udisk/A12");

    if(file.exists()==false)
    {
        //qDebug()<<"upgrade file A12 is not exit!!!!!!!!!!!!!!!!!!11";
        upgradeFlag = false;
    }
    else
    {
        //qDebug()<<"upgrade file A12 is  exit!!!!!!!!!!!!!!!!!!11";
        upgradeFlag = true;
    }

}


void DataExport::on_pushButton_3_clicked()
{
    beep_start;
    if (upgradeFlag == false)
    {
        QMessageBox::information(this, tr("警告"), tr("升级文件不存在，请在U盘中放入升级文件"));
    }
    else
    {
        QMessageBox::StandardButton rb=QMessageBox::information(this, tr("升级"), tr("升级应用"), QMessageBox::Cancel, QMessageBox::Yes);
        if(rb == QMessageBox::Cancel)
        {
            qDebug()<<"QMessageBox::Cancel";
        }
        else if (rb == QMessageBox::Yes)
        {

            system("source /etc/qt_env.sh&");
            system("cp /media/udisk/A12 /root/");
            system("/opt/forlinx_qt4.8/bin/upgrade -qws&");
            system("ps -ef | grep A12 | grep -v grep | cut -c 3-5 | xargs kill -9&");
            qDebug()<<"QMessageBox::Yes";
        }
    }
}

void DataExport::fromRootdialog()
{
    this->close();
}
