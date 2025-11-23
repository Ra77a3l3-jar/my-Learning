#define _POSIX_C_SOURCE 200809L

#include "../include/hash_map.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long hash(const char *key, size_t capacity) {
    unsigned long hash = 5381;
    int c;

    while((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % capacity;
}

HashMap* hashmap_create() {
    HashMap *map = malloc(sizeof(HashMap));
    if(!map) {
        return NULL;
    }

    map->capacity = DEF_CAPACITY;
    map->size = 0;
    map->buckets = calloc(map->capacity, sizeof(HashEntry*));
    if(!map->buckets) {
        free(map);
        return NULL;
    }
    return map;
}

void hashmap_put(HashMap **map, const char *key, int value) {
    if(!*map || !map || !key) return;

    float load_factor = (float)(*map)->size / (*map)->capacity; // check if resize needed
    if(load_factor > 0.75) {
        hashmap_resize(map);
    }

    unsigned long index = hash(key, (*map)->capacity);
    HashEntry *entry = (*map)->buckets[index];

    while(entry) {
        if(strcmp(entry->key, key) == 0) {
            entry->value = value; // updated value of an existing item
            return;
        }
        entry = entry->next;
    }

    HashEntry *new_entry = malloc(sizeof(HashEntry));
    if(!new_entry) {
        return;
    }
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = (*map)->buckets[index]; // placing the new entry as list head
    (*map)->buckets[index] = new_entry; // updating head for the bucket index
    (*map)->size++;
}

int hashmap_get(HashMap **map, const char *key) {
    if(!*map || !map || !key) return 0;

    unsigned long index = hash(key, (*map)->capacity);
    HashEntry *entry = (*map)->buckets[index];

    while(entry) {
        if(strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return 0;
}

void hashmap_remove(HashMap **map, const char *key) {
    if(!*map || !map || !key) return;

    unsigned long index = hash(key, (*map)->capacity);    
    HashEntry *entry = (*map)->buckets[index];
    HashEntry *prev = NULL;

    while(entry) {
        if(strcmp(entry->key, key) == 0) {
            if (prev) {
                prev->next = entry->next;
            } else {
                (*map)->buckets[index] = entry->next;
            }
            free(entry->key);
            free(entry);
            (*map)->size--;
            return;   
        }
        prev = entry;
        entry = entry->next;
    }
    return;
}

void hashmap_destroy(HashMap **map) {
    if(!*map || !map) return;

    for(size_t i = 0; i < (*map)->capacity; i++) {
        HashEntry *entry = (*map)->buckets[i];
        while(entry) {
            HashEntry *next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free((*map)->buckets);
    free(*map);
}

void hashmap_resize(HashMap **map) {
    if(!*map ||!map) return;

    size_t old_capacity = (*map)->capacity;

    HashEntry **old_buckets = (*map)->buckets;
    (*map)->capacity *= 2;
    (*map)->buckets = calloc((*map)->capacity, sizeof(HashEntry*));
    (*map)->size = 0;

    for(size_t i = 0; i < old_capacity; i++) {
        HashEntry *entry = old_buckets[i];
        while(entry) {
            HashEntry *next = entry->next;
            hashmap_put(map, entry->key, entry->value);
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(old_buckets);
}

void hashmap_put_with_resize(HashMap **map, const char *key, int value) {
    if(!*map || !map || !key) return;

    float load_factor = (float)(*map)->size / (*map)->capacity; // check if resize needed
    if(load_factor > 0.75) {
        hashmap_resize(map);
    }
    hashmap_put(map, key, value);
}
