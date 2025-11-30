#define _POSIX_C_SOURCE 200809L

#include "../include/hash_map.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashMap* hashmap_create(size_t key_size, size_t value_size, hash hash_func, compare_func cmp_func) {
    HashMap *map = malloc(sizeof(HashMap));
    if(!map) {
        return NULL;
    }

    map->capacity = DEF_CAPACITY;
    map->size = 0;
    map->key_size = key_size;
    map->value_size = value_size;
    map->hash_func = hash_func;
    map->cmp_func = cmp_func;
    map->buckets = calloc(map->capacity, sizeof(HashEntry*));
    if(!map->buckets) {
        free(map);
        return NULL;
    }
    return map;
}

double load_factor(HashMap *map) {
    return (float)map->size / (float)map->capacity;
}

int hashmap_put(HashMap *map, const void *key, void *value) {
    if(!map || !key || !value) return -1;

    if(load_factor(map) > 0.75) {
        hashmap_resize(map);
    }

    unsigned long index = map->hash_func(key, map->capacity);
    HashEntry *entry = map->buckets[index];

    while(entry) {
        if(map->cmp_func(entry->key, key) == 0) {
            memcpy(entry->value, value, map->value_size);
            return 0;
        }
        entry = entry->next;
    }

    HashEntry *new_entry = malloc(sizeof(HashEntry));
    if(!new_entry) return -1;
    new_entry->key =  malloc(map->key_size);
    if(!new_entry->key) {
        free(new_entry);
        return -1;
    }
    memcpy(new_entry->key, key, map->key_size);
    new_entry->value = malloc(map->value_size);
    if(!new_entry->value) {
        free(new_entry->key);
        free(new_entry);
        return -1;
    }
    memcpy(new_entry->value, value, map->value_size);
    new_entry->next = map->buckets[index];
    map->buckets[index] = new_entry;
    map->size++;
    return 0;
}

void *hashmap_get(HashMap *map, const void *key) {
    if(!map || !key) return NULL;

    unsigned long index = map->hash_func(key, map->capacity);
    HashEntry *entry = map->buckets[index];

    while(entry) {
        if(map->cmp_func(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return NULL;
}

int hashmap_contains(HashMap *map, const void *key) {
    if(!map || !key) return -1;

    unsigned long index = map->hash_func(key, map->capacity);
    HashEntry *entry = map->buckets[index];

    while(entry) {
        if(map->cmp_func(entry->key, key) == 0) {
            return 0;
        }
        entry = entry->next;
    }
    return -1;
} 

int hashmap_remove(HashMap *map, const void *key) {
    if(!map || !key) return -1;

    unsigned long index = map->hash_func(key, map->capacity);    
    HashEntry *entry = map->buckets[index];
    HashEntry *prev = NULL;

    while(entry) {
        if(map->cmp_func(entry->key, key) == 0) {
            if (prev) {
                prev->next = entry->next;
            } else {
                map->buckets[index] = entry->next;
            }
            free(entry->key);
            free(entry->value);
            free(entry);
            map->size--;
            return 0;   
        }
        prev = entry;
        entry = entry->next;
    }
    return -1;
}

int hashmap_destroy(HashMap **map) {
    if(!*map || !map) return -1;

    for(size_t i = 0; i < (*map)->capacity; i++) {
        HashEntry *entry = (*map)->buckets[i];
        while(entry) {
            HashEntry *next = entry->next;
            free(entry->key);
            free(entry->value);
            free(entry);
            entry = next;
        }
    }
    free((*map)->buckets);
    free(*map);
    return 0;
}

int hashmap_resize(HashMap *map) {
    if(!map) return -1;

    size_t old_capacity = map->capacity;
    HashEntry **old_buckets = map->buckets;
    
    map->capacity *= 2;
    map->buckets = calloc(map->capacity, sizeof(HashEntry*));
    if(!map->buckets) {
        map->buckets = old_buckets;
        map->capacity = old_capacity;
        return -1;
    }
    map->size = 0;

    for(size_t i = 0; i < old_capacity; i++) {
        HashEntry *entry = old_buckets[i];
        while(entry) {
            HashEntry *next = entry->next;
            hashmap_put(map, entry->key, entry->value);
            free(entry->key);
            free(entry->value);
            free(entry);
            entry = next;
        }
    }
    free(old_buckets);
    return 0;
}
