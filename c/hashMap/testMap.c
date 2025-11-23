#include "include/hash_map.h"

#include <stdio.h>

int main(void) {
    HashMap *map = hashmap_create();

    hashmap_put(&map, "TexWiller", 10);
    hashmap_put(&map, "Batman", 20);
    hashmap_put(&map, "KitCarson", 30);
    hashmap_put(&map, "Valve", 40);

    int val1 = hashmap_get(&map, "TexWiller");
    printf("Value for 'TexWiller': %d\n", val1);

    int val2 = hashmap_get(&map, "Batman");
    printf("Value for 'Batman': %d\n", val2);

    int val3 = hashmap_get(&map, "KitCarson");
    printf("Value for 'KitCarson': %d\n", val3);

    hashmap_put(&map, "TexWiller", 100);
    int val4 = hashmap_get(&map, "TexWiller");
    printf("Updated value for 'TexWiller': %d\n", val4);

    hashmap_remove(&map, "Batman");
    int val5 = hashmap_get(&map, "Batman");
    printf("Value for 'Batman' after removal: %d\n", val5);

    printf("Map size: %zu\n", map->size);
    printf("Map capacity: %zu\n", map->capacity);

    // test with many items to trigger resize
    hashmap_put(&map, "Gabe", 50);
    hashmap_put(&map, "Torvalds", 60);
    hashmap_put(&map, "Zagor", 70);
    hashmap_put(&map, "Mister_No", 80);
    hashmap_put(&map, "Alan_Ford", 90);
    hashmap_put(&map, "Diabolik", 110);
    hashmap_put(&map, "Dylan_Dog", 120);
    hashmap_put(&map, "Martin_Mystere", 130);

    for(int i = 0; i < 40; i++) {
        char key[20];
        sprintf(key, "hero%d", i);
        hashmap_put(&map, key, i * 10);
    }

    printf("Map size after bulk insert: %zu\n", map->size);
    printf("Map capacity after resize: %zu\n", map->capacity);

    hashmap_destroy(&map);

    return 0;
}
