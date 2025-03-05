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

Node* removeDuplicates(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    int frequency[1000] = {0}; 
    int uniqueValues[1000], uniqueCount = 0;

    while (temp != NULL) {
        frequency[temp->data]++;  
        temp = temp->next;
    }

    for (int i = 0; i < 1000; i++) {
        if (frequency[i] > 0) {
            uniqueValues[uniqueCount++] = i;
        }
    }

    temp = head;
    for (int i = 0; i < uniqueCount; i++) {
        temp->data = uniqueValues[i];
        if (i < uniqueCount - 1) {
            temp = temp->next;
        }
    }
    temp->next = NULL;
    return head;
}

int main() {
    int arr[] = {2, 34, 24, 32, 69, 45, 46, 88, 88};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedListFromArray(arr, size);
    head = removeDuplicates(head);
    printList(head);

    return 0;
}
