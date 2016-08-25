//
// Created by Chris Henk on 1/26/16.
//

#include "SecureString.hpp"

// Default constructor
Passfault::SecureString::SecureString() {
    this->chars = "";
}

// Constructor
Passfault::SecureString::SecureString ( std::string* chars ) {
    // Copy the string
    this->chars = *chars;

    // Zero out every character for safety
    memset((void*)chars->c_str(), 0, chars->size());

    // Erase the string
    delete chars;
}

// Constructor
Passfault::SecureString::SecureString ( std::string & chars ) {
    // Copy the string
    this->chars = chars;

    // Zero out every character for safety
    memset((void*)chars.c_str(), 0, chars.size());

    // Erase the string
    chars.clear();
}

// Copy Constructor
Passfault::SecureString::SecureString ( const Passfault::SecureString & secureString ) {
    // Copy the underlying string
    this->chars = secureString.chars;
}

// Get nth character
char Passfault::SecureString::charAt ( int index ) {
    return this->chars[index];
}

// Get length of string
unsigned long Passfault::SecureString::length() {
    return this->chars.size();
}

// Get a substring as a SecureString from start to end (not inclusive)
Passfault::SecureString Passfault::SecureString::subStr ( size_t start, size_t end ) {
    std::string temp = this->chars.substr(start, end-start);
    return SecureString(temp);
}

// Secure erase the contents of the SecureString
void Passfault::SecureString::clear() {
    // Zero out every character for safety
    memset((void*)this->chars.c_str(), 0, this->chars.size());

    // Clear the zeroed string
    this->chars.clear();
}

// Assignment operator deep copy
Passfault::SecureString & Passfault::SecureString::operator= ( const Passfault::SecureString & rhs ) {
    // Check for self assignment
    if ( this == &rhs )
        return *this;

    // Copy the underlying string
    this->chars = rhs.chars;

    // Return pointer to the existing object
    return *this;
}

// Call the clear function upon destruction
Passfault::SecureString::~SecureString() {
    this->clear();
}