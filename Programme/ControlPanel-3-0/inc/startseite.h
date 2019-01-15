#ifndef STARTSEITE_H
#define STARTSEITE_H

#include <QMainWindow>

#include "inc/jugendraum.h"

namespace Ui {
class Startseite;
}

class Startseite : public QMainWindow
{
    Q_OBJECT

public:
    explicit Startseite(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~Startseite();

private slots:

private:
    Ui::Startseite *ui;
    Jugendraum *jugendraum_;
};

#endif // STARTSEITE_H
