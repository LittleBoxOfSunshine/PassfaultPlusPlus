//
// Created by cahenk on 1/26/16.
//

#ifndef PASSFAULT_COMPOSITEFINDER_HPP
#define PASSFAULT_COMPOSITEFINDER_HPP

#include "PatternFinder.hpp"
#include "PasswordResults.hpp"

namespace Passfault {

    /**
     * CompositeFinders combine multiple finders and treat them as one. It adds additional functions to support
     * parallel processing. The existing analyze function is non-blocking and the two new functions (blockingAnalyze +
     * waitForAnalysis) are blocking. waitForAnalysis is used after analyze is called.
     * @author Ranind
     */
    class CompositeFinder : public Passfault::PatternFinder {
    public:
        /**
         * Blocking analyze. Equivalent to calling analyze and waitForAnalysis.
         * @param pass password results to store found patterns
         */
        virtual void blockingAnalyze ( Passfault::PasswordResults pass ) = 0;

        /**
         * To be used AFTER analyze is called.
         * @param pass password results to store found patterns
         */
        virtual void waitForAnalysis ( Passfault::PasswordResults pass ) = 0;
    };

}

#endif //PASSFAULT_COMPOSITEFINDER_HPP
