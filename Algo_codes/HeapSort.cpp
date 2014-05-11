#include "stdafx.h"
#include "HeapSort.h"




int HeapSort_1::Left(int index) {
	return ((index << 1) + 1);
}

int HeapSort_1::Right(int index) {
	return ((index << 1) + 2);
}

int HeapSort_1::Parent(int index) {
	return ((index - 1) >> 1);
}

void HeapSort_1::Swap(int& item1, int& item2) {
	int iTemp = item1;
	item1 = item2;
	item2 = iTemp;
}

int HeapSort_1::SwapWithChild(int index, int* arrHeap, int arrSize) {
	int left		= Left(index);
	int right		= Right(index);
	int iLargest	= index;
	if (right < arrSize) {
		if (arrHeap[left] < arrHeap[right]) {
			iLargest = right;
		} else {
			iLargest = left;
		}
		if (arrHeap[index] > arrHeap[iLargest]) {
			iLargest = index;
		}
	} else if (left < arrSize) {
		if (arrHeap[index] < arrHeap[left]) {
			iLargest = left;
		}
	}
	if (arrHeap[index] < arrHeap[iLargest]) {
		Swap(arrHeap[index], arrHeap[iLargest]);
	}
	return iLargest;
}

void HeapSort_1::RemoveRoot(int* arrHeap, int arrSize) {
	// Swap the last element with the root
	Swap(arrHeap[0], arrHeap[arrSize - 1]);
	--arrSize;
	int lastItem = 0;
	int i = SwapWithChild(0, arrHeap, arrSize);
	while (i != lastItem) {
		lastItem = i;
		i = SwapWithChild(i, arrHeap, arrSize);
	}
}

int HeapSort_1::SwapWithParent(int i, int* arrHeap) {
	if (i < 1) {
		return i;
	}
	int parentIndex = Parent(i);
	if (arrHeap[i] > arrHeap[parentIndex]) {
		Swap(arrHeap[i], arrHeap[parentIndex]);
		return parentIndex;
	} else {
		return i;
	}
}

void HeapSort_1::AddElement(int newItem, int* arrHeap, int arrSize) {
	arrHeap[arrSize] = newItem;
	int lastItem = arrSize;
	int i = SwapWithParent(lastItem, arrHeap);
	while (lastItem != i) {
		lastItem = i;
		i = SwapWithParent(i, arrHeap);
	}
}

void HeapSort_1::OutputArray(int* outputArr, int iBar, int arrSize) {
	using namespace std;
	for (int i = 0; i < arrSize; ++i) {
		if (i == iBar) {
			cout << "|  ";
		}
		cout << outputArr[i] << "  ";
	}           
	cout << endl;
}

void HeapSort_1::doSort(int* arr, int size)
{
    /*
     // Output the heap after each element that we add
	for (int i = 0; i < size; ++i) {
		AddElement(arr[i], arr, i);
		if (mIsPrintable)
        {
            OutputArray(arr, i + 1, size);
		    LOG( "---------------------------------------------" );
        }
	}
    */

	 // Output the heap after each element that we remove
	for (int i = 0; i < size-1; ++i) {
		RemoveRoot(arr, size - i);
		if (mIsPrintable)
        {
            OutputArray(arr, size-1-i, size);
		    LOG("---------------------------------------------" );
        }
	}

}




// #######################################################################################################################


void HeapSort_2::shiftRight(int* arr, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
        if (arr[swapIdx] < arr[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
            int tmp = arr[root];
            arr[root] = arr[swapIdx];
            arr[swapIdx] = tmp;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}
void HeapSort_2::heapify(int* arr, int low, int high)
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int midIdx = (high - low -1)/2;
    while (midIdx >= 0)
    {
        shiftRight(arr, midIdx, high);
        --midIdx;
    }
    return;
}
void HeapSort_2::heapSort(int* arr, int size)
{
    /*This will put max element in the index 0*/
    heapify(arr, 0, size-1);
    int high = size - 1;
    while (high > 0)
    {
        /*Swap max element with high index in the array*/
        int tmp = arr[high];
        arr[high] = arr[0];
        arr[0] = tmp;
        --high;
        /*Ensure heap property on remaining elements*/
        shiftRight(arr, 0, high);
    }
    return;
}

void HeapSort_2::doSort(int* arr, int size)
{
    heapSort(arr, size);
}



// #########################################################################################################################


void HeapSort_3::doSort(int* arrayToSort, int size) {
        //printArray(arrayToSort, size);
 
        heapsort(arrayToSort, size);
 
        //printArray(arrayToSort, size);
}
 
void HeapSort_3::heapsort(int array[], int size) {
        buildheap(array, size);
        int heapsize = size;
 
        for(int i=size-1; i>0; i--) {
                int temp = array[i];
                array[i] = array[0];
                array[0] = temp;
                heapsize--;
                percolateDown(array, heapsize, 0);
        }
}
 
void HeapSort_3::buildheap(int array[], int size) {
        for(int i=size/2; i>=0; i--) {
                percolateDown(array, size, i);
        }
}
 
void HeapSort_3::percolateDown(int array[], int size, int id) {
        int current = id;
        int max;
        while(true) {
                int left = current*2+1;
                int right = current*2+2;
                if(left >= size)
                        return;
                else if(right >= size)
                        max = left;
                else if(array[left] > array[right])
                        max = left;
                else if(array[left] < array[right])
                        max = right;
                if(array[max] > array[current]) {
                        int temp = array[max];
                        array[max] = array[current];
                        array[current] = temp;
                        current = max;
                } else
                        return;
        }
}