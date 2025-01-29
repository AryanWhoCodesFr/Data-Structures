//Calculate the moving average of the given array elements
#include <stdio.h>

void calculate_moving_average(int arr[], int size, int window_size, double output[]) {
    double current_window_sum = 0;
    for (int i = 0; i < window_size; i++) {
        current_window_sum += arr[i];
    }
    output[0] = current_window_sum / window_size;

    for (int i = window_size; i < size; i++) {
        current_window_sum += arr[i] - arr[i - window_size];
        output[i - window_size + 1] = current_window_sum / window_size;
    }
}

void display_array(double arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int window_size = 3;
    double moving_avg[size - window_size + 1];
    calculate_moving_average(arr, size, window_size, moving_avg);
    display_array(moving_avg, size - window_size + 1);
    return 0;
}
//Counting of the swaps
#include <stdio.h>

void bubble_sort_and_count_swaps(int arr[], int length) {
    int temp, swap_count = 0;
    
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count++;
            }
        }
    }
    
    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of swaps: %d\n", swap_count);
}

int main() {
    int arr[10], length;

    printf("Enter the number of elements: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubble_sort_and_count_swaps(arr, length);

    return 0;
}
//Removing duplicates from the given array
#include <stdio.h>

void remove_duplicates_from_array(int arr[], int *size) {
    for (int i = 0; i < *size; i++) {
        for (int j = i + 1; j < *size; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < *size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*size)--;
                j--;
            }
        }
    }
}

void display_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10], length;

    printf("Enter the number of elements: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    remove_duplicates_from_array(arr, &length);
    
    printf("Array after removing duplicates: ");
    display_array(arr, length);
    
    return 0;
}
//Sorting the array(using bubble sorting technique)
#include <stdio.h>

void sort_array_bubble(int arr[], int length) {
    int temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display_array(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10], length;

    printf("Enter the number of elements: ");
    scanf("%d", &length);

    printf("Enter %d elements: ", length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    sort_array_bubble(arr, length);
    
    printf("Sorted array: ");
    display_array(arr, length);
    
    return 0;
}
//Finding the Kth largest term from the array elements
#include <stdio.h>

void find_kth_largest(int arr[], int length, int k) {
    int temp;
    for (int i = 0; i < k; i++) {
        int max_index = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }

        if (max_index != i) {
            temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
    }

    printf("The %d-th largest element is: %d\n", k, arr[k - 1]);
}

int main() {
    int arr[100], length, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    find_kth_largest(arr, length, k);

    return 0;
}
//Applying insertion sort and counting ..
#include <stdio.h>

void insertion_sort_and_count(int arr[], int length) {
    int temp, insertion_count = 0;

    for (int i = 1; i < length; i++) {
        temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
            insertion_count++;
        }
        arr[j + 1] = temp;
    }

    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Number of insertions: %d\n", insertion_count);
}

int main() {
    int arr[10], length;

    printf("Enter the number of elements: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    insertion_sort_and_count(arr, length);

    return 0;
}
//Counting the element frequency ..
#include <stdio.h>

void count_element_frequency(int arr[], int length) {
    int count;
    for (int i = 0; i < length; i++) {
        count = 1;
        if (arr[i] == -1) continue;
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1;
            }
        }
        printf("%d occurs %d times\n", arr[i], count);
    }
}

int main() {
    int arr[100], length;

    printf("Enter the number of elements: ");
    scanf("%d", &length);

    printf("Enter %d elements: ", length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    count_element_frequency(arr, length);

    return 0;
}


















