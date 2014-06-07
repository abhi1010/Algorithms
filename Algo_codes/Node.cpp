#include "stdafx.h"
#include "Node.h"
#include <set>



Node::~Node(void)
{
    LOG ("~Deleting: " << data);
    /*if (this->next != NULL)
    {
        delete this->next;
        this->next = NULL;
    }
    if (this->next != NULL)
        delete this->next;
        */
}

void Node::printAll()
{
    NodeAlgo algo;
    algo.printAll(this);
}


void Node::appendToTail(int d)
{
    // They called this function to create this new Node
    // Let them take care of deleting the nodes as well once they are done with all the work
    Node* end=new Node(d);
    Node* n=this;
    while(n->next!=NULL)
    {
        n=n->next;
    }
    n->next=end;
    LOG("Added " << end->data);
}
bool Node::operator<(const Node& node) const
{
    LOG ("Comparing < : " << this->data << " with " << node.data);
    return cmp(*this, node);
}
bool Node::cmp (const Node& node1, const Node& node2) const
{
    LOG ("cmp < : " << node1.data << " with " << node2.data);
    return node1.data < node2.data;
}

// -------------------------


void NodeAlgo::printAll(Node* n)
{
    if (n == NULL) return;
    while(n->next!=NULL)
    {
        std::cout << n->data << " << " ;
        n=n->next;
    }
    std::cout << n->data << std::endl;
}

Node* NodeAlgo::deleteNode(Node* head,int d)
{
    Node* n  = head;
    if (head->data == d)
    {
        n = n->next;
        LOG ("1. Want to delete: " << head->data);
        delete head;
        return n;
    }
    while (n->next != NULL)
    {
        if (n->next->data == d)
        {
            Node* nextNode = n->next->next;
            LOG ("2. Want to delete: " << n->next->data);
            LOG ("next node is: " << nextNode->data);
            delete n->next;
            n->next = nextNode;
        }
        n = n->next;
    }
    return head;
}


void NodeAlgo::removeDuplicates(Node* node)
{
    Node* n = node;
    std::set<Node*, Node_Comparable> nodeSet;
    nodeSet.insert(n);
    while (n->next != NULL)
    {
        
        LOG ("removeDuplicates: checking.....  " << n->next->data);
        std::pair<std::set<Node*>::iterator, bool> ret = nodeSet.insert(n->next);
        if (ret.second) // element not there
        {
            // Good enough. 
            LOG ("removeDuplicates: Added " << n->next->data);
        }
        else // already exists. Let's remove this
        {
            LOG ("removeDuplicates: Found duplicate......... " << n->next->data);
            Node* nextNext = n->next->next;
            delete n->next;
            n->next = nextNext;
        }
        n = n->next;
    }
}

Node* NodeAlgo::findKthToLastElement (Node* node, unsigned short k)
{
    Node* secondRunner = node;
    for(unsigned short i = 0; i < k; ++i)
    {
        if (secondRunner->next != NULL)
            secondRunner = secondRunner->next;
        else
            return NULL;
    }
    while (secondRunner)
    {
        secondRunner = secondRunner->next;
        node = node->next;
    }
    return node;
}
Node* NodeAlgo::sendToHigher(Node* higher, Node* n)
{
    n->next = NULL;
    if (higher)
    {
        higher->next = n;
        LOG ("1");
        printAll (higher);
        LOG ("2");
        higher = higher->next;
    }
    else
    {
        LOG ("3");
        higher = n;
    }
    return higher;
}
void NodeAlgo::partitionList (Node* node, int middleValue)
{
    Node* current = node;
    Node* higher = NULL;
    Node* lower = NULL;
    Node* firstLow = NULL;
    while (current != NULL)
    {
        Node* tmp = current;
        current = current->next;
        tmp->next = NULL;
        if (tmp->data > middleValue)
        {
            LOG ("add to higher:" << tmp->data);
            higher = sendToHigher(higher, tmp);
            LOG ("value.high=" << higher->data << "; tmp=" << tmp->data);
        }
        else
        {
            LOG ("add to lower:" << tmp->data);
            lower = sendToHigher(lower, tmp);
            if (firstLow == NULL) firstLow = lower;
            LOG ("value.low=" << lower->data << "; tmp=" << tmp->data);
        }
        if (current)
        {
            LOG ("tmp = " << tmp->data << "; new current =" << current->data);
        }
        else 
            LOG ("tmp = " << tmp->data);
    }
    
    LOG ("\n\nLOWER" );
    printAll(node);
    LOG ("\n\nDONE LOWER" );

    printAll(firstLow);


    LOG ("\n\nDONE LOWER" );

    printAll(lower);
    LOG ("......dne");

    lower->next = node;

    
    LOG ("\n\n----------------------FINAL LOWER" );

    printAll(firstLow);

    LOG ("\n\n================= DONE LOWER" );
}