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

int main() {
    int arr[] = {43, 5, 23, 7, 77, 34, 573, 91, 62};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = arrayToLinkedList(arr, size);
    printLinkedList(head);

    return 0;
}




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

Node* reverseLinkedList(Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main() {
    int arr[] = {43, 5, 23, 7, 77, 34, 573, 91, 62};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedListFromArray(arr, size);

    head = reverseLinkedList(head);
    printList(head);

    return 0;
}




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

Node* reverseLinkedList(Node* head) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main() {
    int arr[] = {66, 23, 29, 23, 32, 49, 69, 24, 21};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedListFromArray(arr, size);

    head = reverseLinkedList(head);
    printList(head);

    return 0;
}
