#ifndef CHANGE_H
#define CHANGE_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qsql.h>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QWidget>
#include <QIcon>
#include <QPixmap>

namespace Ui {
    class Change;
}

class Change : public QWidget
{
    Q_OBJECT

    public:
        explicit Change(QWidget *parent = nullptr,QString name = NULL, QString code = NULL,QString model = NULL, QString type = NULL, QString camp = NULL);
        QString Model;
        QString Update = "update Gundam set name = ";
        ~Change();
    signals:
        void closed();
    private slots:
        void on_pushButton_clicked();

        void on_pushButton_7_clicked();

private:
        Ui::Change *ui;
};

#endif // CHANGE_H
