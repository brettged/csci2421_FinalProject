//##############################################################################
//
//
//  FileName: SearchData.h
//
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   11/29/2016
//
//
//  Assignment: Final Project - A c++ Database System
//
//
//  This file contains the definition of the SearchData class. This class contains
//  most of the functions for searching and outputing information from the database
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
    list<Record> subSearchResults;

    // Pointers to keep track of which list is currently in use
    list<Record>* current;
    list<Record>* previous;

    int fields[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; // array to keep track of which fields to print


  public:

    SearchData(); // constructor
    ~SearchData(); // destructor

    list<Record> getSearchResults();

    void clear(); // clears searchResults list

    string getTerm();

    int getField();

    unsigned int getSearchID();

    // Search functions, returns linked list of search results
    void searchTree(string searchTerm, int field, Node* node, bool exact);
    void subSearch(string searchTerm, int field, bool exact);
    Record* idSearch(unsigned int idNum, BSTree* tree); // search database for exact match on id# returns a pointer to the record
    bool affilSearch(string searchTerm, list<Affiliate> affil, bool exact); // searches the affiliates of record,
                                                                            // returns true if term in in affiliates, false if not

    bool searchAll(string searchTerm, Record* contact, bool exact);


    //************ Tools to sort the list of search results *************

    void sortList(int primary, int secondary);

    //*********** Tools to output results of search ***************

    void selectFields();
    void writeOut();

    string retField(Record* contact, int fNum) const;

    friend ostream& operator << (ostream& out, const SearchData& results);
    friend ofstream& operator << (ofstream& out, const SearchData& results);


}; // end of class


#endif