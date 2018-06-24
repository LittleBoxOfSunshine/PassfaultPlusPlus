//
// Created by cahenk on 2/9/16.
//

#include "common/Path.hpp"

Passfault::Path::Path ( const SecureString & password ) {
    this->password = password;
}

Passfault::Path::Path ( const Path & path ) {
    this->password = path.password;
    this->cost = path.cost;
}

void Passfault::Path::addPattern(PasswordPattern pattern) {
    this->cost *= pattern.getPatternSize();
    this->path.push_back(pattern);
}

double Passfault::Path::getRelativeCost() const {
    if ( path.empty() )
        return RandomPattern::randomCost((int)this->password.length());
    else
        return this->cost;
}

double Passfault::Path::getTotalCost() const {
    if ( this->path.empty() )
        return RandomPattern::randomCost((int)this->password.length());
    else
        return RandomPattern::randomCost(this->path.back().getStartIndex() * ((int)this->getRelativeCost()));
}

std::vector<Passfault::PasswordPattern> Passfault::Path::getPath() const {
    return this->path;
}
