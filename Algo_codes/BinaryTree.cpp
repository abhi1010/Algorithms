#include "stdafx.h"
#include "BinaryTree.h"
#include <queue>
#include <stack>

BinaryTree::BinaryTree(void)
    : mRoot         (NULL)
{
}

BinaryTree::~BinaryTree(void)
{
    if (mRoot)
    {
        destroyTree();
    }
}

void BinaryTree::insert(int key)
{
    if(mRoot!=NULL)
        insert(key, mRoot);
    else
    {
        mRoot = new TreeNode(key);
    }
}

void BinaryTree::insert(int key, TreeNode *node)
{
    if (node->mValue == key)
    {
        LOG ("Tree Node::insert:: Key already in the Binary Tree. Ignoring");
        return;
    }
    if (key < node->mValue)
    {
        if (node->Left != NULL)
        {
            insert (key, node->Left);
        }
        else
        {
            node->Left = new TreeNode(key);
            LOG ("Inserted " << key << " left of " << node->mValue);
        }
    }
    else
    {
        if (node->Right != NULL)
        {
            insert (key, node->Right);
        }
        else
        {
            node->Right = new TreeNode(key);
            LOG ("Inserted " << key << " right of " << node->mValue);
        }
    }
}


TreeNode* BinaryTree::search(int key)
{
    return search(key, mRoot);
}

TreeNode* BinaryTree::search(int key, TreeNode *node)
{
    if (node)
    {
        if (node->mValue == key)
        {
            return node;
        }
        else
        {
            if (key < node->mValue)
                return search (key, node->Left);
            else
                return search (key, node->Right);
        }
    }
    return NULL;
}

void BinaryTree::destroyTree()
{
    if (mRoot)
    {
        destroyTree(mRoot);
    }
}

void BinaryTree::destroyTree(TreeNode *node)
{
    if (node)
    {
        destroyTree(node->Left);
        destroyTree(node->Right);
        delete node;
    }
}







// ############################################ 

using namespace std;

// Find the maximum height of the binary tree
int BinaryTree::maxHeight(TreeNode *p) {
    if (!p) return 0;
    int LeftHeight = maxHeight(p->Left);
    int RightHeight = maxHeight(p->Right);
    return (LeftHeight > RightHeight) ? LeftHeight + 1: RightHeight + 1;
}

// Convert an integer value to string
string BinaryTree::intToString(int val) {
    ostringstream ss;
    ss << val;
    return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
void BinaryTree::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<TreeNode*>& nodesQueue, ostream& out) {
    deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {  
        out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
        out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
    }
    out << endl;
}


// Print the branches and node (eg, ___10___ )
void BinaryTree::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
    deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->Left) ? setfill('_') : setfill(' '));
        out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->mValue) : "");
        out << ((*iter && (*iter)->Right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
    }
    out << endl;
}

// Print the leaves only (just for the bottom row)




void BinaryTree::printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
    deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) 
    {

        out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->mValue) : "");
    }
    out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ paramz
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the Left (eg, indentSpace of 0 means the lowest level of the Left node will stick to the Left margin)
void BinaryTree::printPretty(TreeNode *root, int level, int indentSpace, ostream& out) {
    int h = maxHeight(root);
    int nodesInThisLevel = 1;
    
    int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
    int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between Left neighbor node's Right arm and Right neighbor node's Left arm
    int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the Left most node of each level only)

    deque<TreeNode*> nodesQueue;
    nodesQueue.push_back(root);
    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        branchLen = branchLen/2 - 1;
        nodeSpaceLen = nodeSpaceLen/2 + 1;
        startLen = branchLen + (3-level) + indentSpace;
        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

        for (int i = 0; i < nodesInThisLevel; i++) {
            TreeNode *currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode) {
                nodesQueue.push_back(currNode->Left);
                nodesQueue.push_back(currNode->Right);
            } else {
                nodesQueue.push_back(NULL);
                nodesQueue.push_back(NULL);
            }
        }
        nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}


void BinaryTree::insert (std::vector<int> arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        insert (arr[i]);
    }
    printPretty(mRoot, 3, 0, std::cout);
}

TreeNode* BinaryTree::BFS(int key, TreeNode *node)
{
    if (node == NULL) return NULL;

    std::queue<TreeNode*> q;
    q.push(node);

    while (!q.empty())
    {
        TreeNode* tmp = q.front();
        q.pop();

        if (tmp->mValue == key)
            return tmp;
        else
        {
            if(tmp->Left != NULL)
                q.push(tmp->Left);
            if(tmp->Right != NULL)
                q.push(tmp->Right);
        }
    }
    return NULL;
}
TreeNode* BinaryTree::DFS(int key, TreeNode* node)
{
    
     std::stack<TreeNode*> stack;
 
        stack.push(node);
 
        TreeNode* current = NULL;
 
        while (stack.size()) {
            current = stack.top();
            stack.pop();
             
            // do the processing on a node
            if (current->mValue == key)
                return current;
 
            if (current->Left != NULL)
                stack.push(current->Left);
            if (current->Right != NULL)
                stack.push(current->Right);
        }
        return NULL;
        /*    if (head)
    {
        if (head->left)
        {
            DFS(head->left);
        }
        if (head->right)
        {
            DFS(head->right);
        }
        printf("%d  ", head->a);
    }
    */
}


void BinaryTree::balanceTree(TreeNode* node)
{
    
}