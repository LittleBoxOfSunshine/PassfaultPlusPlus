//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_PASSWORDANALYSIS_HPP
#define PASSFAULT_PASSWORDANALYSIS_HPP

#include <unordered_map>
#include <mutex>
#include <limits>
#include <vector>

#include "common/SecureString.hpp"
#include "pattern/Random.hpp"
#include "common/Path.hpp"

namespace Passfault {

    /**
     * This class is used to store the results of a password analysis. An instance of this class
     * begins with a password to analyze before being used in multiple PatternFinders. This class
     * also performs the post-analysis of the finders found, including finding the weakest
     * combination of finders and locating repeated finders.
     *
     * @author Ranind
     */
    class PasswordAnalysis {
    private:

        // TODO: Figure out a logging library to use?

        /** Mutex for synchronized block */
        std::mutex mutex_;

        /** The password being analyzed */
        SecureString password;

        /** Map of patterns found in the password, indexed by the starting index of the pattern in the password */
        std::unordered_map<int, std::vector<PasswordPattern>> foundPatterns;

        /**
         * Map of deep copies of the smallest cost for each index with a vector of patterns, also indexed by the starting
         * position of the pattern in the password
         */
        std::unordered_map<int, Path> ithSmallestCost;

        /** The total number of patterns identified, initialized to 0 */
        int patternCount = 0;

        /** Stores the finalized PathCost for the password */
        Path* finalResults = nullptr;

        //todo remove counter, this is just for debugging to measure the optimization effectiveness
        int counter = 0;

    public:

        /**
         * Construct a password analysis for the given password
         * @param password the password to be analyzed
         */
        PasswordAnalysis ( SecureString password );

        /**
         * Returns a copy of the password being analyzed
         * @return the password being analyzed
         * @override
         */
        virtual SecureString getPassword();

        /**
         * Returns the length of the password being analyzed
         * @return the length of the password being analyzed
         * @override
         */
        virtual unsigned long getLength();

        /**
         * Function is called by pattern finders to store a newly discovered pattern within the password.
         * This function is synchronized! (Other threads will be blocked until the current thread using the
         * object is finished)
         * @param pattern
         * @override the pattern found in the password
         */
        virtual void foundPattern ( PasswordPattern pattern );

        /**
         * Gets the total number of patterns identified
         * @return the total number of patterns identified
         * @override
         */
        virtual int getPossiblePatternCount();

        /**
         * Calculates the highest probable combination of finders. In other words,
         * the weakest combinations of found passwords
         * @override
         */
        virtual Path calculateHighestProbablePatterns();

    private:

        /**
        * Loads the vector of patterns that begin on the index of the password
        * @param startIndex the starting index of patterns to return
        * @return the vector of patterns that begin on the index of the password
        */
        std::vector<PasswordPattern> & getIndexSet ( int startIndex );

        /**
         * Recursive call to compute the smallest cost (weakest combination) of finders
         * starting at the index specified by startChar
         * @param startChar index of the character to start with
         * @return a pointer to the smallest PathCost found in the analysis
         */
        Path smallestCost ( int startChar );

        /**
         * Helper function for smallest cost
         * @param ithPatterns vector of patterns found for the index
         * @return smallest result of calling smallestCost on all patterns in the vector
         */
        Path calculateIthSmallestCost ( std::vector<PasswordPattern> ithPatterns );

        /**
         * Add the random pattern strength of a substring of the password to the cost.
         * Function will return if startChar is >= length.
         * @param path the path cost to add to
         * @param startChar the starting index
         * @param endChar the ending index (noninclusive)
         * @return the random pattern for the substring of the password
         */
        inline void addRandomPattern ( Path & path, int startChar, unsigned long length );

        /**
         * Overwrites the PathCost stored as the smallest cost for index i. Note that the function will
         * insert a deep copy of the PathCost
         * @param i index to overwrite
         * @param pathCost the new PatCost data to store
         */
        void setIthSmallestCost ( int i, Path pathCost );

        /**
         * Destructor, frees memory for finalResults pointer if necessary
         */
        ~PasswordAnalysis();
    };

}

#endif //PASSFAULT_PASSWORDANALYSIS_HPP
