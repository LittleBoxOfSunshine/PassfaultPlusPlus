//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_JSONWRITER_HPP
#define PASSFAULT_JSONWRITER_HPP

#include <istream>
#include <vector>

#include "PasswordPattern"
#include "PathCost"

namespace Passfault {

    namespace io {

        /// Writes Passfault++ data to a stream as a JSON encoded string
        class JsonWriter {
        public:
            /// Writes all the PasswordPattern's in PathCost to a stream as a JSON encoded string
            static void write ( std::istream & writer, const Passfault::PathCost & highestPath );
            // Writes a PasswordPattern to a stream as a JSON encoded string
            static void write ( std::istream & writer, const Passfault::PasswordPattern & part );
        };

    }

}

#endif //PASSFAULT_JSONWRITER_HPP
