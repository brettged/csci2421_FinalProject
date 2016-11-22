//##############################################################################
//
//
//  FileName: Database.cpp
//
//
//  Author: Brett Gedvilas
//  Class:  CSCI 2421
//  Date:   11/17/2016
//
//
//  Assignment: Final Project - A c++ Database System
//
//
//  This file contains the implementation of the Database class
//
//
//
//##############################################################################


#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


#include "Database.h"
#include "Record.h"

using std::fstream;
using std::cout;
using std::cin;
using std::string;

Database::Database() {
  // default constructor
}


Database::~Database() {
  // destructor
}



//*******************************************************

// readFile()
//
// Precondition:
// Postcondition: The calling Database object will be populated
//                with contact data from a file
// Functionality: This function prompts the user to enter a file
//                name to read from. It reads the data from the
//                file and inserts each record into the database

//*******************************************************

void Database::readFile() {

  ifstream inFile; // create input file object
  string fileName;

  // Prompt the user to enter the filename to read
  //cout << "Enter the file name to read into the database: ";
  //cin >> fileName;

  ofstream outFile;
  outFile.open("testOut.txt");

  fileName = "databasesmall.txt";

  inFile.open(fileName);

  unsigned int tempInt; // Temporary variable to hold integer values
  string tempString; // Temporary variable to hold string values

  Record tempRecord; // Only create one Record object, can keep overwriting it
                     // to insert into Database

  // The main while loop for reading in data from the file
  while (inFile >> tempInt) {

    size++; //increment size of database by 1

    tempRecord.setId(tempInt);

    inFile >> tempString;
    tempRecord.setFirstName(tempString);

    inFile >> tempString;
    tempRecord.setMidName(tempString);

    inFile >> tempString;
    tempRecord.setLastName(tempString);
    inFile.ignore();

    getline(inFile, tempString);
    // inFile >> tempString;
    tempRecord.setCompany(tempString);

    getline(inFile, tempString);
    tempRecord.setHomePhone(tempString);

    getline(inFile, tempString);
    tempRecord.setOffice(tempString);

    inFile >> tempString;
    tempRecord.setEmail(tempString);

    inFile.ignore();
    getline(inFile, tempString);
    tempRecord.setMobile(tempString);

    getline(inFile, tempString);
    tempRecord.setStAddr(tempString);

    getline(inFile, tempString);
    tempRecord.setCity(tempString);

    inFile >> tempString;
    tempRecord.setState(tempString);

    inFile >> tempString;
    tempRecord.setZipCode(tempString);

    inFile.ignore();
    getline(inFile, tempString);
    tempRecord.setCountry(tempString);

    // TODO - loop here to add affiliates

    getline(inFile, tempString); // grab the next line
                                 // either affiliate or |



    // if the next item isn't a | then we have some affiliates to
    // add to the record
    while (tempString != "|") {
      stringstream ss(tempString);

      // ss << tempString; // turn the entire line into a string stream
      // getline(ss, tempString, ' ');

      string token; // for stringstream tokens
      // Affiliate* affilPtr = new Affiliate; // create a pointer to temporary affiliate

      ss >> token;

      Affiliate affilPtr;

      // cout << token;
      // every affiliate has a first and last name
      affilPtr.setFirstName(token);

      // cout << affilPtr.getFirstName() << endl;

      // use getline to get the last name, not including comma

      ss.ignore(); // ignore space between first and last name

      getline(ss, token, ',');
      affilPtr.setLastName(token);

      // cout << affilPtr.getLastName() << endl; // display last name

      // set phone number
      getline(ss, token, ',');
      affilPtr.setPhone(token);

      // cout << affilPtr.getPhone() << endl; // confirm phone

      // set email address
      getline(ss, token, ';');
      affilPtr.setEmail(token);
      // cout << affilPtr.getEmail() << endl; // confirm email


      tempRecord.addAffiliate(affilPtr); // add the affiliate to the record

      getline(inFile, tempString);


    }


    // cout << tempRecord;

    outFile << tempRecord;

    // TODO - add the record to the database

    tempRecord.clearAll(); // clear data from tempRecord in preparation for
                           // next item

  }

  inFile.close();
  outFile.close();

}


//*******************************************************

// addEntry(Record)
//
// Precondition:
// Postcondition: Record object parameter is added to the database
// Functionality: This function creates a node out of the Record and
//                inserts the node into the database tree

//*******************************************************

// TODO - all this shit
// void Database::addEntry(Record _contact) {
//
//   Node
//
//
// }