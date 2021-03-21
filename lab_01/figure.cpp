#include <stdio.h>

#include "figure.h"


figure_t &figure_init(void)
{
    static figure_t tmp_figure;

    vertex_init(tmp_figure.centre);
    vertexes_init(tmp_figure.vertexes);
    links_init(tmp_figure.links);

    return tmp_figure;
}


size_t get_vrtxs_num(const figure_t &figure)
{
    return figure.vertexes.len;
}


err_t read_figure(figure_t &figure, FILE *file)
{
    figure = figure_init();

    err_t rc = OK;

    if ((rc = read_vertex(figure.centre, file)))
        return rc;

    if ((rc = read_vertexes(figure.vertexes, file)))
        return rc;

    if ((rc = read_links(figure.links, get_vrtxs_num(figure), file)))
        destroy_vrtx_arr(figure.vertexes);

    return rc;
}


err_t load_figure(figure_t &figure, filename_t file_name)
{
    FILE *file = fopen(file_name, "r");

    if (!file)
        return FILE_NAME_ERR;

    figure_t tmp_figure;

    err_t rc = read_figure(tmp_figure, file);

    fclose(file);

    if (!rc)
    {
        destroy_figure(figure);
        figure = tmp_figure;
    }

    return rc;
}


err_t move_figure(figure_t &figure, const move_t &move)
{
    move_vertex(figure.centre, move);
    err_t rc = move_vertexes(figure.vertexes, move);
    return rc;
}


err_t scale_figure(figure_t &figure, const scale_t &scale)
{
    err_t rc = scale_vertexes(figure.vertexes, figure.centre, scale);
    return rc;
}


err_t turn_figure(figure_t &figure, const turn_t &turn)
{
    err_t rc = turn_vertexes(figure.vertexes, figure.centre, turn);
    return rc;
}


void destroy_figure(figure_t &figure)
{
    vertex_init(figure.centre);
    destroy_vrtx_arr(figure.vertexes);
    destroy_links_arr(figure.links);
}
