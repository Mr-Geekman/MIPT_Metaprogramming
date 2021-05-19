#include "longevity.hpp"
#include "test_longevity.hpp"
#include <vector>


class Container {
public:
    Container(int value, std::vector<int>* vector_ptr) : value(value), vector_ptr(vector_ptr) {}
    ~Container() {
        vector_ptr->push_back(value);
    }
private:
    int value;
    std::vector<int>* vector_ptr;
};

class Checker {
public:
    Checker(std::vector<int>* actual_history_ptr, std::vector<int>* true_history_ptr) : actual_history_ptr(actual_history_ptr), true_history_ptr(true_history_ptr) {}
    ~Checker() {
        assert((*actual_history_ptr) == (*true_history_ptr));
        actual_history_ptr->clear();
        true_history_ptr->clear();
    }
private:
    std::vector<int>* actual_history_ptr;
    std::vector<int>* true_history_ptr;
};

TEST_F(LongevityTestCase, SimpleTest) {
    std::vector<int>* actual_history = new std::vector<int>();
    std::vector<int>* true_history = new std::vector<int>();
    true_history->push_back(1);
    set_longevity(actual_history, 3);
    set_longevity(true_history, 3);

    Container* object = new Container(1, actual_history);
    set_longevity(object, 1);

    Checker* checker = new Checker(actual_history, true_history);
    set_longevity(checker, 2);
};

TEST_F(LongevityTestCase, MultiTest) {
    std::vector<int>* actual_history = new std::vector<int>();
    std::vector<int>* true_history = new std::vector<int>();
    true_history->push_back(1);
    true_history->push_back(2);
    true_history->push_back(3);
    set_longevity(actual_history, 5);
    set_longevity(true_history, 5);

    Container* object_1 = new Container(1, actual_history);
    Container* object_2 = new Container(2, actual_history);
    Container* object_3 = new Container(3, actual_history);
    set_longevity(object_1, 1);
    set_longevity(object_2, 2);
    set_longevity(object_3, 3);

    Checker* checker = new Checker(actual_history, true_history);
    set_longevity(checker, 4);
};
