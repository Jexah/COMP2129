#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

struct list_head {
    void *data;
    struct list_head *prev, *next;
};

/** Initialises "head" to be the head of a circular linked list */
void list_init(struct list_head *head);

/** Inserts a new entry after "head" */
void list_add(struct list_head *new, struct list_head *head);

/** Inserts a new entry before "head" */
void list_add_tail(struct list_head *new, struct list_head *head);

/** Removes "entry" from the list */
void list_del(struct list_head *entry);

/** Checks if the list is empty */
bool list_empty(struct list_head *head);

#endif
