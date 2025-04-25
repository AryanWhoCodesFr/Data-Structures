#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* initNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int findInorderIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* constructTreeFromPreIn(int inorder[], int preorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    int currentVal = preorder[*preIndex];
    (*preIndex)++;
    struct Node* node = initNode(currentVal);

    if (start == end)
        return node;

    int inIndex = findInorderIndex(inorder, start, end, currentVal);

    node->left = constructTreeFromPreIn(inorder, preorder, start, inIndex - 1, preIndex);
    node->right = constructTreeFromPreIn(inorder, preorder, inIndex + 1, end, preIndex);

    return node;
}

void printInorder(struct Node* root) {
    if (root) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

void printPreorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3};
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    struct Node* root = constructTreeFromPreIn(inorder, preorder, 0, n - 1, &preIndex);

    printf("Constructed Inorder Traversal: ");
    printInorder(root);
    printf("\n");

    printf("Constructed Preorder Traversal: ");
    printPreorder(root);
    printf("\n");

    return 0;
}
