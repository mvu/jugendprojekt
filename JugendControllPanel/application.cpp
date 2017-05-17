#include "application.h"

Application::Application(int& argc, char** argv) : QApplication(argc, argv)
{
    timestamp = 0;
}

bool Application::notify(QObject *receiver, QEvent *e)
{
    QPushButton *button = qobject_cast<QPushButton*>(receiver);

    if ((button != NULL) && (e->type() == QEvent::MouseButtonRelease)) {
        qint64 timePassed = QDateTime::currentMSecsSinceEpoch() - timestamp;
        //std::cout << receiver->objectName().toStdString() << timePassed << "\n";
        if(timePassed > 100)
        {
            timestamp = QDateTime::currentMSecsSinceEpoch();
            return QApplication::notify(receiver, e);
        }
        else
        {
            return true;
        }
    } else {
        // standard event processing
        return QApplication::notify(receiver, e);
    }
}
