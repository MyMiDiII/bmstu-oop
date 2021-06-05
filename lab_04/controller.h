#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <vector>
#include <memory>

#include "config.h"
#include "button.h"

class Controller : public QWidget
{
    Q_OBJECT;

    enum controllerStatus
    {
        IDLE,
        ACTIVE
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() = default;

public slots:
    void newTarget(size_t floor);
    void passFloor(size_t floor);

signals:
    void newTargetSignal(size_t floor);
    void stayOnFloor(bool isLast, const size_t floor = 1);

private:
    std::unique_ptr<QVBoxLayout> _layout;
    std::vector<std::shared_ptr<Button>> _btns;

    controllerStatus _state;
    direction _dir;
    size_t _curFloor;
    size_t _needFloor;
    std::vector<bool> _visitedFloors;

    bool findNearestFloor(size_t &nextFloor);
};

#endif // CONTROLLER_H
