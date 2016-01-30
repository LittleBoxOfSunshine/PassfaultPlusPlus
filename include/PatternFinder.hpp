//
// Created by cahenk on 1/26/16.
//

#ifndef PASSFAULT_PATTERNFINDER_HPP
#define PASSFAULT_PATTERNFINDER_HPP

#include "PasswordResults.hpp"

namespace Passfault {

    /**
     * This interface represents a password pattern finder
     * @author Ranind
     */
    class PatternFinder {
    public:

        /**
         * A password is provided by reference to the find through this function and will have the results
         * placed into it.
         * @param pass Object contains the password and any that will be found as the result of analysis
         */
        virtual void analyze ( PasswordResults pass ) = 0;
    };
}

#endif //PASSFAULT_PATTERNFINDER_HPP
