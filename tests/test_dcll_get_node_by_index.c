/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Tests the dcll_add_node() function.
*/

#include <criterion/criterion.h>
#include "dcll.h"

Test(dcll_get_node_by_index, negative_easy_overflow)
{
    dcll_list_t *list = dcll_create();
    dcll_node_t *result = NULL;

    cr_assert(dcll_add_node(list, NULL, 0, NULL));
    cr_assert(dcll_add_node(list, NULL, 0, NULL));
    cr_assert(dcll_add_node(list, NULL, 0, NULL));
    result = dcll_get_node_by_index(list, -1);
    cr_expect(result == list->head->prev);
    dcll_destroy_list(list);
}

Test(dcll_get_node_by_index, positive_easy_no_overflow)
{
    dcll_list_t *list = dcll_create();
    dcll_node_t *result = NULL;

    cr_assert(dcll_add_node(list, NULL, 0, NULL));
    cr_assert(dcll_add_node(list, NULL, 0, NULL));
    cr_assert(dcll_add_node(list, NULL, 0, NULL));
    result = dcll_get_node_by_index(list, 2);
    cr_expect(result == list->head->prev);
    dcll_destroy_list(list);
}

Test(dcll_get_node_by_index, negative_hard_overflow)
{
    dcll_list_t *list = dcll_create();
    dcll_node_t *result = NULL;

    for (register size_t index = 0; index < 7; index += 1) {
        cr_assert(dcll_add_node(list, NULL, 0, NULL));
    }
    result = dcll_get_node_by_index(list, -8);
    cr_expect(result == list->head->prev);
    dcll_destroy_list(list);
}