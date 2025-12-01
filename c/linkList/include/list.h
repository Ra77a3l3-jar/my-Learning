#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

// return 0 sucess
// return -1 / 1 fail

typedef int (*compare_func)(const void *a, const void *b);
typedef void (*print_func)(void *);

typedef struct Node{
    void *data;
    struct Node *next;
} Node;

typedef struct Dnode {
    void *data;
    struct Dnode *next;
    struct Dnode *prev;
} Dnode;

Node* initNode(void *data);
int addNode(Node **head, void *data);
int addNodeAtPosition(Node **head, void *data, int position);
int addNodeAtHead(Node **head, void *data);
int addNodeSorted(Node **head, void *data, compare_func cmp);
int removeNodeAtPosition(Node **head, int position);
int removeNodeHead(Node **head);
int removeNodeAtEnd(Node **head);
int removeNodeValue(Node **head, void *value, compare_func cmp);
int sortNodesIncreasingly(Node **head, compare_func cmp);
int sortNodesDecreasingly(Node **head, compare_func cmp);
int valueNodeSearch(Node *head, void *value, compare_func cmp);
Node *mergeNodeList(Node **head1, Node **head2, compare_func cmp);
void splitNodeList(Node **origin, Node **slice1, Node **slice2);
void clearNode(Node **head);
void printNode(Node *head, print_func print_data);

Dnode* initDnode(void *data);
int addDNode(Dnode **head, void *data);
int addDNodeAtPosition(Dnode **head, void *data, int position);
int addDNodeAtHead(Dnode **head, void *data);
int addDNodeSorted(Dnode **head, void *data, compare_func cmp);
int removeDNodeAtPosition(Dnode **head, int position);
int removeDNodeHead(Dnode **head);
int removeDNodeAtEnd(Dnode **head);
int removeDNodeValue(Dnode **head, void *value, compare_func cmp);
int sortDNodeIncreasingly(Dnode **head, compare_func cmp);
int sortDNodeDecreasingly(Dnode **head, compare_func cmp);
int valueDNodeSearch(Dnode *head, void *value, compare_func cmp);
Dnode *mergeDNodeList(Dnode **head1, Dnode **head2, compare_func cmp);
void splitDNodeList(Dnode **original, Dnode **slice1, Dnode **slice2);
void clearDNode(Dnode **head);
void printDNode(Dnode *head, print_func print_data);

#endif
