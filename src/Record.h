//##############################################################################
//
//
//  FileName: Record.h
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
//  This file contains the Record class delcaration
//
//
//
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
    unsigned int zipCode; // zip codes cannot be negative
    string country;

    list<Affiliate> affiliates; // double linked list holds the affiliates


  public:

    Record(); // default constructor

    ~Record(); // destructor


    // ******** Mutator Methods **********

    void setId();
    void setFirstName();
    void setMidName();
    void setLastName();
    void setCompany();
    void setHomePhone();
    void setOffice();
    void setEmail();
    void setMobile();
    void setStAddr();
    void setCity();
    void setState();
    void setZipCode();
    void setCountry();
    void addAffiliate();


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
    unsigned int getZipCode() {return zipCode;};
    string getCountry() {return country;};
    list<Affiliate> getAffiliate() {return affiliates;}; // returns a linked list of the affiliates


    // overloaded output operator to either display data or write to a file
    friend ostream& operator << (ostream& out, const Record& contact);

};


#endif