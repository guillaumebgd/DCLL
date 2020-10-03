/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Allocates memory for a new DCLL.
*/

#include "dcll.h"

dcll_list_t *dcll_inject_array(dcll_list_t *list, const void *array,
                                const size_t lenght, const size_t size)
{
    register size_t index = 0;

    if (!list || !array)
        return (NULL);
    for (index = 0; index < lenght; index += 1) {
        dcll_add_node(list, (void *) array + (index * size), size, (void *)free);
    }
    return (list);
}