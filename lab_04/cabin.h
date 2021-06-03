#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "config.h"

#include "door.h"

class Cabin : public QObject
{
    Q_OBJECT;

    enum cabinStatus
    {
        FREE,
        GET,
        MOVING
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() = default;

public slots:
    void takeTarget(const size_t floor);
    void moving();
    void stopped(bool isLast, size_t newFloor = 1);

signals:
    void move();
    void passFloor(const size_t floor, direction dir);
    void openDoor();

private:
    cabinStatus _state;
    Door _door;
    size_t _curFloor;
    size_t _needFloor;
    direction _dir;
    QTimer moveTimer;
};

#endif // CABIN_H
