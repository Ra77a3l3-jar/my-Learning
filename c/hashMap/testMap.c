#include "include/hash_map.h"

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
    HashMap *map = hashmap_create(sizeof(int), sizeof(int), hash_int, compare_int);

    for(size_t i = 0; i < 10; i++) {
        hashmap_put(map, &i, &i);
    }

    for(size_t i = 0; i < 10; i++) {
        printf("Key %zu : %d\n", i, *(int*)(hashmap_get(map, &i)));
    }

    int x = 2;
    if(hashmap_contains(map, &x) == 0) {
        printf("The key %d is contained in the map\n", x);
    } else {
        printf("The key %d is not present in the map\n", x);
    }

    int c = 12;
    if(hashmap_contains(map, &c) == 0) {
        printf("The key %d is contained in the map\n", c);
    } else {
        printf("The key %d is not present in the map\n", c);
    }

    if(hashmap_remove(map, &x) == 0) {
        printf("The key %d is removed from the map\n", x);
    } else {
        printf("The key %d is not present in the map\n", x);
    }

    if(hashmap_contains(map, &x) == 0) {
        printf("The key %d is contained in the map\n", x);
    } else {
        printf("The key %d is not present in the map\n", x);
    }
    
    return 0;
}
