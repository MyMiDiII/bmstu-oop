#include "cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _state = FREE;
    _curFloor = 1;
    _needFloor = 1;
    _dir = STOP;
    _newTarget = false;
    _moveTimer.setSingleShot(true);

    QObject::connect(&_door, SIGNAL(isClosed()), this, SLOT(chooseState()));
    QObject::connect(&_moveTimer, SIGNAL(timeout()), this, SLOT(moving()));
    QObject::connect(this, SIGNAL(stop(bool,size_t)), this, SLOT(stopped(bool,size_t)));
    QObject::connect(this, SIGNAL(move()), this, SLOT(moving()));
    QObject::connect(this, SIGNAL(openDoor()), &_door, SLOT(opening()));
}

void Cabin::takeTarget(const size_t floor)
{
    _newTarget = true;
    _needFloor = floor;
    _dir = _curFloor < _needFloor ? UP : (_curFloor == _needFloor ? STOP : DOWN);

    if (_state == FREE)
    {
        _state = WAIT;
        emit move();
    }
}

void Cabin::chooseState()
{
    if (_newTarget)
    {
        _state = WAIT;
        emit move();
    }
    else
    {
        _state = FREE;
    }
}


void Cabin::moving()
{
    if (WAIT == _state)
        _state = MOVING;
    else if (MOVING == _state)
        _curFloor += _dir;

    if (_curFloor == _needFloor)
        emit passFloor(_curFloor);
    else
    {
        qDebug() << "Этаж: " << _curFloor;
        _moveTimer.start(MOVECABINTIME);
    }
}

void Cabin::stopped(bool isLast, size_t newFloor)
{
    if (isLast)
        _newTarget = false;
    else
        _newTarget = true;

    _needFloor = newFloor;
    _dir = _curFloor < _needFloor ? UP : (_curFloor == _needFloor ? STOP : DOWN);
    _state = WAIT;
    emit openDoor();
}
