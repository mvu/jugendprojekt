#ifndef EINSTELLUNG_H
#define EINSTELLUNG_H

#include <QDialog>

namespace Ui {
class einstellung;
}

class einstellung : public QDialog
{
    Q_OBJECT

public:
    explicit einstellung(QWidget *parent = 0);
    ~einstellung();

private:
    Ui::einstellung *ui;
};

#endif // EINSTELLUNG_H
