/*
** Duo Project C Library
** DCLL
** File description:
** Frees memory allocated by a DCLL.
*/

#include "dcll.h"

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
        dcll_destroy_node(tmp);
        tmp = list->head;
    } while (tmp != stopper);
    end:
    free(list);
}