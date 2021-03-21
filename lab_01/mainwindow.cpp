#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 922, 733);
    ui->graphicsView->setScene(scene);
}


MainWindow::~MainWindow()
{
    request_t quit_request;
    quit_request.code = QUIT;
    handle_request(quit_request);

    delete ui;
}


canvas_t MainWindow::init_canvas()
{
    static canvas_t canvas;

    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    return canvas;
}


void MainWindow::handle_rc(const err_t rc)
{
    if (!rc)
    {
        canvas_t canvas = init_canvas();
        request_t draw_request = {.code = DRAW, .canvas = canvas};
        handle_request(draw_request);
    }
    else
        handle_error(rc);
}


void MainWindow::on_load_btn_clicked()
{
    request_t load_request = {.code = LOAD, .filename = "data.txt"};

    err_t rc = handle_request(load_request);

    handle_rc(rc);
}


err_t MainWindow::read_move(move_t &move)
{
    bool ok1 = true;
    bool ok2 = true;
    bool ok3 = true;

    move.dx = ui->dx_lineEdit->text().toDouble(&ok1);
    move.dy = ui->dy_lineEdit->text().toDouble(&ok2);
    move.dz = ui->dz_lineEdit->text().toDouble(&ok3);

    if (!ok1 || !ok2 || !ok3)
        return MOVE_IN_ERR;

    return OK;
}


void MainWindow::on_move_btn_clicked()
{
    move_t move = {.dx = 0, .dy = 0, .dz  = 0};
    err_t rc = read_move(move);

    if (!rc)
    {
        request_t move_request = {.code = MOVE, .move = move};
        rc = handle_request(move_request);
    }

    handle_rc(rc);
}


err_t MainWindow::read_scale(scale_t &scale)
{
    bool ok1 = true;
    bool ok2 = true;
    bool ok3 = true;

    scale.kx = ui->kx_lineEdit->text().toDouble(&ok1);
    scale.ky = ui->ky_lineEdit->text().toDouble(&ok2);
    scale.kz = ui->kz_lineEdit->text().toDouble(&ok3);

    if (!ok1 || !ok2 || !ok3)
        return SCALE_IN_ERR;

    return OK;
}


void MainWindow::on_scale_btn_clicked()
{
    scale_t scale = {.kx = 0, .ky = 0, .kz = 0};
    err_t rc = read_scale(scale);

    if (!rc)
    {
        request_t scale_request = {.code = SCALE, .scale = scale};
        rc = handle_request(scale_request);
    }

    handle_rc(rc);
}


err_t MainWindow::read_turn(turn_t &turn)
{
    bool ok1 = true;
    bool ok2 = true;
    bool ok3 = true;

    turn.x_angle = ui->xa_lineEdit->text().toDouble(&ok1);
    turn.y_angle = ui->ya_lineEdit->text().toDouble(&ok2);
    turn.z_angle = ui->za_lineEdit->text().toDouble(&ok3);

    if (!ok1 || !ok2 || !ok3)
        return TURN_IN_ERR;

    return OK;
}


void MainWindow::on_turn_btn_clicked()
{
    turn_t turn = {.x_angle = 0, .y_angle = 0, .z_angle = 0};
    err_t rc = read_turn(turn);

    if (!rc)
    {
        request_t turn_request = {.code = TURN, .turn = turn};
        rc = handle_request(turn_request);
    }
    handle_rc(rc);
}
