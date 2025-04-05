#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};

// Convert array to singly linked list
struct node* createSinglyLinkedList(struct node* head, int arr[], int n) {
    struct node* temp = head;
    for (int i = 0; i < n; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// Print singly linked list
void displaySinglyLinkedList(struct node* head) {
    struct node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n\n");
}

// Merge two singly linked lists
struct node* mergeSinglyLinkedLists(struct node* head1, struct node* head2) {
    struct node* temp = head1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    int arr[] = {1001, 1002, 1003, 1004, 1005};
    int brr[] = {2001, 2002, 2003, 2004};

    struct node* head1 = NULL;
    head1 = createSinglyLinkedList(head1, arr, 5);
    displaySinglyLinkedList(head1);

    struct node* head2 = NULL;
    head2 = createSinglyLinkedList(head2, brr, 4);
    displaySinglyLinkedList(head2);

    head1 = mergeSinglyLinkedLists(head1, head2);
    displaySinglyLinkedList(head1);

    return 0;
}
