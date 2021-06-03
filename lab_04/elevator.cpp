#include "elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{

}

QWidget *Elevator::getController()
{
    return &_controller;
}
