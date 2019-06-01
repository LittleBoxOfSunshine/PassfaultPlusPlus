//
// Created by cahenk on 6/24/18.
//

#include "../catch.hpp"

#include "../include/common/SecureString.hpp"

// TODO: Include tests that consider utf8 edge cases once utf8 support is enabled

TEST_CASE("Secure String Class", "[SecureString]") {

    const char* empty = "";
    const char* small = "cat";
    const char* mixed = "1337Password!";
    const char* large = "The quick brown fox jumps over the lazy dog.";
//    const char* utf8  = "";

    std::string sEmpty = empty;
    std::string sSmall = small;
    std::string sMixed = mixed;
    std::string sLarge = large;
//    std::string sUtf8 = utf8;

    // NOTE: These will be zeroed by the following SecureString constructors
    std::string sEmptyCpy = empty;
    std::string sSmallCpy = small;
    std::string sMixedCpy = mixed;
    std::string sLargeCpy = large;
//    std::string sUtf8Cpy = utf8;

    Passfault::SecureString secEmpty(sEmptyCpy);
    Passfault::SecureString secSmall(sSmallCpy);
    Passfault::SecureString secMixed(sMixedCpy);
    Passfault::SecureString secLarge(sLargeCpy);
//    Passfault::SecureString secUtf8(sUtf8Cpy);

    SECTION("String Ptr Constructor") {
        Passfault::SecureString sec1(&sEmpty);
        Passfault::SecureString sec2(&sSmall);
        Passfault::SecureString sec3(&sMixed);
        Passfault::SecureString sec4(&sLarge);
//        Passfault::SecureString sec5(&sUtf8);

        REQUIRE(sec1 == empty);
        REQUIRE(sec2 == small);
        REQUIRE(sec3 == mixed);
        REQUIRE(sec4 == large);
//        REQUIRE(sec5 == utf8);
    }

    SECTION("String Ref Constructor") {
        Passfault::SecureString sec1(sEmpty);
        Passfault::SecureString sec2(sSmall);
        Passfault::SecureString sec3(sMixed);
        Passfault::SecureString sec4(sLarge);
//        Passfault::SecureString sec5(sUtf8);

        // Test proper copy
        REQUIRE(sec1 == empty);
        REQUIRE(sec2 == small);
        REQUIRE(sec3 == mixed);
        REQUIRE(sec4 == large);
//        REQUIRE(sec5 == utf8);

        // Test that original is zeroed
        REQUIRE(sEmpty[0] == 0);
        REQUIRE(sSmall[0] == 0);
        REQUIRE(sMixed[0] == 0);
        REQUIRE(sLarge[0] == 0);
//        REQUIRE(sUtf8[0] == 0);
    }

    // NOTE: These tests are somewhat redundant since substr wraps the function; consider removing
    SECTION("Copy Constructor") {
        Passfault::SecureString secEmptyCpy(secEmpty); // NOLINT
        Passfault::SecureString secSmallCpy(secSmall); // NOLINT
        Passfault::SecureString secMixedCpy(secMixed); // NOLINT
        Passfault::SecureString secLargeCpy(secLarge); // NOLINT
//        Passfault::SecureString secUtf8Cpy(secUtf8);   // NOLINT

        // Test proper copy
        REQUIRE(secEmptyCpy == empty);
        REQUIRE(secSmallCpy == small);
        REQUIRE(secMixedCpy == mixed);
        REQUIRE(secLargeCpy == large);
//        REQUIRE(secUtf8Cpy == utf8);

        // Test that original is unchanged
        REQUIRE(secEmptyCpy == secEmpty);
        REQUIRE(secSmallCpy == secSmall);
        REQUIRE(secMixedCpy == secMixed);
        REQUIRE(secLargeCpy == secLarge);
//        REQUIRE(secUtf8Cpy == secUtf8);
    }

    SECTION("Substring Constructor") {
        // Empty range tests
        REQUIRE(Passfault::SecureString(secEmpty, 0, 0) == sEmpty.substr(0, 0));
        REQUIRE(Passfault::SecureString(secSmall, 1, 0) == sSmall.substr(1, 0));
        REQUIRE(Passfault::SecureString(secMixed, 2, 0) == sMixed.substr(2, 0));
        REQUIRE(Passfault::SecureString(secLarge, 3, 0) == sLarge.substr(3, 0));
//        REQUIRE(Passfault::SecureString(secUtf8, 0, 0) == sUtf8.substr(0, 0));

        // Single range tests
        REQUIRE(Passfault::SecureString(secEmpty, 0, 1) == sEmpty.substr(0, 1));
        REQUIRE(Passfault::SecureString(secSmall, 1, 1) == sSmall.substr(1, 1));
        REQUIRE(Passfault::SecureString(secMixed, 2, 1) == sMixed.substr(2, 1));
        REQUIRE(Passfault::SecureString(secLarge, 3, 1) == sLarge.substr(3, 1));
//        REQUIRE(Passfault::SecureString(secUtf8, 0, 1) == sUtf8.substr(0, 1));

        // Complete copy tests
        REQUIRE(Passfault::SecureString(secEmpty, 0, secEmpty.length()) == sEmpty.substr(0, sEmpty.length()));
        REQUIRE(Passfault::SecureString(secSmall, 0, secSmall.length()) == sSmall.substr(0, sSmall.length()));
        REQUIRE(Passfault::SecureString(secMixed, 0, secMixed.length()) == sMixed.substr(0, sMixed.length()));
        REQUIRE(Passfault::SecureString(secLarge, 0, secLarge.length()) == sLarge.substr(0, sLarge.length()));
//        REQUIRE(Passfault::SecureString(secUtf8, 0, secLarge.length()) == sUtf8.substr(0, sUtf8.length()));

        // Prefix tests
        REQUIRE(Passfault::SecureString(secSmall, 0, 1) == sSmall.substr(0, 1));
        REQUIRE(Passfault::SecureString(secMixed, 0, 3) == sMixed.substr(0, 3));
        REQUIRE(Passfault::SecureString(secLarge, 0, 5) == sLarge.substr(0, 5));
//        REQUIRE(Passfault::SecureString(secUtf8, 0, 3) == sUtf8.substr(0, 3));

        // Suffix tests
        auto a = Passfault::SecureString(secSmall, secSmall.length()-1, 1);
        auto b = sSmall.substr(secSmall.length()-1, 1);
        CHECK(Passfault::SecureString(secSmall, secSmall.length()-1, 1) == sSmall.substr(secSmall.length()-1, 1));
        CHECK(Passfault::SecureString(secMixed, secMixed.length()-4, 4) == sMixed.substr(secMixed.length()-4, 4));
        CHECK(Passfault::SecureString(secLarge, secLarge.length()-5, 5) == sLarge.substr(secLarge.length()-5, 5));
//        REQUIRE(Passfault::SecureString(secUtf8, secUtf8.length()-3, 3) == sUtf8.substr(secUtf8.length()-3, 3));

        // Middle tests
        REQUIRE(Passfault::SecureString(secSmall, 1, 1) == sSmall.substr(1, 1));
        REQUIRE(Passfault::SecureString(secMixed, 2, 6) == sMixed.substr(2, 6));
        REQUIRE(Passfault::SecureString(secLarge, 3, 15) == sLarge.substr(3, 15));
//        REQUIRE(Passfault::SecureString(secUtf8, 0, 1) == sUtf8.substr(0, 1));
    }

    SECTION("Index Operator") {
        // First
        REQUIRE(secSmall[0] == small[0]);
        REQUIRE(secMixed[0] == mixed[0]);
        REQUIRE(secLarge[0] == large[0]);
//        REQUIRE(secUtf8[0] == utf8[0]);

        // Last
        REQUIRE(secSmall[secSmall.length()-1] == small[secSmall.length()-1]);
        REQUIRE(secMixed[secMixed.length()-1] == mixed[secMixed.length()-1]);
        REQUIRE(secLarge[secLarge.length()-1] == large[secLarge.length()-1]);
//        REQUIRE(secUtf8[secUtf8.length()-1] == utf8[secUtf8.length()-1]);

        // Middle
        REQUIRE(secSmall[1] == small[1]);
        REQUIRE(secMixed[5] == mixed[5]);
        REQUIRE(secLarge[15] == large[15]);
//        REQUIRE(secUtf8[2] == utf8[2]);

        // Null terminator
        REQUIRE(secEmpty[secEmpty.length()] == empty[secEmpty.length()]);
        REQUIRE(secSmall[secSmall.length()] == small[secSmall.length()]);
        REQUIRE(secMixed[secMixed.length()] == mixed[secMixed.length()]);
        REQUIRE(secLarge[secLarge.length()] == large[secLarge.length()]);
//        REQUIRE(secUtf8[secUtf8.length()] == utf8[secUtf8.length()]);
    }

    SECTION("Length") {
        REQUIRE(secEmpty.length() == sEmpty.length());
        REQUIRE(secSmall.length() == sSmall.length());
        REQUIRE(secMixed.length() == sMixed.length());
        REQUIRE(secLarge.length() == sLarge.length());
//        REQUIRE(secUtf8.length() == sUtf8.length());
    }

    SECTION("Substring") {
        // Empty range tests
        REQUIRE(secEmpty.substr(0, 0) == sEmpty.substr(0, 0));
        REQUIRE(secSmall.substr(1, 0) == sSmall.substr(1, 0));
        REQUIRE(secMixed.substr(2, 0) == sMixed.substr(2, 0));
        REQUIRE(secLarge.substr(3, 0) == sLarge.substr(3, 0));
//        REQUIRE(secUtf8.substr(0, 0) == sUtf8.substr(0, 0));

        // Single range tests
        REQUIRE(secEmpty.substr(0, 1) == sEmpty.substr(0, 1));
        REQUIRE(secSmall.substr(1, 1) == sSmall.substr(1, 1));
        REQUIRE(secMixed.substr(2, 1) == sMixed.substr(2, 1));
        REQUIRE(secLarge.substr(3, 1) == sLarge.substr(3, 1));
//        REQUIRE(secUtf8.substr(0, 1) == sUtf8.substr(0, 1));

        // Complete copy tests
        REQUIRE(secEmpty.substr(0, secEmpty.length()) == sEmpty.substr(0, secEmpty.length()));
        REQUIRE(secSmall.substr(0, secSmall.length()) == sSmall.substr(0, secSmall.length()));
        REQUIRE(secMixed.substr(0, secMixed.length()) == sMixed.substr(0, secMixed.length()));
        REQUIRE(secLarge.substr(0, secLarge.length()) == sLarge.substr(0, secLarge.length()));
//        REQUIRE(secUtf8.substr(0, secUtf8.length()) == sUtf8.substr(0, secUtf8.length()));

        // Prefix tests
        REQUIRE(secSmall.substr(0, 1) == sSmall.substr(0, 1));
        REQUIRE(secMixed.substr(0, 1) == sMixed.substr(0, 1));
        REQUIRE(secLarge.substr(0, 1) == sLarge.substr(0, 1));
//        REQUIRE(secUtf8.substr(0, 3) == sUtf8.substr(0, 3));

        // Suffix tests
        REQUIRE(secSmall.substr(secSmall.length()-1, 1) == sSmall.substr(secSmall.length()-1, 1));
        REQUIRE(secMixed.substr(secMixed.length()-4, 4) == sMixed.substr(secMixed.length()-4, 4));
        REQUIRE(secLarge.substr(secLarge.length()-5, 5) == sLarge.substr(secLarge.length()-5, 5));
//        REQUIRE(secUtf8.substr(secUtf8.length()-3, 3) == sUtf8.substr(secUtf8.length()-3, 3));

        // Middle tests
        REQUIRE(secSmall.substr(1, 1) == sSmall.substr(1, 1));
        REQUIRE(secMixed.substr(2, 6) == sMixed.substr(2, 6));
        REQUIRE(secLarge.substr(3, 15) == sLarge.substr(3, 15));
//        REQUIRE(secUtf8.substr(0, 1) == sUtf8.substr(0, 1));
    }

    SECTION("Clear") {
        std::string test1 = ""; // NOLINT
        std::string test2 = "Cat";
        std::string test3 = "1337Password!";

        Passfault::SecureString sTest1(sEmpty);
        Passfault::SecureString sTest2(test2);
        Passfault::SecureString sTest3(test3);

        sTest1.clear();
        sTest2.clear();
        sTest3.clear();

        REQUIRE(sTest1.length() == 0);
        REQUIRE(sTest2.length() == 0);
        REQUIRE(sTest3.length() == 0);
    }

    SECTION("SecureString Equality Operator") {
        Passfault::SecureString sec1(sEmpty);
        Passfault::SecureString sec2(sSmall);
        Passfault::SecureString sec3(sMixed);
        Passfault::SecureString sec4(sLarge);
//        Passfault::SecureString sec5(sUtf8);

        REQUIRE(sec1 == secEmpty);
        REQUIRE(sec2 == secSmall);
        REQUIRE(sec3 == secMixed);
        REQUIRE(sec4 == secLarge);
//        REQUIRE(sec5 == secUtf8);
    }

    SECTION("String Equality Operator") {
        REQUIRE(secEmpty == sEmpty);
        REQUIRE(secSmall == sSmall);
        REQUIRE(secMixed == sMixed);
        REQUIRE(secLarge == sLarge);
//        REQUIRE(secUtf8 == sUtf8);
    }

    SECTION("CString Equality Operator") {
        REQUIRE(secEmpty == empty);
        REQUIRE(secSmall == small);
        REQUIRE(secMixed == mixed);
        REQUIRE(secLarge == large);
//        REQUIRE(secUtf8 == utf8);
    }

    // Normally destructors wouldn't be tested, but here it is important to verify zeroing occurred.
    // NOTE: This indirectly accomplishes testing of the private inline function SecureString::zero()
    SECTION("Destructor") {
        std::string str = "Sacrificial String";

        // Create SecureString on Heap (so delete can be manually triggered)
        auto * sstr = new Passfault::SecureString(str);

        // Manually trigger destructor w/delete
        delete sstr;

        // Verify the underlying memory is zeroed
        REQUIRE((*sstr)[0] != 'S');
        REQUIRE((*sstr)[1] != 'a');
        REQUIRE((*sstr)[11] != ' ');
        REQUIRE((*sstr)[16] == 0);
        REQUIRE((*sstr)[17] == 0);
    }
}
