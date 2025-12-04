/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include "gtest/gtest.h"
#include "Autobot.h"
#include "Engine.h"
#include "Weapon.h"

TEST(Autobottest, testMethods)
{
  Engine eng("i4", 52);
  Weapon weapon("minigun", 22);
  Autobot t("Optimus Prime", 200, 80, 80, eng, &weapon, "Matiz", true);
  
  ASSERT_TRUE(t.protectCivilian());
}

TEST(Autobottest, testGetters)
{
  Engine eng("i4", 52);
  Weapon weapon("minigun", 22);
  Autobot t("Optimus Prime", 200, 80, 80, eng, &weapon, "Matiz", true);
  
  ASSERT_STREQ(t.getAltMode().c_str(), "Matiz");
  ASSERT_TRUE(t.getHonorCode());
}

TEST(Autobottest, testSetters)
{
  Engine eng("i4", 52);
  Weapon weapon("minigun", 22);
  Autobot t("Optimus Prime", 200, 80, 80, eng, &weapon, "Matiz", true);
  
  t.setAltMode("Lada_2107");
  t.setHonorCode(false);
  
  ASSERT_STREQ(t.getAltMode().c_str(), "Lada_2107");
  ASSERT_FALSE(t.getHonorCode());
}
