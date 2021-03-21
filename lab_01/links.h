#ifndef LINKS_H
#define LINKS_H

#include <stdio.h>

#include "errors.h"

struct link_t
{
    size_t vertex1;
    size_t vertex2;
};

struct links_arr_t
{
    link_t *data;
    size_t len;
};

void links_init(links_arr_t &links);

err_t read_links(links_arr_t &links, const size_t max_vrtx_num, FILE *file);

void destroy_links_arr(links_arr_t &links);

#endif // LINKS_H
