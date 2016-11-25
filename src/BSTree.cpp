//##############################################################################
//
//
//  FileName: BSTree.cpp
//  Adapted from BSTree.cpp by Dr. Tom Agustine
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   11/23/2016
//
//
//  Assignment: Final Project - A c++ Database System
//
//
//  This file contains the implementation of the BSTree class.
//
//
//
//##############################################################################


#include <iomanip>


#include "BSTree.h"

// Constructor
BSTree::BSTree() {
    root = nullptr;
}

// Destructor
BSTree::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
void BSTree::freeNode(Node* leaf)
{
    if ( this->Root() == leaf)
    {

    }
    // else
    if ( leaf != nullptr ) {
      freeNode(leaf->Left());
      freeNode(leaf->Right());
      // delete leaf->getContact();
      delete leaf;
    }

}

// // Add a node
// void BSTree::addNode(int key)
// {
//     // No elements. Add the root
//     if ( root == nullptr ) {
//         Node* n = new Node();
//         n->setKey(key);
//         root = n;
//     }
//     else {
//         addNode(key, root);
//     }
// }

void BSTree::addNode(Record* contactPtr) {
  // No elements. Add the root
  if ( root == nullptr ) {
      Node* n = new Node();
      n->setKey(contactPtr->getId());
      n->setDataPtr(contactPtr); // set the node pointer to the record

      // Debug statement
      // Record* testPtr;
      // testPtr = n->getContact();
      // cout << testPtr->getLastName() << endl;

      root = n;
  }
  else {
      addNode(contactPtr, root);
  }
}


// Add a node (private)
void BSTree::addNode(Record* contactPtr, Node* leaf) {
    if ( contactPtr->getId() <= leaf->Key() )
    {
        if ( leaf->Left() != nullptr )
            addNode(contactPtr, leaf->Left());
        else {
            Node* n = new Node();
            n->setKey(contactPtr->getId());
            n->setDataPtr(contactPtr); // set the node pointer to the record
            n->setParent(leaf);
            leaf->setLeft(n);
        }
    }
    else
    {
        if ( leaf->Right() != nullptr )
            addNode(contactPtr, leaf->Right());
        else {
            Node* n = new Node();
            n->setKey(contactPtr->getId());
            n->setDataPtr(contactPtr); // set the node pointer to the record
            n->setParent(leaf);
            leaf->setRight(n);
        }
    }
}

// Find a node
Node* BSTree::findNode(unsigned int key, Node* node)
{
  // ******************** Edited by B. Gedvilas 10/30/2016 *********************
  // PRE:
  // POST: Returns a pointer to the node if found, returns nullptr if not
  // FUNC: Recursively finds a node in the binary tree based on the given key,
  //       and a parent node


  // If we get to a node pointing to a nullptr, we know that the key value is not
  // in the binary search tree
  if (node == nullptr) {
    // cout << "nullptr\nNode " << key << " not found" << endl;
    return nullptr;
  }

  // Check to see if the key value at the current node matches the search key
  else if (node->Key() == key) {
      // cout << node->Key() << endl;
      // cout << "Node " << key << " Found" << endl;
      return node;
      // return true;
  }

  // If search key is less than the current node, search the left subtree
  else if (key < node->Key()) {
      // search the left tree
      // cout << node->Key() << "->"; // display each node we visit to visualize the search
      findNode(key, node->Left());
  }

  // If search key is greater than the current node, search the right subtree
  else if (key > node->Key()){
      // search the right tree
      // cout << node->Key() << "->";
      findNode(key, node->Right());
  }

  // **************************** End of edits *********************************

}

// Print the BSTree
void BSTree::printPreorder(Node* node)
{
  // ******************** Edited by B. Gedvilas 10/30/2016 *********************
  // PRE:
  // POST: The nodes of the binary tree are printed in preorder
  // FUNC: Visits the nodes of a binary tree in preorder (visits node, visits
  //       left subtree, visits right subtree) and outputs the key at each node
  //       when it is visited.

  cout << node->Key() << endl; // in preorder we visit the node before any of its
                               // subtrees.

  if (node->Left() != nullptr) { // If the node has a left subtree,
    printPreorder(node->Left()); // recursively call the function on that branch
  }

  if (node->Right() != nullptr) { // If the node has a right subtree,
    printPreorder(node->Right()); // recursively call the function on that branch
  }

  // **************************** End of edits *********************************
}
void BSTree::printInorder(Node* node)
{
  // ******************** Edited by B. Gedvilas 10/30/2016 *********************
  // PRE:
  // POST: The nodes of the binary tree are printed in order
  // FUNC: Uses recursion to visit the nodes of the binary tree in order (visit
  //       left subtree, vist node, visit right subtree) and outputs the key at
  //       each node when it is visited.

  // If the node has a left subtree, recursively call function on that branch
  if (node->Left() != nullptr) {
    printInorder(node->Left());
  }

  // after the left tree is visited, vist the current node
  // cout << setw(9) << setfill('0') << node->Key() << "  " << node->getContact()->getLastName() << endl;

  cout << *node->getContact();

  // NOTE - visit node here!!!


  // then search the right subtree
  if (node->Right() != nullptr) {
    printInorder(node->Right());
  }

  // **************************** End of edits *********************************

}

void BSTree::printPostorder(Node* node)
{
  // ******************** Edited by B. Gedvilas 10/30/2016 *********************
  // PRE:
  // POST: The nodes of the binary tree are printed in postorder.
  // FUNC: Visits the nodes of a binary tree in postorder (visit left subtree,
  //       visit right subtree, visit node) and outputs the key at each node
  //       when it is visited.

  // Visit the left subtree of a node if it exists
  if (node->Left() != nullptr) {
    printPostorder(node->Left());
  }

  // visit the right subtree of a node if it exists
  if (node->Right() != nullptr) {
    printPostorder(node->Right());
  }

  cout << node->Key() << endl; // visit the node after its subtrees have been visited

  // **************************** End of edits *********************************
    // if ( node != nullptr)
    // {
    //
    //         }
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
Node* BSTree::min(Node* node)
{
    Node* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;

    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
Node* BSTree::max(Node* node)
{
    Node * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max(node->Right());
    else
        tempNode = node;

    return tempNode;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-BSTree to get the successor
Node* BSTree::successor(unsigned int key, Node *node)
{


    Node *successor = nullptr;
    Node *current  = root;
    if(root == nullptr)
        return NULL;

    while(current->Key() != key){
        /* If node value is greater than the node which are looking for, then go to left sub tree
         Also when we move left, update the successor pointer to keep track of lst left turn */

        if(current->Key() >key){
            successor = current;
            current= current->Left();
        }
        /* Else take right turn and no need to update successor pointer */
        else
            current = current->Right();
    }
    /*Once we reached at the node for which inorder successor is to be found, check if it has right sub tree,
    if yes then find the minimum in that right sub tree and return that node

     Else last left turn taken node is already stored in successor pointer and will be returned*/
    if(current && current->Right()){
        successor = min(current->Right());
    }

    return successor;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-BSTree to get the predecessor
Node* BSTree::predecessor(unsigned int key, Node *node)
{

    Node* current = findNode(key, node);

    if (current == nullptr)
        { return nullptr; }

    if (current->Left() !=nullptr)
    {
        return max(current->Left());
    } else

    {
        Node *tempParent = current->Parent();
        while (tempParent !=nullptr) {
            if (current == tempParent->Right() ){
                break;
            }
            current = tempParent;
            tempParent = current->Parent();
        }
        return tempParent;
    }
}


void BSTree::deleteNode(unsigned int key)
{
    if (deleteNode(Root(), key) == nullptr)
        setRoot(nullptr);
}

//deleteNode (Private)
Node* BSTree::deleteNode(Node* root, unsigned int key)
{

    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */


        if(root == nullptr) return root;
        else if(key < root->Key())
            root->setLeft( deleteNode(root->Left(),key));
        else if(key > root->Key())
            root->setRight( deleteNode(root->Right(), key) );
        else {
            // Case 1: No Child
            if(root->Left() == nullptr && root->Right() == nullptr){
                delete root;
                root = nullptr;
                // Case 2: one child
            } else if(root->Left() == nullptr){
                Node *temp = root;
                root = root->Right();
                delete temp;
            } else if(root->Right() == nullptr){
                Node *temp = root;
                root = root->Left();
                delete temp;
            } else{
                Node *temp = min(root->Right());
                root->setKey(temp->Key() );
                root->setRight(  deleteNode(root->Right(), temp->Key() ) );
            }
        }
        return root;

}


void visitNodes(Node* node) {

  // If the node has a left subtree, recursively call function on that branch
  if (node->Left() != nullptr) {
    visitNodes(node->Left());
  }

  // NOTE - node gets visited here
  cout << *node->getContact();

  // then search the right subtree
  if (node->Right() != nullptr) {
    visitNodes(node->Right());
  }
}