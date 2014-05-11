#pragma once
#include "AlgoStopwatch.h"

class MergeSort :
    public AlgoStopwatch
{
public:
    MergeSort() : AlgoStopwatch ("Merge Sort", "Creating two heaped arrays as temporary") {};
    virtual ~MergeSort(void) {};

private:
    virtual void doSort(int* arr, int size);
    void mergesort(int a[], int low, int high);
    void merge(int a[], int low, int mid, int high);
};



class MergeSort_Approach2 :
    public AlgoStopwatch
{
public:
    MergeSort_Approach2() : AlgoStopwatch ("Merge Sort", "Single temp array") {};
    virtual ~MergeSort_Approach2(void) {};

private:
    virtual void doSort(int* arr, int size);
    void merge(int* ipA, int iEnd1, int iEnd2);
};
