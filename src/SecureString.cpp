//
// Created by cahenk on 1/26/16.
//

#include "SecureString.hpp"

// Constructor
Passfault::SecureString::SecureString ( std::string & chars ) {
    // Copy the string
    this->chars = chars;

    // Zero out every character for safety
    memset(chars->c_str(), 0, chars->size());

    // Erase the string
    chars.clear();
}

// Get nth character
char Passfault::SecureString::charAt ( int index ) {
    return this->chars[index];
}

// Get length of string
int Passfault::SecureString::length() {
    return this->chars.size();
}

// Get a substring as a SecureString from start to end (not inclusive)
Passfault::SecureString Passfault::SecureString::subStr ( int start, int end ) {
    return this->chars.substr(start, end-start);
}

// Secure erase the contents of the SecureString
void Passfault::SecureString::clear() {
    // Zero out every character for safety
    memset(this->chars.c_str(), 0, this->chars.size());

    // Clear the zeroed string
    this->chars.clear();
}

// Call the clear function upon destruction
Passfault::SecureString::~SecureString() {
    this->clear();
}