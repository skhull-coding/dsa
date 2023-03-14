#include <stdio.h>
#include <stdlib.h>

// Linear Search - Array traversal - O(n)
// Binary search - O(log[n])

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, high, mid;

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[low] == element)
        {
            return low;
        }
        if (arr[high] == element)
        {
            return high;
        }
        if (arr[mid] > element)
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

int main()
{
    int arr1[] = {4, 5, 6, 7, 7, 12, 44, 67, 78};
    int size = sizeof(arr1) / sizeof(int);
    int element = 51;
    printf("The element %d found at index %d.\n", element, linearSearch(arr1, size, element));
    printf("The element %d found at index %d.", element, binarySearch(arr1, size, element));

    return 0;
}

// for sorted array, binary search is the best way if considering time
// for unsorted array, either sort it and then binary search or can linear search it.