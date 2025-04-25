#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insertIntoBST(TreeNode* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value <= root->data)
        root->left = insertIntoBST(root->left, value);
    else
        root->right = insertIntoBST(root->right, value);
    return root;
}

// Global tracking variables for k-th smallest
int nodeCount = 0;
int kthValue = -1;
int foundFlag = 0;

void findKthSmallest(TreeNode* root, int k) {
    if (root == NULL || foundFlag)
        return;
    findKthSmallest(root->left, k);
    nodeCount++;
    if (nodeCount == k) {
        kthValue = root->data;
        foundFlag = 1;
        return;
    }
    findKthSmallest(root->right, k);
}

int main() {
    TreeNode* root = NULL;

    // Sample data
    int elements[] = {1, 2, 4, 9, 7, 11, 5};
    int n = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < n; i++)
        root = insertIntoBST(root, elements[i]);

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    // Reset globals
    nodeCount = 0;
    foundFlag = 0;
    kthValue = -1;

    findKthSmallest(root, k);
    if (foundFlag)
        printf("The %d-th smallest element is %d\n", k, kthValue);
    else
        printf("k is larger than the number of nodes in the tree.\n");

    return 0;
}
