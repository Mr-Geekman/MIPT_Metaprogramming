#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "typelist.hpp"
#include "types.hpp"
#include "hierarchy.hpp"

// элемент абстрактной фабрики
template<class T>
class IFactoryUnit {
public:
    virtual T* create(Type2Type<T>) = 0;
    virtual ~IFactoryUnit() {}
};

// абстрактная фабрика
template<class TList, template<class> class Unit = IFactoryUnit>
class IFactory: public GenScatterHierarchy<TList, Unit> {
public:
    using InnerList = TList;
    template<class T> T* create() {
        Unit<T>& unit = *this;
        return unit.create(Type2Type<T>());
    }
};

// элемент реализации абстрактной фабрики
template<class ConcreteProduct, class Base>
class StandardCreationPolicy: public Base {
public:
    using BaseInnerList = typename Base::InnerList;
    using InnerList = typename BaseInnerList::Tail;
    using Product = typename BaseInnerList::Head;
    ConcreteProduct* create(Type2Type<Product>) {
        return new ConcreteProduct;
    }
};

// реализация конкретной фабрики
template<
        class AbstractFactory,
        class TList,
        template<class, class> class CreationPolicy = StandardCreationPolicy
        >
class CFactory: public GenLinearHierarchy<typename Reverse<TList>::Result, CreationPolicy, AbstractFactory> {};


#endif //FACTORY_HPP