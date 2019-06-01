//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_SECURESTRING_HPP
#define PASSFAULT_SECURESTRING_HPP

#include <string>
#include <cstring>
#include <stdexcept>

namespace Passfault {

    /**
     * This is a string whose destructor 0's out the data upon clear or destructor
     * @author Chris Henk @LittleBoxOfSunshine
     */
    class SecureString {
    private:
        /** Internal string to be managed securely */
        std::string chars;

        /**
         * Zeros out the data contained within this string
         */
        inline void zero ();

        /**
         * Zeros out the data contained within the given string
         * @param chars the string whose data is to be zeroed, defaults to this->chars
         */
        inline void zero ( std::string & str );

        /**
         * Zeros out the data contained within the given string
         * @param pointer to the string whose data is to be zeroed
         * @param length of the string whose data is to be zeroed
         */
        inline void zero ( char* str, size_t length );

    public:

        /**
         * Constructs a secure string that is empty. Default constructor.
         */
        SecureString();

        /**
         * Disallow implicit conversion from cstring
         */
         SecureString(const char *) = delete;

        /**
         * Construct a secure string from an existing string. This process is destructive,
         * the given string will be securely destroyed to increase security
         * @param chars the string pointer to become a SecureString
         */
        SecureString ( std::string* chars );

        /**
         * Construct a secure string from an existing string. This process is destructive,
         * the given string will be securely destroyed to increase security
         * @param chars the string to become a SecureString
         */
        SecureString ( std::string & chars );

        /**
         * Construct a secure string from an existing secure string. This process is NOT
         * destructive, it is a copy constructor.
         * @param secureString the secure string to deep copy
         */
        SecureString ( const SecureString & secureString );

        /**
         * Construct a secure string from a substring of an existing secure string. This
         * procress is NOT destructive, it is intended to be used in the substring
         * function, which functions as a convenient alias for this constructor.
         * @param secureString the secure string to deep copy substring from
         * @param start the starting position of the substring to copy
         * @param length the length of the substring to copy
         * @return a deep copy of the substring as a SecureString object
         * @throw out_of_range If start position is greater than the string length
         */
        SecureString ( const SecureString & secureString, size_t start, size_t length );

        /**
         * @param index of the character to return
         * @return the index-th (nth) character of the string
         */
        char& operator[] ( size_t index );
        /**
         * @param index of the character to return
         * @return the index-th (nth) character of the string
         */
        const char& operator[] ( size_t index ) const;

        /**
         * @return the length of the string
         */
        unsigned long length() const;

        /**
         * @param start the index to begin the substring
         * @param end the index to end the substring (not inclusive)
         * @return the substring from start to end (not inclusive)
         */
        SecureString substr ( size_t start, size_t end ) const;

        /**
         * Securely clears the string by overwriting all data with 0's.
         * This function is called by the destructor
         */
        void clear();

        /**
         * Overloaded assignment operator for deep copy. This is NOT destructive
         * and creates a COPY of the underlying string
         * @param rhs the secure string to clone
         */
        SecureString & operator= ( const SecureString & rhs );

        /**
         * Overloaded equality operator
         * @param rhs the secure string to check against for equality
         * @return the result of the equality comparison
         */
        bool operator== ( const SecureString & rhs ) const;

        /**
         * Overloaded equality operator, convenience function for unit testing
         * @param rhs the string to check against for equality
         * @return the result of the equality comparison
         */
        bool operator== ( const std::string & rhs ) const;

        /**
         * Overloaded equality operator, convenience function for unit testing
         * @param rhs the cstring to check against for equality
         * @return the result of the equality comparison
         */
        bool operator== ( const char * rhs ) const;

        /**
         * Uses the clear function to securely erase its data
         */
        ~SecureString();

    };
}

#endif //PASSFAULT_SECURESTRING_HPP
