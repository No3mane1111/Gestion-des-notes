#include "saisirlesnotes.h"
#include "ui_saisirlesnotes.h"

saisirLesNotes::saisirLesNotes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::saisirLesNotes)
{
    ui->setupUi(this);
}

saisirLesNotes::~saisirLesNotes()
{
    delete ui;
}

void saisirLesNotes::on_buttonSaisir_clicked()
{
    QString NumEtud = ui->NumEtud->text();
    QString CodeCours = ui->CodeCours->text();
    QString Note = ui->NoteObtenu->text();
    QString Date = ui->DateDEval->text();


    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/Noamane/Desktop/qtprjt/GestionDesNotesBD/gestionNotes.db");

    if(!database.open()){
        QMessageBox::information(this,"Not Open","DB Is Not Open ");
        return;
    }else{
         QMessageBox::information(this,"Open","DB was Open  ");    }

    QSqlQuery query(database);
    query.prepare("INSERT INTO Note (idEtudiant, idCours, Note,DateEvaluation)VALUES('" + NumEtud + "','" + CodeCours + "','" + Note + "','" + Date + "')");


    if (query.exec()) {
        QMessageBox::information(this,"INSERTED","Data inserted Successfully");
    } else {
        QMessageBox::information(this,"Not INSERTED","Data Is Not inserted ");
    }



}

