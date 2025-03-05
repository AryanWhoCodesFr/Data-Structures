#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* createLinkedListFromArray(int arr[], int size) {
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

void printFrequency(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    int frequency[1000] = {0}; 

    while (temp != NULL) {
        frequency[temp->data]++;  
        temp = temp->next;
    }

    for (int i = 0; i < 1000; i++) {
        if (frequency[i] > 0) {
            printf("%d  -----  %d\n", i, frequency[i]);
        }
    }
}

int main() {
    int arr[] = {1, 1, 2, 9, 5, 3, 4, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedListFromArray(arr, size);
    printFrequency(head);

    return 0;
}
