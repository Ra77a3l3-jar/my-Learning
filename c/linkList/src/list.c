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

void sortNodesDecreasingly(Node **head) {
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
            if ((*current)->data < (*current)->next->data) {
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


void valueNodeSearch(Node **head, int value) {
    Node *current = *head;

    if(*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while(current->next != NULL) {
        if(current->data != value) {
            current = current->next;
        } else {
            printf("We found %d in the list.\n", value);
            break;
        }
    }
    printf("There is no %d in the list.\n", value);
}

Node *mergeNodeList(Node **head1, Node **head2) {
    Node *head = NULL;
    Node *h = NULL;     // moving ptr

    while (*head1 != NULL && *head2 != NULL) {
        if ((*head1)->data <= (*head2)->data) {
            if (h == NULL) {
                // first node
                head = *head1;
                h = *head1;
            } else {
                h->next = *head1;
                h = h->next;
            }
            *head1 = (*head1)->next;
        } else {
            if (h == NULL) {
                // first node
                head = *head2;
                h = *head2;
            } else {
                h->next = *head2;
                h = h->next;
            }
            *head2 = (*head2)->next;
        }
    }

    // adding the rest
    if (*head1 != NULL) {
        if (h == NULL) {
            head = *head1;
        } else {
            h->next = *head1;
        }
    } else if (*head2 != NULL) {
        if (h == NULL) {
            head = *head2;
        } else {
            h->next = *head2;
        }
    }

    return head;
}

void splitNodeList(Node **origin, Node **slice1, Node **slice2) {
    // empty list
    if(*origin == NULL) {
        *slice1 = NULL;
        *slice2 = NULL;
    }
    
    // finding lenght of origin list
    Node *current = *origin;
    int len = 0;
    while(current != NULL) {
        len += 1;
        current = current->next;
    }

    int middle = len / 2;

    // travers till the middle
    Node *prev = NULL;
    current = *origin;
    for(int i = 0; i < middle; i++) {
        prev = current;
        current = current->next;
    }

    *slice1 = *origin;
    *slice2 = current;

    // this truncates the first slice
    if(prev != NULL) {
        prev->next = NULL;
    }

    *origin = NULL;
}

void clearNode(Node **head) {
    if(*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // recursive giving in input the next ptr
    clearNode(&(*head)->next);
    free(*head);
    *head = NULL;
} 

void printNode(Node **head) {
    Node *current = *head;

    while(current->next != NULL) {
        printf(" %d ->", current->data);
        current = current->next;
    }
    current = current->next;
    printf( " %d -> NULL", current->data);
}
