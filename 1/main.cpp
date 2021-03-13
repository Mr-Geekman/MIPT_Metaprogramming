#include <iostream>
#include "typelist.hpp"

// Тестирование
bool TestCreation() {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using FirstElem = typename TypeAt<CharList, 0u>::Result;
    using SecondElem = typename TypeAt<CharList, 1u>::Result;
    using ThirdElem = typename TypeAt<CharList, 2u>::Result;
    bool result = (
            std::is_same<FirstElem, char>::value
            && std::is_same<SecondElem, signed char>::value
            && std::is_same<ThirdElem, unsigned char>::value
    );
    return result;
}

bool TestEmpty() {
    using EmptyList = TypeListBuilder<>::Result;
    using EraseResult = Erase<EmptyList, char>::Result;
    bool result = std::is_same<EraseResult, EmptyList>::value;
    return result;
}

bool TestFirst() {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using CorrectResult = TypeListBuilder<signed char, unsigned char>::Result;
    using EraseResult = Erase<CharList, char>::Result;
    bool result = std::is_same<EraseResult, CorrectResult>::value;
    return result;
}

bool TestMiddle() {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using CorrectResult = TypeListBuilder<char, unsigned char>::Result;
    using EraseResult = Erase<CharList, signed char>::Result;
    bool result = std::is_same<EraseResult, CorrectResult>::value;
    return result;
}

bool TestLast() {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using CorrectResult = TypeListBuilder<char, signed char>::Result;
    using EraseResult = Erase<CharList, unsigned char>::Result;
    bool result = std::is_same<EraseResult, CorrectResult>::value;
    return result;
}

bool TestNoObj() {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using EraseResult = Erase<CharList, int>::Result;
    bool result = std::is_same<EraseResult, CharList>::value;
    return result;
}

bool TestTwoObj() {
    using CharList = TypeListBuilder<char, signed char, char, unsigned char>::Result;
    using CorrectResult = TypeListBuilder<signed char, char, unsigned char>::Result;
    using EraseResult = Erase<CharList, char>::Result;
    bool result = std::is_same<EraseResult, CorrectResult>::value;
    return result;
}


void testAll() {
    std::cout << "Test 1: " << TestCreation() << std::endl;
    std::cout << "Test 2: " << TestEmpty() << std::endl;
    std::cout << "Test 3: " << TestFirst() << std::endl;
    std::cout << "Test 4: " << TestMiddle() << std::endl;
    std::cout << "Test 5: " << TestLast() << std::endl;
    std::cout << "Test 6: " << TestNoObj() << std::endl;
    std::cout << "Test 7: " << TestTwoObj() << std::endl;
}


int main() {
    return 0;
}
