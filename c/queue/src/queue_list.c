#include "../include/queue_list.h"

#include <stdlib.h>
#include <stddef.h>

Queue *queue_list_create(void) {
    Queue *new_queue = malloc(sizeof(Queue));
    if(!new_queue) return NULL;

    new_queue->back = NULL;
    new_queue->front = NULL;
    new_queue->size = 0;
    return new_queue;
}

int queue_list_push(Queue *queue, void *data) {
    if(!queue || !data) return -1;

    // no nodes case
    if(!queue->front) {
        Node *new_node = malloc(sizeof(Node));
        if(!new_node) return -1;
        new_node->data = data;
        new_node->next = NULL;
        queue->front = new_node;
        queue->back = new_node;
        queue->size++;
        return 0;
    }

    Node *new_node = malloc(sizeof(Node));
    if(!new_node) return -1;
    new_node->data = data;
    new_node->next = NULL;
    queue->back->next = new_node;
    queue->back = new_node;
    queue->size++;
    return 0;
}

int queue_list_pop(Queue *queue) {
    if(!queue || !queue->front) return -1;

    Node *temp = queue->front;
    queue->front = queue->front->next;
    if(!queue->front) {
        queue->back = NULL;
    }
    free(temp);
    queue->size--;
    return 0;
}

void *queue_list_get(Queue *queue, int index) {
    if(!queue || !queue->front || index >= (int)queue->size) return NULL;

    if(index == 0) {
        return queue->front->data;
    }

    if(index == (int)queue->size-1) {
        return queue->back->data;
    }

    Node *current = queue->front;
    int i = 0;
    while(current && i < index) {
        current = current->next;
        i++;
    }
    return current->data;
}

void *queue_list_peek(Queue *queue) {
    if(!queue || !queue->front) return NULL;
    return queue->front->data;
}

size_t queue_list_size(Queue *queue) {
    if(!queue) return 0;
    return queue->size;
}

int queue_list_empty(Queue *queue) {
    if(!queue) return 1;
    return queue->size ? 0 : 1;
}

int queue_list_clear(Queue *queue) {
    if(!queue) return -1;

    Node *current = queue->front;
    while(current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;
    return 0;
}

int queue_list_destroy(Queue *queue) {
    if(!queue) return -1;
    queue_list_clear(queue);
    free(queue);
    return 0;
}
