#ifndef BST_H
#define BST_H

#include <stddef.h>
#include <stdbool.h>

// return 0 sucess
// return 1 / -1 fail

typedef struct TreeNode {
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BST {
    struct TreeNode *root;
    size_t size;
} BST;

BST *BST_create();
TreeNode *create_node(void *data);

TreeNode *BST_insert_recursive(TreeNode *root, void *data);
int BST_insert(BST *tree, void *data);

int BST_search_recursive(TreeNode *root, void *data);
int BST_search(BST *tree, void *data);

TreeNode *BST_find_min(TreeNode *root);
TreeNode *BST_find_max(TreeNode *root);

TreeNode *BST_delete_recursive(TreeNode *root, void *data, bool *deleted);
int BST_delete(BST *tree, void *data);

#endif
