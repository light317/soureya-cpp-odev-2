// The binary search tree

#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"

class BST{
    private:
        int max(int,int);
        int height(BSTNode*);
        BSTNode* MinValueNode(BSTNode*);

    public:
        BSTNode* root;
        BST();
        BST(BSTNode*);
        BSTNode* NewNode(int);
        BSTNode* DeleteNode(BSTNode*,int);
        BSTNode* InsertNode(BSTNode*,int);
        bool IsBalanced(BSTNode*);
        void printTree(BSTNode *, std::string, bool);

};


#endif