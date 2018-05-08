#ifndef MAINVISU_INFOBOARD_H
#define MAINVISU_INFOBOARD_H

#include <QDialog>
#include "mainconfig.h"

namespace Ui {
class MainVisu_InfoBoard;
}

class MainVisu_InfoBoard : public QDialog
{
    Q_OBJECT

public:
    explicit MainVisu_InfoBoard(QWidget *parent = 0, ModelThreadLicht *m = NULL);
    ~MainVisu_InfoBoard();

public slots:
    void afterAnimation();

private slots:

    void on_pushButton_Relais_released();

    void on_pushButton_Hauptlicht_released();

    void on_pushButton_Back_released();

    void on_pushButton_Temperatur_released();

    void on_pushButton_Main_released();

signals:

    void ParentEnable();
private:
    Ui::MainVisu_InfoBoard *ui;
    ModelThreadLicht *mThread;
    int merker;
};

#endif // MAINVISU_INFOBOARD_H
