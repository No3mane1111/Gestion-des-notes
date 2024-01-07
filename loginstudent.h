#ifndef LOGINSTUDENT_H
#define LOGINSTUDENT_H

#include"pageetudiants2.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>


namespace Ui {
class loginStudent;
}

class loginStudent : public QDialog
{
    Q_OBJECT

public:
    explicit loginStudent(QWidget *parent = nullptr);
    ~loginStudent();

private slots:
    void on_studButtomLogin_clicked();

private:
    Ui::loginStudent *ui;
    pageEtudiants2*ptrpageeetudiants;
    QSqlDatabase dbLog;
};

#endif // LOGINSTUDENT_H
