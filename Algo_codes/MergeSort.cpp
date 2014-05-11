#include "stdafx.h"
#include "MergeSort.h"
#include <vector>

using std::vector;


void MergeSort::doSort (int* a, int size)
{
    mergesort(a, 0, size-1);
    //delete []a;
}

void MergeSort::mergesort(int a[], int low, int high)
{
    if(low<high) // The array has atleast 2 elements
    {
        int mid = (low+high)/2;
        mergesort (a, low, mid);     // Recursion chain to sort first half of the array
        mergesort (a, mid+1, high);  // Recursion chain to sort second half of the array
        merge(a, low, mid, high);
    }
}

void MergeSort::merge(int a[], int low, int mid, int high)
{
    int i, j, k, firstHalfSize = mid-low+1, secondHalfSize = high-mid;
    int* firstHalfArr = new int[firstHalfSize], *secondHalfArr = new int[secondHalfSize];
    for(i=0; i < firstHalfSize; i++)  // Extract first half (already sorted)
        firstHalfArr[i] = a[low+i];
    for(i=0; i < secondHalfSize; i++)  // Extract second half (already sorted)
        secondHalfArr[i] = a[mid+i+1];
    i = j = 0;
    k = low;
    while(i < firstHalfSize || j < secondHalfSize)  // Merge the two halves 
    {
        if(i >= firstHalfSize) //Have we finished consuming all of firstHalfArr?
        {
            a[k++] = secondHalfArr[j++];// Only secondHalfArr is left then
            continue;
        }
        if(j >= secondHalfSize) //Have we finished consuming all of secondHalfArr?
        {
            a[k++] = firstHalfArr[i++];// Only firstHalfArr is left then
            continue;
        }
        if(firstHalfArr[i] < secondHalfArr[j])
            a[k++] = firstHalfArr[i++];
        else
            a[k++] = secondHalfArr[j++];
    }
    delete [] firstHalfArr;
    delete [] secondHalfArr;
}


/*
void approach1(vector<int> arr)
{
int iSize = 7;
for (int i = 1; i < iSize; i *= 2)
{
//scout << "i=" << i <"\n";
for (int j = 0; j < iSize - i; j += 2*i)
{
int end2 = (2*i < iSize - j) ? 2*i : iSize - j;
cout << "Merge(&(iaArray["  << j << "]), " << i << ", " << end2 << "\n";
//cout << "\t J==" << j << "; end2=" << end2 << "\n";
//Merge(&(iaArray[j]), i, end2);
}
cout << "\n";
}
}
*/


void MergeSort_Approach2::merge(int* arr, int end1, int end2)
{
    int i = 0;
    int j = end1;
    int k = 0;
    int* tmpArr = new int[end2];
    // Take each next smallest element
    while (i < end1 && j < end2)
    {
        if (arr[i] < arr[j])
        {
            tmpArr[k] = arr[i];
            ++i;
        }
        else
        {
            tmpArr[k] = arr[j];
            ++j;
        }
        ++k;
    }
    // Copy any remaining elements of the 1st array
    while (i < end1)
    {
        tmpArr[k] = arr[i];
        ++i;
        ++k;
    }
    // Copy any remaining elements of the 2nd array
    while (j < end2)
    {
        tmpArr[k] = arr[j];
        ++j;
        ++k;
    }
    // Copy the merged array back to the original
    for (int iIndex = 0; iIndex < end2; ++iIndex)
    {
        arr[iIndex] = tmpArr[iIndex];
    }
    delete [] tmpArr;
}
void MergeSort_Approach2::doSort(int* arr, int size)
{
    // Merge Sort
    for (int i = 1; i < size; i *= 2)
    {
        for (int j = 0; j < size - i; j += 2*i)
        {
            int end2 = (2*i < size - j) ? (2*i) : (size - j);
            merge(&(arr[j]), i, end2);
        }
    }

}