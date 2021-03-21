#include <stdlib.h>

#include "links.h"

void links_init(links_arr_t &links)
{
    links.data = NULL;
    links.len = 0;
}


err_t allocate_links_arr(links_arr_t &links)
{
    links.data = (link_t *) malloc(sizeof(link_t) * links.len);

    if (!links.data)
        return MEMORY_ERR;

    return OK;
}


err_t check_link(const link_t &link, const size_t max_vrtx_num)
{
    if (!link.vertex1 || link.vertex1 > max_vrtx_num
        || !link.vertex2 || link.vertex2 > max_vrtx_num)
        return VALUE_ERR;

    return OK;
}


err_t read_link(link_t &link, const size_t max_vrtx_num, FILE *file)
{
    if (fscanf(file, "%lu%lu", &link.vertex1, &link.vertex2) != 2)
        return READ_ERR;

    if (check_link(link, max_vrtx_num))
        return VALUE_ERR;

    return OK;
}


err_t read_links(links_arr_t &links, const size_t max_vrtx_num, FILE *file)
{
    if (fscanf(file, "%lu", &links.len) != 1)
        return READ_ERR;

    if (!links.len)
        return VALUE_ERR;

    err_t rc = allocate_links_arr(links);

    for (size_t i = 0; !rc && i < links.len; i++)
        rc = read_link(links.data[i], max_vrtx_num, file);

    if (rc)
        destroy_links_arr(links);

    return rc;
}


void destroy_links_arr(links_arr_t &links)
{
    free(links.data);
    links_init(links);
}
