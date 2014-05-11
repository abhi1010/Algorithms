#pragma once 

#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

struct TreeNode
{
    int mValue;
    TreeNode* Left;
    TreeNode* Right;
    TreeNode(int value)
        : mValue    (value)
        , Left      (NULL)
        , Right     (NULL)
    { }
};
class BinaryTree
{
public:
    BinaryTree(void);
    ~BinaryTree(void);

    void        insert(int key);
    void        insert (std::vector<int> arr);
    TreeNode*   search(int key);
    void        destroyTree();

private:
    void        destroyTree(TreeNode *leaf);
    void        insert(int key, TreeNode *leaf);
    TreeNode*   search(int key, TreeNode *leaf);
    TreeNode*   DFS(int key, TreeNode* node);
    TreeNode*   BFS(int key, TreeNode *node);
    TreeNode*   mRoot;
    void        balanceTree(TreeNode* node);

    int maxHeight(TreeNode *p);
    std::string intToString(int val);
    void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<TreeNode*>& nodesQueue, std::ostream& out);
    void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<TreeNode*>& nodesQueue, std::ostream& out);
    void printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<TreeNode*>& nodesQueue, std::ostream& out);
    void printPretty(TreeNode *root, int level, int indentSpace, std::ostream& out);

};

