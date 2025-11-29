#include "./include/vector.h"

#include <stddef.h>
#include <stdio.h>

int compare_ints(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    Vector *vec = vector_create(sizeof(int));

    for(size_t i = 0; i < 10; i++) {
        vector_push(vec, &i);
    }

    printf("The vector has: \n");
    for(size_t i = 0; i < vector_size(vec); i++) {
        printf("pos: %zu = %d\n", i, *(int*)(vector_get(vec, i)));
    }

    if(vector_pop(vec) == 0) {
        printf("We popped the last item to be added.\n");
    }

    printf("The vector has: \n");
    for(size_t i = 0; i < vector_size(vec); i++) {
        printf("pos: %zu = %d\n", i, *(int*)(vector_get(vec, i)));
    }

    printf("Is the vector empty: %s\n", vector_is_empty(vec) ? "True" : "False");

    vector_clear(vec);
    printf("The vector after cleaning has: \n");
    for(size_t i = 0; i < vector_size(vec); i++) {
        printf("pos: %zu = %d\n", i, *(int*)(vector_get(vec, i)));
    }
    printf("Is the vector empty: %s\n", vector_is_empty(vec) ? "True" : "False");

    for(size_t i = 0; i < 10; i++) {
        vector_push(vec, &i);
    }

    int element1 = 10;
    vector_insert(vec, 3, &element1);

    vector_remove(vec, 4, &element1);
    printf("The vector now looks like this: \n");
    for(size_t i = 0; i < vector_size(vec); i++) {
        printf("pos: %zu = %d\n", i, *(int*)(vector_get(vec, i)));
    }

    vector_sort(vec, compare_ints);
    printf("The sorted vector: \n");
    for(size_t i = 0; i < vector_size(vec); i++) {
        printf("pos: %zu = %d\n", i, *(int*)(vector_get(vec, i)));
    }

    vector_reverse(vec);
    printf("The reversed vector: \n");
    for(size_t i = 0; i < vector_size(vec); i++) {
        printf("pos %zu = %d\n", i , *(int*)(vector_get(vec, i)));
    }

    printf("The vector capacity is %zu\n", vector_capacity(vec));
    vector_grow(vec);
    printf("The vector capacity is %zu\n", vector_capacity(vec));

    printf("The vector front is %d\n", *(int*)(vector_front(vec)));
    printf("The vector back is %d\n", *(int*)(vector_back(vec)));
}
