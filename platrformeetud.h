#ifndef PLATRFORMEETUD_H
#define PLATRFORMEETUD_H

#include <QDialog>
#include "loginprofesseur.h"


#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>

namespace Ui {
class PlatrformeEtud;
}

class PlatrformeEtud : public QDialog
{
    Q_OBJECT

public:
    explicit PlatrformeEtud(QWidget *parent = nullptr);
    ~PlatrformeEtud();

private slots:
    void on_Profbutton_clicked();

    void on_Login_clicked();

private:
    Ui::PlatrformeEtud *ui;
    loginProfesseur*ptrloginprofesseur;
     QSqlDatabase db;
};

#endif // PLATRFORMEETUD_H
