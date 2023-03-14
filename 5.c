#include <stdio.h>
#include <stdlib.h>

// Insertion in Array

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int indInsertion(int arr[], int size, int capacity, int element, int index){
    if (size>=capacity){
        printf("Size is full. Cannot insert");
        return 0;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
    
}

int main()
{
    int arr[100] = {1, 2, 6, 78};
    printf("Before Insertion:\n");
    display(arr, 4);
    indInsertion(arr, 4, 100, 45, 3);
    printf("\nAfter Insertion:\n");
    display(arr, 5);

    return 0;
}