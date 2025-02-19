#include <stdio.h>

void bubbleSort(int *arr, int size)
{
    int swapFlag = 0;
    for (int idx = 0; idx < size - 1; idx++)
    {
        if (arr[idx + 1] < arr[idx])
        {
            swapFlag = 1;
        }
    }

    if (swapFlag == 1)
    {
        int sortedFlag = 0;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp =arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            sortedFlag = 0;

            for (int idx = 0; idx < size - 1; idx++)
            {
                if (arr[idx + 1] < arr[idx])
                {
                    sortedFlag = 1;
                }
            }

            if (sortedFlag == 0)
            {
                break;
            }

            printf("Pass %d\n", i + 1);
        }

        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        printf("Array is already sorted\n");

        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int elements[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter element no. %d: ", i + 1);
        scanf("%d", &elements[i]);
    }

    bubbleSort(elements, size);

    return 0;
}