#include <stdio.h>
#include <stdlib.h>

// Deletion in Array

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int indDeletion(int arr[], int size, int index){
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    return 1;
    
}

int main()
{
    int arr[100] = {1, 2, 6, 78};
    printf("Before Insertion:\n");
    display(arr, 4);
    indDeletion(arr, 4, 0);
    printf("\nAfter Deletion:\n");
    display(arr, 3);

    return 0;
}