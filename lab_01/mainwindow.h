#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "requests.h"
#include "figure.h"
#include "errors.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_load_btn_clicked();

    void on_move_btn_clicked();

    void on_scale_btn_clicked();

    void on_turn_btn_clicked();

private:
    err_t read_move(move_t &move);

    err_t read_scale(scale_t &scale);

    err_t read_turn(turn_t &turn);

    void handle_rc(const err_t rc);

    canvas_t init_canvas();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
