#ifndef DSTRING_H
#define DSTRING_H

#include <stddef.h>

#define STR_MAX_LEN = 255

typedef struct {
   char *data;
   size_t length;
   size_t capacity;
} dstring_t;

// Create a new dynamic string. Returns a newly allocated dstring_t or NULL on allocation failure.
dstring_t* create_string(const char *init);

// Destroy a dynamic string and set the caller pointer to NULL. Safe to call.
void destroy_string(dstring_t **str);

// Append/Prepend text to the string.
void string_append(dstring_t **str, const char *text);
void string_prepend(dstring_t **str, const char *text);

// Return a newly allocated dstring_t containing the substring of the source string from index start + len.
dstring_t* substring(dstring_t *src, size_t start, size_t len);

// Checks if a string is present in the source string. 
int find_string(dstring_t *src, const char *text);

// Compares two string and returns 0 if they are equal.
int string_cmp(dstring_t *src, const char *text);

// Prints the string .
void print_string(dstring_t *str);

// Returns the lenght of a string. Returns 0 if NULL.
size_t str_len(const char *text);

#endif
