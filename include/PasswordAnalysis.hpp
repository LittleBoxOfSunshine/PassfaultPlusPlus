//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_PASSWORDANALYSIS_HPP
#define PASSFAULT_PASSWORDANALYSIS_HPP

#include <unordered_map>

#include "PasswordResults.hpp"
#include "SecureString.hpp"
#include "RandomPattern.hpp"

namespace Passfault {

    /**
     * This class is used to store the results of a password analysis. An instance of this class
     * begins with a password to analyze before being used in multiple PatternFinders. This class
     * also performs the post-analysis of the finders found, including finding the weakest
     * combination of finders and locating repeated finders.
     *
     * @author Ranind
     */
    class PasswordAnalysis : public PasswordResults {
    private:

        // TODO: Figure out a logging library to use?

        /** The password being analyzed */
        SecureString password;

        /** Map of patterns found in the password, indexed by the starting index of the pattern in the password */
        std::unordered_map<int, std::vector<PasswordPattern>> foundPatterns;

        /**
         * Map of deep copies of the smallest cost for each index with a vector of patterns, also indexed by the starting
         * position of the pattern in the password
         */
        std::unordered_map<int, PathCost> ithSmallestCost;

        /** The total number of patterns identified, initialized to 0 */
        int patternCount = 0;

        /** The listeners to be notified when the password analysis is completed */
        std::vector<AnalysisListener> analysisListeners;

        /** Post processing finder for identifying finders that have been repeated */
        RepeatingPatternFinder repeatingPatternFinder;

        /** Stores the finalized PathCost for the password */
        PathCost finalResults;

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
        virtual int getLength();

        /**
         * Adds a listener that will be notified when a password is found and when a password analysis is complete.
         * @param listener callback object to be notified when a password is found and when a password analysis is
         * complete.
         * @override
         */
        virtual void addListener ( AnalysisListener listener );

        /**
         * Function is called by pattern finders to store a newly discovered pattern within the password
         * @param pattern
         * @override the pattern found in the password
         */
        virtual void foundPattern ( PasswordPattern pattern );

        /**
         * Loads the vector of patterns that begin on the index of the password
         * @param startIndex the starting index of patterns to return
         * @return the vector of patterns that begin on the index of the password
         */
        std::vector<PasswordPattern> getIndexSet ( int startIndex );

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
        virtual PathCost calculateHighestProbablePatterns();

        /**
         * Recursive call to compute the smallest cost (weakest combination) of finders
         * starting at the index specified by startChar
         * @param startChar index of the character to start with
         * @return the smallest PathCost found in the analysis
         */
        PathCost smallestCost ( int startChar );

        /**
         * Helper function for smallest cost
         * @param ithPatterns vector of patterns found for the index
         * @return smallest result of calling smallestCost on all patterns in the vector
         */
        PathCost calculateIthSmallestCost ( std::vector<PasswordPattern> ithPatterns );

        /**
         * Runs the post processing with a repeatingFinder to handle any duplicates that may exist
         * @param cost the PatchCost to handle duplicates for
         * @return a cloned PathCost that has gone through post processing
         */
        PathCost postAnalysis ( const PathCost & cost );

        /**
         * Get the random pattern strength of a substring of the password
         * @param startChar the starting index
         * @param endChar the ending index (noninclusive)
         * @return the random pattern for the substring of the password
         */
        PasswordPattern getRandomPattern ( int startChar, int endChar );

        /**
         * Overwrites the PathCost stored as the smallest cost for index i. Note that the function will
         * insert a deep copy of the PathCost
         * @param i index to overwrite
         * @param pathCost the new PatCost data to store
         */
        void setIthSmallestCost ( int i, PathCost pathCost );

        /**
         * Returns a deep copy of the smallest PathCost for position i.
         * @param i index to return
         * @return a deep copy of the smallest PathCost for position i.
         */
        PathCost getIthSmallestCost ( int i );

        // TODO: Determine if this function is actually needed, it's meant to help the java garbage collector
        void cleanup();
    };

}

#endif //PASSFAULT_PASSWORDANALYSIS_HPP
