#include "inc/startseite.h"
#include "ui_startseite.h"

Startseite::Startseite(QWidget *parent, Jugendraum *j) :
    QMainWindow(parent),
    ui(new Ui::Startseite)
{
    ui->setupUi(this);
    jugendraum_ = j;
}

Startseite::~Startseite()
{
    delete ui;
    jugendraum_->shutdown();
}
