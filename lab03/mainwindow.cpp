#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupScene();

    _facade = std::make_shared<Facade>(Facade());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupScene()
{
    _scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    auto cont = ui->graphicsView->contentsRect();
    _scene->setSceneRect(0, 0, cont.width(), cont.height());

    std::shared_ptr<DrawerFactory> factory(new QtFactory(_scene));
    _drawer = factory->createDrawer();
}

void MainWindow::updateScene()
{
    DrawScene cmd(_drawer);
    _facade->execute(cmd);
}

void MainWindow::checkCamExist()
{
    auto cameraNum = std::make_shared<size_t>(0);
    CountCamera cameraCmd(cameraNum);

    _facade->execute(cameraCmd);

    if (!*cameraNum)
    {
        std::string msg = "No camera found.";
        throw CameraException(msg);
    }
}

void MainWindow::checkModelsExist()
{
    auto modelNum = std::make_shared<size_t>(0);
    CountModel modelCmd(modelNum);
    _facade->execute(modelCmd);

    if (!*modelNum)
    {
        std::string msg = "No models found.";
        throw ModelException(msg);
    }
}

void MainWindow::checkCamDelete()
{
    auto modelNum = std::make_shared<size_t>(0);
    CountModel modelCmd(modelNum);
    _facade->execute(modelCmd);

    auto cameraNum = std::make_shared<size_t>(0);
    CountCamera cameraCmd(cameraNum);
    _facade->execute(cameraCmd);

    if (*cameraNum <= 1 && *modelNum)
    {
        std::string msg = "Can not delete the last camera with the loaded models";
        throw CameraException(msg);
    }
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();
    AddCamera camera_command(cont.width() / 2.0, cont.height() / 2.0, 0.0);
    _facade->execute(camera_command);

    updateScene();

    auto cam = ui->cameraCB;

    if (0 == cam->count())
        cam->addItem(QString::number(1));
    else
        cam->addItem(QString::number(cam->itemText(cam->count() - 1).toInt() + 1));

    ui->cameraCB->setCurrentIndex(ui->cameraCB->count() - 1);
}

void MainWindow::on_loadModelBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Добавьте камеру!");
        return;
    }

    auto file = QFileDialog::getOpenFileName(nullptr, "Загрузка модели", "/home/mymidi/01_BMSTU/bmstu-oop/lab03/data");

    if (file.isNull())
        return;

    LoadModel cmd(file.toUtf8().data());

    try
    {
        _facade->execute(cmd);
    }
    catch (const BaseException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка при загрузке файла!");
        return;
    }

    updateScene();
    ui->modelsCB->addItem(QFileInfo(file.toUtf8().data()).fileName());
    ui->modelsCB->setCurrentIndex(ui->modelsCB->count() - 1);
}

void MainWindow::on_deleteModelBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    DeleteModel cmd(ui->modelsCB->currentIndex());
    _facade->execute(cmd);

    ui->modelsCB->removeItem(ui->modelsCB->currentIndex());

    updateScene();
}

void MainWindow::on_deleteModelsBtn_clicked()
{
    try
    {
        checkModelsExist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    for (int i = ui->modelsCB->count() - 1; i >= 0; --i)
    {
        DeleteModel delete_command(i);
        _facade->execute(delete_command);

        ui->modelsCB->removeItem(i);
    }

    updateScene();
}

void MainWindow::on_cameraCB_currentIndexChanged(int index)
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    SetCamera cmd(index);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_deleteCameraBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }

    try
    {
        checkCamDelete();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Это последняя камера! Для удаления удалите модели!");
        return;
    }

    DeleteCamera cmd(ui->cameraCB->currentIndex());
    _facade->execute(cmd);

    ui->cameraCB->removeItem(ui->cameraCB->currentIndex());

    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    updateScene();
}

void MainWindow::on_upBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCamera cmd(ui->cameraCB->currentIndex(), 0, 10);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_rigthBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCamera cmd(ui->cameraCB->currentIndex(), -10, 0);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_downBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCamera cmd(ui->cameraCB->currentIndex(), 0, -10);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_leftBtn_clicked()
{
    try
    {
        checkCamExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCamera cmd(ui->cameraCB->currentIndex(), 10, 0);
    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_moveBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    MoveModel cmd(
            ui->dxDSB->value(),
            ui->dyDSB->value(),
            ui->dzDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_scaleBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    ScaleModel cmd(
            ui->kxDSB->value(),
            ui->kyDSB->value(),
            ui->kzDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->execute(cmd);
    updateScene();
}

void MainWindow::on_rotateBtn_clicked()
{
    try
    {
        checkCamExist();
        checkModelsExist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    RotateModel cmd(
            ui->oxDSB->value(),
            ui->oyDSB->value(),
            ui->ozDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->execute(cmd);
    updateScene();
}
