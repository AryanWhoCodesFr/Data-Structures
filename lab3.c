#include <stdio.h>

void apply_box_filter(float grid[][10], int size) {
    // Temporary 3x3 matrix
    float subgrid[3][3];

    // Traverse through each possible 3x3 box...
    for (int row = 0; row < size - 2; row++) {   // Traverse the row.
        for (int col = 0; col < size - 2; col++) {  // Traverse the column up to size-3
            float total = 0;
            
            // Fill the temporary 3x3 matrix and calculate the sum
            for (int r = row; r < row + 3; r++) {
                for (int c = col; c < col + 3; c++) {
                    subgrid[r - row][c - col] = grid[r][c];
                    total += grid[r][c];
                }
            }
            
            // Calculate the average of the 3x3 box as a float
            float mean = total / 9.0;       
            
            // Put the average in the center (diagonal position) of the current 3x3 box
            grid[row + 1][col + 1] = mean;  // Center of the 3x3 box diagonal
        }
    }
}

int main() {
    int size;

    // Get the size of the matrix (size * size)
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    // Ensure the matrix is large enough to fit a 3x3 submatrix
    if (size < 3) {
        printf("Matrix size should be at least 3x3.\n");
        return 0;
    }

    // Declare the matrix dynamically...
    float grid[10][10];

    // Get the matrix elements from the user.
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%f", &grid[i][j]);
        }
    }

    // Display the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.1f ", grid[i][j]);
        }
        printf("\n");
    }

    // Call the function to calculate average and replace the center (diagonal) of 3x3 submatrix
    apply_box_filter(grid, size);

    // Display the modified matrix
    printf("\nModified Matrix with averages in the center of 3x3 submatrices:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.1f ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}




#include<stdio.h>
int main(){
    int size;
    printf("Enter the value of size:");
    scanf("%d",&size);
    int arr[size][size];
    int total=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
    int brr[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&brr[i][j]);
        }
    }
    int result[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            result[i][j]=0;
        }
    }
    for(int i=1;i<size-1;i++){
        for(int j=1;j<size-1;j++){
            total=(arr[i][j]*brr[1][1])+
            (arr[i][j-1]*brr[1][0])+
            (arr[i][j+1]*brr[1][2])+
            (arr[i-1][j-1]*brr[0][0])+
            (arr[i-1][j]*brr[0][1])+
            (arr[i-1][j+1]*brr[0][2])+
            (arr[i+1][j-1]*brr[2][0])+
            (arr[i+1][j]*brr[2][1])+
            (arr[i+1][j+1]*brr[2][2]);
        total=total/9;
        result[i][j]=total;
        total=0;
        }
    }
    printf("Filtered array is\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}




#include<stdio.h>
int sortedArr[9];
void reset_array(int sortedArr[]){
    for(int i=0;i<9;i++){
        (sortedArr[i])=0;
    }
}
void merge_arrays(int left,int right,int mid){
    int left_size=mid-left+1;
    int Left[left_size+1];
    int right_size=right-mid;
    int Right[right_size+1];
    for(int i=0;i<left_size;i++){
        Left[i]=sortedArr[i+left];
    }
    for(int i=0;i<right_size;i++){
        Right[i]=sortedArr[i+mid+1];
    }
    Left[left_size]=999999999;
    Right[right_size]=999999999;
    int left_index=0;
    int right_index=0;
    for(int i=left;i<=right;++i){
        if(Left[left_index]<=Right[right_index]){
            sortedArr[i]=Left[left_index];
            left_index++;
        }
        else{
            sortedArr[i]=Right[right_index];
            right_index++;
        }
    }
}
int find_median(int start,int end){
    int mid_index=(start+end)/2;
    if(end%2==0){
        return sortedArr[mid_index];
    }
    else{
        return (sortedArr[mid_index]+sortedArr[mid_index+1])/2;
    }
}
int sort_and_find_median(int left,int right){
    if(left==right) return 1;
    int mid=(left+right)/2;
    sort_and_find_median(left,mid);
    sort_and_find_median(mid+1,right);
    merge_arrays(left,right,mid);
    int median_value = find_median(0,8);
    return median_value;
}
int main(){
    int size;
    printf("Enter the value of size:");
    scanf("%d",&size);
    int matrix[size][size];
    int total=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int result[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            result[i][j]=0;
        }
    }

    reset_array(sortedArr);
    printf("\n");
    for(int i=1;i<size-1;i++){
        for(int j=1;j<size-1;j++){
            sortedArr[0]=matrix[i-1][j-1];
            sortedArr[1]=matrix[i-1][j];
            sortedArr[2]=matrix[i-1][j+1];
            sortedArr[3]=matrix[i][j-1];
            sortedArr[4]=matrix[i][j];
            sortedArr[5]=matrix[i][j+1];
            sortedArr[6]=matrix[i+1][j-1];
            sortedArr[7]=matrix[i+1][j];
            sortedArr[8]=matrix[i+1][j+1];

            result[i][j]= sort_and_find_median(0,8);
            reset_array(sortedArr);
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}




#include <stdio.h>
#include <stdbool.h>
void display_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void sort_selection(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min_val = 99999999, index;
        for (int j = i; j < size; j++)
        {
            if (data[j] < min_val)
            {
                min_val = data[j];
                index = j;
            }
        }
        int temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
}
void sort_insertion(int dataset[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j >= 1 && dataset[j] < dataset[j - 1])
        {
            int temp = dataset[j];
            dataset[j] = dataset[j - 1];
            dataset[j - 1] = temp;
            j--;
        }
    }
}
int main(){
    int size = 7;
    int array1[7] = {1, 2, 3, 4, 5, 6, 7};
    int array2[7] = {1, 2, 3, 4, 5, 6, 7};
    // selection sort
    sort_selection(array2, size);
    printf("Selection sort array is:\n");
    display_array(array2, size);

    // insertion sort
    sort_insertion(array1, size);
    printf("Insertion sort array is:\n");
    display_array(array1, size);
    return 0;
}




#include <stdio.h>
#include <stdbool.h>
void display_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}
void sort_selection_alternate(int data[], int size)
{
    for (int i = 0; i < size; i=i+2)
    {
        int min_value = 99999999, index;
        for (int j = i; j < size; j=j+2)
        {
            if (data[j] < min_value)
            {
                min_value = data[j];
                index = j;
            }
        }
        int temp = data[i];
        data[i] = data[index];
        data[index] = temp;
    }
    printf("Selection:\n");
    for(int i=0;i<size;i=i+2){
        printf("%d ",data[i]);
    }
    printf("\n");
}
void sort_insertion_alternate(int dataset[], int size)
{
    for (int i = 3; i < size; i=i+2)
    {
        int j = i;
        while (j >= 3 && dataset[j] < dataset[j - 2])
        {
            int temp = dataset[j];
            dataset[j] = dataset[j - 2];
            dataset[j - 2] = temp;
            j=j-2;
        }
    }
    printf("Insertion:\n");
    for(int i=1;i<size;i=i+2){
        printf("%d ",dataset[i]);
    }
    printf("\n");
}
int main(){
    int size = 9;
    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort_selection_alternate(array, size);
    sort_insertion_alternate(array, size);
    printf("Sorted array is:\n");
    display_array(array, size);
    return 0;
}




#include <stdio.h>
#include <stdbool.h>
void print_list(int list[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n\n");
}
void alternate_selection_sort(int values[], int length)
{
    for (int i = 0; i < length; i=i+2)
    {
        int min_val = 99999999, pos;
        for (int j = i; j < length; j=j+2)
        {
            if (values[j] < min_val)
            {
                min_val = values[j];
                pos = j;
            }
        }
        int temp = values[i];
        values[i] = values[pos];
        values[pos] = temp;
    }
    printf("Selection:");
    for(int i=0;i<length;i=i+2){
        printf("%d ",values[i]);
    }
    printf("\n");
}
void alternate_insertion_sort(int numbers[], int length)
{
    for (int i = 3; i < length; i=i+2)
    {
        int j = i;
        while (j >= 3 && numbers[j] < numbers[j - 2])
        {
            int temp = numbers[j];
            numbers[j] = numbers[j - 2];
            numbers[j - 2] = temp;
            j=j-2;
        }
    }
    printf("Insertion:");
    for(int i=1;i<length;i=i+2){
        printf("%d ",numbers[i]);
    }
    printf("\n");
}
int partition_array(int list[], int start, int end)
{
    int pivot = list[start];
    int i = start, j = end;
    while (i < j)
    {
        while (i <= end && list[i] <= pivot)
            i++;
        while (list[j] > pivot)
            j--;
        if (i < j)
        {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    int temp = list[start];
    list[start] = list[j];
    list[j] = temp;
    return j;
}
void quick_sort_array(int list[], int start, int end)
{
    if (start < end)
    {
        int j = partition_array(list, start, end);
        quick_sort_array(list, start, j - 1);
        quick_sort_array(list, j + 1, end);
    }
}
int main(){
    int length = 9;
    int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    alternate_selection_sort(list, length);
    alternate_insertion_sort(list, length);
    quick_sort_array(list, 0, length - 1);
    printf("Sorted list after Quick Sort:\n");
    print_list(list, length);
    return 0;
}




#include <stdio.h>

// Counters for basic operations
int comparison_counter = 0;  // Number of comparisons
int swap_counter = 0;  // Number of swaps

void print_list(int list[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int partition_array(int list[], int start, int end) {
    int pivot = list[start];
    int i = start, j = end;

    while (i < j) {
        while (i <= end && list[i] <= pivot) {
            comparison_counter++; // Counting comparisons
            i++;
        }
        while (list[j] > pivot) {
            comparison_counter++; // Counting comparisons
            j--;
        }
        if (i < j) {
            int temp = list[i];
            list[i] = list[j];
            list[j] = temp;
            swap_counter++;  // Counting swaps
        }
    }
    int temp = list[start];
    list[start] = list[j];
    list[j] = temp;
    swap_counter++;  // Counting the final pivot swap
    return j;
}

void quick_sort_array(int list[], int start, int end) {
    if (start < end) {
        int j = partition_array(list, start, end);
        quick_sort_array(list, start, j - 1);
        quick_sort_array(list, j + 1, end);
    }
}

int main() {
    int length = 9;
    int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    quick_sort_array(list, 0, length - 1);

    printf("Sorted list after Quick Sort:\n");
    print_list(list, length);

    // Print the counts of basic operations
    printf("Total comparisons: %d\n", comparison_counter);
    printf("Total swaps: %d\n", swap_counter);

    return 0;
}




#include <stdio.h>

// Counters for basic operations
int comparison_counter = 0;  // Number of comparisons

void print_list(int list[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void merge(int list[], int start, int mid, int end) {
    int left_size = mid - start + 1;
    int right_size = end - mid;
    int left[left_size + 1], right[right_size + 1];
    
    for (int i = 0; i < left_size; i++) {
        left[i] = list[start + i];
    }
    for (int i = 0; i < right_size; i++) {
        right[i] = list[mid + 1 + i];
    }
    
    left[left_size] = 999999999;
    right[right_size] = 999999999;
    
    int left_index = 0, right_index = 0;
    for (int i = start; i <= end; i++) {
        comparison_counter++;
        if (left[left_index] <= right[right_index]) {
            list[i] = left[left_index];
            left_index++;
        } else {
            list[i] = right[right_index];
            right_index++;
        }
    }
}

void merge_sort_array(int list[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort_array(list, start, mid);
        merge_sort_array(list, mid + 1, end);
        merge(list, start, mid, end);
    }
}

int main() {
    int length = 9;
    int list[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    merge_sort_array(list, 0, length - 1);
    
    printf("Sorted list after Merge Sort:\n");
    print_list(list, length);
    
    // Print the counts of basic operations
    printf("Total comparisons: %d\n", comparison_counter);
    
    return 0;
}

