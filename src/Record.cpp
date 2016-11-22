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

void Record::clearAll() {

  affiliates.clear();


}


// *************** Overloaded ostream and ofstream operators **************


ostream& operator << (ostream& out, const Record& contact) {

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

       for (list<Affiliate>::const_iterator it = contact.affiliates.begin(); it != contact.affiliates.end(); ++it) {

         if (it == contact.affiliates.begin()) {
           out << *it << endl;

         }
         else {
           out << "                " << *it << endl;
         }

       }




  out << "              |" << endl;


  return out;
}


ofstream& operator << (ofstream& out, const Record& contact) {


  out << endl << setw(9) << setfill('0') << contact.idNum << endl
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

 for (list<Affiliate>::const_iterator it = contact.affiliates.begin(); it != contact.affiliates.end(); ++it) {

   out << *it << endl;

 }

 out << '|';

  return out;
}