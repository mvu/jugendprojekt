/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_right;
    QGroupBox *groupBox_clock;
    QPushButton *pushButton_clock;
    QLabel *label_uhrzeit;
    QLabel *label_datum;
    QGroupBox *groupBox_audio;
    QFrame *frame_10;
    QLabel *label_audio;
    QPushButton *pushButton_audio;
    QGroupBox *groupBox_system;
    QFrame *frame_2;
    QLabel *label_system;
    QPushButton *pushButton_system;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_left;
    QGroupBox *groupBox_jugend;
    QFrame *frame_11;
    QLabel *label_lugend;
    QPushButton *pushButton_jugend;
    QLabel *label_lugend_2;
    QGroupBox *groupBox_teenkreis;
    QFrame *frame_12;
    QLabel *label_teenkreis;
    QPushButton *pushButton_teenkreis;
    QLabel *label_teenkreis_2;
    QGroupBox *groupBox_lichteinstellung;
    QFrame *frame_13;
    QLabel *label_lichteinstellung;
    QPushButton *pushButton_lichteinstellung;
    QFrame *background_frame;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setMinimumSize(QSize(800, 480));
        MainWindow->setMaximumSize(QSize(800, 480));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(400, 0, 401, 481));
        verticalLayout_right = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_right->setSpacing(15);
        verticalLayout_right->setContentsMargins(11, 11, 11, 11);
        verticalLayout_right->setObjectName(QStringLiteral("verticalLayout_right"));
        verticalLayout_right->setContentsMargins(7, 15, 15, 15);
        groupBox_clock = new QGroupBox(verticalLayoutWidget_2);
        groupBox_clock->setObjectName(QStringLiteral("groupBox_clock"));
        groupBox_clock->setStyleSheet(QStringLiteral("background-color:rgba(0, 0, 0, 0);"));
        groupBox_clock->setFlat(true);
        groupBox_clock->setCheckable(false);
        pushButton_clock = new QPushButton(groupBox_clock);
        pushButton_clock->setObjectName(QStringLiteral("pushButton_clock"));
        pushButton_clock->setGeometry(QRect(0, 0, 379, 140));
        pushButton_clock->setFocusPolicy(Qt::NoFocus);
        pushButton_clock->setFlat(true);
        label_uhrzeit = new QLabel(groupBox_clock);
        label_uhrzeit->setObjectName(QStringLiteral("label_uhrzeit"));
        label_uhrzeit->setEnabled(false);
        label_uhrzeit->setGeometry(QRect(0, 0, 379, 51));
        QPalette palette;
        QBrush brush(QColor(231, 231, 231, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_uhrzeit->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans Light"));
        font.setPointSize(36);
        label_uhrzeit->setFont(font);
        label_uhrzeit->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_uhrzeit->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        label_datum = new QLabel(groupBox_clock);
        label_datum->setObjectName(QStringLiteral("label_datum"));
        label_datum->setEnabled(false);
        label_datum->setGeometry(QRect(0, 50, 379, 50));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_datum->setPalette(palette1);
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans Light"));
        font1.setPointSize(12);
        label_datum->setFont(font1);
        label_datum->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_datum->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_datum->raise();
        label_uhrzeit->raise();
        pushButton_clock->raise();

        verticalLayout_right->addWidget(groupBox_clock);

        groupBox_audio = new QGroupBox(verticalLayoutWidget_2);
        groupBox_audio->setObjectName(QStringLiteral("groupBox_audio"));
        groupBox_audio->setStyleSheet(QStringLiteral("background-color:rgba(0, 0, 0, 100);"));
        groupBox_audio->setFlat(true);
        groupBox_audio->setCheckable(false);
        frame_10 = new QFrame(groupBox_audio);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setGeometry(QRect(260, 20, 100, 100));
        frame_10->setStyleSheet(QLatin1String("background-image:url(:/bilder/Icons/audio.png);\n"
"background-color:rgba(0,0,0,0);"));
        frame_10->setFrameShape(QFrame::NoFrame);
        frame_10->setFrameShadow(QFrame::Plain);
        frame_10->setLineWidth(1);
        label_audio = new QLabel(groupBox_audio);
        label_audio->setObjectName(QStringLiteral("label_audio"));
        label_audio->setEnabled(false);
        label_audio->setGeometry(QRect(20, 0, 219, 140));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_audio->setPalette(palette2);
        QFont font2;
        font2.setFamily(QStringLiteral("DejaVu Sans Light"));
        label_audio->setFont(font2);
        label_audio->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_audio->setFrameShadow(QFrame::Plain);
        label_audio->setAlignment(Qt::AlignCenter);
        pushButton_audio = new QPushButton(groupBox_audio);
        pushButton_audio->setObjectName(QStringLiteral("pushButton_audio"));
        pushButton_audio->setGeometry(QRect(0, 0, 379, 140));
        pushButton_audio->setFocusPolicy(Qt::NoFocus);
        pushButton_audio->setFlat(true);

        verticalLayout_right->addWidget(groupBox_audio);

        groupBox_system = new QGroupBox(verticalLayoutWidget_2);
        groupBox_system->setObjectName(QStringLiteral("groupBox_system"));
        groupBox_system->setMouseTracking(false);
        groupBox_system->setStyleSheet(QStringLiteral("background-color:rgba(0, 0, 0, 100);"));
        groupBox_system->setFlat(true);
        groupBox_system->setCheckable(false);
        frame_2 = new QFrame(groupBox_system);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(259, 20, 100, 100));
        frame_2->setStyleSheet(QLatin1String("background-image:url(:/bilder/Icons/settings.png);\n"
"background-color:rgba(0,0,0,0);"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Plain);
        label_system = new QLabel(groupBox_system);
        label_system->setObjectName(QStringLiteral("label_system"));
        label_system->setEnabled(false);
        label_system->setGeometry(QRect(20, 0, 219, 140));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_system->setPalette(palette3);
        label_system->setFont(font2);
        label_system->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_system->setAlignment(Qt::AlignCenter);
        pushButton_system = new QPushButton(groupBox_system);
        pushButton_system->setObjectName(QStringLiteral("pushButton_system"));
        pushButton_system->setGeometry(QRect(0, 0, 379, 140));
        pushButton_system->setFocusPolicy(Qt::NoFocus);
        pushButton_system->setToolTipDuration(-1);
        pushButton_system->setFlat(true);

        verticalLayout_right->addWidget(groupBox_system);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 401, 481));
        verticalLayout_left = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_left->setSpacing(15);
        verticalLayout_left->setContentsMargins(11, 11, 11, 11);
        verticalLayout_left->setObjectName(QStringLiteral("verticalLayout_left"));
        verticalLayout_left->setContentsMargins(15, 15, 7, 15);
        groupBox_jugend = new QGroupBox(verticalLayoutWidget_3);
        groupBox_jugend->setObjectName(QStringLiteral("groupBox_jugend"));
        groupBox_jugend->setStyleSheet(QStringLiteral("background-color:rgba(0, 0, 0, 100);"));
        groupBox_jugend->setFlat(true);
        groupBox_jugend->setCheckable(false);
        frame_11 = new QFrame(groupBox_jugend);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setGeometry(QRect(30, 20, 95, 100));
        frame_11->setStyleSheet(QLatin1String("background-image:url(:/bilder/Icons/jugend.png);\n"
"background-color:rgba(0,0,0,0);"));
        frame_11->setFrameShape(QFrame::NoFrame);
        frame_11->setFrameShadow(QFrame::Plain);
        label_lugend = new QLabel(groupBox_jugend);
        label_lugend->setObjectName(QStringLiteral("label_lugend"));
        label_lugend->setEnabled(false);
        label_lugend->setGeometry(QRect(140, 0, 219, 90));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_lugend->setPalette(palette4);
        label_lugend->setFont(font);
        label_lugend->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_lugend->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_lugend->setMargin(1);
        pushButton_jugend = new QPushButton(groupBox_jugend);
        pushButton_jugend->setObjectName(QStringLiteral("pushButton_jugend"));
        pushButton_jugend->setGeometry(QRect(0, 0, 379, 140));
        pushButton_jugend->setFocusPolicy(Qt::NoFocus);
        pushButton_jugend->setFlat(true);
        label_lugend_2 = new QLabel(groupBox_jugend);
        label_lugend_2->setObjectName(QStringLiteral("label_lugend_2"));
        label_lugend_2->setEnabled(false);
        label_lugend_2->setGeometry(QRect(140, 90, 219, 50));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_lugend_2->setPalette(palette5);
        label_lugend_2->setFont(font1);
        label_lugend_2->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_lugend_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_lugend_2->setMargin(1);
        frame_11->raise();
        label_lugend->raise();
        label_lugend_2->raise();
        pushButton_jugend->raise();

        verticalLayout_left->addWidget(groupBox_jugend);

        groupBox_teenkreis = new QGroupBox(verticalLayoutWidget_3);
        groupBox_teenkreis->setObjectName(QStringLiteral("groupBox_teenkreis"));
        groupBox_teenkreis->setStyleSheet(QStringLiteral("background-color:rgba(0, 0, 0, 100);"));
        groupBox_teenkreis->setFlat(true);
        groupBox_teenkreis->setCheckable(false);
        frame_12 = new QFrame(groupBox_teenkreis);
        frame_12->setObjectName(QStringLiteral("frame_12"));
        frame_12->setGeometry(QRect(30, 48, 100, 42));
        frame_12->setStyleSheet(QLatin1String("background-image:url(:/bilder/Icons/fish.png);\n"
"background-color:rgba(0,0,0,0);"));
        frame_12->setFrameShape(QFrame::NoFrame);
        frame_12->setFrameShadow(QFrame::Plain);
        label_teenkreis = new QLabel(groupBox_teenkreis);
        label_teenkreis->setObjectName(QStringLiteral("label_teenkreis"));
        label_teenkreis->setEnabled(false);
        label_teenkreis->setGeometry(QRect(140, 0, 231, 90));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_teenkreis->setPalette(palette6);
        label_teenkreis->setFont(font);
        label_teenkreis->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_teenkreis->setTextFormat(Qt::PlainText);
        label_teenkreis->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        label_teenkreis->setMargin(0);
        pushButton_teenkreis = new QPushButton(groupBox_teenkreis);
        pushButton_teenkreis->setObjectName(QStringLiteral("pushButton_teenkreis"));
        pushButton_teenkreis->setGeometry(QRect(0, 0, 379, 140));
        pushButton_teenkreis->setFocusPolicy(Qt::NoFocus);
        pushButton_teenkreis->setFlat(true);
        label_teenkreis_2 = new QLabel(groupBox_teenkreis);
        label_teenkreis_2->setObjectName(QStringLiteral("label_teenkreis_2"));
        label_teenkreis_2->setEnabled(false);
        label_teenkreis_2->setGeometry(QRect(140, 90, 219, 50));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_teenkreis_2->setPalette(palette7);
        label_teenkreis_2->setFont(font1);
        label_teenkreis_2->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_teenkreis_2->setTextFormat(Qt::PlainText);
        label_teenkreis_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_teenkreis_2->setMargin(0);
        frame_12->raise();
        label_teenkreis->raise();
        label_teenkreis_2->raise();
        pushButton_teenkreis->raise();

        verticalLayout_left->addWidget(groupBox_teenkreis);

        groupBox_lichteinstellung = new QGroupBox(verticalLayoutWidget_3);
        groupBox_lichteinstellung->setObjectName(QStringLiteral("groupBox_lichteinstellung"));
        groupBox_lichteinstellung->setStyleSheet(QStringLiteral("background-color:rgba(0, 0, 0, 100);"));
        groupBox_lichteinstellung->setFlat(true);
        groupBox_lichteinstellung->setCheckable(false);
        frame_13 = new QFrame(groupBox_lichteinstellung);
        frame_13->setObjectName(QStringLiteral("frame_13"));
        frame_13->setGeometry(QRect(30, 20, 100, 100));
        frame_13->setStyleSheet(QLatin1String("background-image:url(:/bilder/Icons/lampe.png);\n"
"background-color:rgba(0,0,0,0);"));
        frame_13->setFrameShape(QFrame::NoFrame);
        frame_13->setFrameShadow(QFrame::Plain);
        label_lichteinstellung = new QLabel(groupBox_lichteinstellung);
        label_lichteinstellung->setObjectName(QStringLiteral("label_lichteinstellung"));
        label_lichteinstellung->setEnabled(false);
        label_lichteinstellung->setGeometry(QRect(140, 0, 219, 140));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_lichteinstellung->setPalette(palette8);
        label_lichteinstellung->setFont(font2);
        label_lichteinstellung->setStyleSheet(QStringLiteral("background-color:rgba(0,0,0,0);"));
        label_lichteinstellung->setAlignment(Qt::AlignCenter);
        pushButton_lichteinstellung = new QPushButton(groupBox_lichteinstellung);
        pushButton_lichteinstellung->setObjectName(QStringLiteral("pushButton_lichteinstellung"));
        pushButton_lichteinstellung->setGeometry(QRect(0, 0, 379, 140));
        pushButton_lichteinstellung->setFocusPolicy(Qt::NoFocus);
        pushButton_lichteinstellung->setFlat(true);

        verticalLayout_left->addWidget(groupBox_lichteinstellung);

        background_frame = new QFrame(centralWidget);
        background_frame->setObjectName(QStringLiteral("background_frame"));
        background_frame->setGeometry(QRect(0, 0, 799, 480));
        background_frame->setStyleSheet(QStringLiteral("background-image:url(:/bilder/Icons/back_small.png);"));
        background_frame->setFrameShape(QFrame::StyledPanel);
        background_frame->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralWidget);
        background_frame->raise();
        verticalLayoutWidget_2->raise();
        verticalLayoutWidget_3->raise();

        retranslateUi(MainWindow);

        pushButton_audio->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Startseite", Q_NULLPTR));
        groupBox_clock->setTitle(QString());
        pushButton_clock->setText(QString());
        label_uhrzeit->setText(QApplication::translate("MainWindow", "22:27", Q_NULLPTR));
        label_datum->setText(QApplication::translate("MainWindow", "20. April", Q_NULLPTR));
        groupBox_audio->setTitle(QString());
        label_audio->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Medien</span></p></body></html>", Q_NULLPTR));
        pushButton_audio->setText(QString());
        groupBox_system->setTitle(QString());
        label_system->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">System</span></p></body></html>", Q_NULLPTR));
        pushButton_system->setText(QString());
        groupBox_jugend->setTitle(QString());
        label_lugend->setText(QApplication::translate("MainWindow", "Jugend", Q_NULLPTR));
        pushButton_jugend->setText(QString());
        label_lugend_2->setText(QApplication::translate("MainWindow", "Licht an", Q_NULLPTR));
        groupBox_teenkreis->setTitle(QString());
        label_teenkreis->setText(QApplication::translate("MainWindow", "Teenkreis", Q_NULLPTR));
        pushButton_teenkreis->setText(QString());
        label_teenkreis_2->setText(QApplication::translate("MainWindow", "Licht an", Q_NULLPTR));
        groupBox_lichteinstellung->setTitle(QString());
        label_lichteinstellung->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt;\">Licht</span><br/><span style=\" font-size:12pt;\">Einstellungen</span></p></body></html>", Q_NULLPTR));
        pushButton_lichteinstellung->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
