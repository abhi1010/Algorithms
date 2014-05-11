#include "stdafx.h"
#include "AlgoStopwatch.h"
#include <algorithm>

#include <ctime>
#include <ratio>
#include <chrono>

#include <iostream>
#include <iterator>
#include <vector>


#include <string>
#include <iostream>


void AlgoStopwatch::print(std::vector<int> arr)
{
    if (arr.size())
    {
        std::cout << "Array[" << arr.size() << "]:: { " ;
        std::copy (arr.cbegin(), arr.cend(), std::ostream_iterator<int>(std::cout, ", "));
        std::cout << "}\n";
    }
    return;
}
void AlgoStopwatch::print(int* arr, int size)
{
    std::vector<int> v (arr, arr + size);
    print (v);
    std::copy (arr, arr + size, std::ostream_iterator<int>(std::cout, ", "));
    //std::for_each(arr, arr + size, std::cout << std::placeholders::_1);
}

void AlgoStopwatch::benchmarkSort(int* arr, int size)
{
    using namespace std::chrono;
    LOG ("Name=" << this->mName << "; Desc=" << this->mDescription);
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (int i = 0;i < MAX_TIMES; i++)
    {
        int* tmpArray = new int[size];
        //memcpy(tmpArray, arr, size * sizeof(arr[0]));
        std::copy (arr, arr + size, tmpArray);
        doSort(tmpArray, size);
        if (i == MAX_TIMES - 1)
            this->print (tmpArray, size);
        delete[] tmpArray;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    nanoseconds  time_span = duration_cast<nanoseconds>(t2 - t1);
    std::cout << "It took " << time_span.count() << " nanoseconds." << std::endl << std::endl;
}

void AlgoStopwatch::benchmarkSort(std::vector<int> arr)
{
    int *a= new int[arr.size()];
    std::copy (arr.begin(), arr.end(), a);
    benchmarkSort (a, arr.size());
    delete[] a;
}

int* AlgoStopwatch::getPointerArray(std::vector<int> arr)
{
    int* a = new int[arr.size()];
    for(int i = 0;i<(int) arr.size(); i++)
    {
        a[i] = arr[i];
    }
    return a;
}

void AlgoStopwatch::doSort(int* arr, int size)
{
    // To be overridden by others
}