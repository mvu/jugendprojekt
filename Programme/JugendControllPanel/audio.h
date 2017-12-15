#ifndef AUDIO_H
#define AUDIO_H

#include <QDialog>
#include <mainconfig.h>

namespace Ui {
class Audio;
}

class Audio : public QDialog
{
    Q_OBJECT

public:
    explicit Audio(QWidget *parent = 0, steuerungThreadLicht *s = NULL, ModelThreadLicht *m = NULL);
    ~Audio();

signals:
    void beamer(bool);
    void pc();
    void ParentEnable();

private slots:
    void on_pushButtonAUX_released();
    void on_pushButtonPlaystation_released();
    void on_pushButton_back_released();

    void afterAnimation();

    void on_pushButton_OnOff_toggled(bool checked);

    void on_pushButtonLautstaerke_Leise_released();

    void on_pushButtonLautstaerke_Mittel_released();

    void on_pushButtonLautstaerke_Laut_released();

    void on_pushButtonPC_released();

private:
    Ui::Audio *ui;
    steuerungThreadLicht *sThread;
    ModelThreadLicht *mThread;
    QProcess *process;
};

#endif // AUDIO_H
