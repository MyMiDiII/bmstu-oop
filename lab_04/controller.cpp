#include "controller.h"
#include <QString>

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    _layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    setLayout(_layout.get());

    for (int i = MINFLOOR; i <= MAXFLOOR; ++i)
    {
        std::shared_ptr<Button> btn(new Button);
        btn->setFloor(MAXFLOOR + 1 - i);
        btn->setText(QString::number(MAXFLOOR + 1 - i));

        _btns.insert(_btns.begin(), btn);
        _layout->addWidget(dynamic_cast<QPushButton *>(btn.get()));
        QObject::connect(
                btn.get(),
                SIGNAL(floorCall(size_t)),
                this,
                SLOT(newTarget(size_t))
        );

        _visitedFloors.push_back(true);
    }
}

void Controller::newTarget(size_t floor)
{
    _state = ACTIVE;
    _visitedFloors[floor - 1] = false;

    findNearestFloor(floor);
    _needFloor = floor;

    emit newTargetSignal(floor);
}

void Controller::passFloor(size_t floor)
{
    if (_state != ACTIVE)
        return;

    _curFloor = floor;

    if (_curFloor == _needFloor)
    {
        qDebug() << "Лифт остановился на " << floor << " этаже.";

        _visitedFloors[floor - 1] = true;
        emit _btns.at(floor - 1)->unpress();

        if (findNearestFloor(floor))
        {
            _needFloor = floor;
            emit stayOnFloor(false, floor);
        }
        else
        {
            _state = IDLE;
            emit stayOnFloor(true);
        }
    }
}

bool Controller::findNearestFloor(size_t &nextFloor)
{
    direction dir = _dir == STOP ? DOWN : _dir;
    bool isFound = false;

    for (size_t i = _curFloor; !isFound && MINFLOOR <= i && i <= MAXFLOOR; i += dir)
    {
        if (!_visitedFloors[i - 1])
        {
            nextFloor = i;
            isFound = true;
        }
    }

    for (size_t i = _curFloor; !isFound && MINFLOOR <= i && i <= MAXFLOOR; i -= dir)
    {
        if (!_visitedFloors[i - 1])
        {
            nextFloor = i;
            isFound = true;
        }
    }

    return isFound;
}
