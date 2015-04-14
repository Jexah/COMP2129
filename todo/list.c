#include <stdbool.h>

#include "list.h"

/** Initialises "head" to be the head of a ciricular linked list */
void list_init(struct list_head *head) {
    head->next = head;
    head->prev = head;
}

/** Inserts a new entry after "head" */
void list_add(struct list_head *new, struct list_head *head) {
    new->prev = head;
    new->next = head->next;

    new->next->prev = new;
    new->prev->next = new;
}

/** Inserts a new entry before "head" */
void list_add_tail(struct list_head *new, struct list_head *head) {
    new->prev = head->prev;
    new->next = head;

    new->prev->next = new;
    new->next->prev = new;
}

/** Removes "entry" from the list */
void list_del(struct list_head *entry) {
    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;

    list_init(entry); // change entry into an empty list for convenience
}

/** Checks if the list is empty */
bool list_empty(struct list_head *head) {
    return head->prev == head;
}
