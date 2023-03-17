#include <stdio.h>
#include <stdlib.h>

// Insertion sort by me
// learned the concept

int x = 0, y = 0;

void insertionSort(int arr[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        j = i;
        while (arr[j] < arr[j - 1] && j > 0)
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
            x++;
        }
    }
}
void insertionSort2(int arr[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        j = i;
        while (arr[j] < arr[j - 1] && j > 0)
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
            y++;
        }
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
    int arr2[] = {9, 8, 7, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);
    insertionSort2(arr2, size);
    printArray(arr, size);

    printf("X : %d\nY: %d\n", x, y);
    return 0;
}