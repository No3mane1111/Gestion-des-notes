#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "platrformeetud.h"
#include "registerstudent.h"
#include "loginstudent.h"
#include "loginprofesseur.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_RegisterStudent_clicked();

    void on_RegisterProfesseurr_clicked();

private:
    Ui::MainWindow *ui;
    RegisterStudent*ptrRegisterStudent;
    loginProfesseur*ptrloginProfesseur;
    loginStudent*ptrloginStudent;
    PlatrformeEtud*ptrPlatformeEtud;
};
#endif // MAINWINDOW_H
