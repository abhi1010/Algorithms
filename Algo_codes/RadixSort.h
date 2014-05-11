#pragma once
#include "algostopwatch.h"
class RadixSort :
    public AlgoStopwatch
{
public:
    RadixSort(void)  : AlgoStopwatch ("RadixSort", "Simple buckets, Sophisticated processing, Speed overhead") {}
    virtual ~RadixSort(void) {};

    virtual void doSort(int* arr, int size);
};

