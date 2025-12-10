#include "include/ringBuffer.h"

#include <stdio.h>

int main(void) {

    Ring *ring = ring_create(32, sizeof(int));

    for(size_t i = 0; i < 10; i++) {
        ring_write(ring, &i);
    }

    for(size_t i = 0; i < ring_size(ring); i++) {
        printf("pos %zu : %d\n", i, *(int*)ring_get(ring, i));
    }

    // the ring now will be full
    for(size_t i = ring_size(ring); i < ring_capacity(ring); i++) {
        ring_write(ring, &i);
    }

    printf("The ring buffer is full? %s.\n", ring_full(ring) ? "Yes" : "No");

    ring_read(ring); // removing the element at head to test the circular buffer
    int x = 404;
    ring_write(ring, &x);

    for(size_t i = 0; i < ring_size(ring); i++) {
        printf("pos %zu : %d\n", i, *(int*)ring_get(ring, i));
    }

    printf("Is the ring empty? %s.\n", ring_empty(ring) ? "Yes" : "No");
    ring_clear(ring);
    printf("Is the ring empty? %s.\n", ring_empty(ring) ? "Yes" : "No");

    ring_destroy(ring);
}
