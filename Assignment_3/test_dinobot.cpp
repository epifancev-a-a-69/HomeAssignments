/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "gtest/gtest.h"
#include "Dinobot.h"
#include "Engine.h"
#include "Weapon.h"

TEST(Dinobottest, testConstructorsAndOperators)
{
    Engine engine0;
    Weapon weapon0;

    Dinobot t0;
    Dinobot t10("10", 10, 10, 10, engine0, &weapon0, "trex", true, 5, true);
    Dinobot t8("8", 10, 10, 10, engine0, &weapon0, "trex", true);
    Dinobot t6("6", 10, 10, 10, engine0, &weapon0);
    Dinobot t5("5", 8, 8, 8, engine0);
    Dinobot t1("1");

    std::stringstream s0, s1, s5, s6, s8, s10;
    s0 << t0;
    s1 << t1;
    s5 << t5;
    s6 << t6;
    s8 << t8;
    s10 << t10;

    ASSERT_STREQ(s0.str().c_str(), "Transformer: null, Health: 0, Power: 0, Transformation time: 0, Engine model: null, Engine Horsepower: 0, Alt mode: null, Honor code: 1, Ferocity: 0, Pack hunter: 1, Weapon: null");
    ASSERT_STREQ(s1.str().c_str(), "Transformer: 1, Health: 0, Power: 0, Transformation time: 0, Engine model: null, Engine Horsepower: 0, Alt mode: null, Honor code: 1, Ferocity: 0, Pack hunter: 1, Weapon: null");
    ASSERT_STREQ(s5.str().c_str(), "Transformer: 5, Health: 8, Power: 8, Transformation time: 8, Engine model: null, Engine Horsepower: 0, Alt mode: null, Honor code: 1, Ferocity: 0, Pack hunter: 1, Weapon: null");
    ASSERT_STREQ(s6.str().c_str(), "Transformer: 6, Health: 10, Power: 10, Transformation time: 10, Engine model: null, Engine Horsepower: 0, Alt mode: null, Honor code: 1, Ferocity: 0, Pack hunter: 1, Weapon: null, Weapon damage: 0");
    ASSERT_STREQ(s8.str().c_str(), "Transformer: 8, Health: 10, Power: 10, Transformation time: 10, Engine model: null, Engine Horsepower: 0, Alt mode: trex, Honor code: 1, Ferocity: 0, Pack hunter: 1, Weapon: null, Weapon damage: 0");
    ASSERT_STREQ(s10.str().c_str(), "Transformer: 10, Health: 10, Power: 10, Transformation time: 10, Engine model: null, Engine Horsepower: 0, Alt mode: trex, Honor code: 1, Ferocity: 5, Pack hunter: 1, Weapon: null, Weapon damage: 0");
}

TEST(Dinobottest, testMethods)
{
    Engine eng("i4", 52);
    Weapon weapon("minigun", 22);
    Dinobot t("Skuf", 200, 80, 80, eng, &weapon, "Pivozavr", true, 10, true);

    ASSERT_TRUE(t.primalRage());
}

TEST(Dinobottest, testGetters)
{
    Engine eng("i4", 52);
    Weapon weapon("minigun", 22);
    Dinobot t("Skuf", 200, 80, 80, eng, &weapon, "Pivozavr", true, 10, true);

    ASSERT_EQ(t.getFerocityLevel(), 10);
    ASSERT_TRUE(t.getIsPackHunter());
}

TEST(Dinobottest, testSetters)
{
    Engine eng("i4", 52);
    Weapon weapon("minigun", 22);
    Dinobot t("Skuf", 200, 80, 80, eng, &weapon, "Pivazavr", true, 10, true);

    t.setFerocityLevel(11);
    t.setIsPackHunter(false);

    ASSERT_EQ(t.getFerocityLevel(), 11);
    ASSERT_FALSE(t.getIsPackHunter());
}
