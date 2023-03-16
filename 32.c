#include <stdio.h>
#include <stdlib.h>

int x = 0, y = 0;

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            x += 1;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSort2(int arr[], int size)
{
    int min, isIncreasing = 0, p = 1;

    for (int i = 0; i < size - 1; i++)
    {
        if (isIncreasing)
        {
            break;
        }
        p = 1;
        for (int j = 0; j < size - 1 - i; j++)
        {
            y += 1;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            if (j == 0)
            {
                min = arr[j];
            }
            if (p && j!=0)
            {
                if ((arr[j] >= arr[j - 1]))
                {
                    if (arr[j] >= min && arr[j - 1] >= min)
                    {
                        isIncreasing = 1;
                    }
                    else
                    {
                        isIncreasing = 0;
                        p = 0;
                    }
                }
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 5,4,1,3, 6, 7, 9,8, 890};
    int arr2[] = {1, 2, 3, 5,4,1,3, 6, 7, 9,8, 890};
    int size = sizeof(arr) / sizeof(int);
    bubbleSort(arr, size);
    bubbleSort2(arr2, size);

    printf("First  : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("X : %d\n\n", x);

    printf("Second : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    printf("Y : %d\n\n", y);

    return 0;
}