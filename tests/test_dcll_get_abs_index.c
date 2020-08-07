/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Tests the __dcll_get_abs_index() function.
*/

#include <criterion/criterion.h>
#include "dcll.h"

Test(__dcll_get_abs_index, all_possibilities)
{
    cr_assert(__dcll_get_abs_index(7, 1) == 1);
    cr_assert(__dcll_get_abs_index(7, 7) == 0);
    cr_assert(__dcll_get_abs_index(7, 8) == 1);
    cr_assert(__dcll_get_abs_index(7, 14) == 0);
    cr_assert(__dcll_get_abs_index(7, 16) == 2);
    cr_assert(__dcll_get_abs_index(7, -0) == 0);
    cr_assert(__dcll_get_abs_index(7, -1) == 6);
    cr_assert(__dcll_get_abs_index(7, -7) == 0);
    cr_assert(__dcll_get_abs_index(7, -8) == 6);
    cr_assert(__dcll_get_abs_index(7, -1) == 6);
}
