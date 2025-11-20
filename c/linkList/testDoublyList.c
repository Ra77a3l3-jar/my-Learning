#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    Dnode *list = initDnode(14);

    addDNode(&list, 23);
    addDNode(&list, 78);
    addDNode(&list, 29);
    printDNode(&list);

    removeDNodeAtEnd(&list);
    printDNode(&list);

    addDNode(&list, 52);
    addDNode(&list, 26);
    addDNode(&list, 71);
    printDNode(&list);

    removeDNodeAtPosition(&list, 2);
    printDNode(&list);

    sortDNodeIncreasingly(&list);
    printDNode(&list);

    sortDNodeDecreasingly(&list);
    printDNode(&list);

    valueDNodeSearch(&list, 52);

    Dnode *list2 = initDnode(46);
    addDNode(&list2, 124);
    addDNode(&list2, 16);
    addDNode(&list2, 73);
    addDNode(&list2, 92);

    Dnode *merge = mergeDNodeList(&list, &list2);
    printDNode(&merge);

    Dnode *slice1 = NULL;
    Dnode *slice2 = NULL;

    splitDNodeList(&merge, &slice1, &slice2);
    printDNode(&slice1);
    printDNode(&slice2);
    clearDNode(&merge);
    clearDNode(&slice1);
    clearDNode(&slice2);
}
