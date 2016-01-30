//
// Created by cahenk on 1/29/16.
//

#ifndef PASSFAULT_ANALYZE_HPP
#define PASSFAULT_ANALYZE_HPP

#include <string>

#include "TimeToCrack.hpp"

namespace Passfault {

    /**
     * Configurable analysis, the default analysis, assumes 1 GPU attacker, bcrypt of cost 10
     */
    static std::string analyzePassword( std::string password, TimeToCrack::HashCrackTimeNS crackTimeNanoseconds = TimeToCrack::HashCrackTimeNS::B_CRYPT, int complexity = 1 );

    /**
     * Analysis with custom difficulty
     */
    static std::string analyzePassword( std::string password, long timeToCrackNanoseconds );

    /**
     * bcrypt specific analysis. Intended for ease of use with PHP's integrated password_hash() function (hence
     * the default cost is 10, as is the case in PHP)
     * @param password The password to be analyzed.
     * @param cost the cost (complexity) parameter to be used. It is the base 2 log of the iteration counter
     * for the underlying Blowfish-based hashing algorithm. Defaults to 10.
     */
    static std::string analyzeBcryptPassword ( std::string password, int cost = 10 );
}

#endif //PASSFAULT_ANALYZE_HPP
