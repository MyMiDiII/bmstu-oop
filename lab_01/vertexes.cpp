#include <stdlib.h>
#include "vertexes.h"
#include "math.h"

double to_radians(double angle)
{
    return M_PI / 180 * angle;
}


void vertex_init(vertex_t &vertex)
{
    vertex.x = 0;
    vertex.y = 0;
    vertex.z = 0;
}


void vertexes_init(vrtx_arr_t &vertexes)
{
    vertexes.data = NULL;
    vertexes.len = 0;
}

err_t allocate_vrtx_arr(vrtx_arr_t &vertexes)
{
    vertexes.data = (vertex_t *) malloc(sizeof(vertex_t) * vertexes.len);

    if (!vertexes.data)
        return MEMORY_ERR;

    return OK;
}


err_t read_vertex(vertex_t &vertex, FILE *file)
{
    if (fscanf(file, "%lf%lf%lf", &vertex.x, &vertex.y, &vertex.z) != 3)
        return READ_ERR;

    return OK;
}


err_t read_vertexes(vrtx_arr_t &vertexes, FILE *file)
{
    if (fscanf(file, "%lu", &vertexes.len) != 1)
        return READ_ERR;

    if (!vertexes.len)
        return VALUE_ERR;

    err_t rc = allocate_vrtx_arr(vertexes);

    for (size_t i = 0; !rc && i < vertexes.len; i++)
        rc = read_vertex(vertexes.data[i], file);

    if (rc)
        destroy_vrtx_arr(vertexes);

    return rc;
}


void move_vertex(vertex_t &vertex, const move_t &move)
{
    vertex.x += move.dx;
    vertex.y += move.dy;
    vertex.z += move.dz;
}


void scale_vertex(vertex_t &vertex, const vertex_t centre,
                  const scale_t &scale)
{
    vertex.x = scale.kx * vertex.x + centre.x * (1 - scale.kx);
    vertex.y = scale.ky * vertex.y + centre.y * (1 - scale.ky);
    vertex.z = scale.kz * vertex.z + centre.z * (1 - scale.kz);
}


void xturn_vertex(vertex_t &vertex, const double angle)
{
    double rad_angle = to_radians(angle);
    double cos_a = cos(rad_angle);
    double sin_a = sin(rad_angle);
    double tmp_y = vertex.y;

    vertex.y = vertex.y * cos_a - vertex.z * sin_a;
    vertex.z = tmp_y * sin_a + vertex.z * cos_a;
}


void yturn_vertex(vertex_t &vertex, const double angle)
{
    double rad_angle = to_radians(angle);
    double cos_a = cos(rad_angle);
    double sin_a = sin(rad_angle);
    double tmp_x = vertex.x;

    vertex.x = vertex.x * cos_a - vertex.z * sin_a;
    vertex.z = tmp_x * sin_a + vertex.z * cos_a;
}


void zturn_vertex(vertex_t &vertex, const double angle)
{
    double rad_angle = to_radians(angle);
    double cos_a = cos(rad_angle);
    double sin_a = sin(rad_angle);
    double tmp_x = vertex.x;

    vertex.x = vertex.x * cos_a - vertex.y * sin_a;
    vertex.y = tmp_x * sin_a + vertex.y * cos_a;
}


err_t move_vertexes(vrtx_arr_t &vrtxs, const move_t &move)
{
    if (!vrtxs.data || !vrtxs.len)
        return NO_DATA_ERR;

    for (size_t i = 0; i < vrtxs.len; i++)
        move_vertex(vrtxs.data[i], move);

    return OK;
}


err_t scale_vertexes(vrtx_arr_t &vrtxs, const vertex_t &centre,
                    const scale_t &scale)
{
    if (!vrtxs.data || !vrtxs.len)
        return NO_DATA_ERR;

    for (size_t i = 0; i < vrtxs.len; i++)
        scale_vertex(vrtxs.data[i], centre, scale);

    return OK;
}


void move_to_centre(vertex_t &vertex, const vertex_t &centre)
{
    vertex.x -= centre.x;
    vertex.y -= centre.y;
    vertex.z -= centre.z;
}


void move_back(vertex_t &vertex, const vertex_t &centre)
{
    vertex.x += centre.x;
    vertex.y += centre.y;
    vertex.z += centre.z;
}


void turn_vertex(vertex_t &vertex, const vertex_t &centre,
                 const turn_t &turn)
{
    move_to_centre(vertex, centre);
    xturn_vertex(vertex, turn.x_angle);
    yturn_vertex(vertex, turn.y_angle);
    zturn_vertex(vertex, turn.z_angle);
    move_back(vertex, centre);
}


err_t turn_vertexes(vrtx_arr_t &vrtxs, const vertex_t &centre,
                    const turn_t &turn)
{
    if (!vrtxs.data || !vrtxs.len)
        return NO_DATA_ERR;

    for (size_t i = 0; i < vrtxs.len; i++)
        turn_vertex(vrtxs.data[i], centre, turn);

    return OK;
}


void destroy_vrtx_arr(vrtx_arr_t &vertexes)
{
    free(vertexes.data);
    vertexes_init(vertexes);
}
