/*
Epifancev Artem
st142163@student.spbu.ru
assignment 3
*/

#include "gtest/gtest.h"
#include "Decepticon.h"
#include "Engine.h"
#include "Weapon.h"

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
