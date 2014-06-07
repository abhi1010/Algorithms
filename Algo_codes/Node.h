#pragma once
class Node;
class NodeAlgo;

class Node
{
    Node* next;
    int data;
public:
    
    friend class NodeAlgo;

    ~Node(void);
    Node(int d): next(NULL), data(d) { };
    
    void appendToTail(int d);
    void printAll();

    // Comparisons
    bool operator<(const Node& node) const;
    bool cmp (const Node& node1, const Node& node2) const;

    // Data functions
    int getData() { return data; }
};
class NodeAlgo
{
public:
    NodeAlgo() {}

    // Processing Algos
    Node* deleteNode(Node* head,int d);
    
    void removeDuplicates(Node* node); // 2.1
    Node* findKthToLastElement (Node* node, unsigned short k); // 2.2
    void partitionList (Node* node, int middleValue);
    
    // Debug Helper - Printing
    
    void printAll(Node* n);
    
private:
    Node* sendToHigher(Node* higher, Node* n);
};

struct Node_Comparable
{
    bool operator ()(Node* const a, Node* const b)
    {
        LOG ("operator(): a=" << a->getData() << "; b=" << b->getData());
        return a->getData() < b->getData();
    }
};

