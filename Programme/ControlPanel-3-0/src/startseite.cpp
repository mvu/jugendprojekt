#include "inc/startseite.h"
#include "ui_startseite.h"

Startseite::Startseite(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Startseite)
{
    ui->setupUi(this);
}

Startseite::~Startseite()
{
    delete ui;
}

void Startseite::on_pushButton_clicked()
{

}
