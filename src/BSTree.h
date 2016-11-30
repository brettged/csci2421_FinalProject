//##############################################################################
//
//
//  FileName: BSTree.h
//  Adapted from BSTree.h by Dr. Tom Agustine
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   11/29/2016
//  Edited by Brett Gedvilas at marked locations
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

    // CHANGED - addNode modified to take a Record pointer instead of int as arg
    // void addNode(int key, Node* leaf);
    void addNode(Record* contactPtr, Node* leaf);

    Node* deleteNode(Node* node, unsigned int key);
    void freeNode(Node* leaf);
public:
    BSTree();
    ~BSTree();
    Node* Root() { return root; }
    void setRoot(Node * _root) {root = _root;}

    // ***** B. Gedvilas edits 11/22/2016 *****
    // CHANGED - changed parameter of public addNode function
    // void addNode(int key);
    void addNode(Record* contactPtr);

    // ******** End Edits *********

    Node* findNode(unsigned int key, Node* parent);
    void printPreorder(Node* node);
    void printInorder(Node* node);
    void printPostorder(Node* node);


    void deleteNode(unsigned int key); // CHANGED to unsigned int

    Node* min(Node* node);
    Node* max(Node* node);
    Node* successor(unsigned int key, Node* parent); // CHANGED to unsigned int
    Node* predecessor(unsigned int key, Node* parent); // CHANGED to unsigned int

};


#endif  //BST
