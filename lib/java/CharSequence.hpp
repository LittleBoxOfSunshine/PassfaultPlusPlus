//
// Created by Chris Henk on 1/26/16.
//

#ifndef PASSFAULT_CHARSEQUENCE_HPP
#define PASSFAULT_CHARSEQUENCE_HPP

namespace Java {

    class CharSequence {
    public:
        char charAt(int index);

        int length();

        CharSequence subSequence(int start, int end);


    };

}

#endif //PASSFAULT_CHARSEQUENCE_HPP
