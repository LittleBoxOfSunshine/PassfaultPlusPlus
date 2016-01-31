//
// Created by Chris Henk on 1/26/16.
//

#include "io/JsonWriter.hpp"

// Writes all the PasswordPattern's in PathCost to a stream as a JSON encoded string
void Passfault::io::JsonWriter::write ( std::ostream & writer, const Passfault::PathCost & highestPath ) {

    // Load total cost and pattern vector
    double cost = highestPath.getTotalCost();
    std::vector<Passfault::PasswordPattern> path = highestPath.getPath();

    // Write the loaded data to the provided stream
    writer << "{\"cost\": " << cost << ",\"patterns\": [";

    for ( const auto & p : path )
        Passfault::io::JsonWriter::write( writer, p );

    writer << "]}";
}

// Writes a PasswordPattern to a stream as a JSON encoded string
void Passfault::io::JsonWriter::write ( std::ostream & writer, const Passfault::PasswordPattern & pattern ) {

    // Write data to stream with necessary formatting to form a JSON encoded string
    writer << '{';

    writer << "\"name\": \"" << pattern.getName() << "\",";
    writer << "\"description\": \"" << pattern.getDescription() << "\",";
    writer << "\"patternSize\": " << pattern.getPatternSize() << ",";
    writer << "\"classification\": \"" << pattern.getClassification() << "\",";

    writer << "\"matchString\": \"";
    Passfault::SecureString chars = pattern.getMatchString();
    for ( int i = 0; i < chars.length(); i++ )
        writer << chars.charAt(i);
    writer << "\",";

    writer << "\"startIndex\": \"" << pattern.getStartIndex() << "\",";
    writer << "\"length\": \"" << pattern.getLength() << "\",";

    writer << '}';
}