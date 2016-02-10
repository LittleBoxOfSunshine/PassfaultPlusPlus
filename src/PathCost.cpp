//
// Created by cahenk on 2/9/16.
//

#include "PathCost.hpp"

Passfault::PathCost::PathCost ( const PasswordResults & password ) {
    this->password = password;
}

Passfault::PathCost::PathCost ( const PathCost & path ) {
    this->password = path.password;
    this->cost = path.cost;
}

void Passfault::PathCost::addPattern(PasswordPattern pattern) {
    this->cost *= pattern.getPatternSize();
    this->path.push_back(pattern);
}

double Passfault::PathCost::getRelativeCost() {
    if ( path.empty() )
        return RandomPattern::randomCost((int)this->password.getLength());
    else
        return this->cost;
}

double Passfault::PathCost::getTotalCost() {
    if ( this->path.empty() )
        return RandomPattern::randomCost((int)this->password.getLength());
    else
        return RandomPattern::randomCost(this->path.back().getStartIndex() * ((int)getRelativeCost()));
}

std::vector<PasswordPattern> Passfault::PathCost::getPath() {
    return this->path;
}
