//
// Created by cahenk on 1/26/16.
//

#ifndef PASSFAULT_TIMETOCRACK_HPP
#define PASSFAULT_TIMETOCRACK_HPP

namespace Passfault {

    /**
     *
     * @author Ranind
     */
    class TimeToCrack {
    public:

        enum HackerType {
            EVERY_DAY_HACKER,
            DEDICATED_HACKER,
            ORGANIZED_CRIME_HACKER,
            GOVERNMENT_HACKER,
        };

        enum HackerBudget {
            US_500 = 500,
            US_5000 = 5000,
            US_50000 = 50000,
            US_500000 = 500000
        };

        enum HashCrackTimeNS : long {
            B_CRYPT = 259000,
            MD5_CRYPT = 226,
            SHA_512_CRYPT = 29247,
            PASSWORD_SAFE = 1543
        };

        /**
         * Estimates the average time to find a password based on attackers computing power
         * @param patternSize the number of passwords that exist in a pattern
         * @param crackTimeNanoseconds the number of nanoseconds required to compute a single hash (on 1 GPU)
         * @param complexity the number of times a password is hashed
         * @param numberOfGPUs the number of GPUs working in parallel
         * @return the number of nanoseconds? needed to crack the pattern
         */
        double getTimeToCrackNanoseconds ( double patternSize, long crackTimeNanoseconds = B_CRYPT, int complexity, int numberOfGPUs = 1 );

        /**
         * Estimates the average time to find a password based on attackers computing power and expresses the result
         * as a string (using words)
         * @param patternSize the number of passwords that exist in a pattern
         * @param crackTimeNanoseconds the number of nanoseconds required to compute a single hash (on 1 GPU)
         * @param complexity the number of times a password is hashed
         * @param numberOfGPUs the number of GPUs working in parallel
         * @return a string that describes the amount of time to crack the pattern, such as "8 months and 3 days"
         */
        std::string getTimeToCrackString ( double patternSize, long crackTimeNanoseconds = B_CRYPT, int complexity, int numberOfGPUs = 1 );

        /**
         * Creates a string that approximately describes the size of a number (in words)
         * @param size the number to be described
         * @return a string that describes the size of a number, such as "1 million 345 thousand"
         */
        std::string getRoundedSizeString ( double size );

    };

}

#endif //PASSFAULT_TIMETOCRACK_HPP
