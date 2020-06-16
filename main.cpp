#include "widget.h"
#include <QApplication>
#include <QDebug>
#include <QtMultimedia/QMediaPlayer>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QMediaPlayer * player = new QMediaPlayer;
    QMediaContent media(QUrl::fromLocalFile("D:/QtProject/SQL/music.mp3"));
    player->setMedia(media);
    player->setVolume(50);
    player->play();
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else{
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Gundam");
        db.setUserName("Chancey");
        db.setPassword("chenxi0403");
    }
    if (!db.open()){
        QMessageBox::about(NULL, "Error", "Error: Failed to connect database.");
        qDebug() << db.lastError();
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    bool isTableExist =query.exec(QString("select count(*) from sqlite_master where type='table' and name='%1'").arg("Gundam"));
    if(!isTableExist){
        model->setQuery("create table Gundam(name varchar(30),code varchar(30),model varchar(30),type varchar(30),camp varchar(30),primary key(model))");
        model->setQuery(QString("insert into Gundam values('试作型高达','无','RX-78-1','泛用多目的试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达','机动战士','RX-78-2','泛用多目的试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('G-3高达','机动战士','RX-78-3','泛用多目的试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达四号机','机动战士','RX-78-4','宇宙用多目的试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达五号机','机动战士','RX-78-5','宇宙用多目的试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达六号机','机动战士','RX-78-6','宇宙用多目的试作型MS(宇宙用炮击试作型MS)','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达七号机','机动战士','RX-78-7','宇宙用多目的试作型MS','尤格·库洛','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达ALEX','高达ALEX','RX-78-NT-1','泛用多目的试作型MS(NT专用)','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('全装甲甲高达ALEX','高达ALEX','RX-78-NT-1-FA','泛用增加装甲装备试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('全装甲高达','全装甲高达','FA-78-1','泛用增加装甲装备试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('全装甲高达B型','全装甲高达','FA-78-1B3','模拟战用增加装甲装备试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('重高达','重高达','FA-78-2','泛用多目的试作型重MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('全装甲高达七号机','全装甲高达','FA-78-3','宇宙用多目的试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('重装全装甲高达7号机','全装甲高达','HFA-78-3','宇宙用增加装甲装备试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('精灵高达','机动战士','RX-78-XX','陆地站专用MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达GT-4','机动战士','RX-78E','陆地站专用MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达GP01','白兰花','GP-01','泛用探测增强试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达GP01','白兰花','GP-01FB','泛用探测增强试作型MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达0','独角兽','RX-0','试作型NT专用MS','地球联邦')"));
        model->setQuery(QString("insert into Gundam values('高达0','报丧女妖','RX-0c','试作型NT专用MS','新吉翁')"));
    }
    Widget w;
    w.show();

    return a.exec();
}
