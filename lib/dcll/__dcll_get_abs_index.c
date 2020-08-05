/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Gets the absolute value of an index in a DCLL.
*/

#include <unistd.h>

ssize_t __dcll_get_abs_index(const ssize_t list_length, ssize_t index)
{
    if (list_length <= 0)
        return (0);
    index %= list_length;
    if (index < 0)
        index += list_length;
    return (index);
}
