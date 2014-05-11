#pragma once

#include <vector>
#define MAX_TIMES 20000


class AlgoStopwatch
{
public:
    AlgoStopwatch(const std::string& name, const std::string& desc)
        : mDescription (desc)
        , mName         (name)
    {} ;
    virtual ~AlgoStopwatch(void) {};

    void benchmarkSort(std::vector<int> arr);
    void benchmarkSort(int* arr, int size);
    void print(std::vector<int> arr);
    void print(int* arr, int size);

protected:
    virtual void doSort(int* arr, int size);

private:
    int* getPointerArray(std::vector<int> arr);
    std::string     mDescription;
    std::string     mName;
};

