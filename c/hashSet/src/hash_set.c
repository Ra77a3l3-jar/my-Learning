#define _POSIX_C_SOURCE 200809L

#include "../include/hash_set.h"

#include <stdio.h>
#include <string.h>

HashSet* hashset_create(size_t element_size) {
    HashSet *set = malloc(sizeof(HashSet));
    if(!set) return NULL;

    set->capacity = DEF_CAPACITY;
    set->size = 0;
    set->key_size = element_size;
    set->buckets = calloc(set->capacity, sizeof(SetEntry*));
    if(!set->buckets) {
        free(set);
        return NULL;
    }
    return set;
}

int hashset_add(HashSet *set, const void *key, hash hashing, compare_func cmp) {
    if(!set || !key) return -1;

    unsigned long index = hashing(key, set->capacity);
    SetEntry *entry = set->buckets[index];

    while(entry) {
        if(cmp(entry->key, key) == 0) {
            return 1;
        }
        entry = entry->next;
    }

    SetEntry *new_entry = malloc(sizeof(SetEntry));
    if(!new_entry) return -1;
    new_entry->key = malloc(set->key_size);
    if(!new_entry->key) {
        free(new_entry);
        return -1;
    }
    memcpy(new_entry->key, key, set->key_size);
    new_entry->next = set->buckets[index];
    set->buckets[index] = new_entry;
    set->size++;
    return 0;
}

int hashset_remove(HashSet *set, const void *key, hash hashing, compare_func cmp) {
    if(!set || !key) return -1;

    unsigned long index = hashing(key, set->capacity);
    SetEntry *entry = set->buckets[index];
    SetEntry *prev = NULL;

    while(entry) {
        if(cmp(entry->key, key) == 0) {
            if(prev) {
                prev->next = entry->next;
            } else {
                set->buckets[index] = entry->next;
            }
            free(entry->key);
            free(entry);
            set->size--;
            return 0;
        }
        prev = entry;
        entry = entry->next;
    }
    return -1;
}

void *hashset_get(HashSet *set, const void *key, hash hashing, compare_func cmp) {
    if(!set || !key) return NULL;

    unsigned long index = hashing(key, set->capacity);
    SetEntry *entry = set->buckets[index];

    while(entry) {
        if(cmp(entry->key, key) == 0) {
            return entry->key;
        }
        entry = entry->next;
    }
    return NULL;
}

int hashset_contains(HashSet *set, const void *key, hash hashing, compare_func cmp) {
    if(!set || !key) return -1;

    unsigned long index = hashing(key, set->capacity);
    SetEntry *entry = set->buckets[index];

    while(entry) {
        if(cmp(entry->key, key) == 0) {
            return 0;
        }
        entry = entry->next;
    }
    return -1;
}

void hashset_destroy(HashSet **set) {
    if(!*set || !set) return;

    for(size_t i = 0; i < (*set)->capacity; i++) {
        SetEntry *entry = (*set)->buckets[i];
        while(entry) {
            SetEntry *next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }

    free((*set)->buckets);
    free(*set);
}
