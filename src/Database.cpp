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

  fileName = "databasesmall.txt";

  inFile.open(fileName);

  unsigned int tempInt; // Temporary variable to hold integer values
  string tempString; // Temporary variable to hold string values


  // The main while loop for reading in data from the file
  while (inFile >> tempInt) {

    Record* contactPtr = new Record; // dynamically allocate memory for a new contact

    size++; //increment size of database by 1

    contactPtr->setId(tempInt);

    inFile >> tempString;
    contactPtr->setFirstName(tempString);

    inFile >> tempString;
    contactPtr->setMidName(tempString);

    inFile >> tempString;
    contactPtr->setLastName(tempString);
    inFile.ignore();

    getline(inFile, tempString);
    contactPtr->setCompany(tempString);

    getline(inFile, tempString);
    contactPtr->setHomePhone(tempString);

    getline(inFile, tempString);
    contactPtr->setOffice(tempString);

    inFile >> tempString;
    contactPtr->setEmail(tempString);

    inFile.ignore();
    getline(inFile, tempString);
    contactPtr->setMobile(tempString);

    getline(inFile, tempString);
    contactPtr->setStAddr(tempString);

    getline(inFile, tempString);
    contactPtr->setCity(tempString);

    inFile >> tempString;
    contactPtr->setState(tempString);

    inFile >> tempString;
    contactPtr->setZipCode(tempString);

    inFile.ignore();
    getline(inFile, tempString);
    contactPtr->setCountry(tempString);


    getline(inFile, tempString); // grab the next line
                                 // either affiliate or |

    // if the next item isn't a | then we have some affiliates to
    // add to the record
    while (tempString != "|") {
      stringstream ss(tempString);

      // ss << tempString; // turn the entire line into a string stream
      // getline(ss, tempString, ' ');

      string token; // for stringstream tokens
      // Affiliate* tempAffil = new Affiliate; // create a pointer to temporary affiliate

      ss >> token;

      Affiliate tempAffil;

      // cout << token;
      // every affiliate has a first and last name
      tempAffil.setFirstName(token);

      // cout << tempAffil.getFirstName() << endl;

      ss.ignore(); // ignore space between first and last name

      // use getline to get the last name, not including comma
      // set lastName
      getline(ss, token, ',');
      tempAffil.setLastName(token);

      // cout << tempAffil.getLastName() << endl; // display last name

      // set phone number
      getline(ss, token, ',');
      tempAffil.setPhone(token);

      // cout << tempAffil.getPhone() << endl; // confirm phone

      // set email address
      getline(ss, token, ';');
      tempAffil.setEmail(token);
      // cout << tempAffil.getEmail() << endl; // confirm email


      contactPtr->addAffiliate(tempAffil); // add the affiliate to the record

      getline(inFile, tempString);


    }

    addEntry(contactPtr); // adds record to database tree
  }

  inFile.close();

}


//*******************************************************

// addEntry(Record)

// Precondition:
// Postcondition: A record is added to the database
// Functionality: This function allows the user to create
//                and enter a new entry int the database

//*******************************************************
void Database::addEntry() {

  Record* contactPtr = new Record;

  unsigned int tempInt;

  string tempString;

  do {

    cout << "Enter Unique 9 digit ID#: ";
    cin >> tempInt;
    contactPtr->setId(tempInt);

  } while(tempInt == (dataTree.findNode(tempInt, dataTree.Root()))->Key());


  cout << "    First Name: ";
  cin >> tempString;
  contactPtr->setFirstName(tempString);


  cout << "   Middle Name: ";
  cin >> tempString;
  contactPtr->setMidName(tempString);


  cout << "     Last Name: ";
  cin >> tempString;
  contactPtr->setLastName(tempString);
  cin.ignore();


  cout << "       Company: ";
  getline(cin, tempString);
  contactPtr->setCompany(tempString);


  cout << "    Home Phone: ";
  getline(cin, tempString);
  contactPtr->setHomePhone(tempString);


  cout << "  Office Phone: ";
  getline(cin, tempString);
  contactPtr->setOffice(tempString);


  cout << " Email Address: ";
  cin >> tempString;
  contactPtr->setEmail(tempString);


  cout << "  Mobile Phone: ";
  cin.ignore();
  getline(cin, tempString);
  contactPtr->setMobile(tempString);


  cout << "Street Address: ";
  getline(cin, tempString);
  contactPtr->setStAddr(tempString);


  cout << "          City: ";
  getline(cin, tempString);
  contactPtr->setCity(tempString);


  cout << "         State: ";
  cin >> tempString;
  contactPtr->setState(tempString);


  cout << "      Zip Code: ";
  cin >> tempString;
  contactPtr->setZipCode(tempString);


  cout << "       Country: ";
  cin.ignore();
  getline(cin, tempString);
  contactPtr->setCountry(tempString);


  char option;

  cout << "Do you have any affiliates to enter? (y/n) ";
  cin >> option;

  while (option == 'y') {

    Affiliate tempAffil;

    cout << "Affiliate First Name: ";
    cin >> tempString;
    tempAffil.setFirstName(tempString);


    cout << "Affiliate Last Name: ";
    cin >> tempString;
    tempAffil.setLastName(tempString);


    cin.ignore();
    cout << "Affiliate Phone Number: ";
    getline(cin, tempString);
    tempAffil.setPhone(tempString);


    cout << "Affiliate Email: ";
    getline(cin, tempString);
    tempAffil.setEmail(tempString);


    contactPtr->addAffiliate(tempAffil); // add the affiliate to the record

    cout << "Enter another affiliate? (y/n) ";
    cin >> option;
  }

  cout << "Adding entry..." << endl;
  addEntry(contactPtr);


}






//*******************************************************

// addEntry(Record)

// Precondition:
// Postcondition: A record is added to the database
// Functionality: This function creates a node out of the Record and
//                inserts the node into the database tree

//*******************************************************
void Database::addEntry(Record* _contactPtr) {


  dataTree.addNode(_contactPtr);


}
