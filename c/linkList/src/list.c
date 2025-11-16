#include "list.h"

#include <stdio.h>
#include <stdlib.h>

Node* initNode(int data) {
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void addNode(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory allocation failed!\n");
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
    if(new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = data;

    // Insert at head
    if(position == 0 || *head == NULL) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse to position-1
    Node *current = *head;
    int posCount = 0;
    while(posCount < position - 1 && current->next != NULL) {
        current = current->next;
        posCount++;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

void addNodeAtHead(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void addNodeSorted(Node **head, int data) {
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    new_node->data = data;

    // Empty list or insert at head
    if(*head == NULL || (*head)->data >= data) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Find the correct position
    Node *current = *head;
    while(current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
}

void removeNodeAtPosition(Node **head, int position) {
    if(*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Remove head
    if(position == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Traverse to position-1
    int posCount = 0;
    Node *current = *head;
    while(posCount < position - 1 && current->next != NULL) {
        current = current->next;
        posCount++;
    }
    
    if(current->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }
    
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void removeNodeHead(Node **head) {
    if(*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeNodeAtEnd(Node **head) {
    if(*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // Only one node
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    
    Node *current = *head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

void removeNodeValue(Node **head, int value) {
    if(*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // Value is at head
    if((*head)->data == value) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    Node *current = *head;
    while(current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    
    if(current->next == NULL) {
        printf("Value %d not found in list.\n", value);
        return;
    }
    
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void sortNodesIncreasingly(Node **head) {
    if(*head == NULL || (*head)->next == NULL) {
        return; // Empty list or single node, already sorted
    }
    
    int swapped;
    Node **current;
    Node *temp;
    
    do {
        swapped = 0;
        current = head;
        
        while(*current != NULL && (*current)->next != NULL) {
            if((*current)->data > (*current)->next->data) {
                // Swap the nodes
                temp = (*current)->next;
                (*current)->next = temp->next;
                temp->next = *current;
                *current = temp;
                
                swapped = 1;
            }
            current = &((*current)->next);
        }
    } while(swapped);
}

void sortNodesDecreasingly(Node **head) {
    if(*head == NULL || (*head)->next == NULL) {
        return; // Empty list or single node, already sorted
    }
    
    int swapped;
    Node **current;
    Node *temp;
    
    do {
        swapped = 0;
        current = head;
        
        while(*current != NULL && (*current)->next != NULL) {
            if((*current)->data < (*current)->next->data) {
                // Swap the nodes
                temp = (*current)->next;
                (*current)->next = temp->next;
                temp->next = *current;
                *current = temp;
                
                swapped = 1;
            }
            current = &((*current)->next);
        }
    } while(swapped);
}

void valueNodeSearch(Node **head, int value) {
    if(*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node *current = *head;
    while(current != NULL) {
        if(current->data == value) {
            printf("We found %d in the list.\n", value);
            return;
        }
        current = current->next;
    }
    
    printf("There is no %d in the list.\n", value);
}

Node *mergeNodeList(Node **head1, Node **head2) {
    Node *head = NULL;
    Node *h = NULL;     // Moving ptr

    while(*head1 != NULL && *head2 != NULL) {
        if((*head1)->data <= (*head2)->data) {
            if(h == NULL) {
                // First node
                head = *head1;
                h = *head1;
            } else {
                h->next = *head1;
                h = h->next;
            }
            *head1 = (*head1)->next;
        } else {
            if(h == NULL) {
                // First node
                head = *head2;
                h = *head2;
            } else {
                h->next = *head2;
                h = h->next;
            }
            *head2 = (*head2)->next;
        }
    }

    // Adding the rest
    if(*head1 != NULL) {
        if(h == NULL) {
            head = *head1;
        } else {
            h->next = *head1;
        }
    } else if(*head2 != NULL) {
        if(h == NULL) {
            head = *head2;
        } else {
            h->next = *head2;
        }
    }

    return head;
}

void splitNodeList(Node **origin, Node **slice1, Node **slice2) {
    // Empty list
    if(*origin == NULL) {
        *slice1 = NULL;
        *slice2 = NULL;
        return;
    }
    
    // Finding length of origin list
    Node *current = *origin;
    int len = 0;
    while(current != NULL) {
        len++;
        current = current->next;
    }

    int middle = len / 2;

    // Traverse till middle
    Node *prev = NULL;
    current = *origin;
    for(int i = 0; i < middle; i++) {
        prev = current;
        current = current->next;
    }

    *slice1 = *origin;
    *slice2 = current;

    // This truncates the first slice
    if(prev != NULL) {
        prev->next = NULL;
    }

    *origin = NULL;
}

void clearNode(Node **head) {
    if(*head == NULL) {
        return;
    }

    // Recursive free from head to tail
    clearNode(&(*head)->next);
    free(*head);
    *head = NULL;
} 

void printNode(Node **head) {
    if(*head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    Node *current = *head;
    while(current->next != NULL) {
        printf(" %d ->", current->data);
        current = current->next;
    }
    printf(" %d -> NULL\n", current->data);
}

Dnode *initDnode(int data) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void addDNode(Dnode **head, int data) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = data;

    // case head does not exist
    if(*head == NULL) {
        *head = new_node;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return;
    }

    Dnode *current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    new_node->next = NULL;
}

void addDNodeAtPosition(Dnode **head, int data, int position) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = data;

    if(*head == NULL || position == 0) {
        new_node->next = *head;
        if (*head != NULL) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }

    int i = 0;
    Dnode *current = *head;
    while(current->next != NULL && i < position - 1) {
        current = current->next;
        i++;
    }

    new_node->next = current->next;
    if(current->next != NULL) {
        current->next->prev = new_node;
    }
    current->next = new_node;
    new_node->prev = current;
}

void addDNodeAtHead(Dnode **head, int data) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = data;

    // case there is no head
    if(*head == NULL) {
        *head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        return;
    }

    new_node->prev = NULL;
    new_node->next = *head;
    *head = new_node;
}

void addDNodeSorted(Dnode **head, int data) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data =data;

    // no head
    if(*head == NULL) {
        *head = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
        return;
    }

    // if the data of the first node is bigger than the data in the second node
    if(data < (*head)->data) {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    // find the correct position in the middle or end
    Dnode *current = *head;
    while(current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // insert new_node after current
    new_node->next = current->next;
    new_node->prev = current;

    if(current->next != NULL) {
        current->next->prev = new_node;
    }
    current->next = new_node;
}

void removeDNodeHead(Dnode **head) {
    if(*head == NULL) {
        printf("List empty.\n");
        return;
    }

    Dnode *tmp = *head;
    *head = (*head)->next;

    if(*head != NULL) {
        (*head)->prev = NULL;
    }

    free(tmp);
}

void removeDNodeAtEnd(Dnode **head) {
    Dnode *current = *head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    current->next = NULL;
}

void removeDNodeValue(Dnode **head, int value) {
    Dnode *tmp = *head;

    // if head has the value
    if((*head)->data == value) {
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(tmp);
        return;
    }

    Dnode *current = *head;
    while(current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    current->next = current->next->next;
    current->next->prev = current;
}

void removeDNodeAtPosition(Dnode **head, int position) {
    Dnode *tmp = *head;
    if(position == 0 && *head != NULL) {
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(tmp);
        return;
    }

    Dnode *current = *head;
    int i = 0;
    while(current->next != NULL && i < position - 1) {
        current = current->next;
        i++;
    }
    current->next = current->next->next;
    current->next->prev = current;
}

void sortDNodeIncreasingly(Dnode **head) {
    if(*head == NULL || (*head)->next == NULL)
        return;

    int swapped;

    do {
        swapped = 0;
        Dnode *current = *head;

        while(current->next != NULL) {

            // if the current data is bigger than the data in the next node
            if(current->data > current->next->data) {
                // swap current and next

                Dnode *next = current->next;

                // node position swap
                // fix pointers before swap
                if(current->prev) {
                    current->prev->next = next;
                } else {
                    *head = next;   // swapping the head
                }
        
                if(next->next) {
                    next->next->prev = current;
                }
                
                // doing the swap of previus pointers
                next->prev = current->prev;
                current->prev = next;

                // swap of next pointers
                current->next = next->next;
                next->next = current;

                swapped = 1;
            } else {
                current = current->next;
            }
        }
    } while(swapped);
}

void sortDNodeDecreasingly(Dnode **head) {
    if(*head == NULL || (*head)->next == NULL)
        return;

    int swapped;

    do {
        swapped = 0;
        Dnode *current = *head;

        while(current->next != NULL) {

            // if the current data is bigger than the data in the next node
            if(current->data < current->next->data) {
                // swap current and next

                Dnode *next = current->next;

                // node position swap
                // fix pointers before swap
                if(current->prev) {
                    current->prev->next = next;
                } else {
                    *head = next;   // swapping the head
                }
        
                if(next->next) {
                    next->next->prev = current;
                }
                
                // doing the swap of previus pointers
                next->prev = current->prev;
                current->prev = next;

                // swap of next pointers
                current->next = next->next;
                next->next = current;

                swapped = 1;
            } else {
                current = current->next;
            }
        }
    } while(swapped);
}

void valueDNodeSearch(Dnode **head, int value) {
    if(*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Dnode *current = *head;
    while(current != NULL) {
        if(current->data == value) {
            printf("We found %d in the list.\n", value);
            return;
        }
        current = current->next;
    }
    
    printf("There is no %d in the list.\n", value);
}

Dnode *mergeDNodeList(Dnode **head1, Dnode **head2) {
    Dnode *head = NULL;
    Dnode *h = NULL; // Moving ptr

    while(*head1 != NULL && *head2 != NULL) {
        if((*head1)->data <= (*head2)->data) {
            if(h == NULL) {
                head = *head1;
                h = *head1;
            } else {
                h->next = *head1;
                (*head1)->prev = h;
                h = h->next;
            }
            *head1 = (*head1)->next;
        } else {
            if(h == NULL) {
                head = *head2;
                h = *head2;
            } else {
                h->next = *head2;
                (*head2)->prev = h;
                h = h->next;
            }
            *head2 = (*head2)->next;
        }
    }

    // Adding the rest
    if(*head1 != NULL) {
        if(h == NULL) {
            head = *head1;
        } else {
            h->next = *head1;
            (*head1)->prev = h;
        }
    } else if(*head2 != NULL) {
        if(h == NULL) {
            head = *head2;
        } else {
            h->next = *head2;
            (*head2)->prev = h;
        }
    }

    if(head != NULL) head->prev = NULL;
    return head;
}

void splitDNodeList(Dnode **original, Dnode **slice1, Dnode **slice2) {
    // Empty list
    if(*original == NULL) {
        *slice1 = NULL;
        *slice2 = NULL;
        return;
    }

    // Finding length of origin list
    Dnode *current = *original;
    int len = 0;
    while(current != NULL) {
        len++;
        current = current->next;
    }

    int middle = len / 2;

    // Traverse till middle
    Dnode *prev = NULL;
    current = *original;
    for(int i = 0; i < middle; i++) {
        prev = current;
        current = current->next;
    }

    *slice1 = *original;
    *slice2 = current;

    // This truncates the first slice
    if(prev != NULL) {
        prev->next = NULL;
    }

    // Fix prev pointers
    if(*slice1 != NULL) (*slice1)->prev = NULL;
    if(*slice2 != NULL) (*slice2)->prev = NULL;

    *original = NULL;
}

void clearDNode(Dnode **head) {
    if(*head == NULL) {
        return;
    }

    // Recursive free from head to tail
    clearDNode(&(*head)->next);
    free(*head);
    *head = NULL;
}

void printDNode(Dnode **head) {
    if(*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Dnode *current = *head;
    while(current->next != NULL) {
        printf(" %d ->", current->data);
        current = current->next;
    }
    printf(" %d -> NULL\n", current->data);
}
