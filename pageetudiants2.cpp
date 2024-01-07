#include "pageetudiants2.h"
#include "ui_pageetudiants2.h"



pageEtudiants2::pageEtudiants2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pageEtudiants2)
{
    ui->setupUi(this);


}


pageEtudiants2::~pageEtudiants2()
{
    delete ui;
}

void pageEtudiants2::on_RechercheButton_clicked()
{   QString UsernameEtudiant = ui->UsernameEtudiant->text();

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/Noamane/Desktop/qtprjt/GestionDesNotesBD/gestionNotes.db");

    if(!database.open()){
        QMessageBox::information(this,"Not Open","DB Is Not Open ");
        return;
    }else{
        QMessageBox::information(this,"Open","DB was Open  ");
        querymodel=new QSqlQueryModel();
        querymodel->setQuery("SELECT studTable.NomEtud AS NomEtud, "
                             "studTable.PrenomEtud AS PrenomEtud, "
                             "Cours.TitreCcours AS TitreCours, "
                             "Note.Note AS NoteObtenue, "
                             "Note.DateEvaluation AS DateEvaluation "
                             "FROM Note "
                             "JOIN studTable ON Note.idEtudiant = studTable.NumEtud "
                             "JOIN Cours ON Note.idCours = Cours.CodeCcours;");

        ui->tableView->setModel(querymodel);
    }
}


void pageEtudiants2::on_Notifications_clicked()
{
    QMessageBox::information(this,"Open","Les Resultas sont pret ");
}

