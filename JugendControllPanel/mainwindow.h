#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "licht.h"
#include "pca_9635.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonLight_clicked();

private:
    Ui::MainWindow *ui;
    pca_9635 * pca;

    Licht *licht;
    int pcaInit;
    //Ui::Licht Licht;
};

#endif // MAINWINDOW_H
