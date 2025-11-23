#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>

#define DEF_CAPACITY 32

typedef struct HashEntry {
    char *key;
    int value;
    struct HashEntry *next;
} HashEntry;

// TODO multiply kind of entries with int keys or string values ecc

typedef struct HashMap {
    HashEntry **buckets;
    size_t size; // number of values - keys
    size_t capacity; // number of buckets
} HashMap;

unsigned long hash(const char *key, size_t capacity);
HashMap* hashmap_create();
void hashmap_put(HashMap **map, const char *key, int value);
int hashmap_get(HashMap **map, const char *key);
void hashmap_remove(HashMap **map, const char *key);
void hashmap_destroy(HashMap **map);
void hashmap_resize(HashMap **map);
void hashmap_put_with_resize(HashMap **map, const char *key, int value);

#endif
