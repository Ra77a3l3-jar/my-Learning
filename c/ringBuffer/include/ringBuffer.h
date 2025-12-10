#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stddef.h>

// return 0 success
// return -1 / 1 fail

#define RING_DEF_CAP 64

typedef struct Ring {
    void *data;
    size_t capacity;
    size_t size;
    size_t tail; // read pos
    size_t head; // write pos
    size_t element_size;
} Ring;

Ring *ring_create(size_t capacity, size_t element_size);
int ring_destroy(Ring *ring);
int ring_clear(Ring *ring);
int ring_write(Ring *ring, void *data);
void *ring_read(Ring *ring);
void *ring_get(Ring *ring, size_t index);
int ring_full(Ring *ring);
int ring_empty(Ring *ring);
size_t ring_size(Ring *ring);
size_t ring_capacity(Ring *ring);
size_t ring_avaible(Ring *ring);

#endif
