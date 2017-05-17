#ifndef AUDIO_H
#define AUDIO_H

#include <QDialog>

namespace Ui {
class Audio;
}

class Audio : public QDialog
{
    Q_OBJECT

public:
    explicit Audio(QWidget *parent = 0);
    ~Audio();

private:
    Ui::Audio *ui;
};

#endif // AUDIO_H
