#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent) : QWidget(parent) , ui(new Ui::Widget){
    ui->setupUi(this);
    QPixmap pix;
    pix.load(":/7.png");
    this->setWindowTitle("Gundam Base");
    this->setWindowIcon(QIcon(pix));
    this->setWindowFlags(Qt::FramelessWindowHint);
    main = new MainProgram();
}

Widget::~Widget(){
    delete ui;
}
void Widget::Login(){
    if (this->ui->lineEdit->text() == "Chancey"){
        if (this->ui->lineEdit_2->text() == "chenxi0403"){
            this->main->show();
            this->main->setFixedSize(1200,800);
            this->hide();
        }else
            QMessageBox::about(NULL, "Error", "Password not correct.");
    }else
        QMessageBox::about(NULL, "Error", "Account doesn't exist.");
}

void Widget::on_pushButton_clicked(){
    this->Login();
}

void Widget::on_lineEdit_2_returnPressed(){
    this->Login();
}

void Widget::on_lineEdit_returnPressed(){
    if(this->ui->lineEdit_2->text() != "Password")
        this->Login();
}

void Widget::on_pushButton_2_clicked(){
    this->close();
}
