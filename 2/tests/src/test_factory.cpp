#include "typelist.hpp"
#include "abstract_factory.hpp"
#include "test_factory.hpp"
#include <string>

class Archer {
public:
    virtual std::string name() = 0;
};

class RomanianArcher: public Archer {
public:
    virtual std::string name() {
        return "RomanianArcher";
    }
};

class CarthaginianArcher: public Archer {
public:
    virtual std::string name() {
        return "CarthaginianArcher";
    }
};

class Infantry {
public:
    virtual std::string name() = 0;
};

class RomanianInfantry: public Infantry {
public:
    virtual std::string name() {
        return "RomanianInfantry";
    }
};

class CarthaginianInfantry: public Infantry {
public:
    virtual std::string name() {
        return "CarthaginianInfantry";
    }
};

class Cavalry {
public:
    virtual std::string name() = 0;
};

class RomanianCavalry: public Cavalry {
public:
    virtual std::string name() {
        return "RomanianCavalry";
    }
};

class CarthaginianCavalry: public Cavalry {
public:
    virtual std::string name() {
        return "CarthaginianCavalry";
    }
};

TEST_F(FactoryTestCase, FactoryTest) {
    using TList = TypeListBuilder<Archer, Infantry, Cavalry>::Result;
    using AbstractArmyFactory = IFactory<TList>;
    using RomanianArmyFactory = CFactory<AbstractArmyFactory, TypeListBuilder<RomanianArcher, RomanianInfantry, RomanianCavalry>::Result>;
    using CarthaginianArmyFactory = CFactory<AbstractArmyFactory, TypeListBuilder<CarthaginianArcher, CarthaginianInfantry, CarthaginianCavalry>::Result>;
    AbstractArmyFactory* romanianArmyFactory = new RomanianArmyFactory();
    AbstractArmyFactory* carthaginianArmyFactory = new CarthaginianArmyFactory();

    std::string romanianArcher = romanianArmyFactory->create<Archer>()->name();
    std::string romanianInfantry = romanianArmyFactory->create<Infantry>()->name();
    std::string romanianCavalry = romanianArmyFactory->create<Cavalry>()->name();
    std::string carthaginianArcher = carthaginianArmyFactory->create<Archer>()->name();
    std::string carthaginianInfantry = carthaginianArmyFactory->create<Infantry>()->name();
    std::string carthaginianCavalry = carthaginianArmyFactory->create<Cavalry>()->name();

    EXPECT_EQ(romanianArcher, "RomanianArcher");
    EXPECT_EQ(romanianInfantry, "RomanianInfantry");
    EXPECT_EQ(romanianCavalry, "RomanianCavalry");

    EXPECT_EQ(carthaginianArcher, "CarthaginianArcher");
    EXPECT_EQ(carthaginianInfantry, "CarthaginianInfantry");
    EXPECT_EQ(carthaginianCavalry, "CarthaginianCavalry");
};