/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include "gtest/gtest.h"
#include "Autobot.h"
#include "Engine.h"
#include "Weapon.h"

TEST(Autobottest, testConstructorsAndOperators) 
{
  Engine engine0;
  Weapon weapon0;
  
  Autobot t0;
  Autobot t8("8", 10, 10, 10, engine0, &weapon0, "truck", true);
  Autobot t6("6", 10, 10, 10, engine0, &weapon0);
  Autobot t5("5", 8, 8, 8, engine0);
  Autobot t1("1");

  std::stringstream s0, s1, s5, s6, s8;
  s0 << t0;
  s1 << t1;
  s5 << t5;
  s6 << t6;
  s8 << t8;
  
  ASSERT_STREQ(s0.str().c_str(), "Transformer: null, Health: 0, Power: 0, Transformation time: 0, Engine model: null, Engine Horsepower: 0, Alt mode: null, Honor code: 1, Weapon: null");
  ASSERT_STREQ(s1.str().c_str(), "Transformer: 1, Health: 0, Power: 0, Transformation time: 0, Engine model: null, Engine Horsepower: 0, Alt mode: null, Honor code: 1, Weapon: null");
  ASSERT_STREQ(s5.str().c_str(), "Transformer: 5, Health: 8, Power: 8, Transformation time: 8, Engine model: null, Engine Horsepower: 0, Alt mode: null, Honor code: 1, Weapon: null");
  ASSERT_STREQ(s6.str().c_str(), "Transformer: 6, Health: 10, Power: 10, Transformation time: 10, Engine model: null, Engine Horsepower: 0, Alt mode: null, Honor code: 1, Weapon: null, Weapon damage: 0");
  ASSERT_STREQ(s8.str().c_str(), "Transformer: 8, Health: 10, Power: 10, Transformation time: 10, Engine model: null, Engine Horsepower: 0, Alt mode: truck, Honor code: 1, Weapon: null, Weapon damage: 0");
}

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
