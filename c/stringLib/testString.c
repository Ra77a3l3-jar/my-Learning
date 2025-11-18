#include "dstring.h"

#include <stdio.h>

int main(void) {

    dstring_t *str = create_string("Hello, World!");

    string_append(&str, " by Raffaele");
    print_string(&str);

    dstring_t *str1 = create_string("combo col Gigante.");
    string_prepend(&str1, "Solo ");

    dstring_t *sub = substring(&str1, 11, 3);
    print_string(&sub);
    
    int i = find_string(&str1, "Gigante");
    if(i != -1) {
        printf("The string is present (index %d).\n", i);
    } else {
        printf("The string is not present.\n");
    }

    dstring_t *str2 = create_string("Batman");
    int x = string_cmp(&str2, "Batman");
    if(x == 0) {
        printf("The strings are equal.\n");
    } else if(x == -1) {
        printf("The text is longer.\n");
    } else if(x == 1) {
        printf("The source is longer.\n");
    } else if(x == -2) {
        printf("One or both strings are NULL.\n");
    }

    int y = string_cmp(&str2, "batman");
    if(y == 0) {
        printf("The strings are equal.\n");
    } else if(y == -1) {
        printf("The text is longer.\n");
    } else if(y == 1) {
        printf("The source is longer.\n");
    } else if(y == -2) {
        printf("One or both strings are NULL.\n");
    }

    print_string(&str1);

    size_t leng = str_len("Hello, World!");
    printf("The length of the string is %zu.\n", leng);

    // free allocated strings
    destroy_string(&str);
    destroy_string(&str1);
    destroy_string(&sub);
    destroy_string(&str2);

    return 0;
}
