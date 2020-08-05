/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Allocates memory for a new DCLL.
*/

#include <stdlib.h>
#include "dcll.h"

dcll_list_t *dcll_create(void)
{
    dcll_list_t *list = malloc(sizeof(dcll_list_t));

    if (!list)
        return (NULL);
    list->head = malloc(sizeof(dcll_node_t));
    if (!(list->head)) {
        free(list);
        return (NULL);
    }
    (*list->head) = (dcll_node_t) {NULL, NULL, list->head, list->head};
    list->length = 1;
    return (list);
}