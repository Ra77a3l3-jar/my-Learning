#include "../include/dequeArr.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

DequeArray *deque_array_create(size_t element_size, size_t capacity) {
    DequeArray *new_deque = malloc(sizeof(DequeArray));
    if(!new_deque) return NULL;

    new_deque->element_size = element_size;
    if(capacity > 0) {
        new_deque->capacity = capacity;
    } else {
        new_deque->capacity = DEQUE_INIT_CAP;
    }
    new_deque->size = 0;
    new_deque->front = 0;
    new_deque->back = 0;

    new_deque->data = malloc(new_deque->element_size * new_deque->capacity);
    if(!new_deque->data) {
        free(new_deque);
        return NULL;
    }
    return new_deque;
}

void deque_array_destroy(DequeArray *deque) {
    if(!deque) return;

    free(deque->data);
    free(deque);
}

int deque_array_empty(DequeArray *deque) {
    return !deque || deque->size == 0;
}

size_t deque_array_size(DequeArray *deque) {
    return deque ? deque->size : 0;
}

size_t deque_array_capacity(DequeArray *deque) {
    return deque ? deque->capacity : 0;
}

static int deque_array_resize(DequeArray *deque) {
    size_t new_capacity = deque->capacity * 2;
    void *new_data = malloc(deque->element_size * new_capacity);
    if(!new_data) return -1;

    for(size_t i = 0; i < deque->size; i++) {
        size_t old_index = (deque->front + i) % deque->capacity;
        memcpy((char*)new_data + i * deque->element_size, 
               (char*)deque->data + old_index * deque->element_size, 
               deque->element_size);
    }

    free(deque->data);
    deque->data = new_data;
    deque->capacity = new_capacity;
    deque->front = 0;
    deque->back = deque->size;
    return 0;
}

int deque_array_push_front(DequeArray *deque, void *data) {
    if(!deque || !data) return -1;

    if(deque->size == deque->capacity) {
        if(deque_array_resize(deque) != 0) return -1;
    }

    deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    memcpy((char*)deque->data + deque->front * deque->element_size, data, deque->element_size);
    deque->size++;
    return 0;
}

int deque_array_push_back(DequeArray *deque, void *data) {
    if(!deque || !data) return -1;

    if(deque->size == deque->capacity) {
        if(deque_array_resize(deque) != 0) return -1;
    }

    memcpy((char*)deque->data + deque->back * deque->element_size, data, deque->element_size);
    deque->back = (deque->back + 1) % deque->capacity;
    deque->size++;
    return 0;
}

void *deque_array_pop_front(DequeArray *deque) {
    if(!deque || deque->size == 0) return NULL;

    void *data = (char*)deque->data + deque->front * deque->element_size;
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return data;
}

void *deque_array_pop_back(DequeArray *deque) {
    if(!deque || deque->size == 0) return NULL;

    deque->back = (deque->back - 1 + deque->capacity) % deque->capacity;
    void *data = (char*)deque->data + deque->back * deque->element_size;
    deque->size--;
    return data;
}

void *deque_array_peek_front(DequeArray *deque) {
    if(!deque || deque->size == 0) return NULL;
    return (char*)deque->data + deque->front * deque->element_size;
}

void *deque_array_peek_back(DequeArray *deque) {
    if(!deque || deque->size == 0) return NULL;
    size_t back = (deque->back - 1 + deque->capacity) % deque->capacity;
    return (char*)deque->data + back * deque->element_size;
}

void deque_array_clean(DequeArray *deque) {
    if(!deque) return;

    deque->size = 0;
    deque->front = 0;
    deque->back = 0;
}
