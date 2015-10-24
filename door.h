#ifndef DOOR_H
#define DOOR_H

#include <QDebug>
#include <wiringPi.h>
#include <configurator.h>

class Door : public QObject
{
    Q_OBJECT

public:
     Door(int pin, int doorType = Door::OPERATE_ON_CLOSE_CIRCUIT, QObject *parent = 0);
    ~Door();

     enum DoorType {
         OPERATE_ON_CUT_CIRCUIT = 1,
         OPERATE_ON_CLOSE_CIRCUIT = 2
     };

private:
     int pin;
protected:
     int doorType;

public slots:
    void openDoor();
};


#endif // DOOR_H

