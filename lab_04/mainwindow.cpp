#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(200, 500);
    _layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    ui->centralwidget->setLayout(_layout.get());
    _layout->addWidget(_elevator.getController());
}

MainWindow::~MainWindow()
{
    delete ui;
}

