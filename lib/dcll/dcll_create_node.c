/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Allocates a new DCLL node.
*/

#include "dcll.h"

dcll_node_t *dcll_create_node()
{
    dcll_node_t *new_node = malloc(sizeof(dcll_node_t));

    if (!new_node) {
        return (NULL);
    }
    return (new_node);
}