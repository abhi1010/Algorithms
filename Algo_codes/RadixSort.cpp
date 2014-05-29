#include "stdafx.h"
#include "RadixSort.h"
#define BASE 10


void RadixSort::doSort(int * a, int n)
{
    int i, m = a[0], exp = 1;
    int *b = new int[n];
    
    //Get the greatest value in the array a and assign it to m
    for (i = 1; i < n; i++)
    {
        if (a[i] > m)
            m = a[i];
    }

    //Loop until exp is bigger than the largest number
    while (m / exp > 0)
    {
        int bucket[BASE] = { 0 };
        //Count the number of keys that will go into each bucket
        for (i = 0; i < n; ++i)
        {
            //LOG (".... i = " << i << "; a[i]=" << a[i] );
            bucket[(a[i] / exp) % BASE]++;
            //LOG ("number of keys.. " << ((a[i] / exp) % BASE));
            //LOG ("bucket[" << ((a[i] / exp) % BASE) << "]=" << bucket[((a[i] / exp) % BASE)]);
        }

        //Add the count of the previous buckets to acquire the indexes after the end of each bucket location in the array
        for (i = 1; i < BASE; ++i)
        {
            //LOG ("(BEFORE) i = " << i << "; bucket=" << bucket[i] << "; i-1 == " << bucket[i-1]);
            bucket[i] += bucket[i - 1];
            //LOG ("(AFTER) i = " << i << "; bucket=" << bucket[i] << "\n");
        }

        //Starting at the end of the list, get the index corresponding to the a[i]'s key, decrement it, and use it to place a[i] into array b.
        for (i = n - 1; i >= 0; --i)
        {
            b[--bucket[(a[i] / exp) % BASE]] = a[i];
            int index = (a[i] / exp) % BASE;
            int x = (bucket[index]);
        }

        //Copy array b to array a
        for (i = 0; i < n; ++i)
            a[i] = b[i];

        //Multiply exp by the BASE to get the next group of keys
        exp *= BASE;
    }
    delete []b;

}