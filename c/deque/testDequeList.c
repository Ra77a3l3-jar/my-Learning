#include "include/dequeList.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    DequeList *deque = deque_list_create();

    for(size_t i = 0; i < 20; i++) {
        int *val = malloc(sizeof(int));
        *val = i;
        deque_list_push_front(deque, val);
    }

    int *x = malloc(sizeof(int));
    *x = 21;
    deque_list_push_back(deque, x);

    for(size_t i = 0; i < deque_list_size(deque); i++) {
        printf("pos %zu : %d\n", i, *(int*)deque_list_get(deque, i));
    }

    deque_list_pop_front(deque);
    deque_list_pop_front(deque);

    printf("Deque after popping once at front and once at the back.\n");

    for(size_t i = 0; i < deque_list_size(deque); i++) {
        printf("pos %zu : %d\n", i, *(int*)deque_list_get(deque, i));
    }

    printf("The value which is peeked at the front is %d\n", *(int*)deque_list_peek_front(deque));
    printf("The value peeked at the back is %d.\n", *(int*)deque_list_peek_back(deque));

    printf("The deque is empty : %s\n", deque_list_empty(deque) ? "False" : "True");
    deque_list_clear(deque);
    printf("The deque is empty : %s\n", deque_list_empty(deque) ? "False" : "True");

    deque_list_destroy(deque);
} 
