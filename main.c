/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Main for debugging of the lib.
*/

#include "dcll.h"

int main(void)
{
    dcll_list_t *list = dcll_create();
    dcll_node_t *result = NULL;
    register size_t index = 0;

    for (; index < 7; index += 1) {
        dcll_add_node(list);
    }
    result = dcll_get_node_by_index(list, -8);
    return (0);
}
