#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDateTime>
#include <QPushButton>
#include <iostream>

class Application final : public QApplication
{
public:
    Application(int& argc, char** argv);
    bool notify(QObject *receiver, QEvent *e);

private:
    qint64 timestamp;
};

#endif // APPLICATION_H
