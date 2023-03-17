#include <stdio.h>
#include <stdlib.h>

// Count sort
void countSort(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    int *auxArray = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i < max + 1; i++)
    {
        auxArray[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        auxArray[arr[i]] += 1;
    }
    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        while (auxArray[i] != 0)
        {
            arr[j] = i;
            auxArray[i]--;
            j++;
        }
    }
    free(auxArray);
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
    int arr[] = {1,2,3,4};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    countSort(arr, size);
    printArray(arr, size);

    return 0;
}