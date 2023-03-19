#include <stdio.h>
#include <stdlib.h>

// Array ADT implementation practice

// Array ADT
// Data - Arrays from dynamic or static mith maxsize fixed

// Operations -
// Insert(-), delete(-), search(-), sort(-), push(-), pop(-), shift(-), unshift(-), first(-), end(-), isfull(-), isempty(-), creation(-), deletion(-), increasemaxcapacity(-)

typedef struct Array
{
    int maxSize, usedSize;
    int *array;
} Array;
typedef Array *pArray;

pArray createArray(int maxCapacity)
{
    pArray arr = (pArray)malloc(sizeof(Array));
    arr->maxSize = maxCapacity;
    arr->usedSize = 0;
    arr->array = (int *)malloc(maxCapacity * sizeof(int));
    return arr;
}

void clearArray(pArray array)
{
    if (array != NULL)
    {
        free(array->array);
        array->array = NULL;
        free(array);
        array = NULL;
    }
}

int isFull(pArray array)
{
    return array->usedSize == array->maxSize;
}

int isEmpty(pArray array)
{
    return array->usedSize == 0;
}

void insert(pArray array, int index, int data)
{
    if (!isFull(array) && index <= array->usedSize)
    {
        for (int i = array->usedSize; i > index; i--)
        {
            (array->array)[i] = (array->array)[i - 1];
        }
        (array->array)[index] = data;
        array->usedSize++;
    }
}

void push(pArray array, int data)
{
    if (!isFull(array))
    {
        (array->array)[array->usedSize] = data;
        array->usedSize++;
    }
}

int deleteByIndex(pArray array, int index)
{
    if (!isEmpty(array) && index < array->usedSize)
    {
        int value = (array->array)[index];
        for (int i = index; i < array->usedSize - 1; i++)
        {
            (array->array)[i] = (array->array)[i + 1];
        }
        array->usedSize--;
        return value;
    }
    return -1;
}

int deleteByValue(pArray array, int data)
{
    if (!isEmpty(array))
    {
        int index = -1;
        for (int i = 0; i < array->usedSize; i++)
        {
            if ((array->array)[i] == data)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            return deleteByIndex(array, index);
        }
    }
    return -1;
}

int pop(pArray array)
{
    if (!isEmpty(array))
    {
        array->usedSize--;
    }
}

int shift(pArray array)
{
    return deleteByIndex(array, 0);
}

int unshift(pArray array, int data)
{
    insert(array, 0, data);
}

int firstVal(pArray array)
{
    if (!isEmpty(array))
    {
        return (array->array)[0];
    }
    return -1;
}

int lastVal(pArray array)
{
    if (!isEmpty(array))
    {
        return (array->array)[array->usedSize - 1];
    }
    return -1;
}

int linearSearch(pArray array, int data)
{
    int index = -1;
    if (!isEmpty(array))
    {
        for (int i = 0; i < array->usedSize; i++)
        {
            if ((array->array)[i] == data)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

void bubbleSort(pArray array)
{
    if (array->usedSize > 1)
    {
        int *arr = array->array;
        int temp, isInOrder;
        for (int i = 0; i < array->usedSize - 1; i++)
        {
            isInOrder = 1;
            for (int j = 0; j < array->usedSize - 1 - i; j++)
            {
                if (arr[j + 1] < arr[j])
                {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                    isInOrder = 0;
                }
            }
            if (isInOrder)
            {
                break;
            }
        }
    }
}

void selectionSort(pArray array)
{
    if (array->usedSize > 1)
    {
        int *arr = array->array;
        int min, temp;
        for (int i = 0; i < array->usedSize - 1; i++)
        {
            min = i;
            for (int j = i; j < array->usedSize; j++)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            if (min != i)
            {
                temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void insertionSort(pArray array)
{
    if (array->usedSize > 1)
    {
        int *arr = array->array;
        int temp, j;
        for (int i = 1; i < array->usedSize; i++)
        {
            temp = arr[i];
            for (j = i; j > 0; j--)
            {
                if (arr[j - 1] > temp)
                {
                    arr[j] = arr[j - 1];
                }
                else
                {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}

void quickSort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pivot = arr[low];
    int i = low + 1, j = high;
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

void performQuickSort(pArray array)
{
    if (array->usedSize > 1)
    {
        quickSort(array->array, 0, array->usedSize - 1);
    }
}

void merge(int *arr, int low, int mid, int high)
{
    int *tempArr = (int *)malloc((high - low + 1) * sizeof(int));

    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            tempArr[k] = arr[i];
            i++;
        }
        else
        {
            tempArr[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        tempArr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        tempArr[k] = arr[j];
        j++;
        k++;
    }

    for (int z = low; z <= high; z++)
    {
        arr[z] = tempArr[z - low];
    }

    free(tempArr);
}

void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void performMergeSort(pArray array)
{
    if (array->usedSize > 1)
    {
        mergeSort(array->array, 0, array->usedSize - 1);
    }
}

void countSort(pArray array)
{
    if (array->usedSize > 1)
    {
        int *arr = array->array;

        int max = arr[0];
        for (int i = 0; i < array->usedSize; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        int *tempArr = (int *)malloc((max + 1) * sizeof(int));

        for (int i = 0; i < max + 1; i++)
        {
            tempArr[i] = 0;
        }

        for (int i = 0; i < array->usedSize; i++)
        {
            tempArr[arr[i]]++;
        }

        int j = 0;
        for (int i = 0; i < max + 1; i++)
        {
            while (tempArr[i])
            {
                arr[j] = i;
                j++;
                tempArr[i]--;
            }
        }

        free(tempArr);
    }
}

int binarySearch(pArray array, int data)
{
    int low = 0;
    int high = array->usedSize - 1;
    int mid;
    int *arr = array->array;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == data)
        {
            return mid;
        }
        else if (arr[mid] > data)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

void printArray(pArray array)
{
    if (!isEmpty(array))
    {
        printf("Array : ");
        for (int i = 0; i < array->usedSize; i++)
        {
            printf("%d ", (array->array)[i]);
        }
    }
    else
    {
        printf("Error Printing the array!");
    }
    printf("\n");
}

int increaseMaxCapacity(pArray array, int capacityToIncrease)
{
    if (capacityToIncrease > array->maxSize)
    {
        int *temp = (int *)malloc(array->usedSize * sizeof(int));

        for (int i = 0; i < array->usedSize; i++)
        {
            temp[i] = (array->array)[i];
        }

        array->array = (int *)realloc(array->array, capacityToIncrease * sizeof(int));

        array->maxSize = capacityToIncrease;

        for (int i = 0; i < array->usedSize; i++)
        {
            (array->array)[i] = temp[i];
        }

        free(temp);
        temp = NULL;
        return 1;
    }
    return 0;
}

int main()
{

    pArray arr = createArray(5);

    printf("%d %d\n", isFull(arr), isEmpty(arr));

    insert(arr, 0, 4);
    push(arr, 66);
    insert(arr, 0, 9);
    insert(arr, 2, 231);
    push(arr, 67);
    push(arr, 69);
    // push(arr, 15554);
    insert(arr, 2, 12);
    deleteByIndex(arr, 2);
    deleteByValue(arr, 231);
    deleteByIndex(arr, 5);
    pop(arr);
    pop(arr);
    push(arr, 4);
    unshift(arr, 96);
    push(arr, 96);
    shift(arr);
    shift(arr);
    shift(arr);
    pop(arr);
    push(arr, 56);
    push(arr, 57);
    push(arr, 58);
    push(arr, 59);
    increaseMaxCapacity(arr, 7);
    push(arr, 60);
    push(arr, 61);
    push(arr, 61);
    pop(arr);
    unshift(arr, 51);
    pop(arr);
    push(arr, 4);

    printf("%d %d\n", isFull(arr), isEmpty(arr));
    printf("%d\n", linearSearch(arr, 56));

    printArray(arr);
    // bubbleSort(arr);
    // insertionSort(arr);
    // selectionSort(arr);
    // performQuickSort(arr);
    // performMergeSort(arr);
    countSort(arr);
    shift(arr);
    unshift(arr, 1);

    printf("%d\n", binarySearch(arr, 1));
    printArray(arr);

    clearArray(arr);

    return 0;
}