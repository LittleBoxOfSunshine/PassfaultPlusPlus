//
// Created by Chris Henk on 1/26/16.
//

#include "common/SecureString.hpp"

// Default constructor
Passfault::SecureString::SecureString() { }

// Constructor
Passfault::SecureString::SecureString ( std::string* chars ) {
    // Copy the string
    this->chars = *chars;

    // Securely erase the existing string
    this->zero(*chars);
}

// Constructor
Passfault::SecureString::SecureString ( std::string & chars ) {
    // Copy the string
    this->chars = chars;

    // Securely erase the existing string
    this->zero(chars);
}

// Copy Constructor
Passfault::SecureString::SecureString ( const Passfault::SecureString & secureString ) {
    // Copy the underlying string
    this->chars = secureString.chars;
}

// Substring Constructor
Passfault::SecureString::SecureString ( const SecureString & secureString, size_t start, size_t end ) {
    // Allocate memory to copy the string
    this->chars.reserve(end - start);

    // TODO: This will need to be adjusted to accommodate utf8
    // Copy the string
    memcpy((char*)this->chars.c_str(), (char*)secureString.chars.c_str() + start, end - start);
}

// Get nth character
char& Passfault::SecureString::operator[] ( size_t index ) {
    return this->chars[index];
}

// Get length of string
unsigned long Passfault::SecureString::length() const {
    return this->chars.size();
}

// Get a substring as a SecureString from start to end (not inclusive)
Passfault::SecureString Passfault::SecureString::substr ( size_t start, size_t end ) {
    // TODO: Determine if memory is unsafe and/or if this can be optimized in a safe way
    // this is almost certainly safe, but it requires an extra copy. Returning it immediately
    // may produce an extra copy that remains uncleared

    // Substring temporary container, SecureString constructor will handle zeroing it
    std::string sub = this->chars.substr(start, end-start);

    SecureString secStr(sub);

    // Construct SecureString from the temporary substring container
    return secStr;
}

// Secure erase the contents of the SecureString
void Passfault::SecureString::clear() {
    // Zero out every character for safety
    this->zero();

    // Clear the zeroed string
    this->chars.clear();
}

// Assignment operator deep copy
Passfault::SecureString & Passfault::SecureString::operator= ( const Passfault::SecureString & rhs ) {
    // Check for self assignment
    if ( this == &rhs ) {
        return *this;
    }
    else {
        // Zero any data that currently exists
        this->zero();

        // Copy the underlying string
        this->chars = rhs.chars;

        // Return pointer to the existing object
        return *this;
    }
}

// Call the clear function upon destruction
Passfault::SecureString::~SecureString() {
    this->zero();
}

// Zero out the data in this string
void Passfault::SecureString::zero() {
    this->zero(this->chars);
}

// Zero out the data in the given string
void Passfault::SecureString::zero ( std::string & str ) {
    this->zero((char*)str.c_str(), str.size());
}


// TODO: Determine if this is necessary, if it works, and if O0 instead of O1 or O2 is needed
// Disable optimizations to ensure that the zeroing actually occurs
#pragma GCC push_options
#pragma GCC optimize ("O0")

// Zero out the data in the given string
void Passfault::SecureString::zero( char* str, size_t length ) {
    memset((void*)str, 0, length);
}

// Restore previous global attributes
#pragma GCC pop_options
