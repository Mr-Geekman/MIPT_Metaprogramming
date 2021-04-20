#ifndef TYPELIST_HPP
#define TYPELIST_HPP

// Определение списка типов
class NullType{};

template <typename T, typename U>
struct TypeList {
    using Head = T;
    using Tail = U;
};

// Создание списка типов
template <typename... Ts>
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

// Добавление элемента в конец списка
template <class TList, class T>
struct Append;

template <>
struct Append<NullType, NullType> {
    using Result = NullType;
};

template <class T>
struct Append<NullType, T> {
    using Result = TypeList<T, NullType>;
};

template <class Head, class Tail>
struct Append<NullType, TypeList<Head, Tail>> {
    using Result = TypeList<Head, Tail>;
};

template <class Head, class Tail, class T>
struct Append<TypeList<Head, Tail>, T> {
    using Result = TypeList<Head, typename Append<Tail, T>::Result>;
};

// Обращение списка типов
template <class TList>
struct Reverse;

template <>
struct Reverse<NullType> {
    using Result = NullType;
};

template <class T, class Tail>
struct Reverse<TypeList<T, Tail>> {
    using Result = typename Append<typename Reverse<Tail>::Result, T>::Result;
};


#endif //TYPELIST_HPP