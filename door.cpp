#include "door.h"

Door::Door(int pin, int doorType, QObject *parent) : QObject(parent)
{
    this->pin = pin;
    this->doorType = doorType;

    wiringPiSetup();

    pinMode(pin, OUTPUT);
    digitalWrite(pin,doorType == Door::OPERATE_ON_CLOSE_CIRCUIT? LOW : HIGH);
}

Door::~Door()
{

}


void Door::openDoor()
{
    QString t = Configurator::instance()->getConfig("tiempoApertura");
    bool ok;
    t.replace(",",".");
    float tempo = t.toFloat(&ok);
    tempo = tempo == 0 || !ok ? 1 : tempo;
    int ti = tempo * 1000;

    qDebug() << "Door open for " << ti << "milli seconds";

    if(doorType == Door::OPERATE_ON_CLOSE_CIRCUIT)
    {
        digitalWrite(pin,HIGH);
        delay(ti);
        digitalWrite(pin,LOW);

    } else {

        digitalWrite(pin,LOW);
        delay(ti);
        digitalWrite(pin,HIGH);
    }

}
