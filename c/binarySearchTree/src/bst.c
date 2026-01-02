#include "../include/bst.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

BST* BST_create() {
    BST *new_bst = malloc(sizeof(BST));
    if(!new_bst) return NULL;
    new_bst->root = NULL;
    new_bst->size = 0;
    return new_bst;
}

TreeNode *create_node(void *data) {
    TreeNode *new_node = malloc(sizeof(TreeNode));
    if(!new_node) return NULL;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

TreeNode *BST_insert_recursive(TreeNode *root, void *data) {
    if(!root) {
        return create_node(data);
    }
    if(data < root->data) {
        BST_insert_recursive(root->left, data);
    } else if(data > root->data) {
        BST_insert_recursive(root->right, data);
    }
    return root;
}

int BST_insert(BST *tree, void *data) {
    if(!tree) return -1;
    tree->root = BST_insert_recursive(tree->root, data);
    tree->size++;
    return 0;
}

int BST_search_recursive(TreeNode *root, void *data) {
    if(!root) return -1;

    if(root->data == data) {
        return 0;
    } else if(data < root->data) {
        BST_search_recursive(root->left, data);
    } else if(data > root->data) {
        BST_search_recursive(root->right, data);
    }
    return -1;
}

int BST_search(BST *tree, void *data) {
    if(!tree) return -1;
    return BST_search_recursive(tree->root, data);
}
