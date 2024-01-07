#include "platrformeetud.h"
#include "ui_platrformeetud.h"

PlatrformeEtud::PlatrformeEtud(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PlatrformeEtud)
{
    ui->setupUi(this);

    ptrloginprofesseur = new loginProfesseur();

    ui->NomProf_2->setPlaceholderText("Enter votre nom");
    ui->PrenomProf_2->setPlaceholderText("Entrer votre prenom");
    ui->UsernameProf_2->setPlaceholderText("Enter un username");
    ui->PasswordProf_2->setPlaceholderText("Saisir un mot de pass");
}

PlatrformeEtud::~PlatrformeEtud()
{
    delete ptrloginprofesseur;
    delete ui;
}

void PlatrformeEtud::on_Profbutton_clicked()
{
    QString NomProf = ui->NomProf_2->text();
    QString PrenomProf = ui->PrenomProf_2->text();
    QString UsernameProf = ui->UsernameProf_2->text();
    QString PasswordProf = ui->PasswordProf_2->text();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Noamane/Desktop/qtprjt/GestionDesNotesBD/gestionNotes.db");

    if(!db.open()){
        QMessageBox::information(this,"Not Open","DB Is Not Open ");
        return;
    }else{
         QMessageBox::information(this,"Open","DB was Open  ");   }

    QSqlQuery query(db);
    query.prepare("INSERT INTO profTable (NomProf, PrenomProf, UsernameProf,PasswordProf)VALUES('" + NomProf + "','" + PrenomProf + "','" + UsernameProf + "','" + PasswordProf + "')");
    if (query.exec()) {
        QMessageBox::information(this,"INSERTED","Data inserted Successfully");
        ptrloginprofesseur->show();

    } else {
        QMessageBox::information(this,"Not INSERTED","Data Is Not inserted ");
    }

}


void PlatrformeEtud::on_Login_clicked()
{
     ptrloginprofesseur->show();
}

