#include <stdio.h>
#include <stdlib.h>

// Tree node definition
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create a new node
struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert value into BST
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL)
        return createTreeNode(value);

    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value)
        root->right = insertNode(root->right, value);

    return root;
}

// Find the node with minimum value
struct TreeNode* getMinNode(struct TreeNode* node) {
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}

// Delete node from BST
struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        // Node found
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct TreeNode* temp = getMinNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Search in BST
int searchValue(struct TreeNode* root, int value) {
    if (root == NULL)
        return 0;
    if (value == root->value)
        return 1;
    else if (value < root->value)
        return searchValue(root->left, value);
    else
        return searchValue(root->right, value);
}

// Inorder traversal
void printInorder(struct TreeNode* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->value);
        printInorder(root->right);
    }
}

// Main function
int main() {
    struct TreeNode* root = NULL;

    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        root = insertNode(root, values[i]);
    }

    printf("Inorder traversal (sorted): ");
    printInorder(root);
    printf("\n");

    int key = 60;
    if (searchValue(root, key))
        printf("Element %d found in BST.\n", key);
    else
        printf("Element %d not found in BST.\n", key);

    root = deleteNode(root, 30);

    printf("After deleting 30, inorder traversal: ");
    printInorder(root);
    printf("\n");

    return 0;
}
