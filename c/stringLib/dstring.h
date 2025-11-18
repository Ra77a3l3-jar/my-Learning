#ifndef DSTRING_H
#define DSTRING_H
#include <stddef.h>

typedef struct {
   char *data;
   size_t length;
   size_t capacity; 
} dstring_t;

dstring_t* create_string(const char *init);
void destroy_string(dstring_t **str);
void string_append(dstring_t **str, const char *text);
void string_prepend(dstring_t **str, const char *text);
dstring_t* substring(dstring_t **src, size_t start, size_t len);
int find_string(dstring_t **src, const char *text);
int string_cmp(dstring_t **src, const char *text);
void print_string(dstring_t **str);
size_t str_len(const char *text);

#endif
