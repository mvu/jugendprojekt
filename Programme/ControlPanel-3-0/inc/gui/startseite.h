#ifndef STARTSEITE_H
#define STARTSEITE_H

#include <QMainWindow>

#include "../model/jugendraum.h"

//! Namespace der GUI, den von Qt von Haus aus verwendet.
namespace Ui {
class Startseite;
}

/*!
 * \brief GUI: Startseite
 */
class Startseite : public QMainWindow
{
    Q_OBJECT

public:
    explicit Startseite(QWidget *parent = nullptr, Jugendraum *j = nullptr);
    ~Startseite();

private slots:
    void on_pushButton_youth_released();
    void on_pushButton_teen_released();
    void on_pushButton_light_released();
    void on_pushButton_media_released();
    void on_pushButton_system_released();

private:
    Ui::Startseite *ui;
    Jugendraum *jugendraum_;
};

#endif // STARTSEITE_H
