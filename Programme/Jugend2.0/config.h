#ifndef CONFIG_H
#define CONFIG_H

#include <QDialog>
#include <mainconfig.h>
#include <arduinocommunication.h>

namespace Ui {
class config;
}

class config : public QDialog
{
    Q_OBJECT

public:
    explicit config(QWidget *parent = 0);
    ~config();

private slots:
    void on_pushButton_PCA_Config_released();

    void on_pushButton_Temperatur_released();

    void on_pushButton_Einstellung_released();

    void on_pushButton_LuefterConfig_released();

private:
    Ui::config *ui;
};

#endif // CONFIG_H
