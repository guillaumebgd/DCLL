/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Tests the dcll_add_node() function.
*/

#include <criterion/criterion.h>
#include "dcll.h"

Test(dcll_add_node, add_a_simple_node)
{
    dcll_list_t *list = dcll_create();

    cr_expect(dcll_add_node(list));
    cr_assert(list);
    cr_assert(list->head);
    cr_assert(list->head->next == list->head->prev);
    cr_assert(list->head->next->next == list->head);
    cr_assert(list->head->next->next == list->head);
    cr_assert(list->head->prev->prev == list->head);
    dcll_destroy_list(list);
}