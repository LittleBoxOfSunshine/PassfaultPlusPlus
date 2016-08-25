//
// Created by Chris Henk on 1/26/16.
//
#include "PasswordAnalysis.hpp"

Passfault::PasswordAnalysis::PasswordAnalysis(SecureString password) {
    this->password = password;
}

SecureString Passfault::PasswordAnalysis::getPassword() {
    return this->password;
}

unsigned long Passfault::PasswordAnalysis::getLength() {
    return this->password.length();
}

/*
 * Interesting things happen with random finders.  Some short finders can be
 * more complex than random finders.  Looking and testing all possible
 * combinations of random finders within a pattern is possible and was
 * experimented with.  However, having different classes of random (upper, lower,
 * numbers...) made it hard to determine if it was worthwhile.  The best solution
 * tried was to compare a newly found pattern to the random pattern of the same
 * sequence, and discard the pattern if random was better(smaller).
 */
void Passfault::PasswordAnalysis::addListener(AnalysisListener listener) {
   this->analysisListeners.push_back(listener);
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

        for (AnalysisListener &observer : this->analysisListeners)
            observer.foundPattern(pattern);
    }
}

std::vector<PasswordPattern> & Passfault::PasswordAnalysis::getIndexSet(int startIndex) {
    return this->foundPatterns[startIndex];
}

int Passfault::PasswordAnalysis::getPossiblePatternCount() {
    return this->patternCount;
}

PathCost Passfault::PasswordAnalysis::calculateHighestProbablePatterns() {
    if (this->finalResults == nullptr){
        // TODO: log that ->  "Calculating the highest probable combination of %s finders\n", getPossiblePatternCount());
        this->finalResults = new PathCost(this->smallestCost(0));

        // Run the post processing with a repeatingFinder to handle any duplicates that may exist
        this->repeatingPatternFinder.process(this->finalResults, this);

        // TODO: log that -> "smallestCost took %d iterations", counter);

        for (AnalysisListener & observer : this->analysisListeners)
            observer.foundHighestProbablePatterns(this->finalResults);

        // TODO: Determine if these are needed, originally intended to clean up any circular references for garbage cleanup
        //this->ithSmallestCost.clear();
        //this->foundPatterns.clear();
    }

    return *finalResults;
}

PathCost Passfault::PasswordAnalysis::smallestCost(int startChar) {
    double smallestCost = std::numeric_limits<double>::max();

    auto itr = this->ithSmallestCost.find(startChar);

    if (*itr == this->ithSmallestCost.end()) {
        PathCost smallestCostPath((PasswordResults)*this);

        for (int i = startChar; i < this->password.length(); i++) {
            std::vector<PasswordPattern> ithPatterns = this->foundPatterns[i];

            if (!ithPatterns.empty()) {
                this->counter++;

                PathCost pathCost = this->calculateIthSmallestCost(ithPatterns);

                // Random characters between startChar and the next found pattern
                this->addRandomPattern(pathCost, startChar, this->password.length());
            }
        }

        if () {

        }

        /*
         * for (int i = startChar; i < password.length(); i++) {
        List<PasswordPattern> ithPatterns = foundPatterns.get(i);
        if (ithPatterns != null) {
          counter++;

          PathCost pathCost = calculateIthSmallestCost(ithPatterns);

          //random characters between startChar and the next found pattern
          PasswordPattern randomPattern = getRandomPattern(startChar, i);
          if (randomPattern != null) {
            pathCost.addPattern(randomPattern);
          }

          if (pathCost.getRelativeCost() < smallestCost) {
            smallestCost = pathCost.getRelativeCost();
            smallestCostPath = pathCost;
          }

         */

    }
    else {
        return *itr;
    }
}



