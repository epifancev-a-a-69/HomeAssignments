/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "gtest/gtest.h"
#include "Decepticon.h"
#include "Engine.h"
#include "Weapon.h"

TEST(Decepticontest, testConstructorsAndOperators)
{
    Engine engine0;
    Weapon weapon0;

    Decepticon t0;
    Decepticon t8("8", 10, 10, 10, engine0, &weapon0, "stealth", false);
    Decepticon t6("6", 10, 10, 10, engine0, &weapon0);
    Decepticon t5("5", 8, 8, 8, engine0);
    Decepticon t1("1");

    std::stringstream s0, s1, s5, s6, s8;
    s0 << t0;
    s1 << t1;
    s5 << t5;
    s6 << t6;
    s8 << t8;

    ASSERT_STREQ(s0.str().c_str(), "Transformer: null, Health: 0, Power: 0, Transformation time: 0, Engine model: null, Engine Horsepower: 0, Special ability: null, Ruthless: 1, Weapon: null");
    ASSERT_STREQ(s1.str().c_str(), "Transformer: 1, Health: 0, Power: 0, Transformation time: 0, Engine model: null, Engine Horsepower: 0, Special ability: null, Ruthless: 1, Weapon: null");
    ASSERT_STREQ(s5.str().c_str(), "Transformer: 5, Health: 8, Power: 8, Transformation time: 8, Engine model: null, Engine Horsepower: 0, Special ability: null, Ruthless: 1, Weapon: null");
    ASSERT_STREQ(s6.str().c_str(), "Transformer: 6, Health: 10, Power: 10, Transformation time: 10, Engine model: null, Engine Horsepower: 0, Special ability: null, Ruthless: 1, Weapon: null, Weapon damage: 0");
    ASSERT_STREQ(s8.str().c_str(), "Transformer: 8, Health: 10, Power: 10, Transformation time: 10, Engine model: null, Engine Horsepower: 0, Special ability: stealth, Ruthless: 0, Weapon: null, Weapon damage: 0");
}

TEST(Decepticontest, testMethods)
{
    Engine eng("i4", 69);
    Weapon weapon("eagle", 42);
    Decepticon t("Megatron", 200, 80, 80, eng, &weapon, "BenchPress", false);

    ASSERT_TRUE(t.sabotage());
}

TEST(Decepticontest, testGetters)
{
    Engine eng("i4", 69);
    Weapon weapon("eagle", 42);
    Decepticon t("Megatron", 200, 80, 80, eng, &weapon, "BenchPress", false);

    ASSERT_STREQ(t.getSpecialAbility().c_str(), "BenchPress");
    ASSERT_FALSE(t.getIsRuthless());
}

TEST(Decepticontest, testSetters)
{
    Engine eng("i4", 69);
    Weapon weapon("eagle", 42);
    Decepticon t("Megatron", 200, 80, 80, eng, &weapon, "BenchPress", false);

    t.setSpecialAbility("DeadLift");
    t.setIsRuthless(true);

    ASSERT_STREQ(t.getSpecialAbility().c_str(), "DeadLift");
    ASSERT_TRUE(t.getIsRuthless());
}
