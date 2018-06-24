//
// Created by Chris Henk on 1/30/16.
//

#ifndef PASSFAULT_PASSWORDPATTERN_HPP
#define PASSFAULT_PASSWORDPATTERN_HPP

#include "common/SecureString.hpp"

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

        /** The index in the password where the pattern beings */
        int startIndex;

        /** The length of the substring that matches the pattern */
        int length;

        /** The number of possible combinations in the pattern (with length taken into account) */
        double cost;

        /** The substring of the password that matches the pattern */
        SecureString matchString;

        /** A description of the pattern */
        std::string description;

        /** Canonical name of the pattern, identified by the constant NAME on a pattern finder strategy */
        std::string name;

        /** Language of the pattern, or another way to classify the pattern */
        std::string classification;

    public:

        /**
         * Constructs a password pattern with full description
         * @param startIndex index into the password of where the pattern begins
         * @param length number of characters of the pattern in the password
         * @param matchString the substring of the password that matches the pattern
         * @param patternSize number of possible combinations in the pattern (with length considered)
         * @param description description of the pattern
         * @param name Canonical name of the pattern, identified by the constant NAME on a pattern finder strategies
         * @param classification usually the language of the pattern, or another way to classify the pattern
         */
        PasswordPattern ( int startIndex, int length, SecureString matchString, double patternSize,
                          std::string description, std::string name, std::string classification );

        /**
         * Constructs a password pattern without defining a name or classification
         * @param startIndex index into the password of where the pattern begins
         * @param length number of characters of the pattern in the password
         * @param matchString the substring of the password that matches the pattern
         * @param patternSize number of possible combinations in the pattern (with length considered)
         * @param description description of the pattern
         */
        PasswordPattern ( int startIndex, int length, SecureString matchString, double patternSize,
                          std::string description );

        /**
         * Gets the number of combinations that fit within this pattern. Note that this
         * includes the length of the specific password found
         * @return the number of combinations that fit within this pattern
         */
        double getPatternSize() const;

        /**
         * Gets the match start index
         * @return the match start index
         */
        int getStartIndex() const;

        /**
         * Gets the match length
         * @return the match length
         */
        int getLength() const;

        /**
         * Gets the cost
         * @return the cost
         */
        double getCost() const;

        /**
         * Gets the match string
         * @return the match string
         */
        SecureString getMatchString() const;

        /**
         * Gets the description
         * @return the description
         */
        std::string getDescription() const;

        /**
         * Gets the name
         * @return the name
         */
        std::string getName() const;

        /**
         * Gets the classification
         * @return the classification
         */
        std::string getClassification() const;
    };

}

#endif //PASSFAULT_PASSWORDPATTERN_HPP
