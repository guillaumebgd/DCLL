/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Tests the dcll_create() function.
*/

#include <criterion/criterion.h>
#include "dcll.h"

Test(dcll_create, test_for_memory_allocation_true)
{
    dcll_list_t *list = dcll_create();

    if (!list)
        return;
    cr_assert_neq(list->head, NULL);
    cr_assert(list->head->next == list->head);
    cr_assert(list->head->prev == list->head);
    cr_assert(list->head->data == NULL);
    cr_assert(list->length == 1);
    dcll_destroy_list(list);
}
