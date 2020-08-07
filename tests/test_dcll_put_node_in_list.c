/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Tests the dcll_put_node_in_list() function.
*/

#include <criterion/criterion.h>
#include "dcll.h"

Test(dcll_put_node_in_list, negative_easy_overflow)
{
    dcll_list_t *list = dcll_create_list();
    dcll_node_t *result = NULL;

    cr_assert(dcll_put_node_in_list(list, dcll_create_node(), -1));
    cr_assert(dcll_put_node_in_list(list, dcll_create_node(), -1));
    cr_assert(dcll_put_node_in_list(list, dcll_create_node(), -1));
    result = dcll_get_node_by_index(list, -1);
    cr_expect(result == list->head->prev);
}

Test(dcll_put_node_in_list, positive_easy_no_overflow)
{
    dcll_list_t *list = dcll_create_list();
    dcll_node_t *result = NULL;

    cr_assert(dcll_put_node_in_list(list, dcll_create_node(), 0));
    cr_assert(dcll_put_node_in_list(list, dcll_create_node(), 0));
    cr_assert(dcll_put_node_in_list(list, dcll_create_node(), 0));
    result = dcll_get_node_by_index(list, 2);
    cr_expect(result == list->head->prev);
}

Test(dcll_put_node_in_list, negative_hard_overflow)
{
    dcll_list_t *list = dcll_create_list();
    dcll_node_t *result = NULL;

    for (register size_t index = 0; index < 7; index += 1) {
        cr_assert(dcll_put_node_in_list(list, dcll_create_node(), -1));
    }
    result = dcll_get_node_by_index(list, -8);
    cr_expect(result == list->head->prev);
}
