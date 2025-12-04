#include "../include/stack_list.h"
#include <stdlib.h>

StackList* stack_list_create(void) {
    StackList *new_list = malloc(sizeof(StackList));
    if(!new_list) return NULL;

    new_list->size = 0;
    new_list->top = NULL;
    return new_list;
}

int stack_list_push(StackList *stack, void *data) {
    if(!stack || !data) return -1;

    StackNode *new_node = malloc(sizeof(StackNode));
    if(!new_node) return -1;

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;

    return 0;
}

void* stack_list_pop(StackList *stack) {
    if(!stack || !stack->top) return NULL;

    void *data = stack->top->data;
    StackNode *next = stack->top->next;
    free(stack->top);
    stack->top = next;
    stack->size--;
    return data;
}

void* stack_list_peek(const StackList *stack) {
    if(!stack || !stack->top) return NULL;
    return stack->top->data;
}

void* stack_list_get(StackList *stack, size_t index) {
    if(!stack || index >= stack->size) return NULL;

    StackNode *current = stack->top;
    for(size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

size_t stack_list_size(StackList *stack) {
    if(!stack) return 0;
    return stack->size;
}

int stack_list_is_empty(const StackList *stack) {
    return stack->size == 0 ? 1 : 0;
}

int stack_list_clear(StackList *stack) {
    if(!stack) return -1;

    StackNode *current = stack->top;
    while(current) {
        StackNode *temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
    stack->size = 0;
    return 0;
}

void stack_list_destroy(StackList *stack) {
    if(!stack) return;

    StackNode *current = stack->top;
    while(current) {
        StackNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}
