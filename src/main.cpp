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


void outputDriver(Database adrBook);

// Start of main method
int main() {

  // Create the database
  Database addressBook;

  // Display the main menu to the user, all other operations will be controlled
  // from within the Database menus

  addressBook.readFile();


  // outputDriver(addressBook);

  addressBook.mainMenu();

  // addressBook.sortList();

  // addressBook.searchMenu();

  return 0;

} // End of main


// Test Driver Functions


// TODO - Search Results output to file
//      - Fix menu flow
//      - add delete record option to search menus


// void outputDriver(Database adrBook) {
//
//
//   adrBook.sortList();
//
//
// }