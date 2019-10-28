/*!
 * \file log.h
 * \brief Header der log() function
 */
#ifndef LOG_H
#define LOG_H

#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

/*!
 * \brief schreibt msg mit vorangestelltem Zeitstempel nach filename
 * \param file Ort des logfiles
 * \param msg zu speichernde Nachricht
 */
void log(QString file, QString msg);

#endif // LOG_H
