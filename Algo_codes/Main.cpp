
#include "stdafx.h"
#include "stdio.h"
#include <time.h>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include "AlgoDemo.h"
#include <iostream>
#include <iomanip>
#include "BinaryTree.h"


int main(int argc, char* argv[])
{
    /* Sorting Algorithms */
    SortingAlgo algo;
    algo.startTesting();
    
    /* Trees demo */
    BinaryTree binTree;
    binTree.insert(algo.getArray());

    return 0;
}
