#define _POSIX_C_SOURCE 200809L

#include "../include/hash_set.h"

#include <stdio.h>
#include <stdio.h>
#include <string.h>

HashSet* hashset_create() {
    HashSet *set = malloc(sizeof(HashSet));
    if(!set) {
        return NULL;
    }

    set->capacity = DEF_CAPACITY;
    set->size = 0;
    set->buckets = calloc(set->capacity, sizeof(SetEntry*));
    if(!set->buckets) {
        free(set);
        return NULL;
    }
    return set;
}

void hashset_add(HashSet **set, const char *key) {
    if(!*set || !set || !key) return;

    unsigned long index = hash(key, (*set)->capacity);
    SetEntry *entry = (*set)->buckets[index];

    while(entry) {
        if(strcmp(entry->key, key) == 0) {
            return;
        }
        entry = entry->next;
    }

    SetEntry *new_entry = malloc(sizeof(SetEntry));
    if(!new_entry) return;
    new_entry->key = strdup(key);
    new_entry->next = (*set)->buckets[index];
    (*set)->buckets[index] = new_entry;
    (*set)->size++;
}

void hashset_contains(HashSet *set, const char *key) {
    if(!set || !key) return;

    unsigned long index = hash(key, set->capacity);
    SetEntry *entry = set->buckets[index];

    while(entry) {
        if(strcmp(entry->key, key) == 0) {
            printf("The value is present.\n");
            return;
        }
        entry = entry->next;
    }
    printf("The value is not present.\n");
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
