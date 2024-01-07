#ifndef REGISTERSTUDENT_H
#define REGISTERSTUDENT_H

#include "loginstudent.h"

#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>







namespace Ui {
class RegisterStudent;
}

class RegisterStudent : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterStudent(QWidget *parent = nullptr);
    ~RegisterStudent();

private slots:


    void on_studButtomRegister_clicked();


    void on_LoginEtud_clicked();

private:
    Ui::RegisterStudent *ui;
    loginStudent*ptrloginStudent;
    QSqlDatabase database;

};

#endif // REGISTERSTUDENT_H
