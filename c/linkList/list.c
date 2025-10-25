#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node* initNode(int data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void addNode(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        printf("Memory allocation failed!\n");
        free(new_node);
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    
    if(*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;    
}

void addNodeAtPosition(Node **head, int data, int position) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        printf("Memory allocation failed!\n");
        free(new_node);
        return;
    }
    new_node->data  = data;

    if(*head == NULL) {
        *head = new_node;
        new_node->next = NULL;
        return;
    }

    // If the list has atleas one node
    Node *current = *head;
    int posCount = 0;
    while(posCount == position-1 || current->next != NULL) {
        current = current->next;
        posCount += 1;
    }
}
