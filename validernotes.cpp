#include "validernotes.h"
#include "ui_validernotes.h"

validerNotes::validerNotes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::validerNotes)
{
    ui->setupUi(this);
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

validerNotes::~validerNotes()
{
    delete ui;
}
