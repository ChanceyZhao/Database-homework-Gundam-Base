#include "mainprogram.h"
#include "ui_mainprogram.h"

MainProgram::MainProgram(QWidget *parent) :QWidget(parent),ui(new Ui::MainProgram){
    ui->setupUi(this);
    QPixmap pix;
    pix.load(":/new/prefix1/icon");
    this->setWindowTitle("Gundam Base");
    this->setWindowIcon(QIcon(pix));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowTitle("Gundam Base");
    this->move(400,150);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("Gundam");
    if(!db.open()){
        QMessageBox::about(NULL, "Error", "Error: Failed to connect database.");
        qDebug() << db.lastError();
    }
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("select * from Gundam"));
    ui->tableView->setModel(model);

    /*QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::trUtf8("名称,代号,型号,类型,派系").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);*/
    ui->tableView->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"        //垂直滑块整体
                                                              "background:rgb(50,50,50,200);"  //背景色
                                                              "padding-top:20px;"    //上预留位置（放置向上箭头）
                                                              "padding-bottom:20px;" //下预留位置（放置向下箭头）
                                                              "padding-left:3px;"    //左预留位置（美观）
                                                              "padding-right:3px;"   //右预留位置（美观）
                                                              "border-left:1px solid #d7d7d7;}"//左分割线
                                                              "QScrollBar::handle:vertical{"//滑块样式
                                                              "background:rgb(100,100,100,200);"  //滑块颜色
                                                              "border-radius:6px;"   //边角圆润
                                                              "min-height:80px;}"    //滑块最小高度
                                                              "QScrollBar::handle:vertical:hover{"//鼠标触及滑块样式
                                                              "background:rgb(100,100,100,200);}" //滑块颜色
                                                              "QScrollBar::add-line:vertical{"//向下箭头样式
                                                              "background:url(:/images/resource/images/checkout/down.png) center no-repeat;}"
                                                              "QScrollBar::sub-line:vertical{"//向上箭头样式
                                                              "background:url(:/images/resource/images/checkout/up.png) center no-repeat;}");
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->verticalHeader()->setStyleSheet("QHeaderView::section {"
                                                   "background:rgb(50,50,50,200);"
                                                           "color: black;padding-left: 4px;border: 0px solid #6c6c6c;}");
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {"
                                                     "background:rgb(50,50,50,200);"
                                                           "color: black;padding-left: 4px;border: 0px solid #6c6c6c;}");
    ui->tableView->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal{"
                                                              "background:#FFFFFF;"
                                                              "padding-top:3px;"
                                                              "padding-bottom:3px;"
                                                              "padding-left:20px;"
                                                              "padding-right:20px;}"
                                                              "QScrollBar::handle:horizontal{"
                                                              "background:rgb(50,50,50,200);"
                                                              "border-radius:6px;"
                                                              "min-width:80px;}"
                                                              "QScrollBar::handle:horizontal:hover{"
                                                              "background:#d0d0d0;}"
                                                              "QScrollBar::add-line:horizontal{"
                                                              "background:url(:/images/resource/images/checkout/right.png) center no-repeat;}"
                                                              "QScrollBar::sub-line:horizontal{"
                                                              "background:url(:/images/resource/images/checkout/left.png) center no-repeat;}");

}

void MainProgram::select(){
    QString sel;
    sel = Select + comb + " = '" + QString(ui->lineEdit->text()) + "'";
    last = sel;
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    model->setQuery(sel);
    ui->tableView->setModel(model);
}

MainProgram::~MainProgram(){
    delete ui;
}

void MainProgram::on_pushButton_clicked(){
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    model->setQuery(QString("select * from Gundam"));
    last = "select * from Gundam";
    ui->tableView->setModel(model);
}

void MainProgram::on_pushButton_2_clicked(){
    select();
}

void MainProgram::on_comboBox_currentIndexChanged(const QString &arg1){
    comb = arg1;
}

void MainProgram::on_lineEdit_returnPressed(){
    select();
}

void MainProgram::on_pushButton_3_clicked(){
    int curRow=ui->tableView->currentIndex().row();
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(curRow,2);
    QVariant datatemp = modessl->data(indextemp);
    QString del;
    del = Delete + "'" + datatemp.toString() + "'";
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    model->setQuery(del);
    model->setQuery(QString(last));
    ui->tableView->setModel(model);
}

void MainProgram::on_pushButton_5_clicked(){
    ask = new Ask();
    ask->show();
    connect(ask,&Ask::closed,this,&MainProgram::subWindowClosed);
}

void MainProgram::subWindowClosed(){
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    model->setQuery(QString(last));
    ui->tableView->setModel(model);
}

void MainProgram::on_pushButton_6_clicked(){
    QString list[5];
    for (int i = 0;i < 5;i++){
        int curRow=ui->tableView->currentIndex().row();
        QAbstractItemModel *modessl = ui->tableView->model();
        QModelIndex indextemp = modessl->index(curRow,i);
        QVariant datatemp = modessl->data(indextemp);
        list[i] = datatemp.toString();
    }
    change = new Change(NULL,list[0],list[1],list[2],list[3],list[4]);
    change->show();
    connect(change, &Change::closed, this, &MainProgram::subWindowClosed);
}

void MainProgram::on_pushButton_4_clicked(){
    this->close();
}

void MainProgram::on_pushButton_7_clicked()
{
    this->close();
}
