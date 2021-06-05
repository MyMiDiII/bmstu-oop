#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QDebug>
#include <QTimer>

#include "config.h"

class Door : public QObject
{
    Q_OBJECT;

    enum doorStatus
    {
        CLOSING,
        CLOSED,
        OPENING,
        OPENED
    };

public:
    explicit Door(QObject *parent = nullptr);
    ~Door() = default;

public slots:
    void closing();
    void closed();
    void opening();
    void opened();

signals:
    void isClosed();

private:
    doorStatus _state;

    QTimer _openingTimer;
    QTimer _closingTimer;
    QTimer _openedTimer;
};

#endif // DOOR_H
