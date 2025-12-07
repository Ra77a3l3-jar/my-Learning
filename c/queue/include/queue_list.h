#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <stddef.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *back;
    size_t size;
} Queue;

Queue *queue_list_create(void);
int queue_list_push(Queue *queue, void *data);
int queue_list_pop(Queue *queue);
void *queue_list_get(Queue *queue, int index);
void *queue_list_peek(Queue *queue);
size_t queue_list_size(Queue *queue);
int queue_list_empty(Queue *queue);
int queue_list_clear(Queue *queue);
int queue_list_destroy(Queue *queue);

#endif
