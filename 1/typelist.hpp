#ifndef TYPELIST_HPP
#define TYPELIST_HPP

// Определение списка типов
class NullType{};

template<typename T, typename U>
struct TypeList {
    using Head = T;
    using Tail = U;
};

// Создание списка типов
template<typename... Ts>
struct TypeListBuilder {
    using Result = NullType;
};

template <typename T, typename... Ts>
struct TypeListBuilder<T, Ts...> {
    using Result = TypeList<T, typename TypeListBuilder<Ts...>::Result>;
};

// Индексирование списка типов
template <class TList, unsigned int i>
struct TypeAt {
    using Result = typename TypeAt<typename TList::Tail, i-1>::Result;
};

template <class Head, class Tail>
struct TypeAt<TypeList<Head, Tail>, 0> {
    using Result = Head;
};

// Удаление элемента из списка типов
template <typename TList, typename T>
struct Erase {
    using Result = TypeList<typename TList::Head, typename Erase<typename TList::Tail, T>::Result>;
};

template <typename T>
struct Erase<NullType, T> {
    using Result = NullType;
};

template <typename T, typename Tail>
struct Erase<TypeList<T, Tail>, T> {
    using Result = Tail;
};


#endif //TYPELIST_HPP