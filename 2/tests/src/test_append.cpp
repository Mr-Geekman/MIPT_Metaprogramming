#include "typelist.hpp"
#include "test_append.hpp"

TEST_F(AppendTestCase, AppendEmpty) {
    using EmptyList = TypeListBuilder<>::Result;
    using AppendResult = Append<EmptyList, char>::Result;
    bool result = std::is_same<AppendResult, TypeListBuilder<char>::Result>::value;
    EXPECT_TRUE(result);
};

TEST_F(AppendTestCase, AppendNotEmpty) {
    using InitialList = TypeListBuilder<int>::Result;
    using AppendResult = Append<InitialList, char>::Result;
    bool result = std::is_same<AppendResult, TypeListBuilder<int, char>::Result>::value;
    EXPECT_TRUE(result);
};
