#include "include/hash_set.h"

#include <stdio.h>
#include <string.h>

unsigned long hash_int(const void *key, size_t capacity) {
    unsigned int value = *(const int *)key;
    value = ((value >> 16) ^ value) * 0x45d9f3b;
    value = ((value >> 16) ^ value) * 0x45d9f3b;
    value = (value >> 16) ^ value;
    return (unsigned long)value % capacity;
}

int compare_int(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    return val_a - val_b;
}

unsigned long hash_string(const void *key, size_t capacity) {
    const char *str = *(const char **)key;
    unsigned long hash = 5381;
    int c;
    
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash % capacity;
}

int compare_string(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    return strcmp(str_a, str_b);
}

int main(void) {
    HashSet *set = hashset_create(sizeof(int));

    for(size_t i = 0; i < 10; i++) {
        hashset_add(set, &i, hash_int, compare_int);
    }

    for(size_t i = 0; i < set->size; i++) {
        printf("pos %zu = %d\n", i, *(int*)(hashset_get(set, &i, hash_int, compare_int)));
    }

    int x = 2;
    if(hashset_contains(set, &x, hash_int, compare_int) == 0) {
        printf("The number %d is contained in the set\n", x);
    } else {
        printf("The number %d is not present in the set\n", x);
    }

    int c = 12;
    if(hashset_contains(set, &c, hash_int, compare_int) == 0) {
        printf("The number %d is contained in the set\n", c);
    } else {
        printf("The number %d is not present in the set\n", c);
    }

    if(hashset_remove(set, &x, hash_int, compare_int) == 0) {
        printf("The number %d is remove from the set\n", x);
    } else {
        printf("The number %d is not present in the set\n", x);
    }

    if(hashset_contains(set, &x, hash_int, compare_int) == 0) {
        printf("The number %d is contained in the set\n", x);
    } else {
        printf("The number %d is not present in the set\n", x);
    }
    
    return 0;
}
