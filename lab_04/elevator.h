#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>

#include "controller.h"
#include "cabin.h"

class Elevator : public QObject
{
    Q_OBJECT
public:
    explicit Elevator(QObject *parent = nullptr);
    ~Elevator() = default;

    QWidget *getController();

private:
    Controller _controller;
    Cabin _cabin;
};

#endif // ELEVATOR_H
