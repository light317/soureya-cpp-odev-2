// Binary Search Tree

#include <iostream>
#include "BST.hpp"

BST::BST(){
    this->root = NULL;
}

BST::BST(BSTNode* start){
    this->root = start;
}


// Create a node
BSTNode* BST::NewNode(int item){
  BSTNode *temp = new BSTNode();
  temp->key = item;
  temp->right = NULL;
  temp->left = NULL;

  return temp; 
}


void inorder(BSTNode* root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    std::cout << root->key << " -> ";

    // Traverse right
    inorder(root->right);
  }
}

BSTNode* BST::InsertNode(BSTNode* node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return NewNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = InsertNode(node->left, key);
  else
    node->right = InsertNode(node->right, key);

  return node;
}

BSTNode* BST::MinValueNode(BSTNode* node) {
  BSTNode* current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

BSTNode* BST::DeleteNode(BSTNode *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = DeleteNode(root->left, key);
  else if (key > root->key)
    root->right = DeleteNode(root->right, key);
  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      BSTNode* temp = root->right;
      delete root;
      //free(root);
      return temp;
    } else if (root->right == NULL) {
      BSTNode* temp = root->left;
      //free(root);
      delete root;
      return temp;
    }

    // If the node has two children
    BSTNode* temp = MinValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = DeleteNode(root->right, temp->key);
  }
  return root;
}

int BST::height(BSTNode* node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;
 
    // If tree is not empty then
    // height = 1 + max of left height
    // and right heights
    return 1 + max(height(node->left), height(node->right));
}

int BST::max(int a, int b) {
  return (a > b) ? a : b;
}

bool BST::IsBalanced(BSTNode* treeRoot)
{

    int leftTreeHeight = 0;
    int rightTreeHeight = 0;
 
    if (treeRoot == NULL){
        return true;
    }
 
    leftTreeHeight = height(treeRoot->left);
    rightTreeHeight = height(treeRoot->right);
 
    if (abs(leftTreeHeight - rightTreeHeight) <= 1 && IsBalanced(treeRoot->left)
        && IsBalanced(treeRoot->right)){
        return true;
        }
 
    return false;
}