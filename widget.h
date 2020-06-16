#ifndef WIDGET_H
#define WIDGET_H
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <mainprogram.h>
#include <QIcon>
#include <QPixmap>
#include <QtMultimedia/QMediaPlayer>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    MainProgram *main;
    QMediaPlayer *player;

    void Login();


private slots:

    void on_pushButton_clicked();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_returnPressed();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
