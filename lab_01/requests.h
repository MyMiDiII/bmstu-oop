#ifndef REQUESTS_H
#define REQUESTS_H

#include "figure.h"
#include "draw.h"

enum request_code_t
{
    LOAD,
    MOVE,
    SCALE,
    TURN,
    DRAW,
    QUIT
};

struct request_t
{
    request_code_t code;
    union
    {
        filename_t filename;
        move_t move;
        scale_t scale;
        turn_t turn;
        canvas_t canvas;
    };
};

err_t handle_request(const request_t &request);

#endif // REQUESTS_H
