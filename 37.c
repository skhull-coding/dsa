#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        int temp;

        do
        {
            while (arr[i] < pivot)
            {
                i++;
            }
            while (arr[j] > pivot)
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        } while (i < j);

        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int arr[] = {2345, 23, 45234, 5, 2345, 23, 64, 56, 457, 34, 123, 12, 4, 1, 765, 8};

    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}