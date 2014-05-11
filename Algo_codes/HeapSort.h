#pragma once
#include "AlgoStopwatch.h"
class HeapSort_1 :
    public AlgoStopwatch
{
public:
    HeapSort_1() : AlgoStopwatch ("HeapSort_1", "Sorting while adding items")
    , mIsPrintable(false)
    {}
    virtual ~HeapSort_1(void) {};

private:
    int Left(int iIndex);
    int Right (int);
    int Parent(int);
    void Swap(int& irX, int& irY);
    int SwapWithChild(int iIndex, int* ipHeap, int iSize);
    void RemoveRoot(int* ipHeap, int iSize);
    int SwapWithParent(int i, int* ipHeap);
    void AddElement(int iNewEntry, int* ipHeap, int iSize);
    void OutputArray(int* ipArray, int iBar, int iSize);

public:
    virtual void doSort(int* arr, int size);
    bool    mIsPrintable;

};

class HeapSort_2 :
    public AlgoStopwatch
{
public:
    HeapSort_2() : AlgoStopwatch ("HeapSort_2", "Sorting a provided array") {}
    virtual ~HeapSort_2(void) {};
private:
     void shiftRight(int* arr, int low, int high);
     void heapify(int* arr, int low, int high);
     void heapSort(int* arr, int size);
 
public:
    virtual void doSort(int* arr, int size);

};

class HeapSort_3 :
    public AlgoStopwatch
{
public:
    HeapSort_3() : AlgoStopwatch ("HeapSort_3", "Sanfoundry version - percolateDown") {}
    virtual ~HeapSort_3(void) {};
private:
    
    void percolateDown(int array[], int size, int id);
    void buildheap(int array[], int size);
    void heapsort(int array[], int size);
 
public:
    virtual void doSort(int* arr, int size);

};


/*
void createHeap();
void checkElement(int index);
int getParent(int index);
int getLeftChild(int index);
int getRightChild(int index);

     
template <typename Iterator>
void heapsort(Iterator begin, Iterator end)
{
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}
*/