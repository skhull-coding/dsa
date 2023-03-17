#include <stdio.h>
#include <stdlib.h>

// Selection sort by myself

int x = 0;

void selectionSort(int arr[], int size)
{
    int min, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            x++;
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
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

    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);

    printf("X : %d", x);

    return 0;
}