//
// Created by Chris Henk on 1/26/16.
//
#include "analyisis/PasswordAnalysis.hpp"

Passfault::PasswordAnalysis::PasswordAnalysis(SecureString password) {
    this->password = password;
}

Passfault::SecureString Passfault::PasswordAnalysis::getPassword() {
    return this->password;
}

unsigned long Passfault::PasswordAnalysis::getLength() {
    return this->password.length();
}


void Passfault::PasswordAnalysis::foundPattern(PasswordPattern pattern) {
    // This is a synchronized function, create a lock
    std::lock_guard<std::mutex> lock(this->mutex_);

    PasswordPattern randomPattern = RandomPattern::getRandomPattern(this->password, pattern.getStartIndex(),
                                                                    pattern.getLength());

    if (pattern.getCost() > randomPattern.getCost()) {
        // TODO: log that -> pattern discarded because random is smaller: {0}", patt.getName())
        return;
    }

    std::vector<PasswordPattern> patterns = getIndexSet(pattern.getStartIndex());
    bool worsePatternAlreadyFound = false;

    for (PasswordPattern &patt : patterns) {
        if (pattern.getLength() == patt.getLength() && pattern.getCost() > patt.getCost()) {
            worsePatternAlreadyFound = true;
            // TODO: log that ->  discarding found pattern since a smaller pattern already exists: {0}", patt.getName())
        }
    }

    if (!worsePatternAlreadyFound) {
        patterns.push_back(pattern);
        this->patternCount++;
    }
}

std::vector<Passfault::PasswordPattern> & Passfault::PasswordAnalysis::getIndexSet(int startIndex) {
    return this->foundPatterns[startIndex];
}

int Passfault::PasswordAnalysis::getPossiblePatternCount() {
    return this->patternCount;
}

Passfault::Path Passfault::PasswordAnalysis::calculateHighestProbablePatterns() {
    if (this->finalResults == nullptr){
        // TODO: log that ->  "Calculating the highest probable combination of %s finders\n", getPossiblePatternCount());
        this->finalResults = new Path(this->smallestCost(0));

        // Run the post processing with a repeatingFinder to handle any duplicates that may exist
        // TODO: Deal with next line
        // this->repeatingPatternFinder.process(this->finalResults, this);

        // TODO: log that -> "smallestCost took %d iterations", counter);

        // TODO: Determine if these are needed, originally intended to clean up any circular references for garbage cleanup
        //this->ithSmallestCost.clear();
        //this->foundPatterns.clear();
    }

    return *finalResults;
}

Passfault::Path Passfault::PasswordAnalysis::smallestCost(int startChar) {
    double smallestCost = std::numeric_limits<double>::max();

    auto itr = this->ithSmallestCost.find(startChar);

    if (itr == this->ithSmallestCost.end()) {
        Path smallestCostPath(this->password);

        for (int i = startChar; i < this->password.length(); i++) {
            std::vector<PasswordPattern> ithPatterns = this->foundPatterns[i];

            if (!ithPatterns.empty()) {
                this->counter++;

                Path pathCost = this->calculateIthSmallestCost(ithPatterns);

                // Random characters between startChar and the next found pattern
                this->addRandomPattern(pathCost, startChar, this->password.length());

                if (pathCost.getRelativeCost() < smallestCost) {
                    smallestCost = pathCost.getRelativeCost();
                    smallestCostPath = pathCost;
                }
            }
        }

        return smallestCostPath;

    }
    else {
        return (*itr).second;
    }
}

inline void Passfault::PasswordAnalysis::addRandomPattern ( Path & path, int startChar, unsigned long length ) {
    if (startChar < length)
        path.addPattern(RandomPattern::getRandomPattern(this->password, startChar, length));
}

