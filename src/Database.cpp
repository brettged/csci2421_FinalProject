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
#include "SearchData.h"

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


void Database::readFile() {
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

  ifstream inFile; // create input file object
  string fileName;

  // Prompt the user to enter the filename to read
  // cout << "Enter the file name to read into the database: ";
  // cin >> fileName;

  fileName = "databasesmall.txt";

  inFile.open(fileName);

  // Error check to see if file successfully opened
  if(!inFile) {
    cout << "Error! Could not open file: " << fileName << endl;
    return;
  }

  cout << endl << "reading file..." << endl << endl;

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

bool Database::validateID(unsigned int testID) {
  //*******************************************************

  // invalidID(unsigned int)

  // Precondition:
  // Postcondition:
  // Functionality: This function tests the database to see
  //                if the argument passed to the function
  //                is already in the database. Returns true
  //                if testID is not in database, false if it is
  //                in the database

  //*******************************************************

  bool valid;

  // start at root of tree and try to find a node with the new id number
  valid = (testID != (dataTree.findNode(testID, dataTree.Root()))->Key());

  return valid; // return true if number is unique, false if not
}

void Database::addEntry() {
  //*******************************************************

  // addEntry(Record)

  // Precondition:
  // Postcondition: A record is added to the database
  // Functionality: This function allows the user to create
  //                and enter a new entry int the database

  //*******************************************************

  Record* contactPtr = new Record;

  unsigned int tempInt;

  string tempString;

  bool validID = false;

  do {
    cout << "Enter Unique 9 digit ID#: ";
    cin >> tempInt;

    validID = validateID(tempInt);

    // if the id is invalid display error message
    if (!validID) {
      cout << "ID# already exists" << endl;
    }

  } while(!validID);

  contactPtr->setId(tempInt);


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
  addEntry(contactPtr); // call private addEntry()

}

void Database::addEntry(Record* _contactPtr) {
  //*******************************************************

  // addEntry(Record) - public

  // Precondition:
  // Postcondition: A record is added to the database
  // Functionality: This function creates a node out of the Record and
  //                inserts the node into the database tree

  //*******************************************************

  dataTree.addNode(_contactPtr);
  size++;

}

void Database::removeEntry() {

  unsigned int idNum;
  cout << "Enter ID number of record: ";
  cin >> idNum;

  if (!validateID(idNum)) {
    // dataTree.deleteNode(idNum); CHANGED
    removeEntry(idNum);
  }

  else {
    cout << "No Record Found" << endl;
  }

}

void Database::removeEntry(unsigned int idNum) {
  //*******************************************************

  // removeEntry()

  // Precondition:
  // Postcondition: A record is deleted from the database
  // Functionality: This function deletes a record from the
  //                database based on a unique id#

  //*******************************************************

  dataTree.deleteNode(idNum);
  size--;
}

void Database::modifyEntry() {

  unsigned int idNum;
  cout << "Enter ID# of record to modify: ";
  cin >> idNum;

  while(validateID(idNum)) {
    cout << "Invalid ID#" << endl;
    cout << "Enter ID# of record to modify: ";
    cin >> idNum;
  }

  Record* ptr = searchList.idSearch(idNum, &dataTree); // get the record from database

  cout << *ptr << endl; // display the record

  char modify = 'y';


  while(modify == 'y' || modify == 'Y') {

    int field = searchList.getField();


    // modifiying an affiliate field function slightly differently
    if (field == 14) {


    }

    string newField = searchList.getTerm();

    switch(field) {
      case 1:
        ptr->setFirstName(newField);
        break;
      case 2:
        ptr->setMidName(newField);
        break;
      case 3:
        ptr->setLastName(newField);
        break;
      case 4:
        ptr->setCompany(newField);
        break;
      case 5:
        ptr->setHomePhone(newField);
        break;
      case 6:
        ptr->setOffice(newField);
        break;
      case 7:
        ptr->setEmail(newField);
        break;
      case 8:
        ptr->setMobile(newField);
        break;
      case 9:
        ptr->setStAddr(newField);
        break;
      case 10:
        ptr->setCity(newField);
        break;
      case 11:
        ptr->setState(newField);
        break;
      case 12:
        ptr->setZipCode(newField);
        break;
      case 13:
        ptr->setCountry(newField);
        break;
      case 15:
        newField = searchList.getTerm();
        ptr->setFirstName(newField);

        newField = searchList.getTerm();
        ptr->setMidName(newField);

        newField = searchList.getTerm();
        ptr->setLastName(newField);

        newField = searchList.getTerm();
        ptr->setCompany(newField);

        newField = searchList.getTerm();
        ptr->setHomePhone(newField);

        newField = searchList.getTerm();
        ptr->setOffice(newField);

        newField = searchList.getTerm();
        ptr->setEmail(newField);

        newField = searchList.getTerm();
        ptr->setMobile(newField);

        newField = searchList.getTerm();
        ptr->setStAddr(newField);

        newField = searchList.getTerm();
        ptr->setCity(newField);

        newField = searchList.getTerm();
        ptr->setState(newField);

        newField = searchList.getTerm();
        ptr->setZipCode(newField);

        newField = searchList.getTerm();
        ptr->setCountry(newField);
      }

      cout << "Change another field? (y/n) ";
      cin >> modify;
  }

  cout << *ptr << endl; // display the update record

}

// Record* Database::idSearch(unsigned int idNum) {
//   // *******************************************************
//   //
//   // idSearch()
//   //
//   // Precondition:
//   // Postcondition:
//   // Functionality:
//   // *******************************************************
//
//   Node* nPtr;
//   nPtr = dataTree.findNode(idNum, dataTree.Root()); // find the node with the key to delete
//
//   if (nPtr == nullptr) {
//     return nullptr;
//   }
//
//   return nPtr->getContact(); // return a pointer to record from the node
//
// }



string Database::getSearchTerm() {

  string searchTerm;
  cout << "Enter the search term: ";
  cin >> searchTerm;

  return searchTerm;

}

// list<Record> Database::exactSearch(string searchTerm) {
//
// }
//
// list<Record> Database::containsSearch(string searchTerm) {
//
//
// }

void Database::sortList() {

  int menuOption;

  cout << "Select Category to Sort Search Results: " << endl;
  cout << "1. ID#" << endl
       << "2. Last Name" << endl
       << "3. Company Name" << endl
       << "4. State" << endl
       << "5. Country" << endl
       << "6. City" << endl
       << ": ";

  cin >> menuOption;

  switch (menuOption)
  {
  case 1:
    // already sorted by id number
    break;

  case 2:
    searchList.sortLastName();
    break;
  case 3:
    searchList.sortCompany();
    break;
  case 4:
    searchList.sortState();
    break;
  case 5:
    searchList.sortCountry();
    break;
  case 6:
    searchList.sortCity();
    break;

  default:
    cout << "That is not a valid choice" << endl;
    break;
  }


  // searchList.searchTree("CO", 11, dataTree.Root(), true);
  // // searchList.sortLastName();
  // searchList.sortCompany();

  cout << searchList;

}


//********************** Menu Functions ****************************


void Database::mainMenu() {
  //*******************************************************

  // mainMenu()

  // Precondition:
  // Postcondition:
  // Functionality:
  //*******************************************************

  int menuOption; // user menu choice

  bool runProgram = true;

  while(runProgram) {

    cout << "Main Menu:" << endl;
    cout << "----------" << endl;

    cout << "1. Read Data File" << endl
         << "2. Update Database" << endl
         << "3. Browse Records" << endl
         << "4. Search Database" << endl
         << "5. Write Data to File" << endl
         << "0. Exit" << endl
         << ": ";

    cin >> menuOption;

    cout << endl;

    switch(menuOption) {

    case 1:
      readFile();
      break;

    case 2:
      updateMenu();
      break;

    case 3:
      outputDataMenu();
      break;

    case 4:
      searchMenu();
      break;

    case 5:
      // writeOut(); // writes current database to file
      break;

    case 0:
      runProgram = false;
      cout << "Goodbye" << endl;
      break;

    default:
      cout << "That is not a valid choice. Please choose from the given options" << endl;

    }

    cout << endl;
  }

  return;
}


void Database::searchMenu() {

  cout << "Search Database" << endl;
  cout << "---------------" << endl;

  int menuOption;
  bool menu = true;

  int field;
  string term;

  while(menu) {

    cout  << "1. Search for ID#" << endl
          << "2. Search by exact matches" << endl
          << "3. Search by matches containing" << endl
          << "4. Main Menu" << endl
          << ": ";

    cin >> menuOption;

    switch(menuOption) {

      // Search the database for an id number
    case 1:
      Record* ptr;
      ptr = searchList.idSearch(searchList.getSearchID(), getDataTree());
      cout << endl; // for readability

      if (ptr != nullptr) {
        cout << *ptr;
      }
      else {
        cout << "No record found" << endl;
      }
      cout << endl;

      break;

      // Search database for an exact match
    case 2:
      field = searchList.getField();
      term = searchList.getTerm();
      searchList.searchTree(term, field, dataTree.Root(), true);
      searchSubMenu(); // after search, go to subsearch menu
      break;

      // Search database for containing
    case 3:
      field = searchList.getField();
      term = searchList.getTerm();
      searchList.searchTree(term, field, dataTree.Root(), false);
      searchSubMenu(); // go to subsearch menu
      break;

    case 4:
      menu = false;
      break;

    default:
      cout << "That is not a valid choice. Please choose from the given options" << endl;

    }
  }
}

void Database::searchSubMenu() {

  cout << endl;
  cout << "Search Results" << endl;
  cout << "--------------" << endl;

  int menuOption;
  bool menu = true;


  while(menu) {

    cout << endl << "Your search returned " << searchList.getSearchResults().size()
    << " results" << endl << endl;

    cout << "1. Refine Search Results" << endl
         << "2. New Search" << endl
         << "3. Browse Results" << endl
         << "4. Modify an Entry" << endl
         << "5. Write search results to file" << endl
         << "6. Remove an Entry from Database" << endl
         << "7. Back to Search Menu" << endl
         << ": ";

    cin >> menuOption;
    cin.ignore();

    // menuOption = 5;

    switch(menuOption) {

      case 1:
        searchAgain(); // keep current results and allow user to search again
        break;

      case 2:
        searchList.clear(); // clear results and then return to search menu
        menu = false;
        break;

      case 3:
        cout << searchList; // display search results to the screen
        break;

      case 4:
        modifyEntry();
        break;

      case 5:
        outputDataMenu();
        break;

      case 6:
        removeEntry();

      case 7:
        menu = false;
        break;

      default:
        cout << "That is not a valid choice. Please choose from the given options" << endl;

      }

  }
}

void Database::searchAgain() {

  cout << "Sub Search" << endl;
  cout << "----------" << endl;

  int menuOption;
  bool menu = true;

  int field;
  string term;

  while(menu) {

    cout << "1. Search for ID#" << endl
         << "2. Search for exact matches" << endl
         << "3. Search for matches containing" << endl
         << "4. Go Back" << endl
         << ": ";

    cin >> menuOption;

    switch(menuOption) {

    case 1:
      Record* ptr;
      ptr = searchList.idSearch(searchList.getSearchID(), getDataTree());
      cout << endl; // for readability

      if (ptr != nullptr) {
        cout << *ptr;
      }
      else {
        cout << "No record found" << endl;
      }
      cout << endl;
      break;

    case 2:
      field = searchList.getField();
      term = searchList.getTerm();
      searchList.subSearch(term, field, true);
      menu = false;
      break;

    case 3:
      field = searchList.getField();
      term = searchList.getTerm();
      searchList.subSearch(term, field, false);
      menu = false;
      break;

    case 4:
      menu = false;
      break;

    default:
      cout << "That is not a valid choice. Please choose from the given options" << endl;

    }

  }

}

void Database::updateMenu() {
  // TODO - updata menu shit

  cout << "Modify Database" << endl;
  cout << "---------------" << endl;

  int menuOption;
  bool menu = true;

  while(menu) {

    cout << "1. Add New Record" << endl
         << "2. Modify Record" << endl
         << "3. Delete Record" << endl
         << "4. Go Back" << endl
         << ": ";

    cin >> menuOption;

    switch(menuOption) {

      case 1:
        addEntry();
        break;
      case 2:
        modifyEntry();
        break;
      case 3:

        cout << "1. Search for a Record"
             << "2. Enter ID# of Record to remove"
             << ": ";

        cin >> menuOption;

        if (menuOption == 1) {
          searchMenu();
        }
        removeEntry();
        break;
      case 4:
        menu = false;

      default:
        cout << "That is not a valid choice. Please choose from the given options" << endl;

    }

  }


}

void Database::outputDataMenu() {
  // TODO - figure out display stuff
  // cout << "Browse data menu called" << endl;

  int menuOption;
  bool menu = true;

  cout << endl;
  cout << "Output Database" << endl;
  cout << "---------------" << endl << endl;

  while(menu) {

    cout << "1. Write Current Search Results to File" << endl
         << "2. Chose Sorting Order" << endl
         << "3. Select Fields to Write" << endl
         << "4. Back" << endl
         << ": ";

    cin >> menuOption;
    // menuOption = 3;

    switch(menuOption) {

      case 1:
        searchList.writeOut();
        break;

      case 2:
        sortList();
        break;

      case 3:
        searchList.selectFields();
        searchList.writeOut();
        break;

      case 4:
        menu = false;
        break;

      default:
        cout << "That is not a valid choice. Please choose from the given options" << endl;

    }

  }

}

void Database::sortMenu() {

  int menuOption;
  cout << "Select Which Field to Sort Search Results By: ";

  cout << "1. Last Name" << endl
       << "2. Company Name" << endl
       << "3. State" << endl
       << "4. Country" << endl
       << "5. City" << endl
       << "6. Go Back" << endl
       << ": ";

  cin >> menuOption;

  while(menuOption > 6 || menuOption < 1) {
    cout << "Please Enter a valid menu choice: ";
    cin >> menuOption;
  }

  switch(menuOption) {

    case 1:
      searchList.sortLastName();
      break;
    case 2:
      searchList.sortCompany();
      break;
    case 3:
      searchList.sortState();
      break;
    case 4:
      searchList.sortCountry();
      break;
    case 5:
      searchList.sortCity();
      break;
    case 6:
      break;

  }


}