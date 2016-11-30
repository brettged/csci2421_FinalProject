//##############################################################################
//
//
//  FileName: Record.h
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
//  This file contains the Record class delcaration. The record class contains
//  member variables corresponding to each field that a entry in the database cannot
//  have, and their associated mutator and accessor functions.
//
//
//##############################################################################


#ifndef RECORD_H
#define RECORD_H


#include <list>
#include <iostream>
#include "Affiliate.h" // include the affiliate header file


using namespace std;

class Record {


  private:

    // Unique 9 digit id number for each entry. ID numbers cannot be negative
    // so it should be an unsigned integer
    unsigned int idNum;

    // Name fields for each contact
    string firstName;
    string middleName;
    string lastName;

    // company
    string company;

    // Phone/emails
    string homePhone;
    string officePhone;
    string email;
    string mobilePhone;

    // address
    string streetAddr;
    string city;
    string state;
    string zipCode;
    string country;

    list<Affiliate> affiliates; // double linked list holds the affiliates

  public:

    Record(); // default constructor

    ~Record(); // destructor


    // ******** Mutator Methods **********

    void setId(unsigned int _idNum);
    void setFirstName(string _first);
    void setMidName(string _middle);
    void setLastName(string _last);
    void setCompany(string _company);
    void setHomePhone(string _homePhone);
    void setOffice(string _officePhone);
    void setEmail(string _email);
    void setMobile(string _mobilePhone);
    void setStAddr(string _streetAddr);
    void setCity(string _city);
    void setState(string _state);
    void setZipCode(string _zipCode);
    void setCountry(string _country);
    void addAffiliate(Affiliate _affil);
    void clearAll();

    // ******** Accessor Methods **********

    unsigned int getId() {return idNum;};
    string getFirstName(){return firstName;};
    string getMidName() {return middleName;};
    string getLastName() {return lastName;};
    string getCompany() {return company;};
    string getHomePhone() {return homePhone;};
    string getOffice() {return officePhone;};
    string getEmail() {return email;};
    string getMobile() {return mobilePhone;};
    string getStAddr() {return streetAddr;};
    string getCity() {return city;};
    string getState() {return state;};
    string getZipCode() {return zipCode;};
    string getCountry() {return country;};
    list<Affiliate> getAffiliate() {return affiliates;}; // returns a linked list of the affiliates


    // overload less than operator
    friend bool operator < (const Record& left, const Record& right);


    // overloaded output operator to either display data or write to a file
    friend ostream& operator << (ostream& out, const Record& contact);

    friend ofstream& operator << (ofstream& out, const Record& contact);

};


#endif