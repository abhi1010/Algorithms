
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
#include "Node.h"

void runLinkedList()
{
    
    Node node(34);

    node.appendToTail(3);
    node.appendToTail(17);
    node.appendToTail(23);
    node.appendToTail(1);
    node.appendToTail(8);
    NodeAlgo nodeAlgo;
    node.printAll();
    //node.deleteNode(&node, 1);
    //node.removeDuplicates(&node);
    //node.findKthToLastElement(&node, 2);
    node.printAll();
}
int main(int argc, char* argv[])
{
    runLinkedList();

    /* Sorting Algorithms */
    SortingAlgo algo;
    algo.startBenchmarking();
    
    /* Trees demo */
    BinaryTree binTree;
    binTree.insert(algo.getVector(10, VectorSequenceType::Random));

    return 0;
}
