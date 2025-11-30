#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>

#define DEF_CAPACITY 32

// return 0 sucess
// return -1 / 1 fail

typedef struct HashEntry {
    void *key;
    void *value;
    struct HashEntry *next;
} HashEntry;

typedef int (*compare_func)(const void *a, const void *b);
typedef unsigned long (*hash)(const void *key, size_t capacity);

typedef struct HashMap {
    HashEntry **buckets;
    size_t size; // number of values - keys
    size_t capacity; // number of buckets
    size_t key_size;
    size_t value_size;
    hash hash_func;
    compare_func cmp_func;
} HashMap;

HashMap* hashmap_create(size_t key_size, size_t value_size, hash hash_func, compare_func cmp_func);
int hashmap_put(HashMap *map, const void *key, void *value);
void *hashmap_get(HashMap *map, const void *key);
int hashmap_remove(HashMap *map, const void *key);
int hashmap_contains(HashMap *map, const void *key);
int hashmap_destroy(HashMap **map);
int hashmap_resize(HashMap *map);
double load_factor(HashMap *map);

#endif
