#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = NULL;

    Node* mover = head;
    for (int i = 1; i < size; i++) {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = NULL;
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void mergeAndSortLinkedLists(Node* head1, Node* head2) {
    if (head1 == NULL) {
        printLinkedList(head2);
        return;
    }
    if (head2 == NULL) {
        printLinkedList(head1);
        return;
    }

    Node* temp = head1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head2; 

    temp = head1;
    int values[1000], count = 0; 
    while (temp) {
        values[count++] = temp->data;
        temp = temp->next;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (values[i] > values[j]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }

    temp = head1;
    for (int i = 0; i < count; i++) {
        temp->data = values[i];
        temp = temp->next;
    }

    printLinkedList(head1);
}

int main() {
    int arr1[] = {1, 9, 20, 31, 50};
    int arr2[] = {21, 54, 98, 34, 2};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    Node* head1 = arrayToLinkedList(arr1, size1);
    Node* head2 = arrayToLinkedList(arr2, size2);

    mergeAndSortLinkedLists(head1, head2);

    return 0;
}
