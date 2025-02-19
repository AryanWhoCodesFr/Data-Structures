#include <stdio.h>
#include <stdlib.h>

int swap(int a, int b){
    int temp=a;
    a=b;
    b=temp;
}

int partition(int*arr, int st, int ed) {
    int pivot = arr[st];
    int i = st + 1;
    int j = ed;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[st], arr[j]);

    return j;
}

void quicksort(int *arr, int st, int ed) {
    if (st < ed) {
        int pivot = partition(arr, st, ed);
        quicksort(arr, st, pivot - 1);
        quicksort(arr, pivot + 1, ed);
    }
}

int main() {
    int arr[10];
    int n = 10;

    printf("Enter 10 elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}