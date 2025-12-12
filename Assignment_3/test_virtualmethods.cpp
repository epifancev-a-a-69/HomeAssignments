/*
Epifancev Artem
st142163@student.spbu.ru
assignment 4
*/

#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>

#include "Transformer.h"
#include "Autobot.h"
#include "Decepticon.h"
#include "Dinobot.h"
#include "Engine.h"
#include "Weapon.h"

using namespace std;

//Calling virtual methods directly

TEST(VirtualMethodsTest, DirectCallAutobot)
{
    Autobot autobot;

    testing::internal::CaptureStdout();
    autobot.vmethod1();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "Autobot. vmethod1\n");

    testing::internal::CaptureStdout();
    autobot.vmethod0();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "Autobot. vmethod0\n");
}

TEST(VirtualMethodsTest, DirectCallDecepticon)
{
    Decepticon decepticon;

    testing::internal::CaptureStdout();
    decepticon.vmethod1();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "Decepticon. vmethod1\n");

    testing::internal::CaptureStdout();
    decepticon.vmethod0();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "Decepticon. vmethod0\n");
}

TEST(VirtualMethodsTest, DirectCallDinobot)
{
    Dinobot dinobot;

    testing::internal::CaptureStdout();
    dinobot.vmethod1();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "Dinobot. vmethod1\n");

    testing::internal::CaptureStdout();
    dinobot.vmethod0();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "Dinobot. vmethod0\n");
}

//Call through a pointer to a base class

TEST(VirtualMethodsTest, PointerCallPolymorphism)
{
    Autobot autobot;
    Decepticon decepticon;
    Dinobot dinobot;

    Transformer* t1 = &autobot;
    Transformer* t2 = &decepticon;
    Transformer* t3 = &dinobot;

    testing::internal::CaptureStdout();
    t1->vmethod1();
    string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "Autobot. vmethod1\n");

    testing::internal::CaptureStdout();
    t2->vmethod1();
    string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "Decepticon. vmethod1\n");

    testing::internal::CaptureStdout();
    t3->vmethod1();
    string output3 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output3, "Dinobot. vmethod1\n");

    testing::internal::CaptureStdout();
    t1->vmethod0();
    string output4 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output4, "Autobot. vmethod0\n");

    testing::internal::CaptureStdout();
    t2->vmethod0();
    string output5 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output5, "Decepticon. vmethod0\n");

    testing::internal::CaptureStdout();
    t3->vmethod0();
    string output6 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output6, "Dinobot. vmethod0\n");
}

//Vector of 9 objects

TEST(VirtualMethodsTest, VectorOfPointersPolymorphism)
{

    vector<unique_ptr<Transformer>> transformers;

    transformers.push_back(make_unique<Autobot>("1"));
    transformers.push_back(make_unique<Autobot>("2"));
    transformers.push_back(make_unique<Autobot>("3"));

    transformers.push_back(make_unique<Decepticon>("4"));
    transformers.push_back(make_unique<Decepticon>("5"));
    transformers.push_back(make_unique<Decepticon>("6"));

    transformers.push_back(make_unique<Dinobot>("7"));
    transformers.push_back(make_unique<Dinobot>("8"));
    transformers.push_back(make_unique<Dinobot>("9"));

    int autobotCount1 = 0, decepticonCount1 = 0, dinobotCount1 = 0;

    for (const auto& t : transformers)
    {
        testing::internal::CaptureStdout();
        t->vmethod1();
        string output = testing::internal::GetCapturedStdout();

        if (output.find("Autobot. vmethod1") != string::npos)
        {
            autobotCount1++;
            EXPECT_EQ(output, "Autobot. vmethod1\n");
        }
        else if (output.find("Decepticon. vmethod1") != string::npos)
        {
            decepticonCount1++;
            EXPECT_EQ(output, "Decepticon. vmethod1\n");
        }
        else if (output.find("Dinobot. vmethod1") != string::npos)
        {
            dinobotCount1++;
            EXPECT_EQ(output, "Dinobot. vmethod1\n");
        }
    }

    EXPECT_EQ(autobotCount1, 3);
    EXPECT_EQ(decepticonCount1, 3);
    EXPECT_EQ(dinobotCount1, 3);

    int autobotCount0 = 0, decepticonCount0 = 0, dinobotCount0 = 0;

    for (const auto& t : transformers)
    {
        testing::internal::CaptureStdout();
        t->vmethod0();
        string output = testing::internal::GetCapturedStdout();

        if (output.find("Autobot. vmethod0") != string::npos)
        {
            autobotCount0++;
            EXPECT_EQ(output, "Autobot. vmethod0\n");
        }
        else if (output.find("Decepticon. vmethod0") != string::npos)
        {
            decepticonCount0++;
            EXPECT_EQ(output, "Decepticon. vmethod0\n");
        }
        else if (output.find("Dinobot. vmethod0") != string::npos)
        {
            dinobotCount0++;
            EXPECT_EQ(output, "Dinobot. vmethod0\n");
        }
    }

    EXPECT_EQ(autobotCount0, 3);
    EXPECT_EQ(decepticonCount0, 3);
    EXPECT_EQ(dinobotCount0, 3);
}

