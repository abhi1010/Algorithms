#pragma once
#include "AlgoStopwatch.h"

class CountingSort :
    public AlgoStopwatch
{
public:
    CountingSort(void) : AlgoStopwatch ("CountingSort", "Simple buckets, Simple processing, Memory overhead") {}
    ~CountingSort(void){ }
    virtual void doSort(int * str, int size);
};

