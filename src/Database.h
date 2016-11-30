//##############################################################################
//
//
//  FileName: Database.h
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
//  This file contains the definition of the Database class. This class contains
//  the Binary Search Tree that will be the main structure of the database, a
//  SearchList object that will contain the results of database queries, and
//  a size member variable representing the number of records in the database.
//
//
//
//##############################################################################

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <list>


#include "BSTree.h"
#include "Record.h"
#include "SearchData.h"

using std::list;

class Database {


  private:

    BSTree dataTree; // The main structure of the database is a binary search tree.
    unsigned int size = 0; // number of entries in the BSTree

    SearchData searchList; // search results are contained in their own class

    // Private addEntry and removeEntry
    void addEntry(Record* contactPtr);
    void removeEntry(unsigned int idNum); // delete an entry from database

  public:


    //************** Constructor/Destructor **************
    Database();
    ~Database();

    bool validateID(unsigned int); // validates a new ID#

    //********** Database Accessors ***********

    unsigned int getSize() {return size;}; // get number of entries in database
    BSTree* getDataTree() {return &dataTree;}; // return a pointer to the binary tree
    SearchData getSearchResults(); // returns the searchData member variable
    void visitNodes(Node* node); // visits node in order

    //********** Database Mutators ***********

    void readFile(); // opens an external file and adds entries to database.
    void modifyEntry(); // allows user to modify an existing entry
    void addEntry(); // user inputs information for a new contact
    void removeEntry(); // deletes an entry from the database


    // Output functions for database

    // void sortList();
    string getSearchTerm();

    // Menu functions
    //*********** Main menu ***********************

    void mainMenu(); // displays main menu to user

    //********** Sub-menus **************

        // Search Menus
    void searchMenu();
    void searchSubMenu();
    void searchAgain();

    void updateMenu(); // sub-menu for modifying the database

    void outputDataMenu(); // sub-menu for displaying database entries to the screen
    void chooseFieldsMenu(); // menu allowing user to pick which fields to display or search from
    void sortMenu(); // menu to chose sorting of search results

};


#endif