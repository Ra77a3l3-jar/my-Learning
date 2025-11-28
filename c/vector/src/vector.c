#include "../include/vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

Vector *vector_create(size_t element_size){
    if(element_size == 0) return NULL;
    
    Vector *new_vec = malloc(sizeof(Vector));
    if(!new_vec) return NULL;

    new_vec->capacity = DEF_CAP;
    new_vec->size = 0;
    new_vec->element_size = element_size;
    new_vec->data = malloc(new_vec->capacity * element_size);
    if(!new_vec->data) {
        free(new_vec);
        return NULL;
    }
    return new_vec;
}

void vector_destroy(Vector **vec) {
    if(!vec) return;
    free((*vec)->data);
    free(*vec);
}

void vector_clear(Vector *vec) {
    if(!vec) return;
    vec->size = 0;
}

size_t vector_size(Vector *vec) {
    if(!vec) return 0;
    return vec ? vec->size : 0;
}

size_t vector_capacity(Vector *vec) {
    if(!vec) return 0;
    return vec ? vec->capacity : 0;
}

bool vector_is_empty(Vector *vec) {
    if(!vec) return false;
    if(vec->size > 0) {
        return true;
    } else {
        return false;
    }
}

void *vector_front(Vector *vec) {
    if(!vec) return NULL;
    return vector_get(vec, 0);
}

void *vector_back(Vector *vec) {
    if(!vec) return NULL;
    return vector_get(vec, vec->size - 1);
}

void *vector_get(Vector *vec, size_t index) {
    if(!vec || index >= vec->size) return NULL;
    return (char *)vec->data + (index + vec->element_size);
}

int vector_set(Vector *vec, size_t index, void *element) {
    if(!vec || index >= vec->size || !element) return -1;
    void *place = (char *)vec->data + (index + vec->element_size);
    memcpy(place, element, vec->element_size);
    return 0;
}

void vector_grow(Vector *vec) {
    if(!vec) return;
    vec->capacity *= GROWTH_FACTOR;
    if(vec->capacity > 0) {
        Vector *new_vector = realloc(vec, sizeof(vec->element_size) * vec->capacity);
        if(!new_vector) return;
        vec = new_vector;
    }
}

int vector_ensure_capacity(Vector *vec, size_t min_capacity) {
    if(!vec) return -1;

    if(vec->capacity < min_capacity) {
        vec->capacity = min_capacity;
    }
    return 0;
}

int vector_push(Vector *vec, void *element) {
    if(!vec || !element) return -1;
    void *place = (char *)vec->data + (vec->size * vec->element_size);
    memcpy(place, element, vec->element_size);
    return 0;
}

int vector_pop(Vector *vec) {
    if(!vec) return -1;
    vec->size -= 1;
    return 0;
}

int vector_insert(Vector *vec, size_t index, void *element) {
    if(!vec || index >= vec->capacity || !element) return -1;
    void *place = (char *)vec->data + (index * vec->element_size); 
    memcpy(place, element, vec->element_size);
    return 0;
}

int vector_remove(Vector *vec, size_t index, void *element) {
    
}

