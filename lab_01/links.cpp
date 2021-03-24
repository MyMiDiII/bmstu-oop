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


err_t check_links(const links_arr_t &links, const size_t max_vrtx_num)
{
    err_t rc = OK;

    for (size_t i = 0; !rc && i < links.len; i++)
        rc = check_link(links.data[i], max_vrtx_num);

    return OK;
}


err_t read_link(link_t &link, FILE *file)
{
    if (fscanf(file, "%lu%lu", &link.vertex1, &link.vertex2) != 2)
        return READ_ERR;

    return OK;
}


err_t read_links_len(links_arr_t &links, FILE *file)
{
    if (fscanf(file, "%lu", &links.len) != 1)
        return READ_ERR;

    if (!links.len)
        return VALUE_ERR;

    return OK;
}


err_t read_links_data(links_arr_t &links, FILE *file)
{
    err_t rc = OK;

    for (size_t i = 0; !rc && i < links.len; i++)
        rc = read_link(links.data[i], file);

    return rc;
}


err_t read_links(links_arr_t &links, FILE *file)
{
    err_t rc = read_links_len(links, file);

    if (!rc)
        rc = allocate_links_arr(links);

    if (!rc)
        rc = read_links_data(links, file);

    if (rc)
        destroy_links_arr(links);

    return rc;
}


void destroy_links_arr(links_arr_t &links)
{
    free(links.data);
    links_init(links);
}
