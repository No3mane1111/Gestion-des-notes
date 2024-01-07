#include "pageprofesseurs.h"
#include "ui_pageprofesseurs.h"

PageProfesseurs::PageProfesseurs(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PageProfesseurs)
{
    ui->setupUi(this);
    ptrsaisirlesnotes = new saisirLesNotes;
    ptrvalidernotes = new validerNotes;
}

PageProfesseurs::~PageProfesseurs()
{
    delete ptrvalidernotes;
    delete ptrsaisirlesnotes;
    delete ui;

}

void PageProfesseurs::on_EnregisterNotes_clicked()
{
    ptrsaisirlesnotes->show();
}


void PageProfesseurs::on_ValiderNotes_clicked()
{
    ptrvalidernotes->show();
}

