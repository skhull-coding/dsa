#include <stdio.h>
#include <stdlib.h>

typedef struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
} mArr;

void createArr(mArr *arr, int tSize, int uSize)
{
    arr->total_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

// Traversal to Array
void showArr(mArr *arr)
{
    printf("Array : ");
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ", (arr->ptr)[i]);
    }
    printf("\n");
}

void setValueToArr(mArr *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter the value for the index value %d : ", i);
        scanf("%d", &((arr->ptr)[i]));
    }
}

int insertToArr(mArr *arr, int index, int element)
{
    if (arr->used_size >= arr->total_size)
    {
        return 0;
    }
    else
    {
        for (int i = arr->used_size - 1; i >= index; i--)
        {
            (arr->ptr)[i + 1] = (arr->ptr)[i];
        }
        (arr->ptr)[index] = element;
        arr->used_size++;
        return 1;
    }
    return 0;
}

int main()
{
    mArr arr;
    createArr(&arr, 20, 3);
    setValueToArr(&arr);
    showArr(&arr);
    if (insertToArr(&arr, 2, 20))
    {
        showArr(&arr);
    }
    else
    {
        printf("Inserting couldn't be done!!");
    }

    return 0;
}