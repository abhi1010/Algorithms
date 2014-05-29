#include "stdafx.h"
#include "AlgoDemo.h"
#include <vector>
#include <algorithm>
#include "MergeSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "CountingSort.h"

using namespace std;
#define VECTOR_SIZE 10

SortingAlgo::SortingAlgo(void)
{
}

SortingAlgo::~SortingAlgo(void)
{
}

vector<int> SortingAlgo::getVector(const int size, const VectorSequenceType seqType) const
{
    vector<int> tmpArray;
    for (unsigned int i = 0; i < size; ++i)
    {
        tmpArray.push_back((rand() % (size*10)));
    }
    if (seqType == VectorSequenceType::Random)
        fisherYatesShuffle(tmpArray);
    else
    {
        // We want it sorted then
        std::sort (tmpArray.begin(), tmpArray.end());
    }
    return tmpArray;
}

void SortingAlgo::fisherYatesShuffle(vector<int>& vec) const
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

    CountingSort countSort;
    countSort.benchmarkSort(arr);
    
    MergeSort mSort;
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
}

void SortingAlgo::startBenchmarking()
{
    LOG ("Testing using 10 Random numbers");
    testUsingArray (getVector(10, VectorSequenceType::Random));
    return;

    LOG ("Testing using 10 Sorted numbers");
    testUsingArray (getVector(10, VectorSequenceType::Sorted));

    
    LOG ("Testing using 1K Random numbers");
    testUsingArray (getVector(1000, VectorSequenceType::Random));

    LOG ("Testing using 1K Sorted numbers");
    testUsingArray (getVector(1000, VectorSequenceType::Sorted));


    LOG ("Testing using 1M Random numbers");
    testUsingArray (getVector(1000000, VectorSequenceType::Random));

    LOG ("Testing using 1M Sorted numbers");
    testUsingArray (getVector(1000000, VectorSequenceType::Sorted));
}


