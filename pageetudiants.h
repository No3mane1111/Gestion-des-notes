#ifndef PAGEETUDIANTS_H
#define PAGEETUDIANTS_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class PageEtudiants;
}

class PageEtudiants : public QDialog
{
    Q_OBJECT

public:
    explicit PageEtudiants(QWidget *parent = nullptr);
    ~PageEtudiants();

private:
    Ui::PageEtudiants *ui;
    QSqlDatabase database;
    QSqlQueryModel *querymodel;

};

#endif // PAGEETUDIANTS_H
