//
// Created by Chris Henk on 1/30/16.
//

#include "PasswordPattern.hpp"

Passfault::PasswordPattern::PasswordPattern(int startIndex, int length, SecureString matchString, double patternSize,
                                            std::string description, std::string name, std::string classification) :
                                                startIndex(startIndex), length(length), matchString(matchString),
                                                cost(patternSize), description(description), name(name),
                                                classification(classification) {
    // NO BODY FOR THIS FUNCTION
}

Passfault::PasswordPattern::PasswordPattern(int startIndex, int length, SecureString matchString, double patternSize,
                                            std::string description) : startIndex(startIndex), length(length),
                                                                       matchString(matchString), cost(patternSize),
                                                                       description(description) {
    // NO BODY FOR THIS FUNCTION
}

double Passfault::PasswordPattern::getPatternSize() const {
    return this->cost;
}

int Passfault::PasswordPattern::getStartIndex() const {
    return this->startIndex;
}

int Passfault::PasswordPattern::getLength() const {
    return this->length;
}

double Passfault::PasswordPattern::getCost() const {
    return this->cost;
}

Passfault::SecureString Passfault::PasswordPattern::getMatchString() const {
    return this->matchString;
}

std::string Passfault::PasswordPattern::getDescription() const {
    return this->description;
}

std::string Passfault::PasswordPattern::getName() const {
    return this->name;
}

std::string Passfault::PasswordPattern::getClassification() const {
    return this->classification;
}