#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qt5/QtWidgets/QMainWindow>
#include <qt5/QtWidgets/QMessageBox>
#include <QGraphicsScene>
#include <QFileDialog>

#include "basecommand.h"
#include "cameracommand.h"
#include "modelcommand.h"
#include "scenecommand.h"
#include "exceptions.h"
#include "drawerfactory.h"
#include "qtfactory.h"
#include "facade.h"

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
    void on_addCameraBtn_clicked();

    void on_loadModelBtn_clicked();

    void on_deleteModelBtn_clicked();

protected:
    void setup_scene();
    void update_scene();
    void check_cam_exist();
    void check_models_exist();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
    std::shared_ptr<Facade> _facade;
    std::shared_ptr<AbstractDrawer> _drawer;
};
#endif // MAINWINDOW_H
