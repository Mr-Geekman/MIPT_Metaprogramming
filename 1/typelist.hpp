#ifndef INC_1_TYPELIST_CPP
#define INC_1_TYPELIST_CPP

// Определение списка типов
class NullType{};

template<typename T=NullType, typename ... U>
struct TypeList {
    using Head = T;
    using Tail = TypeList<U ...>;
};

template<typename T>
struct TypeList<T> {
    using Head = T;
    using Tail = NullType;
};

// Индексирование списка типов
template<class TList, unsigned int i>
struct TypeAt {
    using Result = typename TypeAt<typename TList::Tail, i-1>::Result;
};

template<class TList>
struct TypeAt<TList, 0u> {
    using Result = typename TList::Head;
};

// Поиск индекса первого вхождения
template<class TList, class T>
struct IndexOf {
private:
    enum {temp = IndexOf<typename TList::Tail, T>::value};
public:
    enum {value = (temp == -1) ? -1 : temp + 1};
};

template<class T>
struct IndexOf<NullType, T> {
    enum {value = -1};
};

template<class T, class Tail>
struct IndexOf<TypeList<T, Tail>, T> {
    enum {value = 0};
};

// Удаление первого вхождения по значению
template<class TList, class T>
struct Erase {
    using Result = TypeList<typename TList::Head, typename Erase<typename TList::Tail, T>::Result>;
};

template<class T>
struct Erase<NullType, T> {
    using Result = NullType;
};

template<class T, class Tail>
struct Erase<TypeList<T, Tail>, T> {
    using Result = Tail;
};

#endif //INC_1_TYPELIST_CPP
