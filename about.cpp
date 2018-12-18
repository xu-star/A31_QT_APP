#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->label_model->setText(tr("A31"));
    ui->label_SN->setText(A31SN);
    ui->label_version->setText(A31Version);
    qDebug()<<"A31SN"<<A31SN<<"A31Version"<<A31Version;
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
      beep_start;
    this->close();
}
void About::fromRootdialog()
{
    this->close();
}
