/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Adds a new node to a DCLL.
*/

#include <stdlib.h>
#include "dcll.h"

static void __dcll_put_node(dcll_list_t *list, dcll_node_t *node)
{
    if (!list->head) {
        node->next = node;
        node->prev = node;
        list->head = node;
    } else {
        node->next = list->head;
        node->prev = list->head->prev;
        list->head->prev->prev = node;
        list->head->next = node;
    }
    list->length += 1;
}

bool __dcll_add_node(dcll_list_t *list, __attribute__((unused))ssize_t index)
{
    dcll_node_t *node = NULL;

    node = malloc(sizeof(dcll_node_t));
    if (!node)
        return (false);
    *node = (dcll_node_t){0};
    __dcll_put_node(list, node);
    return (true);
}