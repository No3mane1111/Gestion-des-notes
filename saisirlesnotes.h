#ifndef SAISIRLESNOTES_H
#define SAISIRLESNOTES_H

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
class saisirLesNotes;
}

class saisirLesNotes : public QDialog
{
    Q_OBJECT

public:
    explicit saisirLesNotes(QWidget *parent = nullptr);
    ~saisirLesNotes();

private slots:
    void on_buttonSaisir_clicked();

private:
    Ui::saisirLesNotes *ui;
    QSqlDatabase database;
};

#endif // SAISIRLESNOTES_H
