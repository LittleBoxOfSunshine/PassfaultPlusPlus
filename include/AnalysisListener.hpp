//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_ANALYSISLISTENER_HPP_H
#define PASSFAULT_ANALYSISLISTENER_HPP_H

#include "PathCost.hpp"
#include "PasswordPattern.hpp"

namespace Passfault {

   /**
    * Used to retrieve results from password analysis
    * @author Ranind
    */
    class AnalysisListener {
    public:
        /**
         * The highest probable Patterns were found. This PathCost list is the highest
         * probable combination of Patterns. Highest probable means the most likely to be cracked.
         * @param cost Object that combines a subset of all found patterns with their associated cost (probability of
         * being cracked)
         */
        virtual void foundHighestProbablePatterns ( PashCost cost ) = 0;
        /**
         * A pattern was found in a password.
         * @param pattern Pattern that was found in the password, including it's name and the part of the password that
         * matches the pattern
         */
        virtual void foundPattern ( PasswordPattern pattern ) = 0;
    };

}

#endif //PASSFAULT_ANALYSISLISTENER_HPP_H
