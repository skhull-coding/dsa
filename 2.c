#include <stdio.h>
#include <stdlib.h>

// Array as an ADT
// My attempt to build Array as an ADT

typedef struct myArray {
    int total_size;
    int used_size;
    int arr[total_size]; // couldn't understand how to add this total size variable from the struct
} mArray;

int main()
{
    mArray arr;
    arr.total_size = 9, arr.used_size = 3;

    return 0;
}