#ifndef HASH_SET_H
#define HASH_SET_H

#include <stdlib.h>
#include "hash_map.h"

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
void hashset_add(HashSet **set, const char *key);
void hashset_contains(HashSet *set, const char *key);
void hashset_destroy(HashSet **set);

#endif
