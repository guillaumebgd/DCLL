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

    dcll_add_node(list, NULL, 0, NULL);
    dcll_add_node(list, NULL, 0, NULL);
    dcll_add_node(list, NULL, 0, NULL);
    result = dcll_get_node_by_index(list, 2);
    dcll_destroy_list(list);
    return (0);
}