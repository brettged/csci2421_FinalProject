//##############################################################################
//
//
//  FileName: main.cpp
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
//  This file contains the main program driver for my c++ address book database.
//
//
//##############################################################################


// Include the Database class
#include "Database.h"
#include "BSTree.h"


#include <iostream>
using namespace std;

// Start of main method
int main() {

  // Create the database
  Database addressBook;

  // Display the main menu to the user, all other operations will be controlled
  // from within the Database menus

  addressBook.mainMenu();

  return 0;

} // End of main


// TODO - Secondary SearchData
// TODO - Finish Documentation
// TODO - Final test on cse getSearchID
// TODO - Error Detection