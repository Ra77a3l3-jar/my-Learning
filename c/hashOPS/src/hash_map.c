#include "../include/hash_map.h"

#include <stdio.h>
#include <stdlib.h>

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

    map->capacity = capacity;
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

    (*map)->buckets[index]->key = key; 
    (*map)->buckets[index]->value = value;
    (*map)->buckets[index]->next = NULL;
}


