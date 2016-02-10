//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_TIMETOCRACK_HPP
#define PASSFAULT_TIMETOCRACK_HPP

#include <sstream>

namespace Passfault {

    /**
     * This collection of static functions and enumerations aids in the computation and display
     * of time to crack a password based on its complexity. It assumes worst case scenarios for
     * all of its defaults
     * @author Ranind
     */
    class TimeToCrack {
        private:

            /** Time in nanoseconds for GPU to complete bcrypt with 1 iteration of the underlying blowfish algorithm */
            const static unsigned long B_CRYPT_BASE_NS = 253;

        public:

        /** Preset budgets based on attacker classification */
        enum HackerType {
            EVERY_DAY_HACKER = 500,
            DEDICATED_HACKER = 5000,
            ORGANIZED_CRIME_HACKER = 50000,
            GOVERNMENT_HACKER = 500000,
        };

        enum HashCrackTimeNS : unsigned long {
            B_CRYPT = Passfault::TimeToCrack::getBcryptCrackNanoSeconds(10),
            MD5_CRYPT = 226,
            SHA_512_CRYPT = 29247,
            PASSWORD_SAFE = 1543
        };

        /**
         * Estimates the average time to find a password based on attackers computing power
         * @param patternSize the number of passwords that exist in a pattern
         * @param crackTimeNanoseconds the number of nanoseconds required to compute a single hash (on 1 GPU)
         * @param numberOfGPUs the number of GPUs working in parallel
         * @return the number of nanoseconds? needed to crack the pattern
         */
        static double getTimeToCrackNanoseconds ( double patternSize, long crackTimeNanoseconds = B_CRYPT, int numberOfGPUs = 1 );

        /**
         * Estimates the average time to find a password based on attackers computing power and expresses the result
         * as a string (using words)
         * @param patternSize the number of passwords that exist in a pattern
         * @param crackTimeNanoseconds the number of nanoseconds required to compute a single hash (on 1 GPU)
         * @param numberOfGPUs the number of GPUs working in parallel
         * @return a string that describes the amount of time to crack the pattern, such as "8 months and 3 days"
         */
        static std::string getTimeToCrackString ( double patternSize, long crackTimeNanoseconds = B_CRYPT, int numberOfGPUs = 1 );

        /**
         * Creates a string that approximately describes the size of a number (in words)
         * @param size the number to be described
         * @return a string that describes the size of a number, such as "1 million 345 thousand"
         */
        static std::string getRoundedSizeString ( double size );

        /**
         * Computes the time needed to crack a bcrypt hash based on the cost (complexity)
         * @param cost the cost (complexity) parameter to be used. It is the base 2 log of the iteration counter
         * for the underlying Blowfish-based hashing algorithm. Defaults to 10.
         * @return the number of nanoseconds required to compute the hash
         */
        static unsigned long getBcryptCrackNanoSeconds ( int cost ) const;

    };

}

#endif //PASSFAULT_TIMETOCRACK_HPP
