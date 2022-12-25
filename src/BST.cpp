// Binary Search Tree operations in C++

#include <iostream>
#include "BST.hpp"

// struct node {
//   int key;
//   struct node *left, *right;
// };


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

// struct node *newNode(int item) {
//   struct node *temp = (struct node *)malloc(sizeof(struct node));
//   temp->key = item;
//   temp->left = temp->right = NULL;
//   return temp;
// }

// Inorder Traversal
// void inorder(struct node *root) {
//   if (root != NULL) {
//     // Traverse left
//     inorder(root->left);

//     // Traverse root
//     cout << root->key << " -> ";

//     // Traverse right
//     inorder(root->right);
//   }
// }

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

// Insert a node
// struct node *insert(struct node *node, int key) {
//   // Return a new node if the tree is empty
//   if (node == NULL) return newNode(key);

//   // Traverse to the right place and insert the node
//   if (key < node->key)
//     node->left = insert(node->left, key);
//   else
//     node->right = insert(node->right, key);

//   return node;
// }

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

// Find the inorder successor
// struct node *minValueNode(struct node *node) {
//   struct node *current = node;

//   // Find the leftmost leaf
//   while (current && current->left != NULL)
//     current = current->left;

//   return current;
// }

BSTNode* BST::MinValueNode(BSTNode* node) {
  BSTNode* current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
// struct node *deleteNode(struct node *root, int key) {
//   // Return if the tree is empty
//   if (root == NULL) return root;

//   // Find the node to be deleted
//   if (key < root->key)
//     root->left = deleteNode(root->left, key);
//   else if (key > root->key)
//     root->right = deleteNode(root->right, key);
//   else {
//     // If the node is with only one child or no child
//     if (root->left == NULL) {
//       struct node *temp = root->right;
//       free(root);
//       return temp;
//     } else if (root->right == NULL) {
//       struct node *temp = root->left;
//       free(root);
//       return temp;
//     }

//     // If the node has two children
//     struct node *temp = minValueNode(root->right);

//     // Place the inorder successor in position of the node to be deleted
//     root->key = temp->key;

//     // Delete the inorder successor
//     root->right = deleteNode(root->right, temp->key);
//   }
//   return root;
// }

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

// Returns true if binary tree
// with root as root is height-balanced
bool BST::IsBalanced(BSTNode* treeRoot)
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
    return false;
}

// Print the tree
void BST::printTree(BSTNode *root, std::string indent, bool last) {
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

// Driver code
// int main() {
//   struct node *root = NULL;
//   root = insert(root, 8);
//   root = insert(root, 3);
//   root = insert(root, 1);
//   root = insert(root, 6);
//   root = insert(root, 7);
//   root = insert(root, 10);
//   root = insert(root, 14);
//   root = insert(root, 4);

//   cout << "Inorder traversal: ";
//   inorder(root);

//   cout << "\nAfter deleting 10\n";
//   root = deleteNode(root, 10);
//   cout << "Inorder traversal: ";
//   inorder(root);
// }