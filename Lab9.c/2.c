#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count all nodes in the tree
int getNodeCount(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + getNodeCount(root->left) + getNodeCount(root->right);
}

// Function to count only the leaf nodes
int getLeafCount(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return getLeafCount(root->left) + getLeafCount(root->right);
}

// Function to determine the height of the tree
int getTreeHeight(struct TreeNode* root) {
    if (root == NULL) return 0;
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    // Building this tree:
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

    printf("Total number of nodes: %d\n", getNodeCount(root));
    printf("Number of leaf nodes: %d\n", getLeafCount(root));
    printf("Height of the tree: %d\n", getTreeHeight(root));

    return 0;
}
