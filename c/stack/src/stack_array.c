#include "../include/stack_array.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

Stack_array *stack_array_create(size_t element_size) {
    if(element_size == 0) return NULL;
    
    Stack_array *new_stack = malloc(sizeof(Stack_array));
    if(!new_stack) return NULL;

    new_stack->element_size = element_size;
    new_stack->capacity = STACK_INIT_CAP;
    new_stack->top = 0;

    new_stack->data = malloc(new_stack->element_size * new_stack->capacity);
    if(!new_stack->data) {
        free(new_stack);
        return NULL;
    }
    return new_stack;
}

int stack_array_destroy(Stack_array *stack) {
    if(!stack) return -1;
    free(stack->data);
    free(stack);
    return 0;
}

int stack_array_push(Stack_array *stack, void *data) {
    if(!stack || !data) return -1;

    if(stack->top >= stack->capacity) {
        if(stack_array_grow(stack) != 0) return -1;
    }

    void *place = (char *)stack->data + (stack->top * stack->element_size);
    memcpy(place, data, stack->element_size);
    stack->top++;
    return 0;
}

int stack_array_pop(Stack_array *stack) {
    if(!stack) return -1;
    if(stack->top == 0) return -1;
    stack->top--;
    return 0;
}

void *stack_array_peek(Stack_array *stack) {
    if(!stack || stack->top == 0) return NULL;
    void *place = (char *)stack->data + ((stack->top -1) * stack->element_size);
    return place;
}

void *stack_array_get(Stack_array *stack, int index) {
    if(!stack || index < 0) return NULL;
    void *place = (char *)stack->data + (index * stack->element_size);
    return place;
}

int stack_array_empty(Stack_array *stack) {
    if(!stack) return 1;
    return stack->top == 0 ? 1 : 0;
}

size_t stack_array_size(Stack_array *stack) {
    return stack ? stack->top : 0;
}

void stack_array_clear(Stack_array *stack) {
    if (!stack) return;
    stack->top = 0;
    if (stack->capacity > STACK_INIT_CAP) {
        void *new_data = realloc(stack->data, STACK_INIT_CAP * stack->element_size);
        if (new_data) {
            stack->data = new_data;
            stack->capacity = STACK_INIT_CAP;
        }
    }
}

int stack_array_grow(Stack_array *stack) {
    if(!stack) return -1;
    size_t new_capacity = stack->capacity * GROWTH_FACTOR;
    void *new_data = realloc(stack->data, new_capacity * stack->element_size);
    if(!new_data) return -1;
    stack->data = new_data;
    stack->capacity = new_capacity;
    return 0;
}

