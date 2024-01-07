#ifndef PAGEETUDIANTS2_H
#define PAGEETUDIANTS2_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class pageEtudiants2;
}

class pageEtudiants2 : public QDialog
{
    Q_OBJECT

public:
    explicit pageEtudiants2(QWidget *parent = nullptr);
    ~pageEtudiants2();

private slots:
    void on_RechercheButton_clicked();

    void on_Notifications_clicked();

private:
    Ui::pageEtudiants2 *ui;
    QSqlDatabase database;
    QSqlQueryModel *querymodel;
};

#endif // PAGEETUDIANTS2_H
