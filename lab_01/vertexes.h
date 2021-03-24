#ifndef VERTEXES_H
#define VERTEXES_H

#include <stdio.h>
#include "errors.h"

struct vertex_t
{
    double x;
    double y;
    double z;
};

struct vrtx_arr_t
{
    vertex_t *data;
    size_t len;
};

struct move_t
{
    double dx;
    double dy;
    double dz;
};

struct scale_t
{
    double kx;
    double ky;
    double kz;
};

struct turn_t
{
    double x_angle;
    double y_angle;
    double z_angle;
};

void vertex_init(vertex_t &vertex);

void vertexes_init(vrtx_arr_t &vertexes);

size_t get_vrtxs_num(const vrtx_arr_t &vertexes);

err_t read_vertex(vertex_t &vertex, FILE *file);

err_t read_vertexes(vrtx_arr_t &vertexes, FILE *file);

void move_vertex(vertex_t &vertex, const move_t &move);

err_t move_vertexes(vrtx_arr_t &vrtxs, const move_t &move);

err_t scale_vertexes(vrtx_arr_t &vrtxs, const vertex_t &centre,
                     const scale_t &scale);

err_t turn_vertexes(vrtx_arr_t &vrtxs, const vertex_t &centre,
                    const turn_t &turn);

void destroy_vrtx_arr(vrtx_arr_t &vertexes);

#endif // VERTEXES_H
