//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_PASSWORDRESULT_HPP
#define PASSFAULT_PASSWORDRESULT_HPP

/**
 * This interface represents a collection of discovered password patterns. It is passed to pattern finders and is used
 * to store patterns during analysis. Listeners can be notified of when analysis is complete or even when new finders
 * are found.
 *
 * @author Ranind
 */

namespace Passfault {

    class {

    protected:

        /**
         * Adds a listener that will be notified when a pattern is found and when
         * a password analysis is complete
         * @param listener callback object to be notified when a pattern is found and
         * when analysis is complete.
         */
        virtual void addListener(AnalysisListener listener) = 0;

        /**
         * Calculates the highest probable combination of finders.  In other words,
         * the weakest combination of found patterns.
         * @return List of finders that make up the weakest combination of found passwords
         */
        virtual PathCost calculateHighestProbablePatterns();

        /**
         * This method is called by pattern finders to store a newly discovered pattern
         * in a password.
         * @param patt pattern found in the password.
         */
        void foundPattern(PasswordPattern patt);

        /**
         * @return total number of finders identified.
         */
        int getPossiblePatternCount();

    public:

        CharSequence getCharSequence();

        int getLength();
    };

}
#endif //PASSFAULT_PASSWORDRESULT_HPP
