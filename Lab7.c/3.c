#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prv;
} node;

node* createDoublyLinkedList(int arr[], int size) {
    node *head = NULL, *temp = NULL;
    for (int i = 0; i < size; i++) {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = arr[i];
        newNode->next = NULL;
        newNode->prv = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prv = temp;
            temp = newNode;
        }
    }
    return head;
}

void displayList(node *head) {
    node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* insertAtStart(node *head) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = 111;
    newNode->next = head;
    newNode->prv = NULL;

    if (head) {
        head->prv = newNode;
    }

    return newNode;
}

node* insertAtEnd(node *head) {
    if (head == NULL) {
        return insertAtStart(head);
    }
    node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = 111;
    newNode->next = NULL;
    newNode->prv = temp;

    temp->next = newNode;
    return head;
}

node* insertAtPosition(node *head, int k) {
    if (k == 1) {
        return insertAtStart(head);
    }

    node *temp = head;
    int count = 1;

    while (temp && count < k - 1) {
        temp = temp->next;
        count++;
    }

    if (!temp || !temp->next) {
        return insertAtEnd(head);
    }

    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = 111;
    newNode->next = temp->next;
    newNode->prv = temp;

    if (temp->next) {
        temp->next->prv = newNode;
    }
    temp->next = newNode;

    return head;
}

int main() {
    int arr[] = {101, 202, 303, 404, 505, 606, 707, 808, 909};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = createDoublyLinkedList(arr, size);

    int n = -1;
    while (n != 0) {
        printf("\n0 - Exit\n1 - Insert at Start\n2 - Insert at End\n3 - Insert at Position\n");
        printf("Enter choice: ");
        scanf("%d", &n);

        switch (n) {
            case 0:
                printf("Program ends\n");
                break;
            case 1:
                head = insertAtStart(head);
                displayList(head);
                break;
            case 2:
                head = insertAtEnd(head);
                displayList(head);
                break;
            case 3:
                printf("Enter position: ");
                int k;
                scanf("%d", &k);
                head = insertAtPosition(head, k);
                displayList(head);
                break;
            default:
                printf("Invalid input, try again!\n");
        }
    }
    return 0;
}
