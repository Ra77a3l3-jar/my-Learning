#include "dstring.h"

int main(void) {

    dstring_t *str = create_string("Hello, World!");

    string_append(str, " by Raffaele");
    print_string(str);

    dstring_t *str1 = create_string("combo col Gigante.");
    string_prepend(str1, "Solo ");

    dstring_t *sub = substring(str1, 2, 3);
    print_string(sub);
    
    find_string(str1, "Gigante");

    dstring_t *str2 = create_string("Batman");
    string_cmp(str2, "Batman");
    string_cmp(str2, "batman");

    print_string(str1);

    str_len("Hello, World!");
}
