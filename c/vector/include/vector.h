#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define DEF_CAP 8
#define GROWTH_FACTOR 2

// return 0 sucess
// return -1 / 1 fail

typedef struct {
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
} Vector;

Vector *vector_create(size_t element_size);
void vector_destroy(Vector **vec);
int vector_push(Vector *vec, void *element);
int vector_pop(Vector *vec);
void *vector_get(Vector *vec, size_t index);
int vector_set(Vector *vec, size_t index, void *element);
size_t vector_size(Vector *vec);
size_t vector_capacity(Vector *vec);
bool vector_is_empty(Vector *vec);
void vector_clear(Vector *vec);
void vector_grow(Vector *vec);
int vector_ensure_capacity(Vector *vec, size_t min_capacity);
void *vector_front(Vector *vec);
void *vector_back(Vector *vec);
int vector_insert(Vector *vec, size_t index, void *element);
int vector_remove(Vector *vec, size_t index, void *element);
void vector_sort(Vector *vec);
void vector_reverse(Vector *vec);

#endif
