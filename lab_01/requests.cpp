#include "requests.h"

err_t handle_request(const request_t &request)
{
    static figure_t figure = figure_init();
    err_t rc = OK;

    switch (request.code)
    {
    case LOAD:
        rc = load_figure(figure, request.filename);
        break;
    case MOVE:
        rc = move_figure(figure, request.move);
        break;
    case SCALE:
        rc = scale_figure(figure, request.scale);
        break;
    case TURN:
        rc = turn_figure(figure, request.turn);
        break;
    case DRAW:
        rc = draw_figure(figure, request.canvas);
        break;
    case QUIT:
        destroy_figure(figure);
        break;
    default:
        rc = UNKNOWN_CODE_ERR;
        break;
    }

    return rc;
}
