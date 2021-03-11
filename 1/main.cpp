#include <iostream>
#include "typelist.hpp"

// Тестирование
struct Test1 {
    using CharList = TypeList<char, signed char, unsigned char>;
    using FirstElem = typename TypeAt<CharList, 0u>::Result;
    using SecondElem = typename TypeAt<CharList, 1u>::Result;
    using ThirdElem = typename TypeAt<CharList, 2u>::Result;
    static const bool result = (
            std::is_same<FirstElem, char>::value
            && std::is_same<SecondElem, signed char>::value
            && std::is_same<ThirdElem, unsigned char>::value
    );
};

struct Test2 {
    using List = TypeList<int, char, float>;
    // Sanity check
    using Elem = typename List::Head;
    static const bool sanity = std::is_same<Elem, int>::value;
    // Test
    enum {int_index = IndexOf<List, int>::value};
    enum {char_index = IndexOf<List, char>::value};
    enum {float_index = IndexOf<List, float>::value};
    static const bool result_1 = (int_index == -1);
    static const bool result_2 = (char_index == 1);
    static const bool result_3 = (float_index == -1);
    static const bool result = result_1 && result_2 && result_3;
};

// добавить тесты на удаление
// удаление в пустом списке
// удаление если объект на превом месте
// удаление если объект где-то в середине
// удаление если объекта нет
// удаление если две копии объекта

void testAll() {
    std::cout << "Test 1: " << Test1::result << std::endl;
    std::cout << "Test 2 Sanity: " << Test2::sanity << std::endl;
    std::cout << "Test 2: " << Test2::result_3 << std::endl;
    // ...
}


int main() {
    testAll();
}
