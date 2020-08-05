/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Header of the DCLL Library
*/

#ifndef DCLL_H_

///////////////////
#include <unistd.h>
#include <stdbool.h>
///////////////////

typedef struct dcll_node_s {
    void *data;
    void *(*data_freer)(void *);
    struct dcll_node_s *next;
    struct dcll_node_s *prev;
} dcll_node_t;

typedef struct dcll_list_s {
    dcll_node_t *head;
    ssize_t length;
} dcll_list_t;

/////////////////////////////////////////

//////////////////////////////

//Allocates memory for a new DCLL.
//
//Returns an allocated pointer to a DCLL on success.
//Returns NULL on error.
dcll_list_t *dcll_create(void);
//////////////////////////////

//Library-reserved generic function to add node.
//
//- Not designed to be used.
bool __dcll_add_node(dcll_list_t *list, ssize_t index);

//Allocates memory for a new DCLL node and adds it to the list.
//
//Returns (true) on success.
//Returns (false) on error (memory allocation failed).
static inline bool dcll_add_node(dcll_list_t *list)
{
    return (__dcll_add_node(list, -1));
}
//////////////////////////////

//Library-reserved generic function to get the absolute value of an index
//to allow negative index in the library.
//
//- Not designed to be used.
ssize_t __dcll_get_abs_index(const ssize_t list_length, ssize_t index);
//////////////////////////////

dcll_node_t *dcll_get_node_by_index(const dcll_list_t *list, ssize_t index);

//////////////////////////////

void dcll_destroy_list(dcll_list_t *list);

/////////////////////////////////////////

#endif /* DCLL_H_ */