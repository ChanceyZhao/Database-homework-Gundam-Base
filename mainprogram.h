#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H
//#include <QStandardItemModel>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qsql.h>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>
#include <ask.h>
#include <change.h>
#include <QIcon>
#include <QPixmap>
#include <QScrollBar>
namespace Ui {
    class MainProgram;
}

class MainProgram : public QWidget{
    Q_OBJECT
    QSqlQuery query;
    public:
        explicit MainProgram(QWidget *parent = nullptr);
        Change *change;
        Ask *ask;
        QString Select = "select * from Gundam where ";
        QString Delete = "delete from Gundam where model = ";
        QString comb = "name";
        QString last = "select * from Gundam";
        ~MainProgram();

        void select();

    private slots:
        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

        void on_comboBox_currentIndexChanged(const QString &arg1);

        void on_lineEdit_returnPressed();

        void on_pushButton_3_clicked();

        void on_pushButton_5_clicked();

        void subWindowClosed();

        void on_pushButton_6_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_7_clicked();

private:
        QSqlTableModel *model;
        Ui::MainProgram *ui;
};

#endif // MAINPROGRAM_H
