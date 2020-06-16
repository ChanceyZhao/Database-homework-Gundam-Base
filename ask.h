#ifndef ASK_H
#define ASK_H
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
    class Ask;
}

class Ask : public QWidget
{
    Q_OBJECT
    QString Insert = "insert into Gundam values ( ";

    public:
        explicit Ask(QWidget *parent = nullptr);
        ~Ask();

    signals:
        void closed();

    private slots:
        void on_pushButton_clicked();

        void on_pushButton_7_clicked();

private:
        Ui::Ask *ui;
};

#endif // ASK_H
