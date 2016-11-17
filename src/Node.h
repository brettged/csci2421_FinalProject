//##############################################################################
//
//
//  FileName: Node.h
//
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   10/30/2016
//  Edited by Brett Gedvilas at marked locations
//
//  Assignment: Final Project - A c++ Database System
//
//
//  This file contains the Node class prototype.
//
//
//
//##############################################################################

#ifndef NODE_
#define NODE_
#include <iostream>
using namespace std;

// A generic tree node class

//************ B. Gedvilas Edits *****************

#include "Record.h" // include the Record class

//***************** End of Edits *****************



//Placeholder for a composite data type
// class Datatype{
// private:
//     int number;
//
//
// };

//Binary Tree Node
class Node {
private:
    unsigned int key; // changed datatype to unsigned int
    // Datatype data;

    //************ B. Gedvilas Edits *****************

    Record contact; // Include an instance of a record in each node

    //***************** End of Edits *****************

    Node* left;
    Node* right;
    Node* parent;
public:
    // Node() { key = -1; left = nullptr; right = nullptr; parent = nullptr;};

    //************ B. Gedvilas Edits *****************

    // Since the database BSTree is organized based upon the unique id number for
    // each entry, the node key will eventually get set to the id#.
    // I'll make the assertion that no contact will have a user id of 0 so that
    // will be used as the initialization value.
    Node() {key = 0; left = nullptr; right=nullptr; parent = nullptr;};

    //***************** End of Edits *****************

    void setKey() { key = contact.getId(); }; // the key gets set to the contact id#
    void setLeft(Node* aLeft) { left = aLeft; };
    void setRight(Node* aRight) { right = aRight; };
    void setParent(Node* aParent) { parent = aParent; };
    int Key() { return key; };
    Node* Left() { return left; };
    Node* Right() { return right; };
    Node* Parent() { return parent; };


    //************* B. Gedvilas Edits ******************

    Record getContact() {return contact;}; // returns the contact from the node

    //**************** End of Edits ********************

};



#endif