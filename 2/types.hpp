#ifndef TYPES_HPP
#define TYPES_HPP

// тип для хранения информации о типе, позволяет различать сигнатуры, не создавая никаких объектов типа Type
template <typename T>
struct TypeHolder {
    typedef T Type;
};

#endif //TYPES_HPP