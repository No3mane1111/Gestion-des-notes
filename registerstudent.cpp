#include "registerstudent.h"
#include "ui_registerstudent.h"



RegisterStudent::RegisterStudent(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterStudent)
{

    ui->setupUi(this);


    ptrloginStudent = new loginStudent();


    ui->NomEtud->setPlaceholderText("Enter votre nom");
    ui->PrenomEtud->setPlaceholderText("Entrer votre prenom");
    ui->UsernameStudRegi->setPlaceholderText("Enter un username");
    ui->PasswordEtudRegi->setPlaceholderText("Saisir un mot de pass");
    ui->SpecEtud->setPlaceholderText("Entrer votre Specialite");


}

RegisterStudent::~RegisterStudent()
{
    delete ptrloginStudent;
    delete ui;


}



void RegisterStudent::on_studButtomRegister_clicked()
{
    QString NomEtud = ui->NomEtud->text();
    QString PrenomEtud = ui->PrenomEtud->text();
    QString UsernameStudRegi = ui->UsernameStudRegi->text();
    QString PasswordEtudRegi = ui->PasswordEtudRegi->text();
    QString SpecEtud = ui->SpecEtud->text();

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/Noamane/Desktop/qtprjt/GestionDesNotesBD/gestionNotes.db");

    if(!database.open()){
        QMessageBox::information(this,"Not Open","DB Is Not Open ");
        return;
    }else{
        QMessageBox::information(this,"Open","DB was Open  ");    }

    QSqlQuery query;
    query.prepare("INSERT INTO studTable (NomEtud, PrenomEtud, UsernameEtud,PasswordEtud,SpecEtud) VALUES ('" + NomEtud + "','" + PrenomEtud + "','" + UsernameStudRegi + "','" + PasswordEtudRegi + "','" + SpecEtud + "')");
    if (query.exec()) {
          QMessageBox::information(this,"INSERTED","Data inserted Successfully");
            ptrloginStudent->show();
    } else {
        QMessageBox::information(this,"Not INSERTED","Data Is Not inserted ");
    }






}





void RegisterStudent::on_LoginEtud_clicked()
{
  ptrloginStudent->show();
}

