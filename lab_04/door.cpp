#include "door.h"

// !!!!!!!!!!!!!!!!!!!!!
// !!!  openedTimer  !!!
// !!!!!!!!!!!!!!!!!!!!!

Door::Door(QObject *parent) : QObject(parent)
{
    _state = OPENED;

    _openingTimer.setSingleShot(true);
    _closingTimer.setSingleShot(true);
    _openedTimer.setSingleShot(true);

    _openingTimer.setInterval(1);
    _closingTimer.setInterval(1);
    _openedTimer.setInterval(1);

    // связь сигналов
}

void Door::closing()
{
    if (OPENED == _state)
    {
        qDebug() << "Двери закрываются!";
        _state = CLOSING;

        emit startClosingTimer();
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
    if (CLOSED == _state)
    {
        qDebug() << "Двери открываются!";
        _state = OPENING;

        emit startOpeningTimer();
    }
}

void Door::opened()
{
    if (OPENING == _state)
    {
        qDebug() << "Двери открыты!";
        _state = OPENED;

        emit isOpened();
    }
}
