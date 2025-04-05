#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a circular linked list from an array
struct node* createCircularList(int arr[], int size) {
    struct node *head = NULL, *temp = NULL;
    for (int i = 0; i < size; i++) {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
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
    if (temp) temp->next = head; // Make it circular
    return head;
}

// Function to insert a node at start, end or specific position
struct node* insertInCircularList(struct node *head, int n, int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;

    struct node *temp = head;

    // Insert at beginning
    if (n == 0) {
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        return newNode;
    }

    // Insert at end
    else if (n == -1) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        return head;
    }

    // Insert at nth position
    else {
        for (int i = 1; i < n - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        struct node *temp2 = temp->next;
        temp->next = newNode;
        newNode->next = temp2;
        return head;
    }
}

// Function to print circular linked list
void displayCircularList(struct node *head) {
    if (!head) return;
    struct node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head)\n");
}

int main() {
    int arr[] = {111, 222, 333, 444, 555, 666, 777, 888};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct node *head = NULL;
    head = createCircularList(arr, n);

    bool check = true;
    while (check) {
        printf("\n0 - Exit\n1 - Insert at Start\n2 - Insert at End\n3 - Insert at Position\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            check = false;
            printf("Program terminated.\n");
            break;
        }

        printf("Enter value to insert: ");
        int x;
        scanf("%d", &x);

        switch (choice) {
            case 1:
                head = insertInCircularList(head, 0, x);
                n++;
                displayCircularList(head);
                break;
            case 2:
                head = insertInCircularList(head, -1, x);
                n++;
                displayCircularList(head);
                break;
            case 3:
                printf("Enter the position (1 to %d): ", n + 1);
                int pos;
                scanf("%d", &pos);
                if (pos >= 1 && pos <= n + 1) {
                    head = insertInCircularList(head, pos, x);
                    n++;
                    displayCircularList(head);
                } else {
                    printf("Invalid position! Position should be between 1 and %d.\n", n + 1);
                }
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
