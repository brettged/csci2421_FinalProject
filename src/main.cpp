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


// Start of main method
int main() {

  // First thing to do is create the database
  Database addressBook;

  // Initial read of data from file
  addressBook.readFile();

  // Display the main menu to the user, all other operations will be controlled
  // from within the Database menus
  addressBook.mainMenu();



  return 0;
} // End of main