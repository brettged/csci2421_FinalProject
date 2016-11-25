




#include <iostream>


#include "SearchData.h"
#include "Record.h"

using std::cout;
using std::cin;
using std::endl;

SearchData::SearchData() {

}

SearchData::~SearchData() {

}


string SearchData::getTerm() {

  string term;
  cout << "Enter search term: ";
  cin >> term;
  return term;

}

int SearchData::searchField() {

  int field;

  cout << "Select search field:" << endl;
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
       << "14. Search Affiliates" << endl
       << ": ";

  cin >> field;
  return field;

}


// Search functions, returns linked lists of search results or maybe a BSTree
void SearchData::exactSearch(string searchTerm, int field, Node* node) {

  string recordWord;


  // If the node has a left subtree, recursively call function on that branch
  if (node->Left() != nullptr) {
    exactSearch(searchTerm, field, node->Left());
  }

    // // NOTE - node gets visited here
    // // cout << *node->getContact();
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
      // recordWord = node->getContact()->
      break;
    }


    if (recordWord == searchTerm) {
      searchResults.push_back(node->getContact()); // if the terms match, add pointer to the record to the list
      // cout << "Adding contact " << node->getContact()->getLastName() << endl;

    }

    // cout << recordWord << endl;

  // then search the right subtree
  if (node->Right() != nullptr) {
    exactSearch(searchTerm, field, node->Right());
  }

}

// list<Record> Search::containsSearch(string searchTerm, Database &data) {
//
//   int field = searchField();
//
// }




//************* Overloaded operators ***************

ostream& operator << (ostream& out, const SearchData& results) {

  for (list<Record*>::const_iterator it = results.searchResults.begin(); it != results.searchResults.end(); ++it) {

    out << **it << endl;

  }
  return out;

}


ofstream& operator << (ofstream& out, const SearchData& results) {


}