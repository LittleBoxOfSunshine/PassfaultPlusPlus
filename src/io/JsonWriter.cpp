//
// Created by Chris Henk on 1/26/16.
//

#include "JsonWriter.hpp"

// Writes all the PasswordPattern's in PathCost to a stream as a JSON encoded string
void Passfault::io::JsonWriter::write ( std::istream & writer, const Passfault::PathCost & highestPath ) {

    // Load total cost and pattern vector
    double cost = highestPath.getTotalCost();
    std::vector<Passfault::PasswordPattern> path = highestPath.getPath();

    // Write the loaded data to the provided stream
    writer << "{\"cost\": " << cost << ",\"patterns\": [";

    for(const auto & p : path )
        Passfault::io::JsonWriter::write( writer, p);

    writter << "]}";
}

// Writes a PasswordPattern to a stream as a JSON encoded string
void Passfault::io::JsonWriter::write ( std::istream & writer, const Passfault::PasswordPattern & pattern ) {

    // Write data to stream with necessary formatting to form a JSON encoded string
    writer << "{\"name\": \"" << pattern.getName() << "\",";
    writer << "{\"description\": \"" << pattern.getDescription() << "\",";
    writer << "{\"patternSize\": " << pattern.getPatternSize() << ",";
    writer << "{\"classification\": \"" << pattern.getClassifiation << "\",";


    writer.write("\"matchString\" : \"");
    CharSequence matchString = pattern.getMatchString();
    for(int i=0; i<matchString.length(); i++){
        writer.write(matchString.charAt(i));
    }
    writer.write("\",");

    writer.write("\"startIndex\" : ");
    writer.write(Integer.toString(pattern.getStartIndex()));
    writer.write(",");

    writer.write("\"length\" : ");
    writer.write(Integer.toString(pattern.getLength()));

    writer.write('}');
}