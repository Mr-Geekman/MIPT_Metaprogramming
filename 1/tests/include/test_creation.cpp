#include "typelist.hpp"

TEST_F(CreationTestCase, SimpleCreation) {
    using CharList = TypeListBuilder<char, signed char, unsigned char>::Result;
    using FirstElem = typename TypeAt<CharList, 0u>::Result;
    using SecondElem = typename TypeAt<CharList, 1u>::Result;
    using ThirdElem = typename TypeAt<CharList, 2u>::Result;
    bool result = (
            std::is_same<FirstElem, char>::value
            && std::is_same<SecondElem, signed char>::value
            && std::is_same<ThirdElem, unsigned char>::value
    );
    EXPECT_TRUE(result);
};
