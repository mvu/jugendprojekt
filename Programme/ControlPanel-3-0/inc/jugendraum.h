#ifndef JUGENDRAUM_H
#define JUGENDRAUM_H

#include <QObject>

class Jugendraum : public QObject
{
    Q_OBJECT
public:
    explicit Jugendraum(QObject *parent = nullptr);

signals:

public slots:
};

#endif // JUGENDRAUM_H