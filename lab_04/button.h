#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT;

    enum btnStatus
    {
        PRESSED,
        UNPRESSED
    };

public:
    Button(QWidget *parent = nullptr);
    ~Button() = default;

    void setFloor(const size_t floor);

public slots:
    void pressed();
    void unpressed();

signals:
    void floorCall(const size_t floor);
    void unpress();

private:
    btnStatus _state;
    size_t _floor;
};

#endif // BUTTON_H
