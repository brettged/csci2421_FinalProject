




#include <iostream>
#include <fstream>

#include "SearchData.h"
#include "Record.h"
#include "BSTree.h"
#include "Affiliate.h"

using std::cout;
using std::cin;
using std::endl;

SearchData::SearchData() {

}

SearchData::~SearchData() {

}


list<Record> SearchData::getSearchResults() {

  // return searchResults;

  return *current; // returns the contents of the list pointed to by current

}

void SearchData::clear() {

  searchResults.clear(); // use the stl list clear function
  current = &searchResults;
}

string SearchData::getTerm() {

  string term;
  cout << "Enter term: ";
  cin.ignore();
  getline(cin, term);
  return term;

}

int SearchData::searchField() {

  int field;

  cout << "Select field:" << endl;
  cout << "1. First Name" << endl
       << "2. Middle Name" << endl
       << "3. Last Name" << endl
       << "4. Company Name" << endl
       << "5. Home Phone" << endl
       << "6. Office Phone" << endl
       << "7. Email" << endl
       << "8. Mobile Phone" << endl
       << "9. Street Address" << endl
       << "10. City" << endl
       << "11. State" << endl
       << "12. Zip Code" << endl
       << "13. Country" << endl
       << "14. Affiliates" << endl
       << "15. All Fields" << endl
       << ": ";

  cin >> field;
  return field;

}


unsigned int SearchData::getSearchID() {

  unsigned int id;
  cout << "Enter 9 digit ID#: ";
  cin >> id;

  while ((id > 999999999) || (id <= 0)) {
    cout << "Invalid Search Term" << endl;
    cout << "Enter 9 digit ID#: ";
    cin >> id;
  }

  return id;
}


// Search functions, returns linked lists of search results or maybe a BSTree
void SearchData::searchTree(string searchTerm, int field, Node* node, bool exact) {

  string recordWord;
  current = &searchResults;


  // If the node has a left subtree, recursively call function on that branch
  if (node->Left() != nullptr) {
    searchTree(searchTerm, field, node->Left(), exact);
  }

    // // NOTE - node gets visited here
    switch(field) {

      case 1:
        recordWord = node->getContact()->getFirstName();
        break;
      case 2:
        recordWord = node->getContact()->getMidName();
        break;
      case 3:
        recordWord = node->getContact()->getLastName();
        break;
      case 4:
        recordWord = node->getContact()->getCompany();
        break;
      case 5:
        recordWord = node->getContact()->getHomePhone();
        break;
      case 6:
        recordWord = node->getContact()->getOffice();
        break;
      case 7:
        recordWord = node->getContact()->getEmail();
        break;
      case 8:
        recordWord = node->getContact()->getMobile();
        break;
      case 9:
        recordWord = node->getContact()->getStAddr();
        break;
      case 10:
        recordWord = node->getContact()->getCity();
        break;
      case 11:
        recordWord = node->getContact()->getState();
        break;
      case 12:
        recordWord = node->getContact()->getZipCode();
        break;
      case 13:
        recordWord = node->getContact()->getCountry();
        break;
      case 14:

        if (affilSearch(searchTerm, node->getContact()->getAffiliate(), exact)){
          current->push_back(*node->getContact());
        }
        break;

      case 15:
        if(searchAll(searchTerm, node->getContact(), exact))
        current->push_back(*node->getContact());
        break;

    }

    // If the exact flag is set, an exact match is looked for
    if (exact == true) {

      if (recordWord == searchTerm) {
        current->push_back(*node->getContact()); // if the terms match, add pointer to the record to the list
      }
    }

    // Otherwise it must be a contains search
    else {

      if (recordWord.find(searchTerm) != -1) {
        current->push_back(*node->getContact());
      }

    }

  // then search the right subtree
  if (node->Right() != nullptr) {
    searchTree(searchTerm, field, node->Right(), exact);
  }

}


// overloaded exact search, searches the current search results
void SearchData::searchList(string searchTerm, int field, bool exact) {

  string recordWord;

  if (current == &subSearch) {
    searchResults.clear();
    previous = &subSearch;
    current = &searchResults;
  }

  else {
    subSearch.clear();
    previous = &searchResults;
    current = &subSearch; // set the current pointer to point at searchResults list
  }

  for (list<Record>::iterator it = previous->begin(); it != previous->end(); ++it) {

    switch(field) {
      case 1:
        recordWord = it->getFirstName();
        break;
      case 2:
        recordWord = it->getMidName();
        break;
      case 3:
        recordWord = it->getLastName();
        break;
      case 4:
        recordWord = it->getCompany();
        break;
      case 5:
        recordWord = it->getHomePhone();
        break;
      case 6:
        recordWord = it->getOffice();
        break;
      case 7:
        recordWord = it->getEmail();
        break;
      case 8:
        recordWord = it->getMobile();
        break;
      case 9:
        recordWord = it->getStAddr();
        break;
      case 10:
        recordWord = it->getCity();
        break;
      case 11:
        recordWord = it->getState();
        break;
      case 12:
        recordWord = it->getZipCode();
        break;
      case 13:
        recordWord = it->getCountry();
        break;
      case 14:

        if (affilSearch(searchTerm, it->getAffiliate(), exact)){
          current->push_back(*it);
        }
        break;

      case 15:
        Record* ptr = &*it;
        if(searchAll(searchTerm, ptr, exact))
        current->push_back(*it);
        break;
      }

    // If the exact flag is set, an exact match is looked for
    if (exact == true) {

      if (recordWord == searchTerm) {
        current->push_back(*it);
      }
    }

    // Otherwise it must be a contains search
    else {

      if (recordWord.find(searchTerm) != -1) {
        current->push_back(*it);
      }

    }
  }

}


bool SearchData::affilSearch(string searchTerm, list<Affiliate> affil, bool exact) {

  bool inAffil = false;

  if (exact) {

    for (list<Affiliate>::iterator it = affil.begin(); it != affil.end(); ++it) {

      if (searchTerm == it->getFirstName()) {
        inAffil = true;
      }
      else if (searchTerm == it->getLastName()) {
        inAffil = true;
      }
      else if (searchTerm == it->getPhone()) {
        inAffil = true;
      }
      else if (searchTerm == it->getEmail()) {
        inAffil = true;
      }
    }
  }

  else {
    for (list<Affiliate>::iterator it = affil.begin(); it != affil.end(); ++it) {

      if (it->getFirstName().find(searchTerm) != -1) {
        inAffil = true;
      }
      if (it->getLastName().find(searchTerm) != -1) {
        inAffil = true;
      }
      if (it->getPhone().find(searchTerm) != -1) {
        inAffil = true;
      }
      if (it->getEmail().find(searchTerm) != -1) {
        inAffil = true;
      }
    }
  }

  return inAffil;

}


Record* SearchData::idSearch(unsigned int idNum, BSTree* tree) {
  //*******************************************************

  // idSearch()

  // Precondition:
  // Postcondition:
  // Functionality:
  //*******************************************************

  Node* nPtr;
  nPtr = tree->findNode(idNum, tree->Root()); // find the node with the key to delete

  if (nPtr == nullptr) {
    return nullptr;
  }

  return nPtr->getContact(); // return a pointer to record from the node


}


bool SearchData::searchAll(string searchTerm, Record* contact, bool exact) {

  bool searchFlag = false;

  if (exact) {
    if(contact->getFirstName() == searchTerm)
      searchFlag = true;
    else if(contact->getMidName() == searchTerm)
      searchFlag = true;
    else if (contact->getLastName() == searchTerm)
      searchFlag = true;
    else if (contact->getCompany() == searchTerm)
      searchFlag = true;
    else if (contact->getHomePhone() == searchTerm)
      searchFlag = true;
    else if (contact->getOffice() == searchTerm)
      searchFlag = true;
    else if (contact->getEmail() == searchTerm)
      searchFlag = true;
    else if (contact->getMobile() == searchTerm)
      searchFlag = true;
    else if (contact->getStAddr() == searchTerm)
      searchFlag = true;
    else if (contact->getCity() == searchTerm)
      searchFlag = true;
    else if (contact->getState() == searchTerm)
      searchFlag = true;
    else if (contact->getZipCode() == searchTerm)
      searchFlag = true;
    else if (contact->getCountry() == searchTerm)
      searchFlag = true;
    else if (affilSearch(searchTerm, contact->getAffiliate(), exact))
      searchFlag = true;
  }

  else {
    if(contact->getFirstName().find(searchTerm) != -1)
      searchFlag = true;
    else if(contact->getMidName().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getLastName().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getCompany().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getHomePhone().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getOffice().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getEmail().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getMobile().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getStAddr().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getCity().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getState().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getZipCode().find(searchTerm) != -1)
      searchFlag = true;
    else if (contact->getCountry().find(searchTerm) != -1)
      searchFlag = true;
    else if (affilSearch(searchTerm, contact->getAffiliate(), exact))
      searchFlag = true;
  }

  return searchFlag;
}

//************* Overloaded operators ***************

ostream& operator << (ostream& out, const SearchData& results) {

  for (list<Record>::const_iterator it = results.current->begin(); it != results.current->end(); ++it) {

    out << *it << endl;

  }
  return out;

}


ofstream& operator << (ofstream& out, const SearchData& results) {

  for (list<Record>::const_iterator it = results.current->begin(); it != results.current->end(); ++it) {
    out << *it << endl;
  }

}