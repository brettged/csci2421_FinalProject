//##############################################################################
//
//
//  FileName: Node.h
//
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   11/29/2016
//  Edited by Brett Gedvilas at marked locations
//
//  Assignment: Final Project - c++ Database
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


//Placeholder for a composite data type
// class Datatype{
// private:
//     int number;
//
//
// };

//***************** End of Edits *****************

//Binary Tree Node
class Node {
private:
    unsigned int key; // changed datatype to unsigned int
    // Datatype data;

    //************ B. Gedvilas Edits *****************

    Record* dataPtr = nullptr; // Include a pointer to a record for each node

    //***************** End of Edits *****************

    Node* left;
    Node* right;
    Node* parent;
public:

  //************ B. Gedvilas Edits *****************

  // Node() { key = -1; left = nullptr; right = nullptr; parent = nullptr;};

    // Since the database BSTree is organized based upon the unique id number for
    // each entry, the node key will eventually get set to the id#.
    // I'll make the assertion that no contact will have a user id of 0 so that
    // will be used as the initialization value.
    Node() {key = 0; left = nullptr; right=nullptr; parent = nullptr;};

    // Destructor, must delete dynamically allocated Records
    ~Node() {
      delete dataPtr; // de-allocate the record the node points to
    }


    //***************** End of Edits *****************

    void setKey(unsigned int _key) { key = _key; }; // the key gets set to the contact id#
    void setLeft(Node* aLeft) { left = aLeft; };
    void setRight(Node* aRight) { right = aRight; };
    void setParent(Node* aParent) { parent = aParent; };
    unsigned int Key() { return key; };
    Node* Left() { return left; };
    Node* Right() { return right; };
    Node* Parent() { return parent; };


    //************* B. Gedvilas Edits ******************

    void setDataPtr(Record* _dataPtr) {dataPtr = _dataPtr;};
    Record* getContact() {return dataPtr;}; // returns pointer to contact info

    //**************** End of Edits ********************

};



#endif
