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
    DrawSceneCMD draw_command(_drawer);
    _facade->exec(draw_command);
}

void MainWindow::check_cam_exist()
{
    auto viewer_count = std::make_shared<size_t>(0);
    CountCameraCMD viewer_cmd(viewer_count);

    _facade->exec(viewer_cmd);

    if (!*viewer_count)
    {
        std::string msg = "No camera found.";
        throw ViewerException(msg);
    }
}

void MainWindow::check_models_exist()
{
    auto model_count = std::make_shared<size_t>(0);
    CountModelCMD model_cmd(model_count);
    _facade->exec(model_cmd);

    if (!*model_count)
    {
        std::string msg = "No models found.";
        throw ModelException(msg);
    }
}

void MainWindow::check_can_delete_cam()
{
    auto model_count = std::make_shared<size_t>(0);
    CountModelCMD model_cmd(model_count);
    _facade->exec(model_cmd);

    auto viewer_count = std::make_shared<size_t>(0);
    CountCameraCMD viewer_cmd(viewer_count);
    _facade->exec(viewer_cmd);

    if (*viewer_count <= 1 && *model_count) {
        std::string msg = "Can not delete the last camera with the loaded models";
        throw ViewerException(msg);
    }
}

void MainWindow::on_addCameraBtn_clicked()
{
    auto cont = ui->graphicsView->contentsRect();
    AddCameraCMD camera_command(cont.width() / 2.0, cont.height() / 2.0, 0.0);
    _facade->exec(camera_command);

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
   catch (const ViewerException &error)
   {
       QMessageBox::critical(nullptr, "Ошибка", "Добавьте камеру!");
       return;
   }

   auto file = QFileDialog::getOpenFileName();

   if (file.isNull())
       return;

   LoadModelCMD load_command(file.toUtf8().data());

   try
   {
       _facade->exec(load_command);
   }
   catch (const ViewerException &error)
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

    RemoveModelCMD remove_command(ui->modelsCB->currentIndex());
    _facade->exec(remove_command);

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
        RemoveModelCMD remove_command(i);
        _facade->exec(remove_command);

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
    catch (const ViewerException &error)
    {
        return;
    }

    SetCameraCMD camera_command(index);
    _facade->exec(camera_command);
    update_scene();
}

void MainWindow::on_deleteCameraBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const ViewerException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }

    try
    {
        check_can_delete_cam();
    }
    catch (const ViewerException &error) {
        QMessageBox::critical(nullptr, "Ошибка", "Это последняя камера! Для удаления удалите модели!");
        return;
    }

    RemoveCameraCMD remove_command(ui->cameraCB->currentIndex());
    _facade->exec(remove_command);

    ui->cameraCB->removeItem(ui->cameraCB->currentIndex());

    try
    {
        check_cam_exist();
    }
    catch (const ViewerException &error)
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
    catch (const ViewerException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCameraCMD camera_command(ui->cameraCB->currentIndex(), 0, 10);
    _facade->exec(camera_command);
    update_scene();
}

void MainWindow::on_rigthBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const ViewerException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCameraCMD camera_command(ui->cameraCB->currentIndex(), -10, 0);
    _facade->exec(camera_command);
    update_scene();
}

void MainWindow::on_downBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const ViewerException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCameraCMD camera_command(ui->cameraCB->currentIndex(), 0, -10);
    _facade->exec(camera_command);
    update_scene();
}

void MainWindow::on_leftBtn_clicked()
{
    try
    {
        check_cam_exist();
    }
    catch (const ViewerException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Не загружено ни одной камеры.");
        return;
    }

    MoveCameraCMD camera_command(ui->cameraCB->currentIndex(), 10, 0);
    _facade->exec(camera_command);
    update_scene();
}

void MainWindow::on_moveBtn_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const ViewerException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    MoveModelCMD move_cmd(
            ui->dxDSB->value(),
            ui->dyDSB->value(),
            ui->dzDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->exec(move_cmd);
    update_scene();
}

void MainWindow::on_scaleBtn_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const ViewerException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    ScaleModelCMD scale_cmd(
            ui->kxDSB->value(),
            ui->kyDSB->value(),
            ui->kzDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->exec(scale_cmd);
    update_scene();
}

void MainWindow::on_rotateBtn_clicked()
{
    try
    {
        check_cam_exist();
        check_models_exist();
    }
    catch (const ViewerException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет камер!");
        return;
    }
    catch (const ModelException &error)
    {
        QMessageBox::critical(nullptr, "Ошибка", "Нет моделей!");
        return;
    }

    SpinModelCMD spin_cmd(
            ui->oxDSB->value(),
            ui->oyDSB->value(),
            ui->ozDSB->value(),
            ui->modelsCB->currentIndex());

    _facade->exec(spin_cmd);
    update_scene();
}
