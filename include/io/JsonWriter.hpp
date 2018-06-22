//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_JSONWRITER_HPP
#define PASSFAULT_JSONWRITER_HPP

#include <ostream>
#include <vector>

#include "common/Pattern.hpp"
#include "common/Path.hpp"
#include "common/SecureString.hpp"

namespace Passfault {

    namespace io {

        /**
         * Writes Passfault++ data to a stream as a JSON encoded string
         * @author Ranind
         */
        class JsonWriter {
        public:
            /**
             * Writes all the PasswordPattern's in PathCost to a stream as a JSON encoded string
             * @param writer stream to write JSON encoded string to
             * @param highestPath The PathCost to extract PasswordPattern's from
             */
            static void write ( std::ostream & writer, const Passfault::Path & highestPath );
            /**
             * Writes a PasswordPattern to a stream as a JSON encoded string
             * @param writer stream to write JSON encoded string to
             * @param pattern PasswordPattern to extract data from
             */
            static void write ( std::ostream & writer, const Passfault::PasswordPattern & pattern );
        };

    }

}

#endif //PASSFAULT_JSONWRITER_HPP
