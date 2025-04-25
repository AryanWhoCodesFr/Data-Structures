#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal: Root -> Left -> Right
void traversePreorder(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        traversePreorder(root->left);
        traversePreorder(root->right);
    }
}

// Inorder Traversal: Left -> Root -> Right
void traverseInorder(struct TreeNode* root) {
    if (root != NULL) {
        traverseInorder(root->left);
        printf("%d ", root->value);
        traverseInorder(root->right);
    }
}

// Postorder Traversal: Left -> Right -> Root
void traversePostorder(struct TreeNode* root) {
    if (root != NULL) {
        traversePostorder(root->left);
        traversePostorder(root->right);
        printf("%d ", root->value);
    }
}

int main() {
    // Construct the tree:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6

    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(5);
    root->right->right = createTreeNode(6);

    printf("Preorder Traversal: ");
    traversePreorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    traverseInorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    traversePostorder(root);
    printf("\n");

    return 0;
}
