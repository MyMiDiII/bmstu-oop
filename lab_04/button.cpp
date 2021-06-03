#include "button.h"

Button::Button(QWidget *parent) : QPushButton(parent)
{
    _state = UNPRESSED;
    _floor = 1;

    QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressed()));
    QObject::connect(this, SIGNAL(), this, SLOT(unpressed()));
}

void Button::setFloor(const size_t floor)
{
    _floor = floor;
}

void Button::pressed()
{
    if (UNPRESSED == _state)
    {
        _state = PRESSED;
        setDisabled(true);
        emit floorCall(_floor);

        setStyleSheet("background-color: rgb(255, 124, 124); color: black;");
        update();
    }
}

void Button::unpressed()
{
    if (PRESSED == _state)
    {
        _state = UNPRESSED;
        setDisabled(false);

        setStyleSheet("");
        update();
    }

}
