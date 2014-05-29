#include "stdafx.h"
#include "InsertionSort.h"


void InsertionSort::doSort(int* arr, int size)
{
    for (int index = 1; index < size; ++index)
    {
        // Initialize a local insertion index
        int insertIndex = index;
        while (insertIndex > 0 && arr[insertIndex - 1] > arr[insertIndex])
        {
            // std::swap(arr[insertIndex-1], arr[insertIndex]);// Makes it much slower
            int iSwap             = arr[insertIndex];
            arr[insertIndex]      = arr[insertIndex - 1];
            arr[insertIndex--]  = iSwap;
        }
    }
}