#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Function to insert an element at the end of the list
struct node* element(struct node *head, int x) {
    struct node *temp = head;
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = x;
    nnode->next = NULL;

    if (head == NULL) {
        head = nnode;
    } else {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = nnode;
    }
    return head;
}

// Function to add two linked lists and print the result
void addition(struct node *head1, struct node *head2) {
    struct node *temp1 = head1;
    struct node *temp2 = head2;

    printf("Resultant List (Sum):\n");
    while (temp1 || temp2) {
        int sum = 0;
        if (temp1) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2) {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        printf("%d->", sum);
    }
    printf("NULL\n");
}

// Optional: Free memory
void freeList(struct node *head) {
    struct node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    int n, m, x;
    struct node *head1 = NULL, *head2 = NULL;

    // First linked list
    printf("No. of elements in the first linked list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = element(head1, x);
    }

    // Second linked list
    printf("\nNo. of elements in the second linked list: ");
    scanf("%d", &m);
    printf("Enter the elements: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = element(head2, x);
    }

    // Print sum of linked lists
    printf("\n");
    addition(head1, head2);

    // Free memory
    freeList(head1);
    freeList(head2);

    return 0;
}
