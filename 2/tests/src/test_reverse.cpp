#include "typelist.hpp"
#include "test_reverse.hpp"

TEST_F(ReverseTestCase, ReverseEmpty) {
    using EmptyList = TypeListBuilder<>::Result;
    using ReverseResult = Reverse<EmptyList>::Result;
    bool result = std::is_same<ReverseResult, EmptyList>::value;
    EXPECT_TRUE(result);
};

TEST_F(ReverseTestCase, ReverseNotEmpty) {
    using InitialList = TypeListBuilder<int, char, double>::Result;
    using ReverseResult = Reverse<InitialList>::Result;
    bool result = std::is_same<ReverseResult, TypeListBuilder<double, char, int>::Result>::value;
    EXPECT_TRUE(result);
};
