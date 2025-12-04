#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <stddef.h>

// return 0 succes
// return -1 / 1 fail

typedef struct StackNode {
    void *data;
    struct StackNode *next;
} StackNode;

typedef struct StackList {
    StackNode *top;
    size_t size;
} StackList;

StackList* stack_list_create(void);
int stack_list_push(StackList *stack, void *data);
void* stack_list_pop(StackList *stack);
void* stack_list_peek(const StackList *stack);
void* stack_list_get(StackList *stack, size_t index);
size_t stack_list_size(StackList *stack);
int stack_list_is_empty(const StackList *stack);
int stack_list_clear(StackList *stack);
void stack_list_destroy(StackList *stack);

#endif
