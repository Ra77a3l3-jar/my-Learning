#include "include/list.h"

#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) {
    int val_a = *(int *)a;
    int val_b = *(int *)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

void print_int(void *data) {
    printf("%d ", *(int *)data);
}

int main(void) {
    int values1[] = {12, 14, 19, 32};
    int values2[] = {50, 89, 65};
    int values3[] = {40, 90, 234, 230, 14, 37};
    
    Node *list = initNode(&values1[0]);
    for(int i = 1; i < 4; i++)
        addNode(&list, &values1[i]);
    printNode(list, print_int);
    printf("\n");

    removeNodeAtEnd(&list);
    printNode(list, print_int);
    printf("\n");

    removeNodeHead(&list);
    printNode(list, print_int);
    printf("\n");

    for(int i = 0; i < 3; i++)
        addNode(&list, &values2[i]);
    printNode(list, print_int);
    printf("\n");

    removeNodeAtPosition(&list, 2);
    printNode(list, print_int);
    printf("\n");

    sortNodesIncreasingly(&list, compare_int);
    printNode(list, print_int);
    printf("\n");

    sortNodesDecreasingly(&list, compare_int);
    printNode(list, print_int);
    printf("\n");

    int search_val = 89;
    valueNodeSearch(list, &search_val, compare_int);

    Node *list2 = initNode(&values3[0]);
    for(int i = 1; i < 6; i++)
        addNode(&list2, &values3[i]);

    Node *merge = mergeNodeList(&list, &list2, compare_int);
    printNode(merge, print_int);
    printf("\n");

    Node *slice1 = NULL;
    Node *slice2 = NULL;

    splitNodeList(&merge, &slice1, &slice2);
    printNode(slice1, print_int);
    printf("\n");
    printNode(slice2, print_int);
    printf("\n");
    clearNode(&merge);
    clearNode(&slice1);
    clearNode(&slice2);
}
