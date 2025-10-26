#ifndef LIST_H
#define LIST_H


typedef struct Node{
    int data;
    struct Node *next;   
} Node;

typedef struct Dnode {
    int data;
    struct Dnode *next;
    struct Dnode *prev;
} Dnode;

// Single linked lists

Node* initNode(int data);
void addNode(Node **head, int data);
void addNodeAtPosition(Node **head, int data, int position);
void addNodeAtHead(Node **head, int data);
void addNodeSorted(Node **head, int data);

void removeNodeAtPosition(Node **head, int position);
void removeNodeHead(Node **head);
void removeNodeAtEnd(Node **head);
void removeNodeValue(Node **head, int value);

void sortNodesIncreasingly(Node **head);
void sortNodesDecreasingly(Node **head);

void valueNodeSearch(Node **head, int value);

void mergeNodeList(Node **head1, Node **head2);
void splitNodeList(Node **origin, Node **slice1, Node **slice2);

void clearNode(Node **head);
void printNode(Node **head);

// Doubly linked lists

Dnode* initDnode(int data);
void addDNode(Dnode **head, int data);
void addDNodeAtPosition(Dnode **head, int data, int position);
void addDNodeAtHead(Dnode **head, int data);
void addDNodeSorted(Dnode **head, int data);

void removeDNodeAtPosition(Dnode **head, int position);
void removeDNodeHead(Dnode **head);
void removeDNodeAtEnd(Dnode **head);
void removeDNodeValue(Dnode **head, int value);

void sortDNodeIncreasingly(Dnode **head);
void sortDNodeDecreasingly(Dnode **head);

void valueDNodeSearch(Dnode **head, int value);

void mergeDNodeList(Dnode **head1, Dnode **head2);
void splitDNodeList(Dnode **original, Dnode **slice1, Dnode **slice2);

void clearDNode(Dnode **head);
void printDNode(Dnode **head);

// Circular linked lists



#endif
