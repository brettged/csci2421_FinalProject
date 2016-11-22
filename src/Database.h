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


using std::list;

class Database {

  private:

  //  BSTree dataTree; // The main structure of the database is a binary search tree.
    //BSTree nameTree; // A binary search tree using the last name field as key.
    int size; // number of entries in the BSTree

    list<Record> searchResults; // searches return a linked list in this variable

  public:


    // ************** Constructors *************
    Database();
    ~Database();


    bool validateID(unsigned int); // validates a new ID#


    // Basic functions for adding and removing data from database

    void readFile(); // opens an external file and adds entries to database
    void modifyEntry(); // allows user to modify an existing entry
    void addEntry(); // user inputs information for a new contact

    // overloaded addEntry adds a complete contact
    void addEntry(Record contact);


    void removeEntry(); // delete an entry from database


    // Output functions for database
    void writeOut(); // writes database to file
    void writeOut(list<Record>); // writes the results of a search to a file

    void display(); // displays the current database
    void display(list<Record>); // displays the results of a search


    // Search functions, returns linked lists of search results or maybe a BSTree
    list<Record> exactSearch(string searchTerm);
    list<Record> containsSearch(string searchTerm);

    // NOTE - Sorting functions
    // Sorting a linked list of search results using the list sort function would
    // require an overloaded operator <. This would only allow sorting based on
    // one field though.


    // Menu functions
    //*********** Main menu ***********************

    void mainMenu(); // displays main menu to user

                     // Menu options:
                     //   -browse contacts
                     //   -search contacts
                     //   -update database

    //********** Main menu sub-menus **************

    void searchMenu(); // search database sub-menu


    void updateMenu(); // sub-menu for updating a database entry:
                       // add new entry
                       // modify existing
                       // delete entry


    void displayDataMenu(); // sub-menu for displaying database entries to the screen


    void chooseFieldsMenu(); // menu allowing user to pick which fields to display or search from



    int getFields(); // displays all the possible fields in numbered list and returns
                    // an integer entered by the user indicating the desired field


};


#endif