#ifndef STARTSEITE_H
#define STARTSEITE_H

#include <QMainWindow>

namespace Ui {
class Startseite;
}

class Startseite : public QMainWindow
{
    Q_OBJECT

public:
    explicit Startseite(QWidget *parent = nullptr);
    ~Startseite();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Startseite *ui;
};

#endif // STARTSEITE_H
