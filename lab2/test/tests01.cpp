#include <gtest/gtest.h>
#include "../include/six.h"
#include <sstream>

TEST(SixTest, DefaultConstructor) {
    Six num;
    ASSERT_EQ(num.getSize(), 0);
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "");
}

TEST(SixTest, StringConstructor) {
    Six num("5432");
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "2345");
}

TEST(SixTest, InvalidStringConstructor) {
    ASSERT_THROW(Six num("1267"), std::logic_error);
}

TEST(SixTest, CopyConstructor) {
    Six num1("123");
    Six num2(num1);
    ASSERT_TRUE(num1.equals(num2));
    std::ostringstream oss;
    num2.print(oss);
    ASSERT_EQ(oss.str(), "321");
}

TEST(SixTest, SimpleAddition) {
    Six num1("12");
    Six num2("23");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "53");
}

TEST(SixTest, AdditionWithCarry) {
    Six num1("55");
    Six num2("11");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "011");
}

TEST(SixTest, AdditionDifferentSizes) {
    Six num1("12");
    Six num2("123");
    ASSERT_THROW(num1 + num2, std::logic_error);
}

TEST(SixTest, SimpleSubtraction) {
    Six num1("45");
    Six num2("23");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "22");
}

TEST(SixTest, SubtractionWithBorrow) {
    Six num1("120");
    Six num2("015");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "101");
}

TEST(SixTest, SubtractionNegativeResult) {
    Six num1("12");
    Six num2("45");
    ASSERT_THROW(num1 - num2, std::logic_error);
}


TEST(SixTest, Equality) {
    Six num1("123");
    Six num2("123");
    ASSERT_TRUE(num1 == num2);
    ASSERT_TRUE(num1.equals(num2));
}


TEST(SixTest, GreaterThan) {
    Six num1("543");
    Six num2("123");
    ASSERT_TRUE(num1 > num2);
    ASSERT_TRUE(num1.bolshe(num2));
}


TEST(SixTest, LessThan) {
    Six num1("123");
    Six num2("543");
    ASSERT_TRUE(num1 < num2);
    ASSERT_TRUE(num1.menshe(num2));
}


TEST(SixTest, MoveConstructor) {
    Six num1("454");
    Six num2(std::move(num1));
    ASSERT_EQ(num2.getSize(), 3);
    ASSERT_EQ(num1.getSize(), 0);
    std::ostringstream oss;
    num2.print(oss);
    ASSERT_EQ(oss.str(), "454");
}


TEST(SixTest, ChainedOperations) {
    Six a("100");
    Six b("100");
    Six c("100");
    Six result = (a + b) + c;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "003");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}