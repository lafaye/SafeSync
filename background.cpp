#include "background.h"

background::background(QWidget *mbparent, QObject *parent) : QObject(parent), temp(mbparent)
{
    internalTimer = new QTimer(parent);
    internalTimer->setInterval(3000);
    connect (internalTimer, SIGNAL(timeout()), this, SLOT(verify()));
}

void background::startRunning()
{
    internalTimer->start();
}
void background::verify() {
    int currentHour = QTime::currentTime().hour();
    if (currentHour == 15) {
        if (done == true) {
            done = false;
            QString command = *commandPtr;
            int work = system (command.toStdString().c_str());
            (void)work;
        }
    } else {
        done = true;
        return;
    }
}
