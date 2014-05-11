#include "stdafx.h"
#include "AlgoDemo.h"
#include <vector>
#include <algorithm>
#include "MergeSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "RadixSort.h"


using namespace std;
#define VECTOR_SIZE 10



SortingAlgo::SortingAlgo(void)
{
    reset();
}



SortingAlgo::~SortingAlgo(void)
{
}


void SortingAlgo::reset()
{
    mArr.clear();
    for (unsigned int i = 0; i < VECTOR_SIZE; ++i)
    {
        mArr.push_back((rand() % 100));
    }
    fisherYatesShuffle(mArr);
}
void SortingAlgo::fisherYatesShuffle(vector<int>& vec)
{
    int n = vec.size();
    for (int i = n - 1; i > 0; --i)
    {
        std::swap(vec[i], vec[rand() % (i + 1)]);
    }
}


void SortingAlgo::testUsingArray(std::vector<int>& arr)
{
    
    // Here all versions of all sorts should be called. 
    // Ideally just call AlgoStopwatch types and call 'start()' to let them do what they want.
    MergeSort mSort;
    LOG ("REAL ARRAY to BEGIN WITH...... " );
    mSort.print(arr);
    LOG ("--------------------------------------");
    mSort.benchmarkSort(arr);
    

    MergeSort_Approach2 mSort2;
    mSort2.benchmarkSort(arr);
    
    InsertionSort insertSort;
    insertSort.benchmarkSort(arr);

    
    HeapSort_1 heapSort1;
    heapSort1.benchmarkSort(arr);

    
    HeapSort_2 heapSort2;
    heapSort2.benchmarkSort(arr);
    
    HeapSort_3 heapSort3;
    heapSort3.benchmarkSort(arr);

    QuickSort quickSort;
    quickSort.benchmarkSort(arr);

    RadixSort rdxSort;
    rdxSort.benchmarkSort(arr);
    
    //mSort.
    //HeapSortAlgo mrgSort (arr);
    //mergeSort.approach1(arr);
    //LOG ("ARRAY RIGHT NOW IS.........");
    //printArray();

}

void SortingAlgo::startTesting()
{
    testUsingArray (mArr);




}
