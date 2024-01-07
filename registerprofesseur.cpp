#include "registerprofesseur.h"
#include "ui_registerprofesseur.h"

RegisterProfesseur::RegisterProfesseur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterProfesseur)
{
    ui->setupUi(this);


    ui->NomProf->setPlaceholderText("Enter votre nom");
    ui->PrenomProf->setPlaceholderText("Entrer votre prenom");
    ui->UsernamProfRegi->setPlaceholderText("Enter un username");
    ui->PasswordProfRegi->setPlaceholderText("Saisir un mot de pass");
}

RegisterProfesseur::~RegisterProfesseur()
{
    delete ui;

}



void RegisterProfesseur::on_ProfButtomRegister_clicked()
{
    QString NomProf = ui->NomProf->text();
    QString PrenomProf = ui->PrenomProf->text();
    QString UsernameProfRegi = ui->UsernamProfRegi->text();
    QString PasswordProfRegi = ui->PasswordProfRegi->text();



    QSqlDatabase sqlitedb = QSqlDatabase ::addDatabase("QSQLITE");
    sqlitedb.setDatabaseName("D:/testatQt/sqlliteFileTest/mydb.sqlite");

    if(!sqlitedb.open()){
         QMessageBox::information(this,"Not Open","DB Is Not Open ");


    }else {
         QMessageBox::information(this,"Open","DB was Open  ");

    QSqlQuery query(sqlitedb);
    query.prepare("INSERT INTO tableProf (NomProf, PrenomProf, UsernameProf,PasswordProf)VALUES('" + NomProf + "','" + PrenomProf + "','" + UsernameProfRegi + "','" + PasswordProfRegi + "')");
    if (query.exec()) {
        QMessageBox::information(this,"INSERTED","Data inserted Successfully");

    } else {
        QMessageBox::information(this,"Not INSERTED","Data Is Not inserted ");
    }




}


}

