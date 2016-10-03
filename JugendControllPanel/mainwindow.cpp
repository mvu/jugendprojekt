#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "licht.h"
#include "pca_9635.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    pcaInit = pca->pca9635Setup(0x3f);
    for (int i = 2; i <= 16; i++)
    {
     pca->pca9635PWMWrite(pcaInit, i , 0xff);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLight_clicked()
{
    licht = new Licht(this);
    licht->show();

}
