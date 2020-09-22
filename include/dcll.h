/*
** Duo Project C Library
** DCLL
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

///////////////////////
// Library Functions //
///////////////////////

//Allocates memory for a new DCLL.
//The list content will be set to NULL.
//
//Returns an allocated pointer to a DCLL on success.
//Returns NULL on error.
dcll_list_t *dcll_create_list(void);
//////////////////////////////

//Allocates memory for a new DCLL node.
//The node data content will be set to NULL.
//Its next and prev pointers point to the node.
//
//Returns an allocated pointer to a DCLL node on success.
//Returns NULL on error.
dcll_node_t *dcll_create_node(void);
//////////////////////////////

//Gets a pointer to a node in a list at the given 'index'.
//
//Returns a (dcll_note_t *) on success.
//Returns (NULL) if not found.
dcll_node_t *dcll_get_node_by_index(const dcll_list_t *list, ssize_t index);
//////////////////////////////

//Sets a node 'data' and 'data_freer' function pointer.
//Duplicates given 'data'. Therefore, needs the memory size taken by 'data' as 'data_size'.
//
//Returns (true) on success.
//Returns (false) on error.
bool dcll_set_node(dcll_node_t *node, void *data, const size_t data_size, void *(*data_freer)(void *));
//////////////////////////////

//Puts a node into a list at the desired index.
//
//Returns (true) on success.
//Returns (false) on error.
bool dcll_put_node_in_list(dcll_list_t *list, dcll_node_t *node, const ssize_t index);
//////////////////////////////

//If the list isn't set to NULL, frees the list and its nodes
//using the data_freer function pointers if the data and data_freer fonction pointers aren't set to NULL.
void dcll_destroy_list(dcll_list_t *list);
//////////////////////////////

//If the node isn't set to NULL, frees the node and its content
//using the data_freer function pointers if the data and data_freer fonction pointer aren't set to NULL.
void dcll_destroy_node(dcll_node_t *node);
//////////////////////////////

/////////////////////////////////////////

#endif /* DCLL_H_ */