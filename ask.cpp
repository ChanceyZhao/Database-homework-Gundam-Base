#include "ask.h"
#include "ui_ask.h"

Ask::Ask(QWidget *parent) :QWidget(parent),ui(new Ui::Ask){
    ui->setupUi(this);
    QPixmap pix;
    pix.load(":/new/prefix1/icon");
    this->setWindowTitle("Gundam Base");
    this->setWindowIcon(QIcon(pix));
    this->setWindowTitle("New Gundam");
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Ask::~Ask(){
    delete ui;
}

void Ask::on_pushButton_clicked(){
    if (ui->lineEdit->text() == ""){
        QMessageBox::warning(NULL, "Error", "The model can't be empty");
        return;
    }
    QString ins;
    ins = Insert + "'" + ui->lineEdit->text() + "'," + "'" + ui->lineEdit_2->text() + "'," + "'" + ui->lineEdit_3->text() + "'," + "'" + ui->lineEdit_4->text() + "'," + "'" + ui->lineEdit_5->text() + "')";
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(ins);
    emit closed();
    this->close();
}

void Ask::on_pushButton_7_clicked()
{
    this->close();
}
