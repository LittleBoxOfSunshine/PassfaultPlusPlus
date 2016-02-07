//
// Created by Chris Henk on 2/2/16.
//

#ifndef PASSFAULT_FINDERBYPROPSBUILDER_HPP
#define PASSFAULT_FINDERBYPROPSBUILDER_HPP

namespace Passfault {

    /**
     * Builds a set of pattern finders based on properties. It follows the convention of wordlists
     * in the same location as a words.properties file
     *
     * The words.properties file can declare wordlist groups.  The most popular words start with 1:
     * words.english.1 = mostPopularEnglishWords.words
     * words.english.2 = lessPopularEnglishWords.words
     *
     * A dictionary from the second will have the size of the first and second.
     * @author Ranind
     */
    class FinderByPropsBuilder {
    public:

        // TODO: figure out logging solution



    };

}

#endif //PASSFAULT_FINDERBYPROPSBUILDER_HPP
