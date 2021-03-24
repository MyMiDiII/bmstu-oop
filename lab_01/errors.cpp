#include <QMessageBox>

#include "errors.h"


#define TITLE             "Ошибка"
#define FILE_NAME_ERR_MSG "Не удалось открыть файл!"
#define MEMORY_ERR_MSG    "Не удалось выделить память!"
#define READ_ERR_MSG      "Неверный формат данных в файле!"
#define VALUE_ERR_MSG     "Неверные значения данных в файле!"
#define MOVE_IN_ERR_MSG   "Коэффициенты переноса должны \
                           быть вещественными числами!"
#define SCALE_IN_ERR_MSG  "Коэффициенты масштабирования должны \
                           быть вещественными числами!"
#define TURN_IN_ERR_MSG   "Коэффициенты поворота должны \
                           быть вещественными числами!"
#define NO_DATA_ERR_MSG   "Фигура не загружена!"
#define CODE_ERR_MSG      "Неизвестная команда!"
#define UNKNOWN_ERR_MSG   "Неизвестная ошибка!"


void handle_error(const err_t code)
{
    switch (code)
    {
    case FILE_NAME_ERR:
        QMessageBox::critical(NULL, TITLE, FILE_NAME_ERR_MSG);
        break;
    case MEMORY_ERR:
        QMessageBox::critical(NULL, TITLE, MEMORY_ERR_MSG);
        break;
    case READ_ERR:
        QMessageBox::critical(NULL, TITLE, READ_ERR_MSG);
        break;
    case VALUE_ERR:
        QMessageBox::critical(NULL, TITLE, VALUE_ERR_MSG);
        break;
    case MOVE_IN_ERR:
        QMessageBox::critical(NULL, TITLE, MOVE_IN_ERR_MSG);
        break;
    case SCALE_IN_ERR:
        QMessageBox::critical(NULL, TITLE, SCALE_IN_ERR_MSG);
        break;
    case TURN_IN_ERR:
        QMessageBox::critical(NULL, TITLE, TURN_IN_ERR_MSG);
        break;
    case NO_DATA_ERR:
        QMessageBox::critical(NULL, TITLE, NO_DATA_ERR_MSG);
        break;
    case UNKNOWN_CODE_ERR:
        QMessageBox::critical(NULL, TITLE, CODE_ERR_MSG);
        break;
    default:
        QMessageBox::critical(NULL, TITLE, UNKNOWN_ERR_MSG);
        break;
    }
}
