#include "change.h"
#include "ui_change.h"

Change::Change(QWidget *parent,QString name, QString code,QString model, QString type, QString camp) :QWidget(parent),ui(new Ui::Change){
    ui->setupUi(this);
    QPixmap pix;
    pix.load(":/new/prefix1/icon");
    this->setWindowTitle("Gundam Base");
    this->setWindowIcon(QIcon(pix));
    this->setWindowFlags(Qt::FramelessWindowHint);
    Model = model;
    ui->lineEdit->setText(name);
    ui->lineEdit_2->setText(code);
    ui->lineEdit_3->setText(type);
    ui->lineEdit_4->setText(camp);
    this->setWindowTitle("Change " + model);
}

Change::~Change(){
    delete ui;
}

void Change::on_pushButton_clicked(){
    QString Upd;
    Upd = Update + "'" + ui->lineEdit->text() + "',code = '" + ui->lineEdit_2->text() + "',type = '" + ui->lineEdit_3->text() + "',camp = '" + ui->lineEdit_4->text() + "' where model = '" + Model + "'";
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(Upd);
    model->setQuery(QString());
    emit closed();
    this->close();
}

void Change::on_pushButton_7_clicked()
{
    this->close();
}
