#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>

#include "communicator.h"
#include "polinom.h"

class TApplication : public QCoreApplication
{
    Q_OBJECT

    TCommunicator *comm;

    TPolinom p;

public:

    TApplication(int, char**);

signals:

public slots:

    void recieve(QByteArray);

};

#endif // APPLICATION_H
