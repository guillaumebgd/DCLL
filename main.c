/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Main for debugging of the lib.
*/

#include "dcll.h"

int main(void)
{
    dcll_list_t *list = dcll_create_list();
    dcll_node_t *result = NULL;

    dcll_put_node_in_list(list, dcll_create_node(), -1);
    dcll_put_node_in_list(list, dcll_create_node(), -1);
    dcll_put_node_in_list(list, dcll_create_node(), -1);
    result = dcll_get_node_by_index(list, -1);
    dcll_destroy_list(list);
    return (0);
}
