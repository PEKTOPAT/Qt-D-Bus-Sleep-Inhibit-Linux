#ifndef IDLE_LINUX_H
#define IDLE_LINUX_H

#include <QtDBus>

class idle_linux: public QObject
{
public:
    idle_linux();
    void preventDisplay(const QString &reason);
    void allowDisplay();


private:
    quint32 my_cookie[];
};

#endif // IDLE_LINUX_H
