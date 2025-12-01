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
    int values1[] = {14, 23, 78, 29};
    int values2[] = {52, 26, 71};
    int values3[] = {46, 124, 16, 73, 92};
    
    Dnode *list = initDnode(&values1[0]);
    for(int i = 1; i < 4; i++)
        addDNode(&list, &values1[i]);
    printDNode(list, print_int);
    printf("\n");

    removeDNodeAtEnd(&list);
    printDNode(list, print_int);
    printf("\n");

    for(int i = 0; i < 3; i++)
        addDNode(&list, &values2[i]);
    printDNode(list, print_int);
    printf("\n");

    removeDNodeAtPosition(&list, 2);
    printDNode(list, print_int);
    printf("\n");

    sortDNodeIncreasingly(&list, compare_int);
    printDNode(list, print_int);
    printf("\n");

    sortDNodeDecreasingly(&list, compare_int);
    printDNode(list, print_int);
    printf("\n");

    int search_val = 52;
    valueDNodeSearch(list, &search_val, compare_int);

    Dnode *list2 = initDnode(&values3[0]);
    for(int i = 1; i < 5; i++)
        addDNode(&list2, &values3[i]);

    Dnode *merge = mergeDNodeList(&list, &list2, compare_int);
    printDNode(merge, print_int);
    printf("\n");

    Dnode *slice1 = NULL;
    Dnode *slice2 = NULL;

    splitDNodeList(&merge, &slice1, &slice2);
    printDNode(slice1, print_int);
    printf("\n");
    printDNode(slice2, print_int);
    printf("\n");
    clearDNode(&merge);
    clearDNode(&slice1);
    clearDNode(&slice2);
}
