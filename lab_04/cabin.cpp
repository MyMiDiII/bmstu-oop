#include "cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent)
{
    _state = FREE;
    _curFloor = 1;
    _needFloor = 1;
    _dir = STOP;

    // связи
}

void Cabin::takeTarget(const size_t floor)
{
    _state = GET;
    _needFloor = floor;

    if (_curFloor == _needFloor)
    {
        emit passFloor(_curFloor, _dir);
    }
    else
    {
        _dir = _curFloor < _needFloor ? UP : DOWN;
        emit move();
    }

}

void Cabin::moving()
{
    if (MOVING == _state || GET == _state)
    {
        _state = MOVING;
        moveTimer.start(1);

        QDegug() << "Этаж: " << _curFloor;
        emit passFloor(_curFloor, _dir);

        if (_curFloor != _needFloor)
        {
            _dir = _curFloor < _needFloor ? UP : DOWN;
            _curFloor = _curFloor + _dir;
            // ??? emit move();
        }
    }
}

void Cabin::stopped(bool isLast, size_t newFloor)
{
    if (isLast)
    {
        _state = FREE;
    }
    else
    {
        _state = GET;
        _needFloor = newFloor;
    }

    moveTimer.stop();
    emit openDoor();
}
