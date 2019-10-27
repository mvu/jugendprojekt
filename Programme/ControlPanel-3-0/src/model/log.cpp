/*!
 * \file log.cpp
 * \brief Source der log() function
 */
#include "inc/model/log.h"

void log(QString file, QString msg)
{
    qDebug() << Q_FUNC_INFO;

    QFile logfile(file);
    if (logfile.open(QIODevice::Append))
    {
        QTextStream logstream(&logfile);
        logstream << QDateTime::currentDateTime().toString("[ yyyy-MM-dd hh:mm:ss ] ");
        logstream << msg << endl;
    }
}
