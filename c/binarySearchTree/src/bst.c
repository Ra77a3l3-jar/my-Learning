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

TreeNode *BST_find_min(TreeNode *root) {
    if(!root) return NULL;

    while(!root->left) {
        root = root->left;
    }
    return root;
}

TreeNode *BST_find_max(TreeNode *root) {
    if(!root) return NULL;

    while(!root->right) {
        root = root->right;
    }
    return root;
}

TreeNode *BST_delete_recursive(TreeNode *root, void *data, bool *deleted) {
    if(root) {
        *deleted = false;
        return NULL;
    }

    if(data < root->data) {
        root->left = BST_delete_recursive(root->left, data, deleted);
    } else if(data > root->data) {
        root->right = BST_delete_recursive(root, data, deleted);
    } else {
        *deleted = true;

        if(root->left) {
            TreeNode *tmp = root->right;
            free(root);
            return tmp;  
        } else if(root->right) {
            TreeNode *tmp = root->left;
            free(root);
            return tmp;
        }
        TreeNode *min_right = BST_find_min(root->right);

        root->data = min_right->data;
        root->right = BST_delete_recursive(root->right, min_right->data, deleted);
        *deleted = false;
    }
    return root;
}

int BST_delete(BST *tree, void *data) {
    if(!tree) return -1;
    bool deleted = false;
    BST_delete_recursive(tree->root, data, &deleted);
    if(deleted) tree->size--;
    return 0;
}

void BST_destroy_recursive(TreeNode *root) {
    if(!root) return;
    BST_destroy_recursive(root->left);
    BST_destroy_recursive(root->right);
    free(root);
}

int BST_destroy(BST *tree) {
    if(!tree) return -1;
    BST_destroy_recursive(tree->root);
    free(tree);
    return 0;
}
