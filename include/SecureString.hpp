//
// Created by cahenk on 1/26/16.
//

#ifndef PASSFAULT_SECURESTRING_HPP
#define PASSFAULT_SECURESTRING_HPP

#include <string>
#include <cstring>

namespace Passfault {

    /**
     * This is a string whose destructor 0's out the data upon clear or destructor
     * @author Ranind
     */
    class SecureString {
    private:
        std::string chars;

    public:

        /**
         * Construct a secure string from an existing string. This process is destructive,
         * the given string will be securely destroyed to increase security
         * @param chars the string to become a SecureString
         */
        SecureString ( std::string & chars );

        /**
         * @param index of the character to return
         * @return the index-th (nth) character of the string
         */
        char charAt ( int index );

        /**
         * @return the length of the string
         */
        int length();

        /**
         * @param start the index to begin the substring
         * @param end the index to end the substring (not inclusive)
         * @return the substring from start to end (not inclusive)
         */
        SecureString subStr ( int start, int end );

        /**
         * Securely clears the string by overwriting all data with 0's.
         * This function is called by the destructor
         */
        void clear();

        /**
         * Uses the clear function to securely erase its data
         */
        ~SecureString();

    };
}

#endif //PASSFAULT_SECURESTRING_HPP
