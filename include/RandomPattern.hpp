//
// Created by Chris Henk on 2/2/16.
//

#ifndef PASSFAULT_RANDOMPATTERN_HPP
#define PASSFAULT_RANDOMPATTERN_HPP

#include <string>
#include <cmath>

#include "PasswordPattern.hpp"

namespace Passfault {

    /**
     * This class helps detect different random finders and their strength
     * @author Ranind
     */
    class RandomPattern {
    private:

        /** Constants containing the number of unique characters in various character sets */
        enum CharacterCounts {
            LATIN = 26,
            CYRILLIC = 30,
            SYMBOLS = 42,
            NUMBERS = 10
        };

    public:

        /** Constant for setting PasswordPattern::name */
        static const std::string RANDOM_PATTERN = "RANDOM_CHARACTERS";

        /**
         * Calculates the number of possible strings exist when using all alphanumeric characters
         * and symbols to a specified length
         * @param length the number of random symbols
         * @return the number of permutations that exist
         */
        static double randomCost ( int length );

        /**
         * Calculates the number of possible strings exist when using all lowercase characters
         * @param length the number of random symbols
         * @return the number of permutations that exist
         */
        static double randomCostLowerCase ( int length );

        /**
         * Calculates the number of possible strings exist when using lower-case and upper-case characters
         * @param length the number of random symbols
         * @return the number of permutations that exist
         */
        static double randomCostLowerUpperCase ( int length );

        /**
         * Calculates the random strength of the password by considering its length and the types of
         * characters used (digits, lower-case, upper-case, symbols)
         * @param password the password to find random patterns in
         * @param start the starting index of the substring of the password to use
         * @param length how many characters the substring of the password to use has
         * @return PasswordPattern initialized to match the results of the random strength of the password
         */
        static PasswordPattern getRandomPattern (const SecureString & password, int start, int length );

    };

}

#endif //PASSFAULT_RANDOMPATTERN_HPP
