#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QDebug>
#include "config.h"

#include "door.h"

class Cabin : public QObject
{
    Q_OBJECT;

    enum cabinStatus
    {
        FREE,
        WAIT,
        MOVING
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() = default;

public slots:
    void takeTarget(const size_t floor);
    void moving();
    void stopped(bool isLast, size_t newFloor = 1);
    void chooseState();

signals:
    void move();
    void passFloor(size_t floor);
    void openDoor();
    void stop(bool isLast = true, size_t newFloor = 1);

private:
    cabinStatus _state;
    Door _door;
    size_t _curFloor;
    size_t _needFloor;
    bool _newTarget;
    direction _dir;
    QTimer _moveTimer;
};

#endif // CABIN_H
