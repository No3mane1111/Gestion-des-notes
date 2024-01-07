#include "loginstudent.h"
#include "ui_loginstudent.h"

loginStudent::loginStudent(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginStudent)
{
    ptrpageeetudiants = new pageEtudiants2();


    ui->setupUi(this);
    ui->UsernameEtudLogin->setPlaceholderText("Enter un username");
    ui->PasswordEtudLogin->setPlaceholderText("Saisir un mot de pass");

}

loginStudent::~loginStudent()
{
    delete ptrpageeetudiants ;
    delete ui;

}

void loginStudent::on_studButtomLogin_clicked()
{
    QString UsernameEtudLogin = ui->UsernameEtudLogin->text();
    QString PasswordEtudLogin = ui->PasswordEtudLogin->text();

    dbLog = QSqlDatabase::addDatabase("QSQLITE");
    dbLog.setDatabaseName("C:/Users/Noamane/Desktop/qtprjt/GestionDesNotesBD/gestionNotes.db");

    if(!dbLog.open()){
        QMessageBox::information(this,"Not INSERTED","Data Is Not inserted ");
        return;
    }else{
        QMessageBox::information(this,"INSERTED","Data inserted Successfully");
        QSqlQuery query(dbLog);
        query.prepare("select * from studTable where UsernameEtud like '%"+UsernameEtudLogin+"%'and PasswordEtud like'%"+PasswordEtudLogin+"%'");
        if(!query.exec()){

            QMessageBox::information(this,"Failed","Query Filed to Exucte");

        }else {
            while (query.next()) {
                QString UsernameFromDB = query.value(3).toString();
                QString PasswordFromDB = query.value(4).toString();


                if(UsernameFromDB==UsernameEtudLogin && PasswordFromDB==PasswordEtudLogin ){
                    QMessageBox::information(this,"Success","Login Success");
                    ptrpageeetudiants->show();




                }else{
                    QMessageBox::information(this,"Failed","Login Failed");
                }
            }

        }


   }
}

