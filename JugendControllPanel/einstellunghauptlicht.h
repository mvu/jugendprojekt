#ifndef EINSTELLUNGHAUPTLICHT_H
#define EINSTELLUNGHAUPTLICHT_H

#include <QDialog>
#include "thread.h"

namespace Ui {
class EinstellungHauptlicht;
}

class EinstellungHauptlicht : public QDialog
{
    Q_OBJECT

public:
    explicit EinstellungHauptlicht(QWidget *parent = 0);
    ~EinstellungHauptlicht();
    Thread * mThread;

private:
    Ui::EinstellungHauptlicht *ui;

public slots:

    void onValSliderChanged(int);


private slots:
    //void on_start_clicked();
    void on_pushButton_clicked();
};

#endif // EINSTELLUNGHAUPTLICHT_H
