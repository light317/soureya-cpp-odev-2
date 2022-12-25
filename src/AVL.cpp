#include "AVL.hpp"
#include <iostream>

AVL::AVL(){
    this->root = NULL;
}

AVL::AVL(AVLNode* start){
    this->root = start;
}

// Calculate height
int AVL::height(AVLNode *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int AVL::max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
AVLNode* AVL::NewNode(int key) {
  AVLNode *node = new AVLNode();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
AVLNode* AVL::rightRotate(AVLNode *y) {
  AVLNode *x = y->left;
  AVLNode *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  return x;
}

// Rotate left
AVLNode* AVL::leftRotate(AVLNode *x) {
  AVLNode *y = x->right;
  AVLNode *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),
          height(x->right)) +
        1;
  y->height = max(height(y->left),
          height(y->right)) +
        1;
  return y;
}

// Get the balance factor of each AVLNode
int AVL::getBalanceFactor(AVLNode *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

// Insert a AVLNode
AVLNode* AVL::InsertNode(AVLNode *node, int key) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (NewNode(key));
  if (key < node->key)
    node->left = InsertNode(node->left, key);
  else if (key > node->key)
    node->right = InsertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height = 1 + max(height(node->left),
               height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

// Node with minimum value
AVLNode* AVL::nodeWithMimumValue(AVLNode *node) {
  AVLNode *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
AVLNode* AVL::DeleteNode(AVLNode *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = DeleteNode(root->left, key);
  else if (key > root->key)
    root->right = DeleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
      (root->right == NULL)) {
      AVLNode *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      AVLNode *temp = nodeWithMimumValue(root->right);
      root->key = temp->key;
      root->right = DeleteNode(root->right,
                   temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left),
               height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Returns true if binary tree
// with root as root is height-balanced
bool AVL::IsBalanced(AVLNode* treeRoot)
{

    // for height of left subtree
    int lh = 0;
 
    // for height of right subtree
    int rh = 0;
 
    // If tree is empty then return true
    if (treeRoot == NULL){
        return true;
    }
 
    // Get the height of left and right sub trees
    lh = height(treeRoot->left);
    rh = height(treeRoot->right);
 
    if (abs(lh - rh) <= 1 && IsBalanced(treeRoot->left)
        && IsBalanced(treeRoot->right)){
        return true;
        }
 
    // If we reach here then tree is not height-balanced
        std::cout<<" EUREKA!!!!\n";

    return false;
}

// Print the tree
void AVL::printTree(AVLNode *root, std::string indent, bool last) {
  if (root != nullptr) {
    std::cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "   ";
    } else {
      std::cout << "L----";
      indent += "|  ";
    }
    std::cout << root->key << std::endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

//  int main() {
//    Node *root = NULL;
//    root = InsertNode(root, 33);
//    root = InsertNode(root, 13);
//    root = InsertNode(root, 53);
//    root = InsertNode(root, 9);
//    root = InsertNode(root, 21);
//    root = InsertNode(root, 61);
//    root = InsertNode(root, 8);
//    root = InsertNode(root, 11);
//    printTree(root, "", true);
//    root = DeleteNode(root, 13);
//    std::cout << "After deleting " << std::endl;
//    printTree(root, "", true);
//  }