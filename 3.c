#include <stdio.h>
#include <stdlib.h>

typedef struct myArray
{
    int total_size;
    int used_size;

    int *ptr = NULL;

} mArr;

void createArray(mArr *arr, int tSize, int uSize)
{
    // (*arr).total_size = tSize;
    // (*arr).used_size = uSize;

    // (*arr).ptr = (int *)malloc(tSize * sizeof(int));

    arr->total_size = tSize; // shorthand for derefrencing and then getting the values
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(mArr *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Element at position %d is %d\n", i, (arr->ptr)[i]);
    }
}

void setValue(mArr *arr)
{
    int temp;
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &temp);
        (arr->ptr)[i] = temp;
    }
}

int main()
{
    mArr marks;
    createArray(&marks, 100, 2);
    printf("----We are running setVal now----\n");
    setValue(&marks);
    printf("----We are running show now----\n");
    show(&marks);

    return 0;
}