/*
** Duo Project C Library
** DCLL
** File description:
** Sets node data to a given node.
*/

#include "dcll.h"

bool dcll_set_node(dcll_node_t *node, void *data, const size_t data_size, void *(*data_freer)(void *))
{
    if (!node)
        return (false);
    node->data = __dcll_data_dup(data, data_size);
    if (!node->data)
        return (false);
    node->data_freer = data_freer;
    return (true);
}