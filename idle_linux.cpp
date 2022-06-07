#include "idle_linux.h"

#define MAX_SERVICES 2

idle_linux::idle_linux()

{

}
void idle_linux::preventDisplay(const QString &reason)
{
    if(QDBusConnection::sessionBus().isConnected())
    {
        QString services[MAX_SERVICES] = {
            "org.gnome.SessionManager",
            "org.freedesktop.ScreenSaver"
        };
        QString paths[MAX_SERVICES] = {
            "/org/gnome/SessionManager",
            "/org/freedesktop/ScreenSaver"
        };
        for (int i = 0; i < MAX_SERVICES ; i++)
        {
            QDBusInterface *screenSaverInterface;
            screenSaverInterface = new QDBusInterface(services[i], paths[i], services[i], QDBusConnection::sessionBus());
            if (!screenSaverInterface->isValid()) continue;
            QDBusReply <quint32> reply = screenSaverInterface->call("Inhibit", QCoreApplication::applicationName(), reason);
            if (reply.isValid())
            {
                my_cookie[i] = reply.value();
                //qDebug() << "screenKeepOn() succesful:" << reply << " from " << services[i];
            }
            else
            {
                QDBusError error = reply.error();
                //qWarning() << "screenKeepOn() error:" << error.message() << error.name();
            }
        }
    }
}
void idle_linux::allowDisplay()
{
    QString services[MAX_SERVICES] = {
        "org.gnome.SessionManager",
        "org.freedesktop.ScreenSaver"
    };
    QString paths[MAX_SERVICES] = {
        "/org/gnome/SessionManager",
        "/org/freedesktop/ScreenSaver"
    };
    for (int i = 0; i < MAX_SERVICES ; i++)
    {
        QDBusInterface *screenSaverInterface;
        screenSaverInterface = new QDBusInterface(services[i], paths[i], services[i], QDBusConnection::sessionBus());
        if (!screenSaverInterface->isValid()) continue;
        QDBusReply<uint> reply = screenSaverInterface->call("UnInhibit", my_cookie[i]);
        QDBusError err = screenSaverInterface->lastError();
        if (err.isValid()) {
            //qDebug() << "UnInhibit screensaver error:" << err.message();
        }
    }
}




