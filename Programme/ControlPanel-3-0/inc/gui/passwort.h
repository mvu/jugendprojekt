/*!
 * \file passwort.h
 * \brief Header der Passwort GUI
 */
#ifndef PASSWORT_H
#define PASSWORT_H

#include <QDialog>
#include <QByteArray>
#include <QString>
#include <QCryptographicHash>
#include <QDebug>

#include "inc/model/jugendraum.h"

namespace Ui {
class Passwort;
}

/*!
 * \brief Klasse der Passwort GUI
 * \details Fragt nach einem Passwort. Der SHA256 Hash des eingegebenen
 *      Passwortes wird mit dem übergebenen verglichen und Übereinstimmung
 *      das Signal PasswortCorrect() gesndet.
 */
class Passwort : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Erzeugt eine Passwort GUI
     * \param parent Erzeugendes QWidget
     * \param j Pointer auf das Jugendraum Model
     * \param correct_password_hash Der SHA256 hash des korrekten passwortes
     */
    explicit Passwort(QWidget *parent = nullptr, Jugendraum *j = nullptr, QByteArray correct_password_hash = nullptr);
    /*!
     * \brief Löscht das Passwort Objekt
     */
    ~Passwort();

private slots:
    void ResetEnteredPassword();

    void on_pushButton_1_released(); //!< Zahl 1 für Passwort eingegeben
    void on_pushButton_2_released(); //!< Zahl 2 für Passwort eingegeben
    void on_pushButton_3_released(); //!< Zahl 3 für Passwort eingegeben
    void on_pushButton_4_released(); //!< Zahl 4 für Passwort eingegeben
    void on_pushButton_5_released(); //!< Zahl 5 für Passwort eingegeben
    void on_pushButton_6_released(); //!< Zahl 6 für Passwort eingegeben
    void on_pushButton_7_released(); //!< Zahl 7 für Passwort eingegeben
    void on_pushButton_8_released(); //!< Zahl 8 für Passwort eingegeben
    void on_pushButton_9_released(); //!< Zahl 9 für Passwort eingegeben
    void on_pushButton_0_released(); //!< Zahl 0 für Passwort eingegeben
    /*!
     * \brief Der SHA256Hash des eingegebenen Passworts wird mit dem
     *      geforderten verglichen
     */
    void on_pushButton_ok_released();
    /*!
     * \brief Wenn kein Passwort eingegeben ist, lösche das Objekt;
     *      ansonsten entferne das zuletzt eingegebene Zeichen.
     */
    void on_pushButton_back_released();

signals:
    void PasswortCorrect(); //!< Wird gesendet, wenn das richtige Passwort eingegeben wurde


private:
    Ui::Passwort *ui_;
    Jugendraum *jugendraum_;
    QByteArray correct_password_hash_;  //!< Der erwartete Hash
    QByteArray tmp_password_raw_;       //!< Das eingebene Passwort
};

#endif // PASSWORT_H
