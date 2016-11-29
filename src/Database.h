//##############################################################################
//
//
//  FileName: Database.h
//
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   10/30/2016
//
//
//  Assignment: Final Project - A c++ Database System
//
//
//  This file contains the definition of the Database class. This is the class
//  that will contain the database
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
#include "Affiliate.h"
#include "SearchData.h"

using std::list;

class Database {


  private:

    BSTree dataTree; // The main structure of the database is a binary search tree.
    //BSTree nameTree; // A binary search tree using the last name field as key.
    unsigned int size; // number of entries in the BSTree

    // list<Record> searchResults; // searches return a linked lisrt in this variable

    SearchData searchList; // search results are contained in their own class

    // overloaded addEntry adds a complete contact
    void addEntry(Record* contactPtr);
    void removeEntry(unsigned int idNum); // delete an entry from database

  public:


    //************** Constructors **************
    Database();
    ~Database();

    bool validateID(unsigned int); // validates a new ID#


    // Basic functions for adding and removing data from database

    void readFile(); // opens an external file and adds entries to database.
                     // Returns true if successful, false if not
    void modifyEntry(); // allows user to modify an existing entry
    void addEntry(); // user inputs information for a new contact


    void removeEntry();


    // Output functions for database

    void sortList();


    BSTree* getDataTree() {return &dataTree;};
    unsigned int getSize() {return size;};
    void clear();

    // unsigned int getSearchID();
    string getSearchTerm();


    SearchData getSearchResults(); // returns the linked list of search results


    void outputResults(); // handles the sorting and output of results to a file


    // Menu functions
    //*********** Main menu ***********************

    void mainMenu(); // displays main menu to user

                     // Menu options:
                     //   -browse contacts
                     //   -search contacts
                     //   -update database

    //********** Main menu sub-menus **************

    void searchMenu(); // search database menu
    void searchSubMenu();
    void searchAgain();

    void updateMenu(); // sub-menu for updating a database entry:
                       // add new entry
                       // modify existing
                       // delete entry

    void outputDataMenu(); // sub-menu for displaying database entries to the screen
    void sortMenu();

    void chooseFieldsMenu(); // menu allowing user to pick which fields to display or search from

    int getFields(); // displays all the possible fields in numbered list and returns
                    // an integer entered by the user indicating the desired field


};


#endif