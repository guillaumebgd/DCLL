/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Frees memory allocated by a DCLL node.
*/

#include "dcll.h"

void dcll_destroy_node(dcll_node_t *node)
{
    if (!node)
        return;
    if (node->data && node->data_freer) {
        node->data_freer(node->data);
    }
    free(node);
}
