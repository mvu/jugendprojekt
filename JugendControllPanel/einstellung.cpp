#include "einstellung.h"
#include "ui_einstellung.h"

einstellung::einstellung(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::einstellung)
{
    ui->setupUi(this);
}

einstellung::~einstellung()
{
    delete ui;
}
