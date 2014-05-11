#pragma once
#include "AlgoStopwatch.h"
class InsertionSort :
    public AlgoStopwatch
{
public:
    InsertionSort() : AlgoStopwatch ("InsertionSort", "Approach 1") {};
    virtual ~InsertionSort(void) {};
private:
    virtual void doSort(int* arr, int size);
};

