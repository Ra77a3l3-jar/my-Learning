#ifndef  DEQUELIST_H
#define DEQUELIST_H

#include <stddef.h>

// return 0 sucess
// return -1 / 1 fail

typedef struct DequeNode {
    void *data;
    struct DequeNode *next;
    struct DequeNode *prev;
} DequeNode;

typedef struct DequeList {
    struct DequeNode *front;
    struct DequeNode *back;
    size_t size;
} DequeList;

DequeList *deque_list_create(void);
void deque_list_destroy(DequeList *deque);

int deque_list_empty(const DequeList *deque);
size_t deque_list_size(const DequeList *deque);

int deque_list_push_front(DequeList *deque, void *data);
int deque_list_push_back(DequeList *deque, void *data);
void *deque_list_pop_front(DequeList *deque);
void *deque_list_pop_back(DequeList *deque);

void *deque_list_peek_front(const DequeList *deque);
void *deque_list_peek_back(const DequeList *deque);

void deque_list_clear(DequeList *deque);

void deque_list_print(const DequeList *deque, void (*print_func)(void *data));
void *deque_list_get(DequeList *deque, size_t position);

#endif
