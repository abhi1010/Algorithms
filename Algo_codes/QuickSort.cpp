#include "stdafx.h"
#include "QuickSort.h"
#include <time.h>


void QuickSort::doSort(int* arr, int size)
{
    srand((unsigned int) time(NULL));
    createPartition(arr, size);
}


void QuickSort::createPartition(int* arr, int size)
{
    if (size <= 1)
        return;
    int pivot = arr[(rand() % (size - 1)) + 1];

    int lower = -1;
    int upper = size;

    while (lower < upper) 
    {
        do
        {
            ++lower;
        }
        while (arr[lower] < pivot);

        do 
        {
            --upper;
        }
        while (arr[upper] > pivot);

        if (lower < upper)
        {
            int iTemp       = arr[lower];
            arr[lower]     = arr[upper];
            arr[upper]     = iTemp;
        }
    }
    
    createPartition(arr, lower);
    createPartition(&(arr[lower]), size - lower);
}