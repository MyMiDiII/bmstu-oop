#include "elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    QObject::connect(&_cabin, SIGNAL(passFloor(size_t)),
                     &_controller, SLOT(passFloor(size_t)));
    QObject::connect(&_controller, SIGNAL(newTargetSignal(size_t)),
                     &_cabin, SLOT(takeTarget(size_t)));
    QObject::connect(&_controller, SIGNAL(stayOnFloor(bool,size_t)),
                     &_cabin, SLOT(stopped(bool,size_t)));
}

QWidget *Elevator::getController()
{
    return &_controller;
}
