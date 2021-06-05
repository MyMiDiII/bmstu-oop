#include "door.h"

Door::Door(QObject *parent) : QObject(parent)
{
    _state = CLOSED;
    qDebug() << "Дверь закрыта!";

    _openingTimer.setSingleShot(true);
    _closingTimer.setSingleShot(true);
    _openedTimer.setSingleShot(true);

    QObject::connect(&_openingTimer, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&_openedTimer, SIGNAL(timeout()), this, SLOT(closing()));
    QObject::connect(&_closingTimer, SIGNAL(timeout()), this, SLOT(closed()));
}

void Door::closing()
{
    if (OPENED == _state)
    {
        qDebug() << "Двери закрываются!";
        _state = CLOSING;

        _closingTimer.start(MOVINGDOORTIME);
    }
}


void Door::closed()
{
    if (CLOSING == _state)
    {
        qDebug() << "Двери закрыты!";
        _state = CLOSED;

        emit isClosed();
    }
}

void Door::opening()
{
    if (CLOSED == _state || CLOSING == _state)
    {
        qDebug() << "Двери открываются!";

        if (CLOSED == _state)
        {
            _state = OPENING;
            _openingTimer.start(MOVINGDOORTIME);
        }
        else
        {
            _state = OPENING;
            auto elapsedTime = _closingTimer.remainingTime();
            _closingTimer.stop();
            _openingTimer.start(MOVINGDOORTIME - elapsedTime);
        }
    }
}

void Door::opened()
{
    if (OPENING == _state)
    {
        qDebug() << "Двери открыты!";
        _state = OPENED;

        _openedTimer.start(OPENEDTIME);
    }
}
