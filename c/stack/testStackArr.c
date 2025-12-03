#include "include/stack_array.h"

#include <stdio.h>

int main(void) {

    Stack_array *stack = stack_array_create(sizeof(int));

    for(int i = 0; i < 10; i++) {
        stack_array_push(stack, &i);
    }

    for(int i = 0; i < 10; i++) {
        printf("pos %d : %d\n", i, *(int*)(stack_array_get(stack, i)));
    }

    printf("The stack size is: %zu\n", stack_array_size(stack));

    stack_array_pop(stack);
    printf("The stack size is: %zu\n", stack_array_size(stack));    
    int x = *(int*)stack_array_peek(stack);
    printf("The peeked or top element is: %d\n", x);

    for(int i = 0; i < 10; i++) {
        printf("pos %d : %d\n", i, *(int*)(stack_array_get(stack, i)));
    }

    printf("Is the stack empty: %s\n", stack_array_empty(stack) ? "True" : "False");
    stack_array_clear(stack);
    printf("Clearing the array\n");
    printf("Is the stack empty: %s\n", stack_array_empty(stack) ? "True" : "False");

    stack_array_destroy(stack);
} 
