#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_scene();

    _facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setup_scene()
{
    _scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto cont = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, cont.width(), cont.height());

    std::shared_ptr<AbstractDrawerFactory> factory(new DrawerQtFactory(_scene));
    _drawer = factory->graphic_create();
}

void MainWindow::update_scene()
{
    DrawSceneCommand draw_command(_drawer);
    _facade->exec(draw_command);
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();
    AddViewerCommand camera_command(cont.width() / 2.0, cont.height() / 2.0, 0.0);
    _facade->exec(camera_command);

    update_scene();

    auto cam = ui->cameraCB;

    if (0 == cam->count())
        cam->addItem(QString::number(1));
    else
        cam->addItem(QString::number(cam->itemText(cam->count() - 1).toInt() + 1));

    ui->cameraCB->setCurrentIndex(ui->cameraCB->count() - 1);
}
