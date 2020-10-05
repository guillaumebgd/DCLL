/*
** Duo Project C Library
** DCLL
** File description:
** Tests the dcll_create_node() function.
*/

#include <criterion/criterion.h>
#include "dcll.h"

Test(dcll_create_node, test_for_memory_allocation_true)
{
    dcll_node_t *node = dcll_create_node();

    if (!node)
        return;
    cr_assert(node != NULL);
    cr_assert(node->data == NULL);
    cr_assert(node->data_freer == NULL);
    cr_assert(node->next == node);
    cr_assert(node->prev == node);
}
