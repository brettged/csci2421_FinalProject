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

#include "Affiliate.h"
#include "Record.h"
#include "BSTree.h"

#include "Node.h"

class SearchData {

  private:

    list<Record> searchResults; // search result is a list of pointers, each points to a record
    list<Record> subSearch;

    // Pointers to keep track of which list is currently in use
    list<Record>* current;
    list<Record>* previous;


  public:

    SearchData();
    ~SearchData();


    list<Record> getSearchResults();


    void clear();

    string getTerm();

    int searchField();

    unsigned int getSearchID();

    // Search functions, returns linked lists of search results or maybe a BSTree
    void searchTree(string searchTerm, int field, Node* node, bool exact);
    void searchList(string searchTerm, int field, bool exact);
    // void containsSearch(string searchTerm, Node* node);
    Record* idSearch(unsigned int idNum, BSTree* tree); // search database for exact match on id# returns a pointer to the record
    bool affilSearch(string searchTerm, list<Affiliate> affil, bool exact); // searches the affiliates of record, returns true if term in in affiliates, false if not

    bool searchAll(string searchTerm, Record* contact, bool exact);


    friend ostream& operator << (ostream& out, const SearchData& results);
    friend ofstream& operator << (ofstream& out, const SearchData& results);


}; // end of class


#endif