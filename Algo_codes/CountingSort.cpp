#include "stdafx.h"
#include "CountingSort.h"

void CountingSort::doSort(int * a, int a_len)
{

    int maxVal(0);
    //Get the greatest value in the array a and assign it to maxValue
    for (int i = 0; i < a_len; ++i)
    {
        if (a[i] > maxVal)
            maxVal = a[i];
    }
    int i, j, outPos = -1;
    const int bucket_len = maxVal+1;
    int* bucket = new int[bucket_len];

    memset(bucket, 0, sizeof(int) * bucket_len);

    for (i = 0; i < a_len; i++)
    {
        bucket[a[i]]++;
    }

    for (i=0; i < bucket_len; ++i)
    {
        for (j = 0; j < bucket[i]; ++j)
        {
            a[++outPos] = i;
        }
    }
    delete [] bucket;

}