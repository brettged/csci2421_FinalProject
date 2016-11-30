



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
  cout << endl;
  cout << "Enter term: ";
  cin.ignore();
  getline(cin, term);
  return term;

}

int SearchData::getField() {

  int field;

  cout << endl;
  cout << "      Select field:" << endl;
  cout << "   -------------------" << endl;
  cout << "   1. First Name" << endl
       << "   2. Middle Name" << endl
       << "   3. Last Name" << endl
       << "   4. Company Name" << endl
       << "   5. Home Phone" << endl
       << "   6. Office Phone" << endl
       << "   7. Email" << endl
       << "   8. Mobile Phone" << endl
       << "   9. Street Address" << endl
       << "   10. City" << endl
       << "   11. State" << endl
       << "   12. Zip Code" << endl
       << "   13. Country" << endl
       << "   14. Affiliates" << endl
       << "   15. All Fields" << endl
       << "   : ";

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
void SearchData::subSearch(string searchTerm, int field, bool exact) {

  string recordWord;

  if (current == &subSearchResults) {
    searchResults.clear();
    previous = &subSearchResults;
    current = &searchResults;
  }

  else {
    subSearchResults.clear();
    previous = &searchResults;
    current = &subSearchResults; // set the current pointer to point at searchResults list
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



//************* Sorting Operations ****************


void SearchData::sortLastName() {


  (*current).sort();

}

void SearchData::sortCompany() {


  for(list<Record>::iterator it1 = current->begin(); it1 != (--current->end()); ++it1) {

    Record* small = &(*it1);

    list<Record>::iterator it2 = it1;

    for (++it2; it2 != current->end(); ++it2) {

      if (small->getCompany() > it2->getCompany()) {
        small = &(*it2);
      }

    }

    Record swp = *it1;
    *it1 = *small;
    *small = swp;


  }




}

void SearchData::sortState() {
  for(list<Record>::iterator it1 = current->begin(); it1 != (--current->end()); ++it1) {

    Record* small = &(*it1);

    list<Record>::iterator it2 = it1;

    for (++it2; it2 != current->end(); ++it2) {

      if (small->getState() > it2->getState()) {
        small = &(*it2);
      }

    }

    Record swp = *it1;
    *it1 = *small;
    *small = swp;


  }
}

void SearchData::sortCountry() {
  for(list<Record>::iterator it1 = current->begin(); it1 != (--current->end()); ++it1) {

    Record* small = &(*it1);

    list<Record>::iterator it2 = it1;

    for (++it2; it2 != current->end(); ++it2) {

      if (small->getCountry() > it2->getCountry()) {
        small = &(*it2);
      }

    }

    Record swp = *it1;
    *it1 = *small;
    *small = swp;


  }
}

void SearchData::sortCity() {
  for(list<Record>::iterator it1 = current->begin(); it1 != (--current->end()); ++it1) {

    Record* small = &(*it1);

    list<Record>::iterator it2 = it1;

    for (++it2; it2 != current->end(); ++it2) {

      if (small->getCity() > it2->getCity()) {
        small = &(*it2);
      }

    }

    Record swp = *it1;
    *it1 = *small;
    *small = swp;


  }
}

void SearchData::selectFields() {

  int temp;

  cout << "Enter the fields to want to write out (0 to finish)" << endl;
  cout << "1. ID#" << endl
       << "2. First Name" << endl
       << "3. Middle Name" << endl
       << "4. Last Name" << endl
       << "5. Company Name" << endl
       << "6. Home Phone" << endl
       << "7. Office Phone" << endl
       << "8. Email" << endl
       << "9. Mobile Phone" << endl
       << "10. Street Address" << endl
       << "11. City" << endl
       << "12. State" << endl
       << "13. Zip Code" << endl
       << "14. Country" << endl
       << "15. Affiliates" << endl
       << ": ";
  cin >> temp;

  while (temp != 0) {
    fields[temp - 1] = 1;
    cin >> temp;
  }

  cin.ignore();
  return;
}


//************** Output Operations ****************

void SearchData::writeOut() {

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

  outFile << *this;

}


string SearchData::retField(Record* contact, int fNum) const {

  string fieldValue;

  switch(fNum) {

    case 2:
      fieldValue = contact->getFirstName();
      break;
    case 3:
      fieldValue = contact->getMidName();
      break;
    case 4:
      fieldValue = contact->getLastName();
      break;
    case 5:
      fieldValue = contact->getCompany();
      break;
    case 6:
      fieldValue = contact->getHomePhone();
      break;
    case 7:
      fieldValue = contact->getOffice();
      break;
    case 8:
      fieldValue = contact->getEmail();
      break;
    case 9:
      fieldValue = contact->getMobile();
      break;
    case 10:
      fieldValue = contact->getStAddr();
      break;
    case 11:
      fieldValue = contact->getCity();
      break;
    case 12:
      fieldValue = contact->getState();
      break;
    case 13:
      fieldValue = contact->getZipCode();
      break;
    case 14:
      fieldValue = contact->getCountry();
      break;
  }

  return fieldValue;

}

//************* Overloaded operators ***************

ostream& operator << (ostream& out, const SearchData& results) {

  for (list<Record>::iterator it = results.current->begin(); it != results.current->end(); ++it) {

    out << *it;

  }
  return out;

}


ofstream& operator << (ofstream& out, const SearchData& results) {

  Record* ptr;

  for (list<Record>::iterator it = results.current->begin(); it != results.current->end(); ++it) {

    ptr = &(*it);




    for (int i = 0; i < 15; i++) {

      if (i == 0){
        if (results.fields[0] == 1) {
          // print the id number
          out << it->getId();
          out << endl;
        }
      }

      else if (i < 14) {
        if (results.fields[i] == 1) {
          out << results.retField(ptr, i+1);
          out << endl;
        }
      }
      else if (i == 14) {
        if (results.fields[i] == 1) {
          list<Affiliate> currentAffils = ptr->getAffiliate(); // temporary list of affiliates so we can iterate over and display

          for (list<Affiliate>::const_iterator itr = currentAffils.begin(); itr != currentAffils.end(); ++itr) {

            out << *itr << endl; // Affiliate class has it's own overloaded ostream operator

          }
        }
      }

    }
    out << '|' << endl;

  }
  return out;

}