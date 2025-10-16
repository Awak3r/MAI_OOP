#include <gtest/gtest.h>
#include "../include/growCounter.h"

TEST(test01, BasicTest) {
    ASSERT_EQ(growCounter(100, 10, 910), 10);
}

TEST(test02, InvalidInputTest) {
    ASSERT_EQ(growCounter(0, 0, 0), 0);
}

TEST(test03, NegativeValuesTest) {
    ASSERT_EQ(growCounter(-2, -3, 6), -1);
}

TEST(test04, EqualSpeedsTest) {
    ASSERT_EQ(growCounter(100, 100, 1000), -1);
}

TEST(test05, DownSpeedGreaterTest) {
    ASSERT_EQ(growCounter(10, 100, 1000), -1);
}

TEST(test06, LargeDifferenceTest) {
    ASSERT_EQ(growCounter(2, 1, 1000), 999);
}

TEST(test07, ExactHeightTest) {
    ASSERT_EQ(growCounter(10, 5, 5), 1);
}

TEST(test08, OneDayGrowthTest) {
    ASSERT_EQ(growCounter(10, 5, 8), 1);
}

TEST(test09, ZeroDesiredHeightTest) {
    ASSERT_EQ(growCounter(10, 5, 0), 0);
}

TEST(test10, ZeroUpSpeedTest) {
    ASSERT_EQ(growCounter(0, 5, 10), -1);
}

TEST(test11, BoundaryConditionTest) {
    ASSERT_EQ(growCounter(10, 9, 11), 2);
}

TEST(test12, NoNightDecreaseTest) {
    ASSERT_EQ(growCounter(10, 0, 25), 3);
}

TEST(test13, MinimumValuesTest) {
    ASSERT_EQ(growCounter(1, 0, 1), 1);
}

TEST(test14, PrecisionTest) {
    ASSERT_EQ(growCounter(3, 1, 10), 5);
}

TEST(test15, EdgeCaseTest) {
    ASSERT_EQ(growCounter(100, 99, 100), 1);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}