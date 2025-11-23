#ifndef HASH_SET_H
#define HASH_SET_H

#include <stdlib.h>

#define DEF_CAPACITY 32

typedef struct SetEntry {
    char *key;
    struct SetEntry *next;
} SetEntry;

typedef struct HashSet {
    SetEntry **buckets;
    size_t size;
    size_t capacity;
} HashSet;

HashSet* hashset_create();
unsigned long hash(const char *key, size_t capacity);
void hashset_add(HashSet **set, const char *key);
void hashset_contains(HashSet *set, const char *key);
void hashset_destroy(HashSet **set);

#endif
