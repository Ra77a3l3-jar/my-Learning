#include "include/queue_list.h"

#include <stdio.h>

int main(void) {

    Queue *queue = queue_list_create();
    int values[10];
    for(int i = 0; i < 10; i++) {
        values[i] = i;
        queue_list_push(queue, &values[i]);
    }

    for(size_t i = 0; i < queue_list_size(queue); i++) {
        printf("pos %zu : %d\n", i, *(int*)queue_list_get(queue, i));
    }

    void *data = queue_list_peek(queue);
    printf("Peeked the value %d\n", *(int*)data);

    queue_list_pop(queue);
    queue_list_pop(queue);
    printf("Queue after two values got popped.\n");
    
    for(size_t i = 0; i < queue_list_size(queue); i++) {
        printf("pos %zu : %d\n", i, *(int*)queue_list_get(queue, i));
    }

    queue_list_destroy(queue);
}
