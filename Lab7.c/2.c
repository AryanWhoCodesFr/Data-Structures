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
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

node* deleteFromStart(node *head) {
    if (head == NULL) return NULL;
    node *temp = head;
    head = head->next;
    if (head) head->prv = NULL;
    free(temp);
    return head;
}

node* deleteFromEnd(node *head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    node *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    if (temp->prv) temp->prv->next = NULL;
    free(temp);
    return head;
}

node* deleteAtPosition(node *head, int k) {
    if (head == NULL || (head->next == NULL && k == 1)) {
        free(head);
        return NULL;
    }

    if (k == 1) return deleteFromStart(head);

    node *temp = head;
    int count = 1;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) return head; 

    if (temp->next == NULL) return deleteFromEnd(head); 

    node *prevNode = temp->prv;
    node *nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prv = prevNode;
    free(temp);

    return head;
}

int main() {
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int size = sizeof(arr) / sizeof(arr[0]);
    node *head = createDoublyLinkedList(arr, size);

    int n = -1;
    while (n != 0) {
        printf("0 - Exit\n1 - Delete at Start\n2 - Delete at End\n3 - Delete at Position\n");
        printf("Enter choice: ");
        scanf("%d", &n);

        switch (n) {
            case 0:
                printf("Program ends\n");
                break;
            case 1:
                head = deleteFromStart(head);
                displayList(head);
                break;
            case 2:
                head = deleteFromEnd(head);
                displayList(head);
                break;
            case 3:
                printf("Enter position: ");
                int k;
                scanf("%d", &k);
                head = deleteAtPosition(head, k);
                displayList(head);
                break;
            default:
                printf("Invalid input, try again!\n");
        }
    }
    return 0;
}
