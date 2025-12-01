#include "../include/list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* initNode(void *data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) return NULL;

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int addNode(Node **head, void *data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) return -1;

    new_node->data = data;
    new_node->next = NULL;
    
    if(!*head) {
        *head = new_node;
        return 0;
    }

    Node *current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return 0;
}

int addNodeAtPosition(Node **head, void *data, int position) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) return -1;
    new_node->data = data;

    if(position == 0 || *head == NULL) {
        new_node->next = *head;
        *head = new_node;
        return 0;
    }

    Node *current = *head;
    int posCount = 0;
    while(posCount < position - 1 && current->next != NULL) {
        current = current->next;
        posCount++;
    }
    
    new_node->next = current->next;
    current->next = new_node;
    return 0;
}

int addNodeAtHead(Node **head, void *data) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) return -1;

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    return 0;
}

int addNodeSorted(Node **head, void *data, compare_func cmp) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) return -1;

    new_node->data = data;

    if(*head == NULL || cmp((*head)->data, data) >= 0) {
        new_node->next = *head;
        *head = new_node;
        return 0;
    }

    Node *current = *head;
    while(current->next != NULL && cmp(current->next->data, data) < 0) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
    return 0;
}

int removeNodeAtPosition(Node **head, int position) {
    if(!*head) return -1;

    if(position == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return 0;
    }

    int posCount = 0;
    Node *current = *head;
    while(posCount < position - 1 && current->next != NULL) {
        current = current->next;
        posCount++;
    }
    
    if(!current->next) {
        return -1;
    }
    
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return 0;
}

int removeNodeHead(Node **head) {
    if(!*head) return -1;
    
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return 0;
}

int removeNodeAtEnd(Node **head) {
    if(!*head) return -1;
    
    if(!(*head)->next) {
        free(*head);
        *head = NULL;
        return 0;
    }
    
    Node *current = *head;
    while(current->next->next) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return 0;
}

int removeNodeValue(Node **head, void *value, compare_func cmp) {
    if(!*head) return -1;
    
    if(cmp((*head)->data, value) == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return 0;
    }
    
    Node *current = *head;
    while(current->next != NULL && cmp(current->next->data, value) != 0) {
        current = current->next;
    }
    
    if(!current->next) {
        return -1;
    }
    
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return 0;
}

int sortNodesIncreasingly(Node **head, compare_func cmp) {
    if(*head == NULL || (*head)->next == NULL) {
        return 0;
    }
    
    int swapped;
    Node **current;
    Node *temp;
    
    do {
        swapped = 0;
        current = head;
        
        while(*current != NULL && (*current)->next != NULL) {
            if(cmp((*current)->data, (*current)->next->data) > 0) {
                temp = (*current)->next;
                (*current)->next = temp->next;
                temp->next = *current;
                *current = temp;
                
                swapped = 1;
            }
            current = &((*current)->next);
        }
    } while(swapped);
    
    return 0;
}

int sortNodesDecreasingly(Node **head, compare_func cmp) {
    if(*head == NULL || (*head)->next == NULL) {
        return 0;
    }
    
    int swapped;
    Node **current;
    Node *temp;
    
    do {
        swapped = 0;
        current = head;
        
        while(*current != NULL && (*current)->next != NULL) {
            if(cmp((*current)->data, (*current)->next->data) < 0) {
                temp = (*current)->next;
                (*current)->next = temp->next;
                temp->next = *current;
                *current = temp;
                
                swapped = 1;
            }
            current = &((*current)->next);
        }
    } while(swapped);
    
    return 0;
}

int valueNodeSearch(Node *head, void *value, compare_func cmp) {
    if(!head) return -1;

    Node *current = head;
    while(current) {
        if(cmp(current->data, value) == 0) {
            return 1;
        }
        current = current->next;
    }
    
    return -1;
}

Node *mergeNodeList(Node **head1, Node **head2, compare_func cmp) {
    Node *head = NULL;
    Node *h = NULL;

    while(*head1 != NULL && *head2 != NULL) {
        if(cmp((*head1)->data, (*head2)->data) <= 0) {
            if(!h) {
                head = *head1;
                h = *head1;
            } else {
                h->next = *head1;
                h = h->next;
            }
            *head1 = (*head1)->next;
        } else {
            if(!h) {
                head = *head2;
                h = *head2;
            } else {
                h->next = *head2;
                h = h->next;
            }
            *head2 = (*head2)->next;
        }
    }

    if(*head1 != NULL) {
        if(!h) {
            head = *head1;
        } else {
            h->next = *head1;
        }
    } else if(*head2 != NULL) {
        if(!h) {
            head = *head2;
        } else {
            h->next = *head2;
        }
    }

    return head;
}

void splitNodeList(Node **origin, Node **slice1, Node **slice2) {
    if(*origin == NULL) {
        *slice1 = NULL;
        *slice2 = NULL;
        return;
    }
    
    Node *current = *origin;
    int len = 0;
    while(current) {
        len++;
        current = current->next;
    }

    int middle = len / 2;

    Node *prev = NULL;
    current = *origin;
    for(int i = 0; i < middle; i++) {
        prev = current;
        current = current->next;
    }

    *slice1 = *origin;
    *slice2 = current;

    if(prev != NULL) {
        prev->next = NULL;
    }

    *origin = NULL;
}

void clearNode(Node **head) {
    if(!*head) return;

    clearNode(&(*head)->next);
    free(*head);
    *head = NULL;
}

void printNode(Node *head, print_func print_data) {
    if(!head) {
        printf("The list is empty.\n");
        return;
    }
    
    Node *current = head;
    while(current->next != NULL) {
        printf(" ");
        print_data(current->data);
        printf(" ->");
        current = current->next;
    }
    printf(" ");
    print_data(current->data);
    printf(" -> NULL\n");
}

Dnode* initDnode(void *data) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(!new_node) return NULL;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

int addDNode(Dnode **head, void *data) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(!new_node) return -1;

    new_node->data = data;

    if(!*head) {
        *head = new_node;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return 0;
    }

    Dnode *current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    new_node->next = NULL;
    return 0;
}

int addDNodeAtPosition(Dnode **head, void *data, int position) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(!new_node) return -1;

    new_node->data = data;

    if(*head == NULL || position == 0) {
        new_node->next = *head;
        if (*head != NULL) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return 0;
    }

    int i = 0;
    Dnode *current = *head;
    while(current->next != NULL && i < position - 1) {
        current = current->next;
        i++;
    }

    new_node->next = current->next;
    if(current->next) {
        current->next->prev = new_node;
    }
    current->next = new_node;
    new_node->prev = current;
    return 0;
}

int addDNodeAtHead(Dnode **head, void *data) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(!new_node) return -1;

    new_node->data = data;

    if(!*head) {
        *head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        return 0;
    }

    new_node->prev = NULL;
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
    return 0;
}

int addDNodeSorted(Dnode **head, void *data, compare_func cmp) {
    Dnode *new_node = malloc(sizeof(Dnode));
    if(!new_node) return -1;

    new_node->data = data;

    if(!*head) {
        *head = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
        return 0;
    }

    if(cmp(data, (*head)->data) < 0) {
        new_node->next = *head;
        (*head)->prev = new_node;
        new_node->prev = NULL;
        *head = new_node;
        return 0;
    }

    Dnode *current = *head;
    while(current->next != NULL && cmp(current->next->data, data) < 0) {
        current = current->next;
    }

    new_node->next = current->next;
    new_node->prev = current;

    if(current->next) {
        current->next->prev = new_node;
    }
    current->next = new_node;
    return 0;
}

int removeDNodeAtPosition(Dnode **head, int position) {
    if(!head || !*head) return -1;
    
    Dnode *tmp = *head;
    if(position == 0) {
        *head = (*head)->next;
        if(*head) {
            (*head)->prev = NULL;
        }
        free(tmp);
        return 0;
    }

    Dnode *current = *head;
    int i = 0;
    while(current->next != NULL && i < position - 1) {
        current = current->next;
        i++;
    }
    
    if(!current->next) return -1;
    
    tmp = current->next;
    current->next = tmp->next;
    if(tmp->next != NULL) {
        tmp->next->prev = current;
    }
    free(tmp);
    return 0;
}

int removeDNodeHead(Dnode **head) {
    if(!*head) return -1;

    Dnode *tmp = *head;
    *head = (*head)->next;

    if(*head) {
        (*head)->prev = NULL;
    }

    free(tmp);
    return 0;
}

int removeDNodeAtEnd(Dnode **head) {
    if(!*head) return -1;

    if(!(*head)->next) {
        free(*head);
        *head = NULL;
        return 0;
    }

    Dnode *current = *head;
    while(current->next->next) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return 0;
}

int removeDNodeValue(Dnode **head, void *value, compare_func cmp) {
    if(!head || !*head) return -1;
    
    if(cmp((*head)->data, value) == 0) {
        Dnode *tmp = *head;
        *head = (*head)->next;
        if(*head) {
            (*head)->prev = NULL;
        }
        free(tmp);
        return 0;
    }

    Dnode *current = *head;
    while(current->next != NULL && cmp(current->next->data, value) != 0) {
        current = current->next;
    }
    
    if(!current->next) {
        return -1;
    }
    
    Dnode *tmp = current->next;
    current->next = tmp->next;
    if(tmp->next != NULL) {
        tmp->next->prev = current;
    }
    free(tmp);
    return 0;
}

int sortDNodeIncreasingly(Dnode **head, compare_func cmp) {
    if(*head == NULL || (*head)->next == NULL)
        return 0;

    int swapped;

    do {
        swapped = 0;
        Dnode *current = *head;

        while(current->next != NULL) {

            if(cmp(current->data, current->next->data) > 0) {

                Dnode *next = current->next;

                if(current->prev) {
                    current->prev->next = next;
                } else {
                    *head = next;
                }
        
                if(next->next) {
                    next->next->prev = current;
                }
                
                next->prev = current->prev;
                current->prev = next;

                current->next = next->next;
                next->next = current;

                swapped = 1;
            } else {
                current = current->next;
            }
        }
    } while(swapped);
    
    return 0;
}

int sortDNodeDecreasingly(Dnode **head, compare_func cmp) {
    if(*head == NULL || (*head)->next == NULL)
        return 0;

    int swapped;

    do {
        swapped = 0;
        Dnode *current = *head;

        while(current->next != NULL) {

            if(cmp(current->data, current->next->data) < 0) {

                Dnode *next = current->next;

                if(current->prev) {
                    current->prev->next = next;
                } else {
                    *head = next;
                }
        
                if(next->next) {
                    next->next->prev = current;
                }
                
                next->prev = current->prev;
                current->prev = next;

                current->next = next->next;
                next->next = current;

                swapped = 1;
            } else {
                current = current->next;
            }
        }
    } while(swapped);
    
    return 0;
}

int valueDNodeSearch(Dnode *head, void *value, compare_func cmp) {
    if(!head) return -1;

    Dnode *current = head;
    while(current) {
        if(cmp(current->data, value) == 0) {
            return 1;
        }
        current = current->next;
    }
    
    return -1;
}

Dnode *mergeDNodeList(Dnode **head1, Dnode **head2, compare_func cmp) {
    Dnode *head = NULL;
    Dnode *h = NULL;

    while(*head1 != NULL && *head2 != NULL) {
        if(cmp((*head1)->data, (*head2)->data) <= 0) {
            if(!h) {
                head = *head1;
                h = *head1;
            } else {
                h->next = *head1;
                (*head1)->prev = h;
                h = h->next;
            }
            *head1 = (*head1)->next;
        } else {
            if(!h) {
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

    if(*head1 != NULL) {
        if(!h) {
            head = *head1;
        } else {
            h->next = *head1;
            (*head1)->prev = h;
        }
    } else if(*head2 != NULL) {
        if(!h) {
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
    if(*original == NULL) {
        *slice1 = NULL;
        *slice2 = NULL;
        return;
    }

    Dnode *current = *original;
    int len = 0;
    while(current) {
        len++;
        current = current->next;
    }

    int middle = len / 2;

    Dnode *prev = NULL;
    current = *original;
    for(int i = 0; i < middle; i++) {
        prev = current;
        current = current->next;
    }

    *slice1 = *original;
    *slice2 = current;

    if(prev != NULL) {
        prev->next = NULL;
    }

    if(*slice1) (*slice1)->prev = NULL;
    if(*slice2) (*slice2)->prev = NULL;

    *original = NULL;
}

void clearDNode(Dnode **head) {
    if(!*head) return;

    clearDNode(&(*head)->next);
    free(*head);
    *head = NULL;
}

void printDNode(Dnode *head, print_func print_data) {
    if(!head) {
        printf("The list is empty.\n");
        return;
    }

    Dnode *current = head;
    while(current->next != NULL) {
        printf(" ");
        print_data(current->data);
        printf(" ->");
        current = current->next;
    }
    printf(" ");
    print_data(current->data);
    printf(" -> NULL\n");
}
