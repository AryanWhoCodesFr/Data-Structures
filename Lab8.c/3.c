#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prv;
};

// Push: Add at the beginning
struct node* push(struct node* head, int x) {
    struct node* nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = x;
    nnode->next = head;
    nnode->prv = NULL;

    if (head != NULL) {
        head->prv = nnode;
    }

    head = nnode;
    printf("Pushed: %d\n", x);
    return head;
}

// Pop: Remove from the beginning
struct node* pop(struct node* head) {
    if (head == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return NULL;
    }

    struct node* temp = head;
    int popped_value = temp->data;
    head = head->next;

    if (head != NULL) {
        head->prv = NULL;
    }

    free(temp);
    printf("Popped: %d\n", popped_value);
    return head;
}

// Display the stack
void display(struct node* head) {
    if (head == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct node* temp = head;
    printf("Stack (Top to Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int m = 1;

    while (m) {
        int option;
        printf("\n--- Stack Menu (Doubly Linked List) ---\n");
        printf("0 - Exit\n1 - Push\n2 - Pop\n3 - Display\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int k;
                printf("Enter value to push: ");
                scanf("%d", &k);
                head = push(head, k);
                break;
            }
            case 2:
                head = pop(head);
                break;
            case 3:
                display(head);
                break;
            case 0:
                m = 0;
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
