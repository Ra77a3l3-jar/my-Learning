#include "../include/ringBuffer.h"

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

Ring *ring_create(size_t capacity, size_t element_size) {
    Ring *new_ring = malloc(sizeof(Ring));
    if(!new_ring) return NULL;

    if(capacity == 0) {
        new_ring->capacity = RING_DEF_CAP;
    } else {
        new_ring->capacity = capacity;
    }

    new_ring->size = 0;
    new_ring->head = 0;
    new_ring->tail = 0;
    new_ring->element_size = element_size;
    new_ring->data = malloc(new_ring->element_size * new_ring->capacity);
    if(!new_ring->data) {
        free(new_ring);
        return NULL;
    }
    return new_ring;
}

int ring_destroy(Ring *ring) {
    if(!ring) return -1;
    if(!ring->data) return -1;

    free(ring->data);
    free(ring);
    return 0;
}

int ring_clear(Ring *ring) {
    if(!ring) return -1;
    if(!ring->data) return -1;

    free(ring->data);
    ring->data = malloc(ring->element_size * ring->capacity);
    if(!ring->data) return -1;

    ring->size = 0;
    ring->tail = 0;
    ring->head = 0;
    return 0;
}

int ring_write(Ring *ring, void *data) {
    if(!ring || !data) return -1;

    if(ring->size == ring->capacity && ring->tail != 0) {
        void *place = (char*)ring->data + (ring->element_size * (ring->tail - 1));
        memcpy(place, data, ring->element_size);
        ring->head++;
        ring->size++;
        return 0;
    }

    void *place = (char*)ring->data + (ring->element_size * ring->head);
    memcpy(place, data, ring->element_size);
    ring->head++;
    ring->size++;
    return 0;
}

void *ring_read(Ring* ring) {
    if(!ring) return NULL;

    void *place = (char*)ring->data + (ring->element_size * (ring->tail));
    ring->size--;
    ring->tail++;
    return place;
}

void *ring_get(Ring *ring, size_t index) {
    if(!ring || index > ring->size) return NULL;

    void *place = (char*)ring->data + (ring->element_size * index);
    return place;
}

int ring_full(Ring *ring) {
    if(!ring) return -1;
    if(ring->size == ring->capacity) return 0;
    return -1;
}

int ring_empty(Ring *ring) {
    if(!ring) return -1;
    if(ring->size == 0) return 0;
    return -1;
}

size_t ring_size(Ring *ring) {
    return ring ? ring->size : 0;
}

size_t ring_capacity(Ring *ring) {
    return ring ? ring->capacity : 0;
}

size_t ring_avaible(Ring *ring) {
    return ring ? (ring->capacity - ring->size) : 0;
}
