//
// Created by cahenk on 1/30/16.
//

#include "PasswordPattern.hpp"

Passfault::PasswordPattern::PasswordPattern(int startIndex, int length, SecureString matchString, double patternSize,
                                            std::string description, std::string name, std::string classification) {
    this->startIndex = startIndex;
    this->length = length;
    this->matchString = matchString;
    this->patternSize = patternSize;
    this->description = description;
    this->name = name;
    this->classification = classification;
}

Passfault::PasswordPattern::PasswordPattern(int startIndex, int length, SecureString matchString, double patternSize,
                                            std::string description) {
    this->startIndex = startIndex;
    this->length = length;
    this->matchString = matchString;
    this->patternSize = patternSize;
    this->description = description;
}

double Passfault::PasswordPattern::getPatternSize() {
    return this->patternSize;
}

int Passfault::PasswordPattern::getStartIndex() {
    return this->startIndex;
}

int Passfault::PasswordPattern::getLength() {
    return this->getLength();
}

double Passfault::PasswordPattern::getCost() {
    return this->cost;
}

Passfault::SecureString Passfault::PasswordPattern::getMatchString() {
    return this->matchString;
}

std::string Passfault::PasswordPattern::getDescription() {
    return this->description;
}

std::string Passfault::PasswordPattern::getName() {
    return this->name;
}

std::string Passfault::PasswordPattern::getClassification() {
    return this->classification;
}