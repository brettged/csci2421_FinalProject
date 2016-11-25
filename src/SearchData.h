//##############################################################################
//
//
//  FileName: SearchSort.h
//
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   11/24/2016
//
//
//  Assignment: Final Project - A c++ Database System
//
//
//  This file contains the definition of the SearchSort class
//
//
//
//##############################################################################


#ifndef SEARCHDATA_H
#define SEARCHDATA_H


#include <iostream>
#include <list>

// #include "Database.h"
#include "Record.h"
// #include "Affiliate.h"

#include "Node.h"

class SearchData {

  private:

    list<Record*> searchResults; // search result is a list of pointers, each points to a record

  public:

    SearchData();
    ~SearchData();


    // list<Record> getSearchResults;

    string getTerm();

    int searchField();

    // Search functions, returns linked lists of search results or maybe a BSTree
    void exactSearch(string searchTerm, int field, Node* node);
    // list<Record> containsSearch(string searchTerm, Database &data);
    // Record* idSearch(unsigned int idNum); // search database for exact match on id# returns a pointer to the record


    friend ostream& operator << (ostream& out, const SearchData& results);
    friend ofstream& operator << (ofstream& out, const SearchData& results);


}; // end of class


#endif