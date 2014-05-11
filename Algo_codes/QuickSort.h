#pragma once
#include "algostopwatch.h"
class QuickSort :
    public AlgoStopwatch
{
public:
    QuickSort(void)  : AlgoStopwatch ("QuickSort", "Supposed to be quickest but depends on data + Pivot") {}
    virtual ~QuickSort(void) {};

public:
    virtual void doSort(int* arr, int size);
    void         createPartition(int* arr, int size);
};

