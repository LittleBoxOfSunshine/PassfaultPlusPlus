//
// Created by Chris Henk on 2/2/16.
//

#ifndef PASSFAULT_FINDERBYPROPSBUILDER_HPP
#define PASSFAULT_FINDERBYPROPSBUILDER_HPP

#include <vector>
#include <set>
#include <unordered_map>
#include <fstream>

#include "dictionary/Dictionary.hpp"

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
    private:

        // TODO: figure out logging solution (should be static)

        /** Input stream for reading the file */
        std::ifstream inputStream;

        /** If file is kept in memory or not */
        bool inMemory = false;

    public:

        /** Define the file name for the word list index */
        const static std::string WORDLIST_CONFIG_PROPERTIES = "words.properties";

        /** Define group prefix for word lists */
        const static std::string WORDLIST_GROUP_PREFIX = "words.";

        /** Define the key suffix for word list name */
        const static std::string WORDLIST_NAME = ".name";

        /** Define the key suffix for word list file name */
        const static std::string WORDLIST_FILENAME = ".file";

        /** Define the default word list directory */
        const static std::string DEFAULT_WORDLISTS_LOCATION = "res/wordlists";

        /** Loads the default word lists using the default word list directory */
        void loadDefaultWordLists();

        /**
         *
         */
        void setWordListPath ( std::string resourceDir );

        /**
         * Sets flag for whether or not files should be kept in memory
         * @param inMemory whether or not to keep files in memory
         */
        void setInMemory ( bool inMemory );

        /**
         * Builds pattern finders for the word lists. This function assumes the resource directory
         * contains words.properties file that describes the word lists in the directory
         * @return PatternFinders for the word lists in the resource directory
         */
        std::vector<PatternFinder> build();

    protected:

        /**
         * Constructs a vector of the standard finders (EnglishKeyboard, RussianKeyboard,
         * DateFinder, RandomClassesFinder)
         * @return vector of the standard finders
         */
        std::vector<PatternFinder> buildStandardFinders();

        /**
         * Constructs a vector of the standard dictionary strategies for the given dictionary
         * (ExactWord, Misspelling, Insertion, Substitution, l337Substitution)
         * @param dictionary The dictionary to build strategies for
         * @return vector of the standard strategies for the dictionary
         */
        std::vector<PatternFinder> buildDictionaryFinders ( Dictionary dictionary );

        /**
         * Extracts the base filename (removes the extension)
         * @param wordlist the filename to extract the base from
         * @return the extracted base name
         */
        std::string getFileNameWithoutExtension ( std::string wordlist );

    private:

        /**
         * Constructs file's path based on group name and group index
         * @param group the group the file is in
         * @param i the file's index in group
         * @return the file's path
         */
        std::string buildFileName ( std::string group, int i );

        /**
         * Builds a dictionary from all files that belong to a group
         * @param groupName the name of the group
         * @param wordListName the name of the word list resource
         * @return dictionary with all data from the files in the group
         */
        Dictionary buildDictionary ( std::string groupName, std::string wordListName );

        /**
         * Gets the word list groups from the config/properties file
         * @param wordsConfig a key-value dictionary of the data from the word list properties file
         * @return set of the word list groups from the config/properties file
         */
        std::set<std::string> getWordListGroups ( std::unordered_map<std::string, std::string> wordsConfig );

    };

}

#endif //PASSFAULT_FINDERBYPROPSBUILDER_HPP
