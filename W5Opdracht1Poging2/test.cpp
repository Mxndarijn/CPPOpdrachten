#include "pch.h"
#include <gtest/gtest.h>
#include <fstream>

// Rekenkundige functies
int Add(int a, int b) {
    return a + b;
}

int Sub(int a, int b) {
    return a - b;
}

int Divide(int a, int b) {
    return a / b;
}

int Multiply(int a, int b) {
    return a * b;
}

// Testfixture
class MyTest : public ::testing::Test {
protected:
    static void SetUpTestCase() {
        // initialisatiecode hier
    }

    static void TearDownTestCase() {
        // opruimcode hier
    }
};

// Testcases met ASSERT_EQ macro
TEST_F(MyTest, TestAddition) {
    // De feitelijke test
    ASSERT_EQ(Add(2, 2), 4);
}

TEST_F(MyTest, TestSubtraction) {
    // De feitelijke test
    ASSERT_EQ(Sub(4, 2), 2);
}

TEST_F(MyTest, TestDivision) {
    // De feitelijke test
    ASSERT_EQ(Divide(10, 2), 5);
}

TEST_F(MyTest, TestMultiplication) {
    // De feitelijke test
    ASSERT_EQ(Multiply(3, 4), 12);
}

int main(int argc, char** argv) {
    // Initialiseer het Google Test-framework
    ::testing::InitGoogleTest(&argc, argv);

    // Voer alle testcases uit
    return RUN_ALL_TESTS();
}