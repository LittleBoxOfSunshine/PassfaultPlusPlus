//
// Created by Chris Henk on 1/31/16.
//

#ifndef PASSFAULT_PATH_HPP
#define PASSFAULT_PATH_HPP

#include <vector>

#include "pattern/Pattern.hpp"
#include "pattern/Random.hpp"

// TODO: Include generic way to identify repeated patterns as post-processing step
namespace Passfault {

    /**
     * This class represents a list (path) of patterns in a password and computes the cost of
     * the patterns. It is considered a path because the patterns found in a password can be
     * ordered in a graph. A path in the graph contains patterns that do not overlap. The cost
     * of the path is the combination of all patterns in the graph plus the additional cost of
     * any part of the password that does not have a cost.
     *
     * @author Ranind
     */
    class Path {
    private:

        /** Results of the password analysis */
        SecureString password;

        /** The patterns that make up the path */
        std::vector<PasswordPattern> path;

        /** Total cost of the patterns */
        double cost = 1.0;

    public:

        /**
         * Constructor
         * @param password results of analysis to compute cost from
         */
        Path ( const SecureString & password );

        /**
         * Copy Constructor
         * @param password The PathCost object to copy
         */
        Path ( const Path & path );

        /**
         * Adds a pattern to the current path and cost
         * @param pattern The pattern to add
         */
        void addPattern ( PasswordPattern pattern );

        /**
         * Returns the cost of the current finders to the end of the pattern list. It includes the
         * cost of the finders and any random unidentified characters from the first pattern to
         * the end of the password. Any random characters before the first patter are included.
         * See. getTotalCost
         * @return the cost of the current finders to the end of the pattern list
         */
        double getRelativeCost() const;

        /**
         * Returns the number of passwords that fit in the finders in this path plus the additional
         * cost of random characters not covered by finders.
         * @return number of passwords in finders + random character cost
         */
        double getTotalCost() const;

        /**
         * Returns the patterns that make up the PathCost's path
         * @return the patterns that make up the PathCost's path
         */
        std::vector<PasswordPattern> getPath() const;
    };

}

#endif //PASSFAULT_PATH_HPP
