/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Allocates memory for a new DCLL.
*/

#include "dcll.h"

dcll_list_t *dcll_create_list(void)
{
    dcll_list_t *list = malloc(sizeof(dcll_list_t));

    if (!list)
        return (NULL);
    (*list) = (dcll_list_t){.head = NULL, .length = 0};
    return (list);
}
