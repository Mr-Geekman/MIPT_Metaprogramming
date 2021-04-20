#ifndef HIERARCHY_HPP
#define HIERARCHY_HPP

#include "typelist.hpp"

// определяем распределенную иерархию
template <class TList, template <class> class Unit>
class GenScatterHierarchy;

// задаем рекурсивное определение при помощи TypeList
template <class T1, class T2, template <class> class Unit>
class GenScatterHierarchy<TypeList<T1, T2>, Unit>:
        public GenScatterHierarchy<T1, Unit>,
        public GenScatterHierarchy<T2, Unit> {
public:
    using TList = TypeList<T1, T2>;
    using LeftBase = GenScatterHierarchy<T1, Unit>;
    using RightBase = GenScatterHierarchy<T2, Unit>;
};

// конкретизируем реализацию для атомарных типов
template <class AtomicType, template <class> class Unit>
class GenScatterHierarchy: public Unit<AtomicType> {
public:
    using LeftBase = Unit<AtomicType>;
};

// конкретизируем для пустого типа
template <template <class> class Unit>
class GenScatterHierarchy<NullType, Unit> {};


// определяем линейную иерархию
template <class TList, template <class AtomicType, class base> class Unit, class Root = NullType>
class GenLinearHierarchy;

// задаем рекурсивное определение при помощи TypeList
template <class T1, class T2, template <class, class> class Unit, class Root>
class GenLinearHierarchy<TypeList<T1, T2>, Unit, Root>:
        public Unit<T1, GenLinearHierarchy<T2, Unit, Root>> {};

// конкретизируем для атомарных типов
template <class AtomicType, template <class, class> class Unit, class Root>
class GenLinearHierarchy<TypeList<AtomicType, NullType>, Unit, Root>:
        public Unit<AtomicType, Root> {};


#endif //HIERARCHY_HPP