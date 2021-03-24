#ifndef ERRORS_H
#define ERRORS_H

enum err_t
{
    OK,
    FILE_NAME_ERR,
    MEMORY_ERR,
    READ_ERR,
    VALUE_ERR,
    MOVE_IN_ERR,
    SCALE_IN_ERR,
    TURN_IN_ERR,
    NO_DATA_ERR,
    UNKNOWN_CODE_ERR
};

void handle_error(const err_t code);

#endif // ERRORS_H
