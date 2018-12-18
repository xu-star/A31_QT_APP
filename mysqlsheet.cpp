#include "mysqlsheet.h"
#include "ui_mysqlsheet.h"
mysqlSheet::mysqlSheet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mysqlSheet)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    //    QDate time = QDate::currentDate();
    //    QString year = QString::number(time.year());
    //    QString month =QString::number(time.month());
    //    QString date = QString::number(time.day());
    //    ui->label_date_2->setText(date);
    //    ui->label_mounth->setText(month);
    //    ui->label_year->setText(year);
    //    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    //    ui->dateTimeEdit_2->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    //    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    //    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());

    ui->stackedWidget->setCurrentIndex(0);
    model = new QSqlQueryModel(ui->tableView);
    //query = new QSqlQuery;
    //query = new QSqlQuery;
    sqlinit();
}

void mysqlSheet::sqlinit()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("test");
    query = QSqlQuery(db);
    if (!db.open())
    {
        QMessageBox::warning(this,"QMYSQL","open error");
        return;
    }
    //QSqlQuery query;
    bool flag = query.exec(
                "create table IF NOT EXISTS productData(RecordID int unsigned not null primary key auto_increment,userID char not null,productNum int unsigned not null,productName VARCHAR(30) not null, productPrice real not null, productWeight real not null,productDescribe VARCHAR(30) null,created_at timestamp not NULL DEFAULT CURRENT_TIMESTAMP) CHARSET=utf8;");

    //if (query.exec(sql))
    if (flag)
    {
        qDebug() << "db creat table ok";
    }
    else
    {
        QSqlError error = query.lastError();
        QMessageBox::warning(this,"create error", QString("the error is:")+error.databaseText());
    }
}
void mysqlSheet::sqlinsert()
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    qDebug() << time.toLocalTime();
    //query = new QSqlQuery;
    //insert into productData (userID,productNum,productName,productPrice,productWeight,productDescribe,created_at) values ("11","1","apple","1.2","2.2","dsf",now());
    QString str = QString("insert into productData (userID,productNum,productName,productPrice,productWeight,productDescribe,created_at) "
                          "values('%1', '%2', '%3', %4, '%5','%6',now())")
            .arg(ui->lineEdit_6->text()).arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text());
    //        QString str = QString("insert into productData values('%1', '%2', '%3', %4, '%5','%6')")
    //          .arg(ui->lineEdit->text()).arg(ui->lineEdit_2->text()).arg(ui->lineEdit_3->text()).arg(ui->lineEdit_4->text()).arg(ui->lineEdit_5->text()).arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    bool ret = query.exec(str);
    if (ret)
    {
        qDebug() << "insert ok!!!!!!";
    }
    else
    {
        qDebug()<<"insert failed!!!!!!";
    }
}

mysqlSheet::~mysqlSheet()
{
    delete ui;
}

void mysqlSheet::on_toolButton_7_clicked()
{
    beep_start;
    if (ui->stackedWidget->currentIndex()==4)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if (ui->stackedWidget->currentIndex()==5)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if (ui->stackedWidget->currentIndex()==6)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if (ui->stackedWidget->currentIndex()==7)
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if (ui->stackedWidget->currentIndex()==11)
    {
        ui->stackedWidget->setCurrentIndex(10);
    }
    else if (ui->stackedWidget->currentIndex()==13)
    {
        ui->stackedWidget->setCurrentIndex(12);
    }
    else if (ui->stackedWidget->currentIndex()==14)
    {
        ui->stackedWidget->setCurrentIndex(13);
    }
    else if (ui->stackedWidget->currentIndex()==15)
    {
        ui->stackedWidget->setCurrentIndex(11);
    }
    else if (ui->stackedWidget->currentIndex()==16)
    {
        ui->stackedWidget->setCurrentIndex(8);
    }
    else if (ui->stackedWidget->currentIndex()==12)
    {
        ui->stackedWidget->setCurrentIndex(8);
    }
    else if (ui->stackedWidget->currentIndex()==9)
    {
        ui->stackedWidget->setCurrentIndex(16);
    }
    else if (ui->stackedWidget->currentIndex()==19)
    {
        ui->stackedWidget->setCurrentIndex(18);
    }
    else if (ui->stackedWidget->currentIndex()==18)
    {
        ui->stackedWidget->setCurrentIndex(17);
    }
    else if (ui->stackedWidget->currentIndex()==17)
    {
        ui->stackedWidget->setCurrentIndex(10);
    }
    else
    {
        this->close();
    }
}

void mysqlSheet::on_pushButton_2_clicked()
{
    beep_start;
    //if (ui->label_mounth->text().toInt())
    if (ui->label_date_2->text().toInt()>1)
    {
        int new_date = (ui->label_date_2->text().toInt()-1);
        ui->label_date_2->setText(QString::number(new_date));
    }
    else
    {
        ui->label_date_2->setText(QString::number(31));
        if ((ui->label_mounth->text().toInt())>1)
        {
            int new_date = (ui->label_mounth->text().toInt()-1);
            ui->label_mounth->setText(QString::number(new_date));
        }
        else
        {
            ui->label_mounth->setText(QString::number(12));
        }
    }
    qDebug()<<"----------------"<<ui->label_date_2->text();
    QString temp = ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text();
  //  QString temp=ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text()
    RecDaily.StartTime=temp;
    qDebug() << "temp date" <<temp;

    QString tempStart = ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text()+" 00:00:00";
    QString tempEnd = ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text()+" 23:59:59";

    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"';";

    qDebug() << "tempStartDate" <<tempStartDate;

    condition = "select * from productData where " + tempStartDate;
    conditionNum = "select count(*) from productData where " + tempStartDate;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
    RecDaily.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_24->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
    RecDaily.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_25->setText(QString::number(GrossSheet));
}

void mysqlSheet::on_pushButton_clicked()
{
    beep_start;
    if (ui->label_date_2->text().toInt()<31)
    {
        int new_date = (ui->label_date_2->text().toInt()+1);
        ui->label_date_2->setText(QString::number(new_date));
    }
    else
    {
        ui->label_date_2->setText(QString::number(1));
        if ((ui->label_mounth->text().toInt())<12)
        {
            int new_date = (ui->label_mounth->text().toInt()+1);
            ui->label_mounth->setText(QString::number(new_date));
        }
        else
        {
            ui->label_mounth->setText(QString::number(1));
        }
    }
    qDebug()<<"+++++++++++++++++++"<<ui->label_date_2->text();
    //if ();
    //QString temp = ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text()+" "+"00:00:00";
    //qDebug() << "temp date" <<temp;

    QString temp=ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text();
    RecDaily.StartTime=temp;
    QString tempStart = ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text()+" 00:00:00";
    QString tempEnd = ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text()+" 23:59:59";

    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"';";

    qDebug() << "tempStartDate" <<tempStartDate;

    condition = "select * from productData where " + tempStartDate;
    conditionNum = "select count(*) from productData where " + tempStartDate;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    //model->setQuery(condition);
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
    RecDaily.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_24->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
    RecDaily.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_25->setText(QString::number(GrossSheet));
}

void mysqlSheet::on_toolButton_6_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(3);
}

void mysqlSheet::on_toolButton_2_clicked()
{
    beep_start;
    QDate time = QDate::currentDate();
    QString year = QString::number(time.year());
    QString month =QString::number(time.month());

    ui->label_mounth_2->setText(month);
    ui->label_year_2->setText(year);

    ui->stackedWidget->setCurrentIndex(1);
  
   
    QString temp= ui->label_year_2->text()+"-"+ui->label_mounth_2->text();

    RecMonth.StartTime=temp;
    QString tempStart = ui->label_year_2->text()+"-"+ui->label_mounth_2->text()+"-"+"01"+" 00:00:00";
    QString tempEnd = ui->label_year_2->text()+"-"+ui->label_mounth_2->text()+"-"+"31"+" 23:59:59";

    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"';";

    qDebug() << "tempStartDate" <<tempStartDate;

    condition = "select * from productData where " + tempStartDate;
    conditionNum = "select count(*) from productData where " + tempStartDate;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    //model->setQuery(condition);
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
    qDebug() << "row number: " << numRows;
   RecMonth.numCount=numRows;
    ui->label_27->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
	RecMonth.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_29->setText(QString::number(GrossSheet));

}

void mysqlSheet::on_pushButton_3_clicked()
{
    beep_start;
    if (ui->label_mounth_2->text().toInt()>1)
    {
        int new_date = (ui->label_mounth_2->text().toInt()-1);
        ui->label_mounth_2->setText(QString::number(new_date));
    }
    else
    {
        ui->label_mounth_2->setText(QString::number(12));
        if ((ui->label_year_2->text().toInt())>1)
        {
            int new_date = (ui->label_year_2->text().toInt()-1);
            ui->label_year_2->setText(QString::number(new_date));
        }
        //        else
        //        {
        //            ui->label_year_2->setText(QString::number());
        //        }
    }

    QString temp= ui->label_year_2->text()+"-"+ui->label_mounth_2->text();

    RecMonth.StartTime=temp;
    QString tempStart = ui->label_year_2->text()+"-"+ui->label_mounth_2->text()+"-"+"01"+" 00:00:00";
    QString tempEnd = ui->label_year_2->text()+"-"+ui->label_mounth_2->text()+"-"+"31"+" 23:59:59";

    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"';";

    qDebug() << "tempStartDate" <<tempStartDate;

    condition = "select * from productData where " + tempStartDate;
    conditionNum = "select count(*) from productData where " + tempStartDate;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    //model->setQuery(condition);
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
     RecMonth.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_27->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
    RecMonth.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_29->setText(QString::number(GrossSheet));
}

void mysqlSheet::on_pushButton_4_clicked()
{
    beep_start;
    if (ui->label_mounth_2->text().toInt()<12)
    {
        int new_date = (ui->label_mounth_2->text().toInt()+1);
        ui->label_mounth_2->setText(QString::number(new_date));
    }
    else
    {
        ui->label_mounth_2->setText(QString::number(1));
        if ((ui->label_year_2->text().toInt())>1)
        {
            int new_date = (ui->label_year_2->text().toInt()+1);
            ui->label_year_2->setText(QString::number(new_date));
        }
    }

     QString temp= ui->label_year_2->text()+"-"+ui->label_mounth_2->text();

    RecMonth.StartTime=temp;
    QString tempStart = ui->label_year_2->text()+"-"+ui->label_mounth_2->text()+"-"+"01"+" 00:00:00";
    QString tempEnd = ui->label_year_2->text()+"-"+ui->label_mounth_2->text()+"-"+"31"+" 23:59:59";

    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"';";

    qDebug() << "tempStartDate" <<tempStartDate;

    condition = "select * from productData where " + tempStartDate;
    conditionNum = "select count(*) from productData where " + tempStartDate;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    //model->setQuery(condition);
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
    RecMonth.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_27->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
    RecMonth.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_29->setText(QString::number(GrossSheet));
}

void mysqlSheet::on_toolButton_clicked()
{
    beep_start;
    QDate time = QDate::currentDate();
    QString year = QString::number(time.year());
    QString month =QString::number(time.month());
    QString date = QString::number(time.day());

    ui->label_date_2->setText(date);
    ui->label_mounth->setText(month);
    ui->label_year->setText(year);


    ui->stackedWidget->setCurrentIndex(0);
    //QString date = "created_at>='"+ui->dateTimeEdit->text()+"' and created_at<= DATE_ADD('"+ui->dateTimeEdit_2->text()+"',INTERVAL 1 DAY)";
   //RecDaily.Year=(ui->label_year->text().toInt())%100;
   // RecDaily.Month=ui->label_mounth->text().toInt();
    //RecDaily.Day=ui->label_date_2->text().toInt();
    QString temp=ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text();
    RecDaily.StartTime=temp;

    QString tempStart = ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text()+" 00:00:00";
    QString tempEnd = ui->label_year->text()+"-"+ui->label_mounth->text()+"-"+ui->label_date_2->text()+" 23:59:59";

    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"';";
    qDebug() << "tempStartDate" <<tempStartDate;

    condition = "select * from productData where " + tempStartDate;
    conditionNum = "select count(*) from productData where " + tempStartDate;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    //model->setQuery(condition);
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
	 RecDaily.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_24->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
	RecDaily.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_25->setText(QString::number(GrossSheet));

}

void mysqlSheet::on_toolButton_3_clicked()
{
    beep_start;
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEdit_2->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());

    ui->stackedWidget->setCurrentIndex(2);
}

void mysqlSheet::on_toolButton_10_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(4);

    QString tempStart = ui->dateTimeEdit_2->text();
	
    QString tempEnd = ui->dateTimeEdit->text();


    RecAll.StartTime=tempStart;
    RecAll.EndTime=tempEnd;

    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"';";
    qDebug() << "tempStartDate" <<tempStartDate;

    condition = "select * from productData where " + tempStartDate;
    conditionNum = "select count(*) from productData where " + tempStartDate;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    //model->setQuery(condition);
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
	RecAll.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_17->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
	RecAll.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_19->setText(QString::number(GrossSheet));


}

void mysqlSheet::on_toolButton_8_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(5);

    model->setQuery(condition);

    //列名
//    model->setHeaderData(0, Qt::Horizontal, tr("产品代码"));
//    model->setHeaderData(1, Qt::Horizontal, tr("产品名称"));
//    model->setHeaderData(2, Qt::Horizontal, tr("产品单价"));
//    model->setHeaderData(3, Qt::Horizontal, tr("产品重量"));
//    model->setHeaderData(4, Qt::Horizontal, tr("产品描述"));
//    model->setHeaderData(5, Qt::Horizontal, tr("时间"));
    ui->tableView->setShowGrid(true);//显示表格线
    //ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Fixed);

    //ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    //ui->tableView->horizontalHeader()->setDefaultSectionSize(120);

    ui->tableView->setModel(model);//数据放置进去

    ui->tableView->setColumnWidth(0,60);
    ui->tableView->setColumnWidth(1,60);
    ui->tableView->setColumnWidth(2,60);
    ui->tableView->setColumnWidth(3,60);
    ui->tableView->setColumnWidth(4,60);
    ui->tableView->setColumnWidth(5,60);
    ui->tableView->setColumnWidth(6,60);
    ui->tableView->setColumnWidth(7,60);
}

void mysqlSheet::on_toolButton_9_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(6);

    model->setQuery(condition);
    ui->tableView_2->setShowGrid(true);//显示表格线
    ui->tableView_2->setModel(model);//数据放置进去

    ui->tableView_2->setColumnWidth(0,60);
    ui->tableView_2->setColumnWidth(1,60);
    ui->tableView_2->setColumnWidth(2,60);
    ui->tableView_2->setColumnWidth(3,60);
    ui->tableView_2->setColumnWidth(4,60);
    ui->tableView_2->setColumnWidth(5,60);
    ui->tableView_2->setColumnWidth(6,60);
    ui->tableView_2->setColumnWidth(7,60);
}

void mysqlSheet::on_toolButton_11_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(7);

    model->setQuery(condition);
    ui->tableView_3->setShowGrid(true);//显示表格线
    ui->tableView_3->setModel(model);//数据放置进去

    ui->tableView_3->setColumnWidth(0,60);
    ui->tableView_3->setColumnWidth(1,60);
    ui->tableView_3->setColumnWidth(2,60);
    ui->tableView_3->setColumnWidth(3,60);
    ui->tableView_3->setColumnWidth(4,60);
    ui->tableView_3->setColumnWidth(5,60);
    ui->tableView_3->setColumnWidth(6,60);
    ui->tableView_3->setColumnWidth(7,60);
	query1 = model->query();
	query1.exec("select productNum from productData where RecordID = 1");
       query1.next();
       Sql.SqlCode=query1.value(0).toInt();
	query1.exec("select productName from productData where RecordID = 1");
       query1.next();
       Sql.SqlproductName=query1.value(0).toString();
       query1.exec("select productPrice from productData where RecordID = 1");
       query1.next();
       Sql.SqlproductPrice=query1.value(0).toFloat();
       query1.exec("select productWeight from productData where RecordID = 1");
       query1.next();
       Sql.Sqlweight=query1.value(0).toFloat();
       query1.exec("select created_at from productData where RecordID = 1");
       query1.next();
       Sql.SqlTime=query1.value(0).toString();
       // if(!b_Print) emit PrintSqlSignal();
}

void mysqlSheet::on_toolButton_12_clicked()
{
    beep_start;
    if ((ui->lineEdit_6->text()==NULL)||(ui->lineEdit->text()==NULL)||(ui->lineEdit_2->text()==NULL)||(ui->lineEdit_3->text()==NULL)||(ui->lineEdit_4->text()==NULL)||ui->lineEdit_5->text()==NULL)
    {
        ui->label_9->setText("输入错误，请重新输入");
    }
    else
    {
        ui->label_9->hide();
        sqlinsert();
    }
}

void mysqlSheet::on_toolButton_4_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(8);
}

void mysqlSheet::on_toolButton_13_clicked()
{
    beep_start;
    ui->dateTimeEdit_3->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEdit_4->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEdit_3->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_4->setDateTime(QDateTime::currentDateTime());

    ui->stackedWidget->setCurrentIndex(12);
}

void mysqlSheet::on_toolButton_5_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(10);
}

void mysqlSheet::on_toolButton_14_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(11);

    QString temp = ui->lineEdit_8->text();
    RecUser.userID=temp;
   
    condition = "select * from productData where userID='"+temp+"';";
    qDebug() << "condition" <<condition;

    conditionNum = "select count(*) from productData where userID='"+temp+"';";
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
    RecUser.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_50->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where userID='"+temp+"';";
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
    RecUser.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_52->setText(QString::number(GrossSheet));
}


void mysqlSheet::on_toolButton_15_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(16);

    QString temp = ui->lineEdit_7->text();
    RecProduct.productName=temp;
    condition = "select * from productData where productName='"+temp+"';";
    qDebug() << "condition" <<condition;

    conditionNum = "select count(*) from productData where productName='"+temp+"';";
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
    RecProduct.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_56->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where productName='"+temp+"';";
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
    RecProduct.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_58->setText(QString::number(GrossSheet));
    /*model->setQuery(condition);
    ui->tableView_4->setShowGrid(true);//显示表格线
    ui->tableView_4->setModel(model);//数据放置进去

    ui->tableView_4->setColumnWidth(0,60);
    ui->tableView_4->setColumnWidth(1,60);
    ui->tableView_4->setColumnWidth(2,60);
    ui->tableView_4->setColumnWidth(3,60);
    ui->tableView_4->setColumnWidth(4,60);
    ui->tableView_4->setColumnWidth(5,60);
    ui->tableView_4->setColumnWidth(6,60);
    ui->tableView_4->setColumnWidth(7,60);*/
}
void mysqlSheet::on_toolButton_16_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(13);

    QString tempStart = ui->dateTimeEdit_3->text();
    QString tempEnd = ui->dateTimeEdit_4->text();

     RecProduct.StartTime=tempStart;
     RecProduct.EndTime=tempEnd;
	 
    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"' ";
    QString tempProductName = "and productName='"+ui->lineEdit_7->text()+"';";

    RecProduct.productName=ui->lineEdit_7->text();
    qDebug() << "tempStartDate" <<tempStartDate;
    qDebug() << "tempProductName1111111111111111111111" <<tempProductName;

    condition = "select * from productData where " + tempStartDate+tempProductName;
    conditionNum = "select count(*) from productData where " + tempStartDate+tempProductName;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    //model->setQuery(condition);
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt();
     RecProduct.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_45->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate+tempProductName;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
    RecProduct.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_47->setText(QString::number(GrossSheet));
}


void mysqlSheet::on_toolButton_17_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(14);

    model->setQuery(condition);
    ui->tableView_5->setShowGrid(true);//显示表格线
    ui->tableView_5->setModel(model);//数据放置进去

    ui->tableView_5->setColumnWidth(0,60);
    ui->tableView_5->setColumnWidth(1,60);
    ui->tableView_5->setColumnWidth(2,60);
    ui->tableView_5->setColumnWidth(3,60);
    ui->tableView_5->setColumnWidth(4,60);
    ui->tableView_5->setColumnWidth(5,60);
    ui->tableView_5->setColumnWidth(6,60);
    ui->tableView_5->setColumnWidth(7,60);
}


void mysqlSheet::on_toolButton_18_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(15);

    model->setQuery(condition);
    ui->tableView_6->setShowGrid(true);//显示表格线
    ui->tableView_6->setModel(model);//数据放置进去

    ui->tableView_6->setColumnWidth(0,60);
    ui->tableView_6->setColumnWidth(1,60);
    ui->tableView_6->setColumnWidth(2,60);
    ui->tableView_6->setColumnWidth(3,60);
    ui->tableView_6->setColumnWidth(4,60);
    ui->tableView_6->setColumnWidth(5,60);
    ui->tableView_6->setColumnWidth(6,60);
    ui->tableView_6->setColumnWidth(7,60);
}

void mysqlSheet::on_toolButton_19_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(9);

    model->setQuery(condition);
    ui->tableView_4->setShowGrid(true);//显示表格线
    ui->tableView_4->setModel(model);//数据放置进去

    ui->tableView_4->setColumnWidth(0,60);
    ui->tableView_4->setColumnWidth(1,60);
    ui->tableView_4->setColumnWidth(2,60);
    ui->tableView_4->setColumnWidth(3,60);
    ui->tableView_4->setColumnWidth(4,60);
    ui->tableView_4->setColumnWidth(5,60);
    ui->tableView_4->setColumnWidth(6,60);
    ui->tableView_4->setColumnWidth(7,60);
}


void mysqlSheet::on_toolButton_20_clicked()
{
    beep_start;
    ui->dateTimeEdit_5->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEdit_6->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
    ui->dateTimeEdit_5->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_6->setDateTime(QDateTime::currentDateTime());

    ui->stackedWidget->setCurrentIndex(17);
}

void mysqlSheet::on_toolButton_21_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(18);

    QString tempStart = ui->dateTimeEdit_5->text();
    QString tempEnd = ui->dateTimeEdit_6->text();

    RecUser.StartTime=tempStart;
    RecUser.EndTime=tempEnd;

    qDebug() << "tempStart" << tempStart;
    qDebug() << "tempEnd" <<tempEnd;

    QString tempStartDate = "created_at>='"+tempStart+"' and created_at<='"+tempEnd+"' ";
    QString tempProductName = "and userID='"+ui->lineEdit_8->text()+"';";
    RecUser.userID=ui->lineEdit_8->text();
    //where userID='"+ui->lineEdit_8->text()+"';";
    qDebug() << "tempStartDate" <<tempStartDate;
    qDebug() << "tempProductName1111111111111111111111" <<tempProductName;

    condition = "select * from productData where " + tempStartDate+tempProductName;
    conditionNum = "select count(*) from productData where " + tempStartDate+tempProductName;
    qDebug()<<"condition"<<condition;
    qDebug()<<"conditionNum"<<conditionNum;
    //model->setQuery(condition);
    query.exec(conditionNum);
    query.next();
    int numRows = query.value(0).toInt(); 
    RecUser.numCount=numRows;
    qDebug() << "row number: " << numRows;
    ui->label_64->setText(QString::number(numRows));

    QString TempGrossSheet = "select sum(productWeight) from productData where " + tempStartDate+tempProductName;
    query.exec(TempGrossSheet);
    query.next();
    float GrossSheet = query.value(0).toFloat();
    RecUser.AccWeight=GrossSheet;
    qDebug() << "GrossSheet: " << GrossSheet;
    ui->label_66->setText(QString::number(GrossSheet));
}

void mysqlSheet::on_toolButton_22_clicked()
{
    beep_start;
    ui->stackedWidget->setCurrentIndex(19);

    model->setQuery(condition);
    ui->tableView_7->setShowGrid(true);//显示表格线
    ui->tableView_7->setModel(model);//数据放置进去

    ui->tableView_7->setColumnWidth(0,60);
    ui->tableView_7->setColumnWidth(1,60);
    ui->tableView_7->setColumnWidth(2,60);
    ui->tableView_7->setColumnWidth(3,60);
    ui->tableView_7->setColumnWidth(4,60);
    ui->tableView_7->setColumnWidth(5,60);
    ui->tableView_7->setColumnWidth(6,60);
    ui->tableView_7->setColumnWidth(7,60);
}

void mysqlSheet::dataOutputcsv()
{
    qDebug() << "receive  dataOutputcsv";

    QDateTime time = QDateTime::currentDateTime();
    QString date = time.toString("yyyy-MM-dd-hh-mm-ss");
    //qDebug() << "date"<<date;
    //QString TempGrossSheetTemp = "select * into outfile '/work/"+date+".csv' from productData;";
    //qDebug() << "TempGrossSheetTemp"<<TempGrossSheetTemp;

    //QString TempGrossSheet = "select * from productData into outfile '/work/2018051501.csv'";
    //select * into outfile '/work/2.csv' from productData;
    QString TempGrossSheet = "select * into outfile '/work/"+date+".csv' from productData;";
    query.exec(TempGrossSheet);
    //query.next();
    //float GrossSheet = query.value(0).toFloat();
    qDebug() << "dataOutputcsv";
    //ui->label_19->setText(QString::number(GrossSheet));

    QString tmp;
    tmp="cp /work/"+date+".csv /media/udisk/";
    qDebug() << "tmp"<<tmp;

    std::string str = tmp.toStdString();
    const char* ch = str.c_str();
    system(ch);
    system("rm /work/*");
    system("cd /media/udisk");
}
void mysqlSheet::dataOutputxls()
{
    QDateTime time = QDateTime::currentDateTime();
    QString date = time.toString("yyyy-MM-dd-hh-mm-ss");
    //qDebug() << "date"<<date;
    //QString TempGrossSheetTemp = "select * into outfile '/work/"+date+".csv' from productData;";
    //qDebug() << "TempGrossSheetTemp"<<TempGrossSheetTemp;

    //QString TempGrossSheet = "select * from productData into outfile '/work/2018051501.csv'";
    //select * into outfile '/work/2.csv' from productData;
    QString TempGrossSheet = "select * into outfile '/work/"+date+".xls' from productData;";
    query.exec(TempGrossSheet);
    //query.next();
    //float GrossSheet = query.value(0).toFloat();
    qDebug() << "dataOutputcsv";
    //ui->label_19->setText(QString::number(GrossSheet));

    QString tmp;
    tmp="cp /work/"+date+".xls /media/udisk/";
    qDebug() << "tmp"<<tmp;

    std::string str = tmp.toStdString();
    const char* ch = str.c_str();
    system(ch);
    system("rm /work/*");
    system("cd /media/udisk");
}
void mysqlSheet::fromRootdialog(void)
{
    this->close();
}

void mysqlSheet::on_toolButton_23_clicked()
{
   beep_start;
  if(!b_Print) emit PrintDailySignal();
}

void mysqlSheet::on_toolButton_24_clicked()
{
   beep_start;
   if(!b_Print) emit PrintMonthSignal();
}

void mysqlSheet::on_toolButton_25_clicked()
{
   beep_start;
  if(!b_Print)  emit PrintAllSignal();
}

void mysqlSheet::on_toolButton_26_clicked()
{
   beep_start;
   if(!b_Print) emit PrintProductSeniorSignal();
}

void mysqlSheet::on_toolButton_27_clicked()
{
   beep_start;
   if(!b_Print) emit PrintUserSignal();
}

void mysqlSheet::on_toolButton_28_clicked()
{
   beep_start;
   if(!b_Print) emit PrintProductSignal();
}

void mysqlSheet::on_toolButton_29_clicked()
{
   beep_start;
   if(!b_Print) emit PrintUserSeniorSignal();
}
