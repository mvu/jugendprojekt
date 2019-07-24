/*!
 * \file log.cpp
 * \brief Source der log() function
 */
#include "inc/log.h"

void log(QString file, QString msg)
{
    qDebug() << Q_FUNC_INFO;

    QString log_msg = QDateTime::currentDateTime().toString("[ dd-MM-yy/hh:mm:ss ] ").append(msg);

    QFile logfile(file);
    if (logfile.open(QIODevice::Append))
    {
        QTextStream logstream(&logfile);
        logstream << QDateTime::currentDateTime().toString("[ dd-MM-yy/hh:mm:ss ] ");
        logstream << msg << endl;
    }
}
