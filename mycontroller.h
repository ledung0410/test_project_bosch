#ifndef MYCONTROLLER_H
#define MYCONTROLLER_H
#include <QObject>
#include <QQuickItem>

class mycontroller: public QObject
{
public:
    Q_OBJECT
       Q_PROPERTY(bool status READ status WRITE setStatus NOTIFY statusChanged)
   public:
       explicit mycontroller(QObject *parent = nullptr);
       Q_INVOKABLE bool getStatus();
       bool status();
   public slots:
       void setStatus(bool);

   signals:
       void statusChanged();

   private:
       bool m_status;

};

#endif // MYCONTROLLER_H
