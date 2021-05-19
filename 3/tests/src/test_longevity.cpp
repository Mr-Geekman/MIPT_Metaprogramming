#include "longevity.hpp"
#include "test_longevity.hpp"
#include <vector>


class FirstClass {
public:
    FirstClass(std::vector<int>* vector_ptr) : vector_ptr(vector_ptr) {}
    ~FirstClass() {
        vector_ptr->push_back(1);
    }
private:
    std::vector<int>* vector_ptr;
};

class SecondClass {
public:
    SecondClass(std::vector<int>* vector_ptr) : vector_ptr(vector_ptr) {}
    ~SecondClass() {
        vector_ptr->push_back(2);
    }
private:
    std::vector<int>* vector_ptr;
};

class ThirdClass {
public:
    ThirdClass(std::vector<int>* vector_ptr) : vector_ptr(vector_ptr) {}
    ~ThirdClass() {
        vector_ptr->push_back(3);
    }
private:
    std::vector<int>* vector_ptr;
};

TEST_F(LongevityTestCase, FirstTest) {
    std::vector<int> actual_history;
    std::vector<int> true_history{1};
    FirstClass* object = new FirstClass(&actual_history);
    set_longevity(object, 1);
    EXPECT_EQ(actual_history, true_history);
};