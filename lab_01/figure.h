#ifndef FIGURE_H
#define FIGURE_H

#include "errors.h"
#include "vertexes.h"
#include "links.h"


struct figure_t
{
    vertex_t centre;
    vrtx_arr_t vertexes;
    links_arr_t links;
};

using filename_t = const char *;


figure_t &figure_init(void);

err_t load_figure(figure_t &figure, filename_t file_name);

err_t move_figure(figure_t &figure, const move_t &move);

err_t scale_figure(figure_t &figure, const scale_t &scale);

err_t turn_figure(figure_t &figure, const turn_t &turn);

void destroy_figure(figure_t &figure);

#endif // FIGURE_H
