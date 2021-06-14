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

    std::shared_ptr<DrawerFactory> factory(new QtFactory(_scene));
    _drawer = factory->createDrawer();
}

void MainWindow::update_scene()
{
    DrawScene draw_command(_drawer);
    _facade->execute(draw_command);
}

void MainWindow::check_cam_exist()
{
    auto viewer_count = std::make_shared<size_t>(0);
    CountCamera viewer_cmd(viewer_count);

    _facade->execute(viewer_cmd);

    if (!*viewer_count)
    {
        std::string msg = "No camera found.";
        throw CameraException(msg);
    }
}

void MainWindow::check_models_exist()
{
    auto model_count = std::make_shared<size_t>(0);
    CountModel model_cmd(model_count);
    _facade->execute(model_cmd);

    if (!*model_count)
    {
        std::string msg = "No models found.";
        throw ModelException(msg);
    }
}

void MainWindow::check_can_delete_cam()
{
    auto model_count = std::make_shared<size_t>(0);
    CountModel model_cmd(model_count);
    _facade->execute(model_cmd);

    auto viewer_count = std::make_shared<size_t>(0);
    CountCamera viewer_cmd(viewer_count);
    _facade->execute(viewer_cmd);

    if (*viewer_count <= 1 && *model_count) {
        std::string msg = "Can not delete the last camera with the loaded models";
        throw CameraException(msg);
    }
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();
    AddCamera camera_command(cont.width() / 2.0, cont.height() / 2.0, 0.0);
    _facade->execute(camera_command);

    update_scene();

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
        check_cam_exist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Добавьте камеру!");
        return;
    }

    auto file = QFileDialog::getOpenFileName();

    if (file.isNull())
        return;

    LoadModel load_command(file.toUtf8().data());

    try
    {
        _facade->execute(load_command);
    }
    catch (const BaseException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка при загрузке файла!");
        return;
    }

    update_scene();
    ui->modelsCB->addItem(QFileInfo(file.toUtf8().data()).fileName());
    ui->modelsCB->setCurrentIndex(ui->modelsCB->count() - 1);
}

void MainWindow::on_deleteModelBtn_clicked()
{
    try
    {
        check_models_exist();
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет загруженных моделей!");
        return;
    }

    DeleteModel delete_command(ui->modelsCB->currentIndex());
    _facade->execute(delete_command);

    ui->modelsCB->removeItem(ui->modelsCB->currentIndex());

    update_scene();
}

void MainWindow::on_deleteModelsBtn_clicked()
{
    try
    {
        check_models_exist();
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

    update_scene();
}

void MainWindow::on_cameraCB_currentIndexChanged(int index)
{
    try
    {
        check_cam_exist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    SetCamera camera_command(index);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_deleteCameraBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }

    try
    {
        check_can_delete_cam();
    }
    catch (const CameraException &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Это последняя камера! Для удаления удалите модели!");
        return;
    }

    DeleteCamera delete_command(ui->cameraCB->currentIndex());
    _facade->execute(delete_command);

    ui->cameraCB->removeItem(ui->cameraCB->currentIndex());

    try
    {
        check_cam_exist();
    }
    catch (const CameraException &error)
    {
        return;
    }

    update_scene();
}

void MainWindow::on_upBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCamera camera_command(ui->cameraCB->currentIndex(), 0, 10);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_rigthBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCamera camera_command(ui->cameraCB->currentIndex(), -10, 0);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_downBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCamera camera_command(ui->cameraCB->currentIndex(), 0, -10);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_leftBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const CameraException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCamera camera_command(ui->cameraCB->currentIndex(), 10, 0);
    _facade->execute(camera_command);
    update_scene();
}

void MainWindow::on_moveBtn_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
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

    MoveModel move_cmd(
            ui->dxDSB->value(),
            ui->dyDSB->value(),
            ui->dzDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->execute(move_cmd);
    update_scene();
}

void MainWindow::on_scaleBtn_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
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

    ScaleModel scale_cmd(
            ui->kxDSB->value(),
            ui->kyDSB->value(),
            ui->kzDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->execute(scale_cmd);
    update_scene();
}

void MainWindow::on_rotateBtn_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
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

    RotateModel spin_cmd(
            ui->oxDSB->value(),
            ui->oyDSB->value(),
            ui->ozDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->execute(spin_cmd);
    update_scene();
}
