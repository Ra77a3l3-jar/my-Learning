#include "include/list.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Node *list = initNode(12);

    addNode(&list, 14);
    addNode(&list, 19);
    addNode(&list, 32);
    printNode(&list);

    removeNodeAtEnd(&list);
    printNode(&list);

    removeNodeHead(&list);
    printNode(&list);

    addNode(&list, 50);
    addNode(&list, 89);
    addNode(&list, 65);
    printNode(&list);

    removeNodeAtPosition(&list, 2);
    printNode(&list);

    sortNodesIncreasingly(&list);
    printNode(&list);

    sortNodesDecreasingly(&list);
    printNode(&list);

    valueNodeSearch(&list, 89);

    Node *list2 = initNode(40);
    addNode(&list2, 90);
    addNode(&list2, 234);
    addNode(&list2, 230);
    addNode(&list2, 14);
    addNode(&list2, 37);

    Node *merge = mergeNodeList(&list, &list2);
    printNode(&merge);

    Node *slice1 = NULL;
    Node *slice2 = NULL;

    splitNodeList(&merge, &slice1, &slice2);
    printNode(&slice1);
    printNode(&slice2);
    clearNode(&merge);
    clearNode(&slice1);
    clearNode(&slice2);
}
