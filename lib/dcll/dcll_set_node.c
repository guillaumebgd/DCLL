/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Sets node data to a given node.
*/

#include "dcll.h"

bool dcll_set_node(dcll_node_t *node, void *data, void *(*data_freer)(void *))
{
    if (!node)
        return (false);
    node->data = data;
    node->data_freer = data_freer;
    return (true);
}