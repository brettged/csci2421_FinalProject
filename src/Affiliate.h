//##############################################################################
//
//
//  FileName: Affiliate.h
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
//  This file contains the Affiliate class prototype. Each affiliate has a
//  first and last name, and may have a mobile phone and/or email.
//
//
//
//##############################################################################



#ifndef AFFIL_H
#define AFFIL_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Affiliate {


  private:

    string firstName;
    string lastName;

    string mobilePhone;
    string email;

  public:

    Affiliate();

    ~Affiliate();


    //************ Mutator Methods *****************
    void setFirstName(string _first) {firstName = _first;};
    void setLastName(string _last) {lastName = _last;};
    void setPhone(string _mPhone) {mobilePhone = _mPhone;};
    void setEmail(string _email) {email = _email;};


    //************* Accessor Methods ***************
    string getFirstName() {return firstName;};
    string getLastName() {return lastName;};
    string getPhone() {return mobilePhone;};
    string getEmail() {return email;};

    friend ostream& operator << (ostream& out, const Affiliate& affil){

      out << affil.firstName << " " << affil.lastName << "," << affil.mobilePhone
          << "," << affil.email << ";";

      return out;

    }

};



#endif

// United States
// Troy Borges,(636)553-5433,tborges2450@oic.biz;
// Bob Corcoran,(808)368-6692,bcorcoran@comcast.net;
// Mike Franklin,(340)784-9249,mfranklin@qwest.com;
// Audie Boren,(567)906-9017,aboren5@yahoo.com;
// Archie Packard,(308)686-9564,apackard@oic.biz;