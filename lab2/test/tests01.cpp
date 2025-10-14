#include <gtest/gtest.h>
#include "../include/six.h"
#include <sstream>

TEST(test01, DefaultConstructorTest) {
    Six num;
    ASSERT_EQ(num.getSize(), 0);
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "");
}

TEST(test02, SizeConstructorTest) {
    Six num(5, '3');
    ASSERT_EQ(num.getSize(), 5);
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "33333");
}

TEST(test03, InitializerListConstructorTest) {
    Six num({'1', '2', '3'});
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "123");
}

TEST(test04, StringConstructorTest) {
    Six num("5432");
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "2345");
}

TEST(test05, InvalidStringConstructorTest) {
    ASSERT_THROW(Six num("1267"), std::logic_error);
}

TEST(test06, InvalidInitializerListTest) {
    ASSERT_THROW(Six num({'1', '9', '3'}), std::logic_error);
}

TEST(test07, CopyConstructorTest) {
    Six num1("123");
    Six num2(num1);
    ASSERT_TRUE(num1.equals(num2));
    std::ostringstream oss;
    num2.print(oss);
    ASSERT_EQ(oss.str(), "321");
}

TEST(test08, MoveConstructorTest) {
    Six num1("454");
    Six num2(std::move(num1));
    ASSERT_EQ(num2.getSize(), 3);
    ASSERT_EQ(num1.getSize(), 0);
    std::ostringstream oss;
    num2.print(oss);
    ASSERT_EQ(oss.str(), "454");
}

TEST(test09, SimpleAdditionTest) {
    Six num1("12");
    Six num2("23");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "53");
}

TEST(test10, AdditionWithCarryTest) {
    Six num1("55");
    Six num2("11");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "011");
}

TEST(test11, AdditionZeroTest) {
    Six num1("123");
    Six num2("000");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "321");
}

TEST(test12, AdditionDifferentSizesTest) {
    Six num1("12");
    Six num2("123");
    ASSERT_THROW(num1 + num2, std::logic_error);
}

TEST(test13, AdditionMultipleCarryTest) {
    Six num1("555");
    Six num2("555");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "4551");
}

TEST(test14, SimpleSubtractionTest) {
    Six num1("45");
    Six num2("23");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "22");
}

TEST(test15, SubtractionWithBorrowTest) {
    Six num1("120");
    Six num2("015");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "101");
}

TEST(test16, SubtractionResultZeroTest) {
    Six num1("123");
    Six num2("123");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "0");
}

TEST(test17, SubtractionNegativeResultTest) {
    Six num1("12");
    Six num2("45");
    ASSERT_THROW(num1 - num2, std::logic_error);
}

TEST(test18, SubtractionLeadingZerosTest) {
    Six num1("555");
    Six num2("544");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "11");
}

TEST(test19, EqualsTest) {
    Six num1("123");
    Six num2("123");
    ASSERT_TRUE(num1 == num2);
}

TEST(test20, NotEqualsTest) {
    Six num1("123");
    Six num2("124");
    ASSERT_FALSE(num1 == num2);
}

TEST(test21, BolsheTestTrue) {
    Six num1("543");
    Six num2("123");
    ASSERT_TRUE(num1 > num2);
}

TEST(test22, BolsheTestFalse) {
    Six num1("123");
    Six num2("543");
    ASSERT_FALSE(num1 > num2);
}

TEST(test23, MensheTestTrue) {
    Six num1("123");
    Six num2("543");
    ASSERT_TRUE(num1 < num2);
}

TEST(test24, MensheTestFalse) {
    Six num1("543");
    Six num2("123");
    ASSERT_FALSE(num1 < num2);
}

TEST(test25, CompareEqualNumbersTest) {
    Six num1("333");
    Six num2("333");
    ASSERT_FALSE(num1 > num2);
    ASSERT_FALSE(num1 < num2);
    ASSERT_TRUE(num1 == num2);
}

TEST(test26, Plus1Test) {
    Six num("12");
    num.plus1('3');
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "213");
}

TEST(test27, Minus1Test) {
    Six num("123");
    num.minus1();
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "32");
}

TEST(test28, GetSizeTest) {
    Six num("12345");
    ASSERT_EQ(num.getSize(), 5);
}

TEST(test29, SingleDigitAdditionTest) {
    Six num1("5");
    Six num2("5");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "41");
}

TEST(test30, LargeNumberTest) {
    Six num1("555555");
    Six num2("111111");
    Six result = num1 + num2;
    ASSERT_EQ(result.getSize(), 7);
}

TEST(test31, EdgeCaseSubtractionTest) {
    Six num1("100");
    Six num2("001");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "55");
}

TEST(test32, AllZerosTest) {
    Six num1("000");
    Six num2("000");
    ASSERT_TRUE(num1 == num2);
}

TEST(test33, MaxDigitsTest) {
    Six num1("5555");
    Six num2("0001");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "00001");
}

TEST(test34, PrintMethodTest) {
    Six num("12345");
    std::ostringstream oss;
    num.print(oss);
    ASSERT_EQ(oss.str(), "54321");
}

TEST(test35, EmptyNumberTest) {
    Six num1;
    Six num2;
    ASSERT_TRUE(num1 == num2);
}

TEST(test36, OperatorPlusTest) {
    Six num1("23");
    Six num2("12");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "53");
}

TEST(test37, OperatorMinusTest) {
    Six num1("543");
    Six num2("321");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "222");
}

TEST(test38, OperatorEqualTest) {
    Six num1("123");
    Six num2("123");
    ASSERT_TRUE(num1 == num2);
}

TEST(test39, OperatorGreaterTest) {
    Six num1("500");
    Six num2("100");
    ASSERT_TRUE(num1 > num2);
}

TEST(test40, OperatorLessTest) {
    Six num1("100");
    Six num2("500");
    ASSERT_TRUE(num1 < num2);
}

TEST(test41, ChainedOperationsTest) {
    Six a("100");
    Six b("100");
    Six c("100");
    Six result = (a + b) + c;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "003");
}

TEST(test42, ImmutabilityTest) {
    Six a("100");
    Six b("050");
    Six c = a + b;
    std::ostringstream oss1, oss2;
    a.print(oss1);
    c.print(oss2);
    ASSERT_EQ(oss1.str(), "001");
    ASSERT_EQ(oss2.str(), "051");
}

TEST(test43, SubtractionImmutabilityTest) {
    Six a("200");
    Six b("100");
    Six c = a - b;
    std::ostringstream oss1, oss2;
    a.print(oss1);
    c.print(oss2);
    ASSERT_EQ(oss1.str(), "002");
    ASSERT_EQ(oss2.str(), "001");
}

TEST(test44, OperatorOutputTest) {
    Six num("12345");
    std::ostringstream oss;
    oss << num;
    ASSERT_EQ(oss.str(), "54321");
}

TEST(test45, ComplexAdditionTest) {
    Six num1("5555");
    Six num2("0001");
    Six result = num1 + num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "00001");
}

TEST(test46, ZeroSubtractionTest) {
    Six num1("555");
    Six num2("555");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "0");
}

TEST(test47, SingleDigitSubtractionTest) {
    Six num1("5");
    Six num2("3");
    Six result = num1 - num2;
    std::ostringstream oss;
    result.print(oss);
    ASSERT_EQ(oss.str(), "2");
}

TEST(test48, CompareWithDifferentLengthsTest) {
    Six num1("12");
    Six num2("123");
    ASSERT_THROW(num1 > num2, std::logic_error);
}

TEST(test49, EqualsMethodTest) {
    Six num1("555");
    Six num2("555");
    ASSERT_TRUE(num1.equals(num2));
}

TEST(test50, BolsheMethodTest) {
    Six num1("321");
    Six num2("123");
    ASSERT_TRUE(num1.bolshe(num2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}