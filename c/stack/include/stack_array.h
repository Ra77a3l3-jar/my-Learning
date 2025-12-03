#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <stddef.h>

#define STACK_INIT_CAP 8
#define GROWTH_FACTOR 2

typedef struct Stack_array{
    void *data;
    size_t top;
    size_t capacity;
    size_t element_size;
} Stack_array;

Stack_array *stack_array_create(size_t element_size);
int stack_array_destroy(Stack_array *stack);
int stack_array_push(Stack_array *stack, void *data);
int stack_array_pop(Stack_array *stack);
void *stack_array_peek(Stack_array *stack);
void *stack_array_get(Stack_array *stack, int index);
int stack_array_empty(Stack_array *stack);
size_t stack_array_size(Stack_array *stack);
void stack_array_clear(Stack_array *stack);
int stack_array_grow(Stack_array *stack);

#endif
