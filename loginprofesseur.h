#ifndef LOGINPROFESSEUR_H
#define LOGINPROFESSEUR_H

#include <QDialog>

#include"pageprofesseurs.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class loginProfesseur;
}

class loginProfesseur : public QDialog
{
    Q_OBJECT

public:
    explicit loginProfesseur(QWidget *parent = nullptr);
    ~loginProfesseur();

private slots:

    void on_ProfLogButton_clicked();

private:
    Ui::loginProfesseur *ui;
    QSqlDatabase bd;
    PageProfesseurs*ptrpageprofesseurs;

};

#endif // LOGINPROFESSEUR_H
