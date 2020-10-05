/*
** Duo Project C Library
** DCLL_C_Library
** File description:
** Header of the DCLL Library
*/

#ifndef DCLL_H_

////////////////////
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
////////////////////

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

///////////////////////////
// Library private utils //
///////////////////////////

//Library-reserved generic function to get the absolute value of an index
//to allow negative index in the library.
//
//- Not designed to be used.
ssize_t __dcll_get_abs_index(const ssize_t list_length, ssize_t index);

//Library-reserved function to duplicate void *data.
//
//- Not designed to be used.
static inline void *__dcll_data_dup(void *data, const size_t size)
{
    void *new_data = malloc(size);

    if (!new_data)
        return (NULL);
    memcpy(new_data, data, size);
    return (new_data);
}

//////////////////////////////

//////////////////////////////

//Allocates memory for a new DCLL.
//The list inside of the structure will be set to NULL.
//
//Returns an allocated pointer to a DCLL on success.
//Returns NULL on error.
dcll_list_t *dcll_create(void);
//////////////////////////////

//Library-reserved generic function to add node.
//
//- Not designed to be used.
bool __dcll_add_node(dcll_list_t *list, void *data, void *(*data_freer)(void *));

//Allocates memory for a new DCLL node and adds it to the list.
//
//Returns (true) on success.
//Returns (false) on error (memory allocation failed).
static inline bool dcll_add_node(dcll_list_t *list, void *data, const size_t data_size, void *(*data_freer)(void *))
{
    return (__dcll_add_node(list, __dcll_data_dup(data, data_size), data_freer));
}

dcll_node_t *dcll_get_node_by_index(const dcll_list_t *list, ssize_t index);


//////////////////////////////

void dcll_destroy_list(dcll_list_t *list);

//Allocates, sets and appends a node for each element of a given array to a given list.
//'length' is the number of element of the given array
//'size' is memory size of each element of the given array
//Each created node is allocated a new memory block to store one array element.
//The free() function is set by default to each node as the data_freer.
//
//Returns (list) on success.
//Returns (NULL) on error (NULL pointers passed).
dcll_list_t *dcll_inject_array(dcll_list_t *list, const void *array, const size_t length, const size_t size);

/////////////////////////////////////////

#endif /* DCLL_H_ */
