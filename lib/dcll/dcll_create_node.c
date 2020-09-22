/*
** Duo Project C Library
** DCLL
** File description:
** Allocates memory for a new DCLL node.
*/

#include "dcll.h"

dcll_node_t *dcll_create_node(void)
{
    dcll_node_t *node = malloc(sizeof(dcll_node_t));

    if (!node) {
        return (NULL);
    }
    (*node) = (dcll_node_t){.data = NULL, .data_freer = NULL, .next = node, .prev = node};
    return (node);
}