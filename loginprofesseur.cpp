#include "loginprofesseur.h"
#include "ui_loginprofesseur.h"

loginProfesseur::loginProfesseur(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginProfesseur)
{
    ui->setupUi(this);
    ptrpageprofesseurs= new PageProfesseurs;


    ui->UserProfLog_2->setPlaceholderText("Enter un username");
    ui->PassProfLog_2->setPlaceholderText("Saisir un mot de pass");
}

loginProfesseur::~loginProfesseur()
{
    delete ptrpageprofesseurs;
    delete ui;
}









void loginProfesseur::on_ProfLogButton_clicked()
{
    QString UsernameProfLogin = ui->UserProfLog_2->text();
    QString PasswordProfLogin = ui->PassProfLog_2->text();

    bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("C:/Users/Noamane/Desktop/qtprjt/GestionDesNotesBD/gestionNotes.db");

    if(!bd.open()){
        QMessageBox::information(this,"Not INSERTED","Data Is Not inserted ");
        return;
    }else{
        QMessageBox::information(this,"INSERTED","Data inserted Successfully");
        QSqlQuery query(bd);
        query.prepare("select * from profTable where UsernameProf like '%"+UsernameProfLogin+"%'and PasswordProf like'%"+PasswordProfLogin+"%'");
        if(!query.exec()){

            QMessageBox::information(this,"Failed","Query Filed to Exucte");

        }else {
            while (query.next()) {
                QString UsernameFromDB = query.value(3).toString();
                QString PasswordFromDB = query.value(4).toString();


                if(UsernameFromDB==UsernameProfLogin && PasswordFromDB==PasswordProfLogin ){
                    QMessageBox::information(this,"Success","Login Success");
                    ptrpageprofesseurs->show();



                }else{
                    QMessageBox::information(this,"Failed","Login Failed");
                }
            }

        }


    }
}

