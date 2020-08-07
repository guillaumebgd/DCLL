/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Puts a node into a DCLL.
*/

#include "dcll.h"

static void __dcll_place_node_before_another(dcll_node_t *node, dcll_node_t *old_node)
{
    node->next = old_node;
    node->prev = old_node->prev;
    old_node->prev->next = node;
    old_node->prev = node;
}

bool dcll_put_node_in_list(dcll_list_t *list, dcll_node_t *node, const ssize_t index)
{
    dcll_node_t *old_pos_node = NULL;

    if (!list || !node)
        return (false);
    if (!list->head) {
        list->head = node;
        goto end;
    }
    old_pos_node = dcll_get_node_by_index(list, index);
    if (old_pos_node == list->head) {
        list->head = node;
    }
    __dcll_place_node_before_another(node, old_pos_node);
    end:
    list->length += 1;
    return (true);
}
