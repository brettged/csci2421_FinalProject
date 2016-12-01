//##############################################################################
//
//
//  FileName: Database.cpp
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
//  This file contains the implementation of the Database class
//
//
//
//##############################################################################


#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "BSTree.h"
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
  cout << "Enter the file name to read into the database: ";
  cin >> fileName;

  inFile.open(fileName); // open file

  // Error check to see if file successfully opened
  if(!inFile) {
    cout << "Error! Could not open file: " << fileName << endl;
    return;
  }

  cout << endl << "reading file... ";

  unsigned int tempInt; // Temporary variable to hold integer values
  string tempString; // Temporary variable to hold string values

  // The main while loop for reading in data from the file
  while (inFile >> tempInt) {

    Record* contactPtr = new Record; // dynamically allocate memory for a new contact

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

      getline(inFile, tempString); // get next line in the file
    }

    addEntry(contactPtr); // adds record to database tree

  }

  cout << getSize() << " Records added to database." << endl;
  inFile.close(); // close the file

}

bool Database::validateID(unsigned int testID) {
  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: This function tests the database to see
  //                if the argument passed to the function
  //                is already in the database. Returns true
  //                if testID is not in database, false if it is
  //                in the database

  //*******************************************************

  // bool valid;

  // start at root of tree and try to find a node with the new id number

  if (dataTree.findNode(testID, dataTree.Root()) == nullptr) {
    return true;
  }
  else {
    return false;
  }
  //
  // valid = (testID != (dataTree.findNode(testID, dataTree.Root()))->Key());
  //
  // return valid; // return true if number is unique, false if not
}

void Database::addEntry() {
  //*******************************************************

  // Public addEntry()

  // Precondition:
  // Postcondition: A record is added to the database
  // Functionality: This function allows the user to create
  //                and enter a new entry int the database

  //*******************************************************

  Record* contactPtr = new Record; // dynamically allocate memory for a new Record

  // temporary variables to hold fields
  unsigned int tempInt;
  string tempString;

  bool validID = false;

  do {
    // get ID# from user and check to see if it is already in database
    cout << "Enter Unique 9 digit ID#: ";
    cin >> tempInt;

    validID = validateID(tempInt);

    // if the id is invalid display error message
    if (!validID) {
      cout << "ID# already exists" << endl;
    }

  } while(!validID);

  contactPtr->setId(tempInt); // set id number

  // Prompt user for all the fields of the new contact
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

  // Check to see if any affiliates need to be added
  cout << "Do you have any affiliates to enter? (y/n) ";
  cin >> option;

  while (option == 'y') {

    contactPtr->addAffiliate(); // add the affiliate to the record

    cout << "Enter another affiliate? (y/n) ";
    cin >> option;
  }

  cout << "Adding entry..." << endl;
  addEntry(contactPtr); // add the entry to the database

}

void Database::addEntry(Record* _contactPtr) {
  //*******************************************************

  // Private addEntry function

  // Precondition:
  // Postcondition: A record is added to the database
  // Functionality: This function creates a node out of the Record and
  //                inserts the node into the database tree

  //*******************************************************

  dataTree.addNode(_contactPtr); // add node to BSTree with a pointer to a new contact
  size++; // increase size of database

}

void Database::removeEntry() {
  //*******************************************************

  // Public removeEntry()

  // Precondition:
  // Postcondition: A node is removed from the database
  // Functionality: This function prompts the user for a id#
  //                and removes that Record from the database
  //                if the id# is in the database, and displays
  //                an error message if it's not in the database

  //*******************************************************
  unsigned int idNum;
  cout << "Enter ID number of record: ";
  cin >> idNum;

  if (!validateID(idNum)) { // make sure the id# of the contact to delete is in the database
    removeEntry(idNum); // call private remove entry to delete node/contact info
    cout << "Successfully Removed!" << endl;
  }

  else {
    cout << "No Record Found" << endl;
  }

}

void Database::removeEntry(unsigned int idNum) {
  //*******************************************************

  // Private removeEntry()

  // Precondition:
  // Postcondition: A record is deleted from the database
  // Functionality: This function deletes a record from the
  //                database based on a unique id#

  //*******************************************************

  dataTree.deleteNode(idNum); // call the BSTree deleteNode function
  size--; // decrement size
}

void Database::modifyEntry() {

  //*******************************************************

  // Precondition: The entry to modify must be in the database
  // Postcondition: A Record in the database is modified
  // Functionality: This function allows the user to modify
  //                any field of a Record except the id number

  //*******************************************************

  // Get ID# from user
  unsigned int idNum;
  cout << "Enter ID# of record to modify: ";
  cin >> idNum;

  // Validate the entry is in the database
  while(validateID(idNum)) {
    cout << "Invalid ID#" << endl;
    cout << "Enter ID# of record to modify: ";
    cin >> idNum;
  }

  Record* ptr = searchList.idSearch(idNum, &dataTree); // get the record from database

  cout << endl;
  cout << *ptr << endl; // display the current record

  char modify = 'y';

  // While loop lets the user modify as many fields as they wish
  while(modify == 'y' || modify == 'Y') {

    int field = searchList.getField(); // get the field the user wants to modify

    // modifiying an affiliate field function slightly differently
    if (field == 14) {
      int menuOpt;
      cout << endl;
      cout << "   1. Delete Affiliate" << endl
           << "   2. Add Affiliate" << endl
           << "   : ";

      cin >> menuOpt;

      if (menuOpt == 1) {
        ptr->rmvAffiliate();
      }

      else if (menuOpt == 2) {
        ptr->addAffiliate();
      }
    }

    else {
      string newField = searchList.getTerm(); // get the new field value from user

      // switch statement mutates the correct field
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
        // Mutate all the fields
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

    }


      // See if user wants to change another field
      cout << "Change another field? (y/n) ";
      cin >> modify;
  }

  cout << *ptr << endl; // display the updated record
}

void Database::visitNodes(Node* node) {
  // Precondition:
  // Postcondition: All contacts in the database are output to console
  // Functionality: This function visits the nodes of the binary search tree in
  //                order and when a node is visited, the contents of the Record
  //                pointed at by the node is output to the console.

  // If the node has a left subtree, recursively call function on that branch
  if (node->Left() != nullptr) {
    visitNodes(node->Left());
  }

  // NOTE - node gets visited here
  cout << *node->getContact();

  // then search the right subtree
  if (node->Right() != nullptr) {
    visitNodes(node->Right());
  }
}

//********************** Menu Functions ****************************


void Database::mainMenu() {

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: This function displays the main menu to the
  //                user, and controls the flow of the program

  //*******************************************************

  int menuOption; // user menu choice

  bool runProgram = true;

  while(runProgram) {
    cout << endl;
    cout << "      Main Menu:" << endl;
    cout << " --------------------" << endl;

    cout << "   1. Read Data From File" << endl
         << "   2. Update Database" << endl
         << "   3. Browse Records" << endl
         << "   4. Search Database" << endl
         << "   5. Write Database to File" << endl
         << "   0. Exit" << endl
         << "   : ";

    cin >> menuOption;

    switch(menuOption) {

    case 1:
      cout << endl;
      readFile();
      break;

    case 2:
      updateMenu();
      break;

    case 3:
      visitNodes(dataTree.Root());
      break;

    case 4:
      searchMenu();
      break;

    case 5:
      writeDatabase();
      break;
    case 0:
      runProgram = false;
      cout << "Goodbye" << endl;
      break;

    default:
      cout << "That is not a valid choice. Please choose from the given options" << endl;

    }
  }

  return;
}

void Database::writeDatabase() {

  //*******************************************************

  // Precondition: Database has a non-zero number of entries
  // Postcondition: The current database is written to a file
  // Functionality: This function prompts the user for a file
  //                name and then writes the current database
  //                to the file.

  //*******************************************************

  ofstream outFile;
  string filename;
  char yesno;

  cout << endl;
  cout << "Enter the name of a file to write to: ";
  cin >> filename;

  cout << endl;
  cout << "If this file exists it will be overwritten! Continue? (y/n) ";
  cin >> yesno;

  if (yesno == 'n' || yesno == 'N') {
    cout << "Enter a new file name: ";
    cin >> filename;
  }

  outFile.open(filename);

  writeFile(dataTree.Root(), outFile);
}

void Database::writeFile(Node* node, ofstream& outfile) {

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Recursively Visits binary tree in pre-order
  //                and writes all Record fields to file.

  //*******************************************************

  outfile << *node->getContact();

  if (node->Left() != nullptr) { // If the node has a left subtree,
    writeFile(node->Left(), outfile); // recursively call the function on that branch
  }

  if (node->Right() != nullptr) { // If the node has a right subtree,
    writeFile(node->Right(), outfile); // recursively call the function on that branch
  }
}

void Database::searchMenu() {

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Displays the search menu

  //*******************************************************


  int menuOption;
  bool menu = true;

  int field;
  string term;


  while(menu) {
    cout << endl;
    cout << "      Search Database" << endl;
    cout << "    -------------------" << endl;
    cout << "   1. Search for ID#" << endl
         << "   2. Search by exact matches" << endl
         << "   3. Search by matches containing" << endl
         << "   4. Main Menu" << endl
         << "   : ";

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

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Displays the results of a search and allows
  //                the user to perform sub searches or output the
  //                results.

  //*******************************************************


  int menuOption;
  bool menu = true;


  while(menu) {
    cout << endl;
    cout << "      Search Results" << endl;
    cout << "  ----------------------" << endl;

    cout << endl << "Your search returned " << searchList.getSearchResults().size()
    << " results" << endl << endl;

    cout << "   1. Refine Search Results" << endl
         << "   2. New Search" << endl
         << "   3. Browse Results" << endl
         << "   4. Modify an Entry" << endl
         << "   5. Write search results to file" << endl
         << "   6. Remove an Entry from Database" << endl
         << "   7. Back to Search Menu" << endl
         << "   : ";

    cin >> menuOption;
    cin.ignore();

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
        modifyEntry(); // modify an entry
        break;

      case 5:
        outputDataMenu(); // call menu for outputting data
        break;

      case 6:
        removeEntry(); // call function to remove record

      case 7:
        menu = false;
        break;

      default:
        cout << "That is not a valid choice. Please choose from the given options" << endl;

      }

  }
}

void Database::searchAgain() {

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: This menu allows the user to perform a sub
  //                search on the current list of search results

  //*******************************************************


  int menuOption;
  bool menu = true;

  int field;
  string term;

  while(menu) {
    cout << endl;
    cout << "      Sub Search" << endl;
    cout << "  ------------------" << endl;

    cout << "   1. Search for ID#" << endl
         << "   2. Search for exact matches" << endl
         << "   3. Search for matches containing" << endl
         << "   4. Go Back" << endl
         << "   : ";

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

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Provides user options for making updates
  //                to the database

  //*******************************************************



  int menuOption;
  bool menu = true;

  while(menu) {
    cout << endl;
    cout << "      Modify Database" << endl;
    cout << "   ---------------------" << endl;
    cout << "   1. Add New Record" << endl
         << "   2. Modify Record" << endl
         << "   3. Delete Record" << endl
         << "   4. Go Back" << endl
         << "   : ";

    cin >> menuOption;

    switch(menuOption) {

      case 1:
        addEntry();
        break;
      case 2:
        modifyEntry();
        break;
      case 3:
        cout << endl;
        cout << "      1. Search for a Record" << endl
             << "      2. Enter ID# of Record to remove" << endl
             << "      : ";

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

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Menu to allow user to choose how to output
  //                search results.

  //*******************************************************

  int menuOption;
  bool menu = true;


  while(menu) {
    cout << endl;
    cout << "      Data Output" << endl;
    cout << "  -------------------" << endl;
    cout << "   1. Write to File" << endl
         << "   2. Chose Sorting Order" << endl
         << "   3. Select Fields to Write" << endl
         << "   4. Back" << endl
         << "   : ";

    cin >> menuOption;

    switch(menuOption) {

      case 1:
        searchList.writeOut();
        break;

      case 2:
        sortMenu();
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

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Menu allowing user to choose which fields
  //                to sort by

  //*******************************************************


  int primary;
  int secondary;

  cout << endl;

  cout << "Enter primary and secondary sorting fields, or primary and 0 for one sort: "<<endl;

  cout << "   1. Last Name" << endl
       << "   2. Company Name" << endl
       << "   3. State" << endl
       << "   4. Country" << endl
       << "   5. City" << endl
       << "   6. Go Back" << endl
       << "   : ";

  cin >> primary;
  cin >> secondary;

  searchList.sortList(primary, secondary); // call sorting function

}