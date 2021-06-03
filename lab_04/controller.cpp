#include "controller.h"
#include <QString>

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    _layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    setLayout(_layout.get());

    for (int i = 1; i <= 9; ++i)
    {
        std::shared_ptr<Button> btn(new Button);
        btn->setFloor(10 - i);
        btn->setText(QString::number(10 - i));

        _btns.push_back(btn);
        _layout->addWidget(dynamic_cast<QPushButton *>(btn.get()));
    }
}
