#ifndef REGISTERPROFESSEUR_H
#define REGISTERPROFESSEUR_H


#include <QDialog>

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>


namespace Ui {
class RegisterProfesseur;
}

class RegisterProfesseur : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterProfesseur(QWidget *parent = nullptr);
    ~RegisterProfesseur();

private slots:


    void on_ProfButtomRegister_clicked();

private:
    Ui::RegisterProfesseur *ui;

};

#endif // REGISTERPROFESSEUR_H
