#include <gtest/gtest.h>
#include "../include/six.h"
#include <sstream>

std::string captureOutput(Six& num) {
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf());
    num.printclass();
    std::cout.rdbuf(oldCoutBuf);
    return oss.str();
}

TEST(test01, DefaultConstructorTest) {
    Six num;
    ASSERT_EQ(num.getSize(), 0);
    ASSERT_EQ(captureOutput(num), "[ ]\n");
}

TEST(test02, SizeConstructorTest) {
    Six num(5, '3');
    ASSERT_EQ(num.getSize(), 5);
    ASSERT_EQ(captureOutput(num), "[ 3 3 3 3 3 ]\n");
}

TEST(test03, InitializerListConstructorTest) {
    Six num({'1', '2', '3'});
    ASSERT_EQ(captureOutput(num), "[ 1 2 3 ]\n");
}

TEST(test04, StringConstructorTest) {
    Six num("5432");
    ASSERT_EQ(captureOutput(num), "[ 2 3 4 5 ]\n");
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
    ASSERT_EQ(captureOutput(num2), "[ 3 2 1 ]\n");
}

TEST(test08, MoveConstructorTest) {
    Six num1("454");
    Six num2(std::move(num1));
    ASSERT_EQ(num2.getSize(), 3);
    ASSERT_EQ(num1.getSize(), 0);
    ASSERT_EQ(captureOutput(num2), "[ 4 5 4 ]\n");
}

TEST(test09, SimpleAdditionTest) {
    Six num1("12");
    Six num2("23"); 
    Six result = num1.add(num2);
    ASSERT_EQ(captureOutput(result), "[ 5 3 ]\n");
}

TEST(test10, AdditionWithCarryTest) {
    Six num1("55");
    Six num2("11");
    Six result = num1.add(num2);
    ASSERT_EQ(captureOutput(result), "[ 0 1 1 ]\n");
}

TEST(test11, AdditionZeroTest) {
    Six num1("123");
    Six num2("000");
    Six result = num1.add(num2);
    ASSERT_EQ(captureOutput(result), "[ 3 2 1 ]\n");
}

TEST(test12, AdditionDifferentSizesTest) {
    Six num1("12");
    Six num2("123");
    ASSERT_THROW(num1.add(num2), std::logic_error);
}

TEST(test13, AdditionMultipleCarryTest) {
    Six num1("555");
    Six num2("555");
    Six result = num1.add(num2);
    ASSERT_EQ(captureOutput(result), "[ 4 5 5 1 ]\n");
}

TEST(test14, SimpleSubtractionTest) {
    Six num1("45");
    Six num2("23");
    Six result = num1.remove(num2);
    ASSERT_EQ(captureOutput(result), "[ 2 2 ]\n");
}

TEST(test15, SubtractionWithBorrowTest) {
    Six num1("120");
    Six num2("015");
    Six result = num1.remove(num2);
    ASSERT_EQ(captureOutput(result), "[ 1 0 1 ]\n");
}

TEST(test16, SubtractionResultZeroTest) {
    Six num1("123");
    Six num2("123");
    Six result = num1.remove(num2);
    ASSERT_EQ(captureOutput(result), "[ 0 ]\n");
}

TEST(test17, SubtractionNegativeResultTest) {
    Six num1("12");
    Six num2("45");
    ASSERT_THROW(num1.remove(num2), std::logic_error);
}

TEST(test18, SubtractionLeadingZerosTest) {
    Six num1("555");
    Six num2("544");
    Six result = num1.remove(num2);
    ASSERT_EQ(captureOutput(result), "[ 1 1 ]\n");
}

TEST(test19, EqualsTest) {
    Six num1("123");
    Six num2("123");
    ASSERT_TRUE(num1.equals(num2));
}

TEST(test20, NotEqualsTest) {
    Six num1("123");
    Six num2("124");
    ASSERT_FALSE(num1.equals(num2));
}

TEST(test21, BolsheTestTrue) {
    Six num1("543");
    Six num2("123");
    ASSERT_TRUE(num1.bolshe(num2));
}

TEST(test22, BolsheTestFalse) {
    Six num1("123");
    Six num2("543");
    ASSERT_FALSE(num1.bolshe(num2));
}

TEST(test23, MensheTestTrue) {
    Six num1("123");
    Six num2("543");
    ASSERT_TRUE(num1.menshe(num2));
}

TEST(test24, MensheTestFalse) {
    Six num1("543");
    Six num2("123");
    ASSERT_FALSE(num1.menshe(num2));
}

TEST(test25, CompareEqualNumbersTest) {
    Six num1("333");
    Six num2("333");
    ASSERT_FALSE(num1.bolshe(num2));
    ASSERT_FALSE(num1.menshe(num2));
}

TEST(test26, Plus1Test) {
    Six num("12");
    num.plus1('3');
    ASSERT_EQ(captureOutput(num), "[ 2 1 3 ]\n");
}

TEST(test27, Minus1Test) {
    Six num("123");
    num.minus1();
    ASSERT_EQ(captureOutput(num), "[ 3 2 ]\n");
}

TEST(test28, GetSizeTest) {
    Six num("12345");
    ASSERT_EQ(num.getSize(), 5);
}

TEST(test29, SingleDigitAdditionTest) {
    Six num1("5");
    Six num2("5");
    Six result = num1.add(num2);
    ASSERT_EQ(captureOutput(result), "[ 4 1 ]\n");
}

TEST(test30, LargeNumberTest) {
    Six num1("555555");
    Six num2("111111");
    Six result = num1.add(num2);
    ASSERT_EQ(result.getSize(), 7);
}

TEST(test31, EdgeCaseSubtractionTest) {
    Six num1("100");
    Six num2("001");
    Six result = num1.remove(num2);
    ASSERT_EQ(captureOutput(result), "[ 5 5 ]\n");
}

TEST(test32, AllZerosTest) {
    Six num1("000");
    Six num2("000");
    ASSERT_TRUE(num1.equals(num2));
}

TEST(test33, MaxDigitsTest) {
    Six num1("5555");
    Six num2("0001");
    Six result = num1.add(num2);
    ASSERT_EQ(captureOutput(result), "[ 0 0 0 0 1 ]\n");
}

TEST(test34, PrintClassFormatTest) {
    Six num("12345");
    ASSERT_EQ(captureOutput(num), "[ 5 4 3 2 1 ]\n");
}

TEST(test35, EmptyNumberTest) {
    Six num1;
    Six num2;
    ASSERT_TRUE(num1.equals(num2));
}

TEST(test36, VisualOutputTest) {
    Six num("321");
    std::cout << "Тест вывода: ";
    num.printclass(); 
    ASSERT_EQ(num.getSize(), 3);
}

TEST(test37, ChainOperationsTest) {
    Six num1("23");
    Six num2("12");
    Six result = num1.add(num2);
    std::cout << "Результат сложения 23 + 12: ";
    result.printclass();
    ASSERT_EQ(captureOutput(result), "[ 5 3 ]\n");
}

TEST(test38, SubtractionVisualTest) {
    Six num1("543");
    Six num2("321");
    Six result = num1.remove(num2);
    std::cout << "Результат вычитания 543 - 321: ";
    result.printclass();
    ASSERT_EQ(captureOutput(result), "[ 2 2 2 ]\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}