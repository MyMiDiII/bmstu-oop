#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <vector>
#include <memory>

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

private:
    std::unique_ptr<QVBoxLayout> _layout;
    std::vector<std::shared_ptr<Button>> _btns;
};

#endif // CONTROLLER_H
