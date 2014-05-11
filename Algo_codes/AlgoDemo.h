#pragma once
#include <vector>

class Utilities
{
public:
    static void print(std::vector<int> arr)
    {
        unsigned int size = arr.size();
        std::cout << "Array[" << size<< "] = {" ;
        for (unsigned int i  = 0; i < size; ++i)
        {
            std::cout << arr[i]<< ", " ;
            //LOG ("i=" << i << "; Value=" << arr[i]);
        }
        std::cout << " }\n";
    }
    static void print(int* arr, int size)
    {
        std::vector<int> a;
        for(int i = 0;i<size; i++)
        {
            a.push_back(arr[i]);
        }
        print(a);
    }
};

class SortingAlgo
{
public:
    SortingAlgo(void);
    ~SortingAlgo(void);

    void fisherYatesShuffle(std::vector<int>& vec);
    void reset();
    
    void startTesting();
    void testUsingArray(std::vector<int>& arr);
    
    void shuffle();
    std::vector<int> getArray()
    {
        return mArr;
    }
private:
    std::vector<int> mArr;
};

