//
// Created by Chris Henk on 1/26/16.
//

#include "io/TimeToCrack.hpp"

double Passfault::TimeToCrack::getTimeToCrackNanoseconds(double patternSize, unsigned long crackTimeNanoseconds,
                                                         int numberOfGPUs) {
    // Compute crack time
    return (crackTimeNanoseconds * patternSize) / numberOfGPUs;
}

std::string Passfault::TimeToCrack::getTimeToCrackString(double patternSize, unsigned long crackTimeNanoseconds,
                                                         int numberOfGPUs) {
    // Compute crack time
    double ns = Passfault::TimeToCrack::getTimeToCrackNanoseconds(patternSize, crackTimeNanoseconds, numberOfGPUs);

    // Define time interval constants (used as divisors for time conversions)
    int days = (int) (ns / 1e9 / 60 / 60 / 24);
    int months = (int) (ns / 1e9 / 60 / 60 / 24 / 30);
    int years = (int) (ns / 1e9 / 60 / 60 / 24 / 365);
    int decades = years / 10;
    int centuries = years / 100;
    int remainderMonths = months % 12;
    int remainderDays = days % 30;
    int remainderYears = years % 10;
    int remainderDecades = decades % 10;

    // Convert number to string representation
    std::stringstream ss;

    if ( centuries > 0 ) {
        remainderYears = 0; // don't show years if centuries are shown
        ss << centuries << (centuries == 1 ? " century" : " centuries"); // Display time with unit

        if ( remainderDecades > 0 && centuries < 10 )
            ss << ", ";
    }

    if ( remainderDecades > 0 && centuries < 10 ) {
        remainderMonths = 0; // don't show months if decades are shown
        ss << remainderDecades << (remainderDecades == 1 ? " decade" : " decades"); // Display time with unit

        if ( remainderYears > 0 && decades < 10 )
            ss << ", ";
    }

    if ( remainderYears > 0 && decades < 10 ) {
        remainderDays = 0; // don't show days if years are shown
        ss << remainderYears << (remainderYears == 1 ? " year" : " years"); // Display time with unit

        if ( remainderMonths > 0 && years < 10 )
            ss << ", ";
    }

    if ( remainderMonths > 0 && years < 10 ) {
        ss << remainderMonths << (remainderMonths == 1 ? " month" : " months"); // Display time with unit

        if ( remainderDays > 0 && years < 10 )
            ss << ", ";
    }

    if ( remainderDays > 0 && years < 10 ) {
        ss << remainderDays << (remainderDays == 1 ? " day" : " days"); // Display time with unit
    }

    if ( remainderDays == 0 && remainderMonths == 0 && years == 0) {
        ss << "less than 1 day...";
    }

    return ss.str();
}

std::string Passfault::TimeToCrack::getRoundedSizeString ( double size ) {
    int roundCount = 0;

    // Find the number of 1000s in number
    while ( size >= 1000 ) {
        size /= 1000;
        roundCount++;
    }

    // Convert number to rounded string representation
    std::stringstream ss;

    ss << (int) size;

    const char * const types[] = {
            "hundred",
            "thousand",
            "million",
            "billion",
            "trillion",
            "quadrillion",
            "quintillion",
            "sextillion",
            "septillion",
            "octillion",
            "nonillion",
            "decillion",
    };

    // Pad the number with zeros until it is small enough to use a label
    for ( int i = roundCount+1; i >= (sizeof(types)/sizeof(*types)); i-- )
        ss << ",000";

    // Print the size label
    ss << ' ' << types[roundCount];

    return ss.str();
}

unsigned long Passfault::TimeToCrack::getBcryptCrackNanoSeconds ( unsigned int cost ) {
    return B_CRYPT_BASE_NS * (2 << cost);
}