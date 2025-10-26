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
    new_node->next = current->next;
    current->next = new_node;
}

void addNodeAtHead(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        printf("Memory allocation failed!\n");
        free(new_node);
        return;
    }

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void addNodeSorted(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        printf("Memory allocation failed!\n");
        free(new_node);
        return;
    }

    new_node->data = data;

    // Now has to check and sort the list and place the node in the right spot
    sortNodesIncreasingly(head);
    Node *current = *head;
    while(current->next != NULL || (current->data < data && current->next->data > data)) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void removeNodeAtPosition(Node **head, int position) {
    // Remove head
    if(position == 0) {
        *head = (*head)->next;
        return;
    }

    int posCount = 0;
    Node *current = *head;
    while(posCount == position - 1 || current->next != NULL) {
        current = current->next;
        posCount += 1;
    }
    current->next = current->next->next;
}

void removeNodeHead(Node **head) {
    *head = (*head)->next;
}

void removeNodeAtEnd(Node **head) {
    Node *current = *head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void removeNodeValue(Node **head, int value) {
    Node *current = *head;
    while(current->next != NULL || current->data != value) {
        current = current->next;
    }
    current->next = current->next->next;
}

void sortNodesIncreasingly(Node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // Empty list or single node, already sorted
    }
    
    int swapped;
    Node **current;
    Node *temp;
    
    do {
        swapped = 0;
        current = head;
        
        while (*current != NULL && (*current)->next != NULL) {
            if ((*current)->data > (*current)->next->data) {
                // Swap the nodes
                temp = (*current)->next;
                (*current)->next = temp->next;
                temp->next = *current;
                *current = temp;
                
                swapped = 1;
            }
            current = &((*current)->next);
        }
    } while (swapped);
}
