//##############################################################################
//
//
//  FileName: Record.cpp
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
//  This file contains the implementation of the Record class.
//
//
//
//
//
//
//
//##############################################################################

#include <list>
#include <iomanip>
#include <fstream>

#include "Record.h"
#include "Affiliate.h"

using std::list;

Record::Record() {

}


Record::~Record() {

}


// ******** Mutator Methods **********

void Record::setId(unsigned int _idNum) {
  idNum = _idNum;
}

void Record::setFirstName(string _first) {
  firstName = _first;
}

void Record::setMidName(string _middle) {
  middleName = _middle;
}

void Record::setLastName(string _last) {
  lastName = _last;
}

void Record::setCompany(string _company) {
  company = _company;
}

void Record::setHomePhone(string _homePhone) {
  homePhone = _homePhone;
}

void Record::setOffice(string _officePhone) {
  officePhone = _officePhone;
}

void Record::setEmail(string _email) {
  email = _email;
}

void Record::setMobile(string _mobilePhone) {
  mobilePhone = _mobilePhone;
}

void Record::setStAddr(string _streetAddr) {
  streetAddr = _streetAddr;
}

void Record::setCity(string _city) {
  city = _city;
}

void Record::setState(string _state) {
  state = _state;
}

void Record::setZipCode(string _zipCode) {
  zipCode = _zipCode;
}

void Record::setCountry(string _country) {
  country = _country;
}

void Record::addAffiliate(Affiliate _affil) {
  affiliates.push_back(_affil);
}

void Record::addAffiliate() {
  string tempString;
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

  addAffiliate(tempAffil);

}

void Record::rmvAffiliate() {

  Affiliate* temp = new Affiliate;

  string last;
  string first;
  cout << "Enter full name of affiliate to remove: ";
  cin >> first;
  cin.ignore();
  getline(cin, last);
  temp->setFirstName(first);
  temp->setLastName(last);

  // cout << temp->getLastName() << endl;

  affiliates.remove(*temp);
  delete temp;
  return;
}


string Record::searchField(int sNum) {

  string field;

  switch(sNum) {

    case 1:
      field = getLastName();
      break;
    case 2:
      field = getCompany();
      break;
    case 3:
      field = getState();
      break;
    case 4:
      field = getCountry();
      break;
    case 5:
      field = getCity();
      break;
  }

  return field;

}

bool operator < (const Record& left, const Record& right) {

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Overloaded the less than operator for the Record class. one
  //                Record is less than another if the last name is in higher
  //                alphabetical order.

  //*******************************************************
  return left.lastName < right.lastName;

}

// *************** Overloaded ostream and ofstream operators **************

ostream& operator << (ostream& out, const Record& contact) {

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Overloads the generic ostream operator <<. When output is
  //                piped to the console, it will invoke this operator.

  //*******************************************************

  out  << "           ID#: " << setw(9) << setfill('0') << contact.idNum << endl
       << "    First Name: " << contact.firstName << endl
       << "   Middle Name: " << contact.middleName << endl
       << "     Last Name: " << contact.lastName << endl
       << "       Company: " << contact.company << endl
       << "    Home Phone: " << contact.homePhone << endl
       << "  Office Phone: " << contact.officePhone << endl
       << " Email Address: " << contact.email << endl
       << "  Mobile Phone: " << contact.mobilePhone << endl
       << "Street Address: " << contact.streetAddr << endl
       << "          City: " << contact.city << endl
       << "         State: " << contact.state << endl
       << "      Zip Code: " << contact.zipCode << endl
       << "       Country: " << contact.country << endl
       << "    Affiliates: ";

       // utilize STL list<> iterators to visit all the affiliates
  for (list<Affiliate>::const_iterator it = contact.affiliates.begin(); it != contact.affiliates.end(); ++it) {

    if (it == contact.affiliates.begin()) {
     out << *it << endl; // affiliate has its own overloaded ostream operator
    }
    else {
     out << "                " << *it << endl;
    }
  }

  // small formatting modifier to make sure contacts with no affiliates
  // get displayed correctly
  if (contact.affiliates.size() == 0) {
    cout << endl;
  }
  out << "              |" << endl;

  return out;
}


ofstream& operator << (ofstream& out, const Record& contact) {

  //*******************************************************

  // Precondition:
  // Postcondition:
  // Functionality: Overloads the ofstream operator <<. This function
  //                allows each record to be written to a file in the
  //                same format as the original input file.

  //*******************************************************

  // ensure leading 0's are printed in the id number
  out << setw(9) << setfill('0') << contact.idNum << endl
       // write all the fields
       << contact.firstName << endl
       << contact.middleName << endl
       << contact.lastName << endl
       << contact.company << endl
       << contact.homePhone << endl
       << contact.officePhone << endl
       << contact.email << endl
       << contact.mobilePhone << endl
       << contact.streetAddr << endl
       << contact.city << endl
       << contact.state << endl
       << contact.zipCode << endl
       << contact.country << endl;

       // utilize list iterator to display all the affiliates
  for (list<Affiliate>::const_iterator it = contact.affiliates.begin(); it != contact.affiliates.end(); ++it) {

    out << *it << endl; // Affiliate class has it's own overloaded ostream operator

  }

 // small formatting modifier to make sure contacts with no affiliates
 // get displayed correctly
 // if (contact.affiliates.size() == 0) {
 //   out << endl;
 // }

 out << '|' << endl; // write a character delimiting each record

  return out;
}