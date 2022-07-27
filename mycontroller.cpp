#include "mycontroller.h"

mycontroller::mycontroller(QObject *parent)
: QObject{parent}
{
    m_status = true;
}

bool mycontroller::getStatus()
{
    return m_status;
}

bool mycontroller::status()
{
    return m_status;
}

void mycontroller::setStatus(bool newStatus)
{
    if (m_status == newStatus)
        return;
    m_status = newStatus;
    emit statusChanged();
}
