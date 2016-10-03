#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Thread : public QObject
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = 0);
    void threadInit(QThread &cThread);
	bool Stop;


signals:
    void ValSlider(int);

public slots:
    void threadEinstellungHauptlicht();

};

#endif // THREAD_H
