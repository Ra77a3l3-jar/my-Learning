#include "dstring.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define STR_LEN_DEF 20

size_t str_len(const char *text) {
    if(!text) return 0;
    const char *x = text;
    while(*x) x++;
    return (size_t)(x - text);
}

dstring_t* create_string(const char *init) {
    dstring_t *str = malloc(sizeof *str);
    if(!str) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    size_t length = init ? str_len(init) : 0;
    size_t needed = length + 1; // include null terminator

    size_t capacity = STR_LEN_DEF;
    if(capacity < needed) {
        // grow until it fits, guarding against overflow
        while(capacity < needed) {
            if (capacity > SIZE_MAX / 2) { capacity = needed; break; }
            capacity *= 2;
        }
    }

    str->data = malloc(capacity * sizeof *str->data);
    if(!str->data) {
        printf("Memory allocation failed!\n");
        free(str);
        return NULL;
    }

    if(init && length > 0) {
        memcpy(str->data, init, length);
    }
    str->data[length] = '\0';
    str->length = length;
    str->capacity = capacity;
    return str;
}

void destroy_string(dstring_t **str) {
    if(!str || !*str) return;
    free((*str)->data);
    free(*str);
    *str = NULL;
}

void string_append(dstring_t **str, const char *text) {
    if(!str || !*str || !text) return;
    size_t tlen = str_len(text);
    if(tlen == 0) return;

    size_t new_length = (*str)->length + tlen;
    size_t needed = new_length + 1;
    if(needed > (*str)->capacity) {
        // capacity grows until it fits with overflow guard
        size_t new_capacity = (*str)->capacity ? (*str)->capacity : STR_LEN_DEF;
        while(new_capacity < needed) {
            if(new_capacity > SIZE_MAX / 2) { new_capacity = needed; break; }
            new_capacity *= 2;
        }
        char *new_data = realloc((*str)->data, new_capacity * sizeof *new_data);
        if(!new_data) {
            printf("Memory allocation failed!\n");
            return;
        }
        (*str)->data = new_data;
        (*str)->capacity = new_capacity;
    }

    // Starts coping text bytes from the index lenght forward so it does not corrupt the source string
    memcpy((*str)->data + (*str)->length, text, tlen);
    (*str)->length = new_length;
    (*str)->data[new_length] = '\0';
}

void string_prepend(dstring_t **str, const char *text) {
    if(!str || !*str || !text) return;
    size_t tlen = str_len(text);
    if (tlen == 0) return;

    size_t new_length = (*str)->length + tlen;
    size_t needed = new_length + 1;
    if(needed > (*str)->capacity) {
        size_t new_capacity = (*str)->capacity ? (*str)->capacity : STR_LEN_DEF;
        while(new_capacity < needed) {
            if(new_capacity > SIZE_MAX / 2) { new_capacity = needed; break; }
            new_capacity *= 2;
        }
        char *new_data = realloc((*str)->data, new_capacity * sizeof *new_data);
        if(!new_data) {
            printf("Memory allocation failed!\n");
            return;
        }
        (*str)->data = new_data;
        (*str)->capacity = new_capacity;
    }

    // move existing data to make space for prefix: use memmove for overlap
    memmove((*str)->data + tlen, (*str)->data, (*str)->length);
    memcpy((*str)->data, text, tlen);
    (*str)->length = new_length;
    (*str)->data[new_length] = '\0';
}

dstring_t* substring(dstring_t *src, size_t start, size_t len) {
    if(!src) return NULL;
    if(start >= src->length) return create_string("");
        
    // adjust length if it goes beyond string end
    if(start + len > src->length) {
        len = src->length - start;
    }
    
    dstring_t *temp = create_string(NULL);
    if(!temp) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // ensure capacity for substring
    if(temp->capacity < len + 1) {
        size_t new_capacity = temp->capacity ? temp->capacity : STR_LEN_DEF;
        while(new_capacity < len + 1) {
            if(new_capacity > SIZE_MAX / 2) { new_capacity = len + 1; break; }
            new_capacity *= 2;
        }

        // allocating new size for the substring
        char *new_temp_data = realloc(temp->data, new_capacity * sizeof *new_temp_data);
        if(!new_temp_data) {
            destroy_string(&temp);
            return NULL;
        }
        temp->data = new_temp_data;
        temp->capacity = new_capacity;
    }

    // coping the substring from data + start index
    memcpy(temp->data, src->data + start, len);
    temp->data[len] = '\0';
    temp->length = len;
    return temp;
}

int find_string(dstring_t *src, const char *text) {
    // Check for border case
    if(!src || !text) return -1;

    size_t text_len = str_len(text);
    if(text_len == 0) return 0; // empty string
    if(text_len > src->length) return -1; // text too long

    size_t max_ind = src->length - text_len;
    for(size_t i = 0; i <= max_ind; i++) {
        if(memcmp(src->data + i, text, text_len) == 0) return (int)i;
    }
    return -1;
}

int string_cmp(dstring_t *src, const char *text) {
    if(!src || !text) return -2;
    
    size_t i = 0;
    while(i < src->length && text[i] != '\0') {
        if(src->data[i] != text[i]) {
            // returns only if the chars are diffrent not if they are not same lenght
            return (src->data[i] < text[i]) ? -1 : 1;
        }
        i++;
    }

    // if the dstring is longer return 1
    if(i < src->length) return 1;
    // if the dstring is shorter return -1
    if(text[i] != '\0') return -1;
    return 0;
}

void print_string(dstring_t *str) {
    if(!str || !str->data) return;
    printf("%s\n", str->data);
}
