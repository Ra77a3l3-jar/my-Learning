#include "dstring.h"
#include <stdlib.h>
#include <stdio.h>

#define STR_LEN_DEF 20

size_t str_len(const char *text) {
    const char *x = text;
    // Traverses to the last char
    while(*x) {
        x++;
    }
    return (x - text);
}

dstring_t* create_string(const char *init) {
    // Allocate the struct itself
    dstring_t *str = malloc(sizeof(dstring_t));
    if(!str) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    // Calculate initial string length
    size_t length = 0;
    if(init) {
        length = str_len(init);
    }
    
    // Check capacity (at least STR_LEN_DEF or length + 1)
    size_t capacity = STR_LEN_DEF;
    if(length >= capacity) {
        capacity = length * 2 + 1;
    }
    
    // Allocate the data buffer
    str->data = malloc(sizeof(char) * capacity);
    if(!str->data) {
        printf("Memory allocation failed!\n");
        free(str);
        return NULL;
    }
    
    // Copy the initial string
    if(init) {
        size_t i;
        for(i = 0; i < length; i++) {
            str->data[i] = init[i];
        }
        str->data[length] = '\0';
    } else {
        str->data[0] = '\0';
    }
    
    // Set struct fields
    str->length = length;
    str->capacity = capacity;
    
    return str;
}

void destroy_string(dstring_t **str) {
    if(str && *str) {
        if((*str)->data) {
            free((*str)->data);
        }
        free(*str);
        *str = NULL;
    }
}

void string_append(dstring_t **str, const char *text) {
    if(!*str || !text) return;
    
    size_t text_len = str_len(text);
    size_t new_length = (*str)->length + text_len;
    
    // Check if we need to resize
    if(new_length + 1 > (*str)->capacity) {
        size_t new_capacity = (new_length + 1) * 2;
        char *new_data = realloc((*str)->data, new_capacity);
        if(!new_data) {
            printf("Memory allocation failed!\n");
            return;
        }
        (*str)->data = new_data;
        (*str)->capacity = new_capacity;
    }
    
    // Copy text to end
    size_t i;
    for(i = 0; i < text_len; i++) {
        (*str)->data[(*str)->length + i] = text[i];
    }
    (*str)->data[new_length] = '\0';
    (*str)->length = new_length;
}

void string_prepend(dstring_t **str, const char *text) {
    if(!*str || !text) return;
    
    size_t text_len = str_len(text);
    size_t new_length = (*str)->length + text_len;
    
    // Check if we need to resize
    if(new_length + 1 > (*str)->capacity) {
        size_t new_capacity = (new_length + 1) * 2;
        char *new_data = realloc((*str)->data, new_capacity);
        if(!new_data) {
            printf("Memory allocation failed!\n");
            return;
        }
        (*str)->data = new_data;
        (*str)->capacity = new_capacity;
    }
    
    // Shift existing string to the right
    // Shifts starting from the last char of the original string
    size_t i;
    for(i = (*str)->length; i > 0; i--) {
        (*str)->data[i + text_len - 1] = (*str)->data[i - 1];
    }
    
    // Copy text to beginning
    for(i = 0; i < text_len; i++) {
        (*str)->data[i] = text[i];
    }
    (*str)->data[new_length] = '\0';
    (*str)->length = new_length;
}

// This function it returns a substring give the start index and the lenght of the substring
dstring_t* substring(dstring_t **src, size_t start, size_t len) {
    if(!*src || start >= (*src)->length) {
        return create_string("");
    }
    
    // Adjust length if it goes beyond string end
    if(start + len > (*src)->length) {
        len = (*src)->length - start;
    }
    
    // Create temporary buffer for substring
    char *temp = malloc(len + 1);
    if(!temp) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    size_t i;
    for(i = 0; i < len; i++) {
        temp[i] = (*src)->data[start + i];
    }
    temp[len] = '\0';
    
    dstring_t *result = create_string(temp);
    free(temp);
    
    return result;
}

int find_string(dstring_t **src, const char *text) {
    // Check for border case
    if(!*src || !text) return -1;

    size_t text_len = str_len(text);
    if(text_len == 0 || text_len > (*src)->length) return -1;
    
    size_t i = 0, j = 0;
    for(i = 0; i <= (*src)->length - text_len; i++) {
        int match = 1;
        for(j = 0; j < text_len; j++) {
            if((*src)->data[i + j] != text[j]) {
                match = 0;
                break;
            }
        }
        if(match) {
            return i;
        }
    }
    
    return -1;
}

int string_cmp(dstring_t **src, const char *text) {
    if(!*src || !text) return -2;
    
    size_t i;
    for(i = 0; i < (*src)->length && text[i] != '\0'; i++) {
        if((*src)->data[i] < text[i]) return -1;
        if((*src)->data[i] > text[i]) return 1;
    }
    
    if(i < (*src)->length) return 1;   // src is longer
    if(text[i] != '\0') return -1;  // text is longer
    return 0;                        // equal
}

void print_string(dstring_t **str) {
    if(*str && (*str)->data) {
        printf("%s\n", (*str)->data);
    }
}
