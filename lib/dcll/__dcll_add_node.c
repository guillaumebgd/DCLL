/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Adds a new node to a DCLL.
*/

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
        list->head->prev->next = node;
        list->head->prev = node;
    }
    list->length += 1;
}

bool __dcll_add_node(dcll_list_t *list, void *data, void *(*data_freer)(void *))
{
    dcll_node_t *node = NULL;

    node = malloc(sizeof(dcll_node_t));
    if (!node)
        return (false);
    (*node) = (dcll_node_t){0};
    node->data = data;
    node->data_freer = data_freer;
    __dcll_put_node(list, node);
    return (true);
}