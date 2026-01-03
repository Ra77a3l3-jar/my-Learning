#include "include/bst.h"

#include <stdio.h>

int main(void) {

    BST *tree = BST_create();

    int values[] = {10, 50, 40, 60, 20, 75, 30, 15, 80, 95};

    for(size_t i = 0; i < 10; i++) {
        BST_insert(tree, &values[i]);
    }

    TreeNode *x = BST_find_max(tree->root);
    printf("The maximum value in the Tree is %d.\n", *(int*)x->data);
    x = BST_find_min(tree->root);
    printf("The minimum value in the Tree is %d.\n", *(int*)x->data);

    printf("\nThe size of the tree is %zu.\n", tree->size);
    BST_delete(tree, &values[9]);
    printf("The size of the Tree after deleting a single valuei is %zu.\n", tree->size);

    BST_destroy(tree);
}
