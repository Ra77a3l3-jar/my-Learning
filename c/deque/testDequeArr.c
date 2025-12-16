#include "include/dequeArr.h"

#include <stdio.h>

int main(void) {

    DequeArray *deque = deque_array_create(sizeof(int), 32);

    printf("The default initial capacity is %d while in the deque the capacity is %zu.\n", DEQUE_INIT_CAP, deque_array_capacity(deque));

    for(size_t i = 0; i < 30; i++) {
        int temp = i;
        deque_array_push_front(deque, &temp);
    }

    int x = 30;
    deque_array_push_back(deque, &x);

    for(size_t i = 0; i < deque_array_size(deque); i++) {
        size_t idx = (deque->front + i) % deque->capacity;
        printf("Pos %zu : %d\n", i, *((int*)deque->data + idx));
    }

    deque_array_pop_front(deque);
    deque_array_pop_back(deque);

    printf("Popped once at front and at the back.\n");

    for(size_t i = 0; i < deque_array_size(deque); i++) {
        size_t idx = (deque->front + i) % deque->capacity;
        printf("Pos %zu : %d\n", i, *((int*)deque->data + idx));
    }

    printf("The peeked value at front is %d and at the back is %d.\n", *(int*)deque_array_peek_front(deque), *(int*)deque_array_peek_back(deque));

    printf("The deque is empty : %s.\n", deque_array_empty(deque) ? "True" : "False");
    deque_array_clean(deque);
    printf("The deque is empty : %s.\n", deque_array_empty(deque) ? "True" : "False");

    deque_array_destroy(deque);
}
