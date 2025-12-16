#ifndef DEQUEARR_H
#define DEQUEARR_H

#include <stddef.h>

#define DEQUE_INIT_CAP 16

typedef struct DequeArray {
    void *data;
    size_t capacity;
    size_t size;
    size_t front;
    size_t back;
    size_t element_size;
} DequeArray;

DequeArray *deque_array_create(size_t element_size, size_t capacity);
void deque_array_destroy(DequeArray *deque);

int deque_array_empty(DequeArray *deque);
size_t deque_array_size(DequeArray *deque);
size_t deque_array_capacity(DequeArray *deque);

int deque_array_push_front(DequeArray *deque, void *data);
int deque_array_push_back(DequeArray *deque, void *data);

void *deque_array_pop_front(DequeArray *deque);
void *deque_array_pop_back(DequeArray *deque);

void *deque_array_peek_front(DequeArray *deque);
void *deque_array_peek_back(DequeArray *deque);

void deque_array_clean(DequeArray *deque);

#endif
