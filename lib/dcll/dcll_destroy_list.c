/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Frees memory allocated by a DCLL.
*/

#include <stdlib.h>
#include "dcll.h"

static void __dcll_destroy_node(dcll_node_t *node)
{
    if (!node)
        return;
    if (node->data) {
        node->data_freer(node->data);
    }
    free(node);
}

void dcll_destroy_list(dcll_list_t *list)
{
    dcll_node_t *tmp = NULL;
    dcll_node_t *stopper = NULL;

    if (!list)
        return;
    if (!list->head)
        goto end;
    tmp = list->head;
    stopper = list->head;
    do {
        list->head = list->head->next;
        __dcll_destroy_node(tmp);
        tmp = list->head;
    } while (tmp != stopper);
    end:
    free(list);
}