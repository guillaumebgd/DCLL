/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Gets a pointer to the x node of a DCLL.
*/

#include "dcll.h"

dcll_node_t *dcll_get_node_by_index(const dcll_list_t *list, ssize_t index)
{
    dcll_node_t *tmp = NULL;

    if (!list)
        return (NULL);
    tmp = list->head;
    index = __dcll_get_abs_index(list->length, index);
    if (index <= list->length / 2) {
        for (; index-- > 0; tmp = tmp->next);
    } else {
        index = list->length - index;
        for (; index-- > 0; tmp = tmp->prev);
    }
    return (tmp);
}