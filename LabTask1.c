#include <stdio.h>
// Display all elements of the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Add an element at the start of the array
void addAtStart(int arr[], int *size, int value, int maxSize) {
    if (*size >= maxSize) {
        printf("Insertion failed: Array is full.\n");
        return;
    }
    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    (*size)++;
}
// Add an element at the end of the array
void addAtEnd(int arr[], int *size, int value, int maxSize) {
    if (*size >= maxSize) {
        printf("Insertion failed: Array is full.\n");
        return;
    }
    arr[*size] = value;
    (*size)++;
}
// Insert an element at a specified position
void addAtPosition(int arr[], int *size, int pos, int value, int maxSize) {
    if (*size >= maxSize) {
        printf("Insertion failed: Array is full.\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*size)++;
}
// Remove the first element of the array
void removeFirst(int arr[], int *size) {
    if (*size == 0) {
        printf("Deletion failed: Array is empty.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
// Remove the last element of the array
void removeLast(int arr[], int *size) {
    if (*size == 0) {
        printf("Deletion failed: Array is empty.\n");
        return;
    }
    (*size)--;
}
// Remove an element at a specified position
void removeAtPosition(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
// Perform a linear search for a value in the array
void findElement(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Value found at index %d.\n", i);
            return;
        }
    }
    printf("Value not found in the array.\n");
}
// Sort the array in ascending order
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Sort elements present at even positions
void sortEvenPositions(int arr[], int size) {
    for (int i = 0; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Sort elements present at odd positions
void sortOddPositions(int arr[], int size) {
    for (int i = 1; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Sort all even numbers in the array
void sortEvenValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Sort all odd numbers in the array
void sortOddValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] % 2 != 0 && arr[j] % 2 != 0 && arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int size, maxSize;
    printf("Enter the maximum array size: ");
    scanf("%d", &maxSize);
    int arr[maxSize];
    printf("Enter the number of initial elements: ");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Initial Array: ");
    printArray(arr, size);
    // Perform operations
    addAtStart(arr, &size, 10, maxSize);
    printf("After adding 10 at the start: ");
    printArray(arr, size);
    addAtEnd(arr, &size, 20, maxSize);
    printf("After adding 20 at the end: ");
    printArray(arr, size);
    addAtPosition(arr, &size, 2, 30, maxSize);
    printf("After adding 30 at position 2: ");
    printArray(arr, size);
    removeFirst(arr, &size);
    printf("After removing the first element: ");
    printArray(arr, size);
    removeLast(arr, &size);
    printf("After removing the last element: ");
    printArray(arr, size);
    removeAtPosition(arr, &size, 1);
    printf("After removing element at position 1: ");
    printArray(arr, size);
    findElement(arr, size, 30);
    sortArray(arr, size);
    printf("After sorting the array: ");
    printArray(arr, size);
    sortEvenPositions(arr, size);
    printf("After sorting even positions: ");
    printArray(arr, size);
    sortOddPositions(arr, size);
    printf("After sorting odd positions: ");
    printArray(arr, size);
    sortEvenValues(arr, size);
    printf("After sorting even values: ");
    printArray(arr, size);
    sortOddValues(arr, size);
    printf("After sorting odd values: ");
    printArray(arr, size);
    return 0;
}