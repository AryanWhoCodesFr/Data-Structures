#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Push operation: insert at the beginning
struct node* push(struct node* head, int x) {
    struct node* nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = x;
    nnode->next = head;
    printf("Pushed %d onto the stack.\n", x);
    return nnode;
}

// Pop operation: remove from the beginning
struct node* pop(struct node* head) {
    if (head == NULL) {
        printf("Stack underflow! No element to remove.\n");
    } else {
        struct node* temp = head;
        printf("Popped %d from the stack.\n", temp->data);
        head = head->next;
        free(temp);
    }
    return head;
}

// Display current stack
void display(struct node* head) {
    if (head == NULL) {
        printf("Stack is empty.\n");
    } else {
        struct node* temp = head;
        printf("Stack (Top to Bottom): ");
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct node* head = NULL;
    int running = 1;

    while (running) {
        int option;
        printf("\n--- Stack Menu ---\n");
        printf("0 - Exit\n1 - Push\n2 - Pop\n3 - Display\nEnter choice: ");
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
                running = 0;
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
