#include "typelist.hpp"
#include "test_erase.hpp"

TEST_F(EraseTestCase, EraseEmpty) {
    using EmptyList = TypeListBuilder<>::Result;
    using EraseResult = Erase<EmptyList, char>::Result;
    bool result = std::is_same<EraseResult, EmptyList>::value;
    EXPECT_TRUE(result);
};

TEST_F(EraseTestCase, EraseFirst) {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using CorrectResult = TypeListBuilder<signed char, unsigned char>::Result;
    using EraseResult = Erase<CharList, char>::Result;
    bool result = std::is_same<EraseResult, CorrectResult>::value;
    EXPECT_TRUE(result);
};


TEST_F(EraseTestCase, EraseMiddle) {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using CorrectResult = TypeListBuilder<char, unsigned char>::Result;
    using EraseResult = Erase<CharList, signed char>::Result;
    bool result = std::is_same<EraseResult, CorrectResult>::value;
    EXPECT_TRUE(result);
};

TEST_F(EraseTestCase, EraseLast) {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using CorrectResult = TypeListBuilder<char, signed char>::Result;
    using EraseResult = Erase<CharList, unsigned char>::Result;
    bool result = std::is_same<EraseResult, CorrectResult>::value;
    EXPECT_TRUE(result);
};

TEST_F(EraseTestCase, EraseNoObj) {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using EraseResult = Erase<CharList, int>::Result;
    bool result = std::is_same<EraseResult, CharList>::value;
    EXPECT_TRUE(result);
};

TEST_F(EraseTestCase, EraseTwoObjs) {
    using CharList = TypeListBuilder<char, signed char, char, unsigned char>::Result;
    using CorrectResult = TypeListBuilder<signed char, char, unsigned char>::Result;
    using EraseResult = Erase<CharList, char>::Result;
    bool result = std::is_same<EraseResult, CorrectResult>::value;
    EXPECT_TRUE(result);
};

