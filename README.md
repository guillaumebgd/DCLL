***

# Doubly Circular Linked Lists - C Library

A C library made for flexible __*doubly circular linked lists*__.
If you're unfamiliar with this concept, we advise you to search about it for the memory and pointers behind before using the library!

## Usage of the Library

Everything is described in details [here](https://github.com/guillaumebgd/DCLL_C_Library/wiki/DCLL-Wiki:-Home)!<br>
Examples to understand even more the logic behind the library are available there!

## Table of Contents

As in release v1.0.0, here is the material you can work with this library (for further explanation on them, click [here](https://github.com/guillaumebgd/DCLL_C_Library/wiki/DCLL-Wiki:-Home))

***

A node that can contain any type of data and with which you can bind a function that frees it.

```C
typedef struct dcll_node_s {
    void *data;
    void *(*data_freer)(void *);
    struct dcll_node_s *next;
    struct dcll_node_s *prev;
} dcll_node_t;
```

---

Creating nodes after nodes to make a list can be stored in this structure that keeps track of the length of your list.

```C
typedef struct dcll_list_s {
    dcll_node_t *head;
    ssize_t length;
} dcll_list_t;
```

---

Allocates memory for a <code>dcll_list_t *list</code>, sets the <code>dcll_node_t *head</code> to <code>NULL</code> and the <code>ssize_t length</code> to <code>0</code>.

```C
dcll_list_t *dcll_create_list(void);
```

---

Allocates memory for a <code>dcll_node_t *node</code>, sets the <code>void *data</code> and the <code>void *(*data_freer)(void *)</code> to NULL. Also sets the <code>dcll_node_t *next</code> and <code>dcll_node_t *prev</code> to the newly allocated <code>dcll_node_t *node</code>.

```C
dcll_node_t *dcll_create_node(void);
```

---

Duplicates <code>void *data</code> by allocating a new memory field of size <code>const size_t data_size</code> to it. Also sets the <code>void *(*data_freer)(void *)</code> to the address of a function that frees <code>void *data</code>.

```C
bool dcll_set_node(dcll_node_t *node, void *data, const size_t data_size, void *(*data_freer)(void *));
```

---

Puts a <code>dcll_node_t *node</code> to a certain <code>const ssize_t index</code> position in a <code>dcll_list_t *list</code>.
Explanations on indexes usages in this library are available in the [wiki](https://github.com/guillaumebgd/DCLL_C_Library/wiki/DCLL-Wiki:-Indexes)!

```C
bool dcll_put_node_in_list(dcll_list_t *list, dcll_node_t *node, const ssize_t index);
```

---

Gets a <code>dcll_note_t *node</code> at the given <code>ssize_t index</code> in the given <code>const dcll_list_t *list</code>.
Explanations on indexes usages in this library are available in the [wiki](https://github.com/guillaumebgd/DCLL_C_Library/wiki/DCLL-Wiki:-Indexes)!
```C
dcll_node_t *dcll_get_node_by_index(const dcll_list_t *list, ssize_t index);
```

---

Frees allocated memory given to a <code>dcll_list_t *list</code> including each of its <code>dcll_node_t *node</code>'s in it.

```C
void dcll_destroy_list(dcll_list_t *list);
```

---

Frees allocated memory given to a <code>dcll_list_t *node</code> including all of the <code>void *data</code> in it using the <code>void *(*data_freer)(void *)</code>.

```C
void dcll_destroy_node(dcll_node_t *node);
```

## Expected to be seen in the next release

* A converter function from array data types to *DCLL*'s that could create a list of characters, integers or strings for instances.
* A data sorter. (By ascending or by descending order) -> With possibility to create your own sorting function and use it interactively with the library.

##

Thanks for reading about our work !

- by [Mathéo Lucak](https://github.com/matheo-lucak) and [Guillaume Bogard](https://github.com/guillaumebgd)
