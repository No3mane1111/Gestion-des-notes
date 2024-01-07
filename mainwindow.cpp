#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrRegisterStudent = new RegisterStudent();
    ptrloginProfesseur = new loginProfesseur();
    ptrloginStudent = new loginStudent();
    ptrPlatformeEtud = new PlatrformeEtud();
}

MainWindow::~MainWindow()
{

    delete ptrRegisterStudent;
    delete ptrPlatformeEtud;
    delete ptrloginProfesseur;
    delete ptrloginStudent;
    delete ui;

}

void MainWindow::on_RegisterStudent_clicked()
{
    ptrRegisterStudent->show();

}


void MainWindow::on_RegisterProfesseurr_clicked()
{
    ptrPlatformeEtud->show();
}

