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

using std::string;

class Affiliate {


  private:

    string firstName;
    string lastName;

    string mPhone;
    string email;

  public:

    //************ Mutator Methods *****************
    void setFirstName(string first) {firstName = first;};
    void setLastName(string last) {lastName = last;};
    void setPhone(string phoneNum) {mPhone = phoneNum;};
    void setEmail(string newEmail) {email = newEmail;};


    //************* Accessor Methods ***************
    string getFirstName() {return firstName;};
    string getLastName() {return lastName;};
    string getPhone() {return mPhone;};
    string getEmail() {return email;};


};



#endif