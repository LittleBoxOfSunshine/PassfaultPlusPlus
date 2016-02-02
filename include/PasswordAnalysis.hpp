//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_PASSWORDANALYSIS_HPP
#define PASSFAULT_PASSWORDANALYSIS_HPP

#include <unordered_map>

#include "PasswordResults.hpp"
#include "SecureString.hpp"

namespace Passfault {

    class PasswordAnalysis : public PasswordResults {
    private:

        // TODO: Figure out a logging library to use?

        SecureString password;

        std::unordered_map<int, std::vector<PasswordPattern>> foundPatterns;

        std::unordered_map<int, PathCost> ithSmallestCost;

        int patternCount = 0;

        std::vector<AnalysisListener> analysisListeners;

        RepeatingPatternFinder repeatingPatternFinder;

        PathCost finalResults;

        RandomPattern randomPatternFinder;

        //todo remove counter, this is just for debugging to measure the optmization effectiveness
        int counter = 0;

    public:

        PasswordAnalysis ( SecureString password );

        /**
         * @override
         */
        virtual SecureString getPassword();

        /**
         * @override
         */
        virtual int getLength();

        /**
         * @override
         */
        virtual void addListener ( AnalysisListener listener );

        /**
         * @override
         */
        virtual void foundPattern ( PasswordPattern patt );

        std::vector<PasswordPattern> getIndexSet ( int startIndex );

        /**
         * @override
         */
        virtual int getPossiblePatternCount();

        /**
         * @override
         */
        virtual PathCost calculateHighestProbablePatterns();

        PathCost smallestCost ( int startChar );

        PathCost calculateIthSmallestCost ( std::vector<PasswordPattern> ithPatterns );

        PathCost postAnalysis ( PathCost cost );

        PasswordPattern getRandomPattern ( int startChar, int endChar );

        void setIthSmallestCost ( int i, PathCost pathCost );

        PathCost getIthSmallestCost ( int i );

        // TODO: Determine if this function is actually needed, it's meant to help the java garbage collector
        void cleanup();
    };

}

#endif //PASSFAULT_PASSWORDANALYSIS_HPP
