#include <stdio.h>
#include <stdlib.h>

// Learnt insertion code with some optimization
// understood it

void insertionSort(int arr[], int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 1, 2, 8, 9, 0};

    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);
    return 0;
}