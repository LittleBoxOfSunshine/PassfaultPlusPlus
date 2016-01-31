//
// Created by cahenk on 1/30/16.
//

#ifndef PASSFAULT_PASSWORDPATTERN_HPP
#define PASSFAULT_PASSWORDPATTERN_HPP

#include "SecureString.hpp"

namespace Passfault {

    /**
     * Stores information about an identified password pattern. Additionally, it contains the size of the
     * pattern and the location in the password that the pattern was found. Note that some finders have
     * the same cost regardless of the specific pattern found, but others do not. For example, a dictionary
     * word has the same cost for all words in the dictionary, but a keyboard sequence will have a higher
     * cost for longer sequences.
     *
     * @author Ranind
     */
    class PasswordPattern {
    private:

        const int startIndex;
        const int length;
        const double cost;
        const SecureString matchString;
        const std::string description;
        const std::string name;
        const std::string classification;

    public:

        /**
         *
         */
        PasswordPattern ( int startIndex, int length, SecureString matchString, double patternSize,
                          std::string description, std::string name, std::string classification );

        /**
         * @param startIndex
         * @param length
         * @param
         */
        PasswordPattern ( int startIndex, int length, SecureString matchString, double patternSize,
                          std::string description );

        /**
         * Gets the number of combinations that fit within this pattern. Note that this
         * includes the length of the specific password found
         * @return the number of combinations that fit within this pattern
         */
        double getPatternSize();

        /**
         * Gets the match start index
         * @return the match start index
         */
        int getStartIndex();

        /**
         * Gets the match length
         * @return the match length
         */
        int getLength();

        /**
         * Gets the cost
         * @return the cost
         */
        double getCost();

        /**
         * Gets the match string
         * @return the match string
         */
        SecureString getMatchString();

        /**
         * Gets the description
         * @return the description
         */
        std::string getDescription();

        /**
         * Gets the name
         * @return the name
         */
        std::string getName();

        /**
         * Gets the classification
         * @return the classification
         */
        std::string getClassification();
    };

}

#endif //PASSFAULT_PASSWORDPATTERN_HPP
