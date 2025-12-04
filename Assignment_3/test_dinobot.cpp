/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include "gtest/gtest.h"
#include "Dinobot.h"
#include "Engine.h"
#include "Weapon.h"

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
