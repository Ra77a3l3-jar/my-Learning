#include "../include/dequeList.h"

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

DequeList *deque_list_create(void) {
    DequeList *new_deque = malloc(sizeof(DequeList));
    if(!new_deque) return NULL;

    new_deque->back = NULL;
    new_deque->front = NULL;
    new_deque->size = 0;
    return new_deque;
}

void deque_list_destroy(DequeList *deque) {
    if(!deque) return;

    deque_list_clear(deque);
    free(deque);
}

int deque_list_empty(const DequeList *deque) {
    if(!deque) return -1;
    if(deque->size == 0) return 0;
    return -1;
}

size_t deque_list_size(const DequeList *deque) {
    return deque ? deque->size : 0;
}

int deque_list_push_front(DequeList *deque, void *data) {
    if(!deque || !data) return -1;

    // new node
    DequeNode *new_node = malloc(sizeof(DequeNode));
    if(!new_node) return -1;

    new_node->data = data;
    new_node->next = deque->front;
    new_node->prev = NULL;

    deque->front = new_node;
    deque->size++;
    return 0;
}

int deque_list_push_back(DequeList *deque, void *data) {
    if(!deque || !data) return -1;

    DequeNode *new_node = malloc(sizeof(DequeNode));
    if(!new_node) return -1;

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = deque->back;

    deque->back = new_node;
    deque->size++;
    return 0;
}

void *deque_list_pop_front(DequeList *deque) {
    if(!deque) return NULL;

    DequeNode *curr = deque->front;
    DequeNode *next = deque->front->next;
    deque->front = next;
    deque->size--;
    return curr->data;
}

void *deque_list_pop_back(DequeList *deque) {
    if(!deque) return NULL;

    DequeNode *curr = deque->back;
    DequeNode *prev = deque->back->prev;
    deque->back = prev;
    deque->size--;
    return curr->data;
}

void *deque_list_peek_front(const DequeList *deque) {
    if(!deque) return NULL;
    return deque->front->data;
}

void *deque_list_peek_back(const DequeList *deque) {
    if(!deque) return NULL;
    return deque->back->data;
}


void deque_list_clear(DequeList *deque) {
    if(!deque) return;
    
    DequeNode *current = deque->front;
    while(current) {
        DequeNode *next = current->next;
        free(current);
        current = next;
    }
    deque->front = NULL;
    deque->back = NULL;
    deque->size = 0;
}
