#ifndef PAGEPROFESSEURS_H
#define PAGEPROFESSEURS_H

#include <QDialog>

#include"saisirlesnotes.h"
#include"validernotes.h"

namespace Ui {
class PageProfesseurs;
}

class PageProfesseurs : public QDialog
{
    Q_OBJECT

public:
    explicit PageProfesseurs(QWidget *parent = nullptr);
    ~PageProfesseurs();

private slots:
    void on_EnregisterNotes_clicked();

    void on_ValiderNotes_clicked();

private:
    Ui::PageProfesseurs *ui;
    saisirLesNotes*ptrsaisirlesnotes;
    validerNotes*ptrvalidernotes;
};

#endif // PAGEPROFESSEURS_H
