#include "include/stack_list.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    StackList *stack = stack_list_create();

    for(size_t i = 0; i < 10; i++) {
        int *val = malloc(sizeof(int));
        *val = i;
        stack_list_push(stack, val);
    }

    for(size_t i = 0; i < stack_list_size(stack); i++) {
        printf("pos %zu : %d\n", i, *(int*)stack_list_get(stack, i));
    }

    free(stack_list_pop(stack));
    free(stack_list_pop(stack));

    for(size_t i = 0; i < stack_list_size(stack); i++) {
        printf("pos %zu : %d\n", i, *(int*)stack_list_get(stack, i));
    }

    printf("The stack is empty: %s.\n", stack_list_is_empty(stack) ? "True" : "False");
    
    while(!stack_list_is_empty(stack)) {
        free(stack_list_pop(stack));
    }
    
    printf("The stack is empty: %s.\n", stack_list_is_empty(stack) ? "True" : "False");

    stack_list_destroy(stack);
}
