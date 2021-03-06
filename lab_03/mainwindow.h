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

    void on_deleteModelsBtn_clicked();

    void on_cameraCB_currentIndexChanged(int index);

    void on_deleteCameraBtn_clicked();

    void on_upBtn_clicked();

    void on_rigthBtn_clicked();

    void on_downBtn_clicked();

    void on_leftBtn_clicked();

    void on_moveBtn_clicked();

    void on_scaleBtn_clicked();

    void on_rotateBtn_clicked();

protected:
    void setupScene();
    void updateScene();
    void checkCamExist();
    void checkModelsExist();
    void checkCamDelete();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *_scene;
    std::shared_ptr<Facade> _facade;
    std::shared_ptr<BaseDrawer> _drawer;
    std::vector<std::size_t> _models;
    std::vector<std::size_t> _cameras;
    std::size_t _camInd;
};
#endif // MAINWINDOW_H
