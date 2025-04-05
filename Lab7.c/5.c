#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct node {
    int data;
    struct node* next;
    struct node* prv;
};

// Function to create a circular doubly linked list from an array
struct node* createCircularDoublyList(int arr[], int size) {
    struct node* head = NULL;
    struct node* temp = NULL;
    
    for (int i = 0; i < size; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = NULL;
        newNode->prv = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prv = temp;
            temp = newNode;
        }
    }

    // Making it circular
    temp->next = head;
    head->prv = temp;

    return head;
}

// Function to insert a node at start, end, or a specific position
struct node* insertInCircularDoublyList(struct node* head, int n, int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    
    struct node* temp = head;

    // Insert at start
    if (n == 0) {
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        newNode->prv = temp;
        temp->next = newNode;
        head->prv = newNode;
        return newNode;
    }
    
    // Insert at end
    else if (n == -1) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prv = temp;
        newNode->next = head;
        head->prv = newNode;
        return head;
    }

    // Insert at nth position
    else {
        for (int i = 1; i < n - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        struct node* temp2 = temp->next;
        temp->next = newNode;
        newNode->prv = temp;
        newNode->next = temp2;
        temp2->prv = newNode;
        return head;
    }
}

// Function to print the circular doubly linked list
void displayCircularDoublyList(struct node* head) {
    if (!head) return;
    
    struct node* temp = head;
    printf("Doubly Circular Linked List: ");
    
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

int main() {
    int arr[] = {101, 202, 303, 404, 505, 606, 707, 808};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    struct node* head = NULL;
    head = createCircularDoublyList(arr, n);

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
                head = insertInCircularDoublyList(head, 0, x);
                n++;
                displayCircularDoublyList(head);
                break;
            case 2:
                head = insertInCircularDoublyList(head, -1, x);
                n++;
                displayCircularDoublyList(head);
                break;
            case 3:
                printf("Enter the position (1 to %d): ", n + 1);
                int pos;
                scanf("%d", &pos);
                if (pos >= 1 && pos <= n + 1) {
                    head = insertInCircularDoublyList(head, pos, x);
                    n++;
                    displayCircularDoublyList(head);
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
