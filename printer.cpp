#include "printer.h"
#include "ui_printer.h"
#include <QImage>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
Printer::Printer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Printer)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->verticalScrollBar,SIGNAL(valueChanged(int)),this,SLOT(slot_ScroolWidget(int)));
    init();
}

Printer::~Printer()
{
    delete ui;
}
/*void show_image(QString filename1)
{
    //filename = filename1;

}*/

void Printer::init()
{
    filename = "/root/123.png";
    sheet=0;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    PrintMode=configIniRead->value("baseinfo/PrintMode").toInt();
    delete configIniRead;
    switch(PrintMode)
    {
    case 0:
        ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/123.png";
        break;
    case 1:
        ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/144.png";
        break;
    case 2:
        ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/2.png";
        break;
    case 3:
        ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/3.png";
        break;
    case 4:
        ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/4.png";
        break;
    case 5:
        ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/6.png";
        break;
    case 6:
        ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/7.png";
        break;
    case 7:
        ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/5.png";
        break;
    case 8:
        ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/5.png";
        break;
    case 9:
        ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/5.png";
        break;
    default:
        ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/123.png";
        break;
    }
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            /*QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));*/
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));


    }
}
void Printer::on_pushButton_clicked()
{
    beep_start;
    filename = "/root/123.png";
    ui->stackedWidget->setCurrentIndex(0);
    ui->pushButton->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 16pt");
    ui->pushButton_2->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 16pt");
    ui->pushButton_3->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 16pt");

    switch(PrintMode)
    {
    case 0:
        ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/123.png";
        break;
    case 1:
        ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/144.png";
        break;
    case 2:
        ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/2.png";
        break;
    case 3:
        ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/3.png";
        break;
    case 4:
        ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/4.png";
        break;
    case 5:
        ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/5.png";
        break;
    case 6:
        ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/5.png";
        break;
    case 7:
        ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/5.png";
        break;
    case 8:
        ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/5.png";
        break;
    case 9:
        ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/5.png";
        break;
    default:
        ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/123.png";
        break;
    }
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            /*QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));*/
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));


    }

}

void Printer::on_pushButton_2_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(1);
    ui->pushButton_2->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 16pt");
    ui->pushButton->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 16pt");
    ui->pushButton_3->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 16pt");
    switch(sheet)
    {
    case 0:
        ui->pushButton_19->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/11.png";
        break;
    case 1:

        filename = "/root/12.png";
        break;
    case 2:

        filename = "/root/13.png";
        break;
    case 3:

        filename = "/root/14.png";
        break;
    case 4:

        filename = "/root/15.png";
        break;
    default:
        //ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
        filename = "/root/11.png";
        break;

    }
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            /*QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));*/
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));


    }

}

/*void Printer::on_pushButton_3_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(2);
}

void Printer::on_pushButton_4_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(3);
}*/

void Printer::on_pushButton_5_clicked()
{
    beep_start;
    this->close();
}
void Printer::slot_ScroolWidget(int value)
{
    double p=static_cast<double>(value)/static_cast<double>(ui->verticalScrollBar->maximum());
    ui->widget->move(0,-(ui->widget->height()-350)*p);
}

void Printer::on_pushButton_6_clicked()
{
    beep_start;
    filename = "/root/123.png";
    PrintMode=0;
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",0);

    delete configIniRead;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}
void Printer::fromRootdialog(void)
{
    this->close();
}

void Printer::on_pushButton_7_clicked()
{
    beep_start;
    filename = "/root/144.png";
    PrintMode=1;
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",1);

    delete configIniRead;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}

void Printer::on_pushButton_8_clicked()
{
    beep_start;
    filename = "/root/2.png";
    /*Totfa=0;
Totfn=0;
QSettings *configIniRead = new QSettings("/A31/config.ini", QSettings::IniFormat);
    configIniRead->setValue("printinfo/Totfa",Totfa);
   configIniRead->setValue("printinfo/Totfn",Totfn);
    delete configIniRead;*/
    PrintMode=2;
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");

    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",PrintMode);

    delete configIniRead;

    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}

void Printer::on_pushButton_10_clicked()
{
    beep_start;
    filename = "/root/4.png";
    PrintMode=4;
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");

    if(PrintCodeHeight>2)PrintCodeHeight=0;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",PrintMode);
    //configIniRead->setValue("printinfo/PrintCodeHeight",PrintCodeHeight);
    //configIniRead->setValue("printinfo/PrintCodeType",PrintCodeType);
    delete configIniRead;

    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}

void Printer::on_pushButton_11_clicked()
{
    beep_start;
    filename = "/root/6.png";
    PrintMode=5;
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",PrintMode);

    delete configIniRead;


    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}



void Printer::on_pushButton_9_clicked()
{
    beep_start;
    filename = "/root/3.png";
    PrintMode=3;
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",3);

    delete configIniRead;

    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}

void Printer::on_pushButton_12_clicked()
{
    filename = "/root/7.png";

    beep_start;
    PrintMode=6;
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",PrintMode);

    delete configIniRead;

    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}

void Printer::on_pushButton_13_clicked()
{
    filename = "/root/5.png";
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");

    beep_start;
    PrintMode=7;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",PrintMode);

    delete configIniRead;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }

}

void Printer::on_pushButton_14_clicked()
{
    filename = "/root/5.png";
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");

    beep_start;
    PrintMode=8;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",PrintMode);
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }

}

void Printer::on_pushButton_15_clicked()
{
    filename = "/root/5.png";
    ui->pushButton_15->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_7->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_8->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_9->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_10->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_11->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_12->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_13->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_14->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_6->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");

    beep_start;
    PrintMode=9;
    QSettings *configIniRead = new QSettings("/CommConfig.ini", QSettings::IniFormat);
    configIniRead->setValue("baseinfo/PrintMode",PrintMode);
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}

void Printer::on_pushButton_19_clicked()
{
    filename = "/root/11.png";
    sheet=0;
    ui->pushButton_19->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_18->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_20->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_21->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_22->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");

    beep_start;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }

}

void Printer::on_pushButton_18_clicked()
{
    filename = "/root/12.png";
    sheet=1;
    ui->pushButton_18->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_19->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_20->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_21->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_22->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");

    beep_start;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}

void Printer::on_pushButton_20_clicked()
{
    filename = "/root/14.png";
    sheet=3;
    ui->pushButton_20->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_18->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_19->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_21->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_22->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    beep_start;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}



void Printer::on_pushButton_21_clicked()
{
    filename = "/root/13.png";
    sheet=2;
    ui->pushButton_21->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_18->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_20->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_19->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_22->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    beep_start;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }

}



void Printer::on_pushButton_3_clicked()
{
    beep_start;
    filename = "/root/16.png";
    ui->stackedWidget->setCurrentIndex(2);
    ui->pushButton_3->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 16pt");
    ui->pushButton_2->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 16pt");
    ui->pushButton->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 16pt");
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            /* QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));*/
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}

void Printer::on_pushButton_16_clicked()
{
    filename = "/root/16.png";
    ui->pushButton_16->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");


    beep_start;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }

}

void Printer::on_pushButton_22_clicked()
{
    filename = "/root/15.png";
    sheet=4;
    ui->pushButton_22->setStyleSheet("background-image: url(:/other/other/67.bmp);color: black;font: 12pt");
    ui->pushButton_18->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_20->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_19->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    ui->pushButton_21->setStyleSheet("background-image: url(:/other/other/67.bmp);color: white;font: 12pt");
    beep_start;
    if(filename.isEmpty())
    {
        return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }
}
