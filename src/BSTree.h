//##############################################################################
//
//
//  FileName: BSTree.h
//  Adapted from BSTree.h by Dr. Tom Agustine
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   11/23/2016
//
//
//  Assignment: Final Project - A c++ Database System
//
//
//  Header file with class prototype for BSTree.
//
//
//
//##############################################################################



#ifndef BSTREE_
#define BSTREE_
#include <iostream>
using namespace std;
#include "Node.h"

// Binary Search Tree class
class BSTree {
private:
    Node* root;
    void addNode(Record* contactPtr, Node* leaf);
    Node* deleteNode(Node* node, unsigned int key);
    void freeNode(Node* leaf);
public:
    BSTree();
    ~BSTree();
    Node* Root() { return root; }
    void setRoot(Node * _root) {root = _root;}
    // void addNode(int key);
    //
    // ***** B. Gedvilas edits 11/22/2016 *****

    void addNode(Record* contactPtr);


    // ******** End Edits *********

    Node* findNode(unsigned int key, Node* parent);
    void printPreorder(Node* node);
    void printInorder(Node* node);
    void printPostorder(Node* node);


    void deleteNode(unsigned int key);

    Node* min(Node* node);
    Node* max(Node* node);
    Node* successor(unsigned int key, Node* parent);
    Node* predecessor(unsigned int key, Node* parent);


    // void deleteTree(Node* node);

};
#endif  //BST
