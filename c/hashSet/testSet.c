#include "include/hash_set.h"

#include <stdio.h>

int main(void) {
    HashSet *set = hashset_create();

    hashset_add(&set, "TexWiller");
    hashset_add(&set, "Batman");
    hashset_add(&set, "KitCarson");
    hashset_add(&set, "Valve");

    printf("Set size: %zu\n", set->size);

    hashset_contains(set, "TexWiller");
    hashset_contains(set, "Batman");
    hashset_contains(set, "Superman");

    hashset_add(&set, "Batman");
    printf("Set size after duplicate insert: %zu\n", set->size);

    // add many items to test collision handling
    hashset_add(&set, "Gabe");
    hashset_add(&set, "Torvalds");
    hashset_add(&set, "Zagor");
    hashset_add(&set, "Mister_No");
    hashset_add(&set, "Alan_Ford");
    hashset_add(&set, "Diabolik");
    hashset_add(&set, "Dylan_Dog");
    hashset_add(&set, "Martin_Mystere");

    printf("Set size after bulk insert: %zu\n", set->size);
    printf("Set capacity: %zu\n", set->capacity);

    hashset_contains(set, "Torvalds");
    hashset_contains(set, "Spiderman");

    hashset_destroy(&set);

    return 0;
}
