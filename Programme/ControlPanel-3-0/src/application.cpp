#include "inc/application.h"

Application::Application(int& argc, char** argv) : QApplication(argc, argv)
{
    timestamp_ = 0;
}

bool Application::notify(QObject *receiver, QEvent *event)
{
    QPushButton *button = qobject_cast<QPushButton*>(receiver);

    if ((button != nullptr) && (event->type() == QEvent::MouseButtonRelease)) {
        // check time to last event
        qint64 time_passed = QDateTime::currentMSecsSinceEpoch() - timestamp_;
        if(time_passed > min_time_passed_ms_)
        {
            timestamp_ = QDateTime::currentMSecsSinceEpoch();
            return QApplication::notify(receiver, event);
        }
        else
        {
            return true;
        }
    } else {
        // standard event processing
        return QApplication::notify(receiver, event);
    }
}
