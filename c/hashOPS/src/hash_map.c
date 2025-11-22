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

HashMap* hashmap_create(size_t capacity) {
    HashMap *map = malloc(sizeof(HashMap));
    if(!map) {
        return NULL;
    }

    if(capacity <= 0) {
        map->capacity = DEF_CAPACITY;
    } else {
        map->capacity = capacity;
    }
    map->size = 0;
    map->buckets = calloc(capacity, sizeof(HashEntry));
    if(!map->buckets) {
        free(map);
        return NULL;
    }
    return map;
}

void hashmap_put(HashMap **map, char *key, int value) {
    if(!*map || !map) {
        return;
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

int hashmap_get(HashMap **map, const char *key, int value) {
    if(!*map || !map) return 0;

    unsigned long index = hash(key, (*map)->capacity);
    HashEntry *entry = (*map)->buckets[index];

    while(entry) {
        if(strcmp(entry->key, key) == 0) { // compares the keys if 0 they are equal
            return entry->value;
        }
        entry = entry->next;
    }
     return 0;
}

void hashmap_remove(HashMap **map, const char *key) {
    if(!*map || !map) return;

    unsigned long index = hash(key, (*map)->capacity);    
    HashEntry *entry = (*map)->buckets[index];

    while(entry) {
        if(strcmp(entry->key, key) == 0) {
            
        }
    }
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
    
}

void hashmap_put_with_resize(HashMap **map, const char *key, int value) {
    
}
