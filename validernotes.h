#ifndef VALIDERNOTES_H
#define VALIDERNOTES_H

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
class validerNotes;
}

class validerNotes : public QDialog
{
    Q_OBJECT

public:
    explicit validerNotes(QWidget *parent = nullptr);
    ~validerNotes();

private:
    Ui::validerNotes *ui;
    QSqlDatabase database;
    QSqlQueryModel *querymodel;
};

#endif // VALIDERNOTES_H
