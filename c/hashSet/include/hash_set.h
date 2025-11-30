#ifndef HASH_SET_H
#define HASH_SET_H

#include <stdlib.h>

#define DEF_CAPACITY 32

// return 0 sucess
// return 1 / -1 fail

typedef struct SetEntry {
    void *key;
    struct SetEntry *next;
} SetEntry;

typedef struct HashSet {
    SetEntry **buckets;
    size_t size;
    size_t capacity;
    size_t key_size;
} HashSet;

typedef int (*compare_func)(const void *a, const void *b);
typedef unsigned long (*hash)(const void *key, size_t capacity);

HashSet* hashset_create(size_t element_size);
int hashset_add(HashSet *set, const void *key, hash hashing, compare_func cmp);
int hashset_remove(HashSet *set, const void *key, hash hashing, compare_func cmp);
void *hashset_get(HashSet *set, const void *key, hash hashing, compare_func cmp);
int hashset_contains(HashSet *set, const void *key, hash hashing, compare_func cmp);
void hashset_destroy(HashSet **set);

#endif
