/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Tests the dcll_inject_array() function.
*/

#include <criterion/criterion.h>
#include "dcll.h"

Test(dcll_inject_array, test_bad_parameters_1)
{
    dcll_list_t *list = dcll_create();

    if (!list)
        return;
    dcll_inject_array(list, NULL, 5, sizeof(int));
    cr_assert(list->length == 0);
    dcll_destroy_list(list);
}

Test(dcll_inject_array, test_bad_parameters_2)
{
    dcll_list_t *list = dcll_create();
    int array[] = {1, 2, 3, 4, 5};

    if (!list)
        return;
    cr_assert(!dcll_inject_array(NULL, array, 5, sizeof(int)));
    dcll_destroy_list(list);
}

Test(dcll_inject_array, test_valid_int_array)
{
    dcll_list_t *list = dcll_create();
    int array[] = {1, 2, 3, 4, 5};

    if (!list)
        return;
    dcll_inject_array(list, array, 5, sizeof(int));
    cr_assert(*(int *)dcll_get_node_by_index(list, 0)->data == 1);
    cr_assert(*(int *)dcll_get_node_by_index(list, 1)->data == 2);
    cr_assert(*(int *)dcll_get_node_by_index(list, 2)->data == 3);
    cr_assert(*(int *)dcll_get_node_by_index(list, 3)->data == 4);
    cr_assert(*(int *)dcll_get_node_by_index(list, 4)->data == 5);
    cr_assert(list->length == 5);
    dcll_destroy_list(list);
}

Test(dcll_inject_array, test_valid_char_array)
{
    dcll_list_t *list = dcll_create();
    char array[] = {1, 2, 3, 4, 5};

    if (!list)
        return;
    dcll_inject_array(list, array, 5, sizeof(char));
    cr_assert(*(int *)dcll_get_node_by_index(list, 0)->data == 1);
    cr_assert(*(int *)dcll_get_node_by_index(list, 1)->data == 2);
    cr_assert(*(int *)dcll_get_node_by_index(list, 2)->data == 3);
    cr_assert(*(int *)dcll_get_node_by_index(list, 3)->data == 4);
    cr_assert(*(int *)dcll_get_node_by_index(list, 4)->data == 5);
    cr_assert(list->length == 5);
    dcll_destroy_list(list);
}
