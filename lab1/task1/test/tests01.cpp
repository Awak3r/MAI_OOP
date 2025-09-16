#include <gtest/gtest.h>
#include "../include/growCounter.h"

TEST(test01, BasicTest) {
    ASSERT_EQ(growCounter(100, 10, 910), 10);
}
TEST(test02, BasicTest) {
    ASSERT_EQ(growCounter(0, 0, 0), -1);
}
TEST(test03, BasicTest) {
    ASSERT_EQ(growCounter(-2, -3, 6), -1);
}
TEST(test04, BasicTest) {
    ASSERT_EQ(growCounter(100, 100, 1000), -1);
}
TEST(test05, BasicTest) {
    ASSERT_EQ(growCounter(10, 100, 1000), -1);
}
TEST(test06, BasicTest) {
    ASSERT_EQ(growCounter(2, 1, 1000), 999);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}