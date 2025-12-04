/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include "gtest/gtest.h"

#include "Transformer.h"
#include "Engine.h"
#include "Weapon.h"

TEST(Transformertest, testMethods)
{
  Engine eng("v6", 250);
  Weapon weapon("elitki", 55);
  Transformer t("Optimus Prime", 200, 80, 80, eng, &weapon);
  
  ASSERT_TRUE(t.attack());
  ASSERT_TRUE(t.move());
  ASSERT_TRUE(t.transform());
}

TEST(Transformertest, testGetters)
{
  Engine eng("v6", 250);
  Weapon weapon("elitki", 55);
  Transformer t("Optimus Prime", 200, 80, 80, eng, &weapon);
  
  ASSERT_STREQ(t.getName().c_str(), "Optimus Prime");
  ASSERT_EQ(t.getHealth(), 200);
  ASSERT_EQ(t.getPower(), 80);
  ASSERT_EQ(t.getTransformationTime(), 80);
}

TEST(Transformertest, testEngineAndWeaponGetters)
{
  Engine eng("v6", 250);
  Weapon weapon("elitki", 55);
  Transformer t("Optimus Prime", 200, 80, 80, eng, &weapon);
  
  ASSERT_STREQ(t.getEngine().getModel().c_str(), "v6");
  ASSERT_EQ(t.getEngine().getHorsepower(), 250);
  ASSERT_STREQ(t.getWeapon()->getName().c_str(), "elitki");
  ASSERT_EQ(t.getWeapon()->getDamage(), 55);
}

TEST(Transformertest, testSetters)
{
  Engine eng("v6", 250);
  Weapon weapon("elitki", 55);
  Transformer t("Optimus Prime", 200, 80, 80, eng, &weapon);
  
  t.setName("robot");
  t.setHealth(198);
  t.setPower(82);
  t.setTransformationTime(70);
  
  ASSERT_STREQ(t.getName().c_str(), "robot");
  ASSERT_EQ(t.getHealth(), 198);
  ASSERT_EQ(t.getPower(), 82);
  ASSERT_EQ(t.getTransformationTime(), 70);
}

TEST(Transformertest, testEngineAndWeaponSetters)
{
  Engine eng("v6", 250);
  Weapon weapon("elitki", 55);
  Transformer t("Optimus Prime", 200, 80, 80, eng, &weapon);
  
  Engine eng2("I6", 290);
  Weapon blaster("Blaster", 54);
  
  t.setEngine(eng2);
  t.setWeapon(&blaster);
  
  ASSERT_STREQ(t.getEngine().getModel().c_str(), "I6");
  ASSERT_EQ(t.getEngine().getHorsepower(), 290);
  ASSERT_STREQ(t.getWeapon()->getName().c_str(), "Blaster");
  ASSERT_EQ(t.getWeapon()->getDamage(), 54);
}
