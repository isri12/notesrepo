

Prototype of the square root function
```cpp
double square‑root (const double);
```
Unit test for the square root function
```
#include "gtest/gtest.h"

TEST (SquareRootTest, PositiveNos) { 
    EXPECT_EQ (18.0, square‑root (324.0));
    EXPECT_EQ (25.4, square‑root (645.16));
    EXPECT_EQ (50.3321, square‑root (2533.310224));
}

TEST (SquareRootTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0.0, square‑root (0.0));
    ASSERT_EQ (‑1, square‑root (‑22.0));
}
```
Running the first test
- The ::testing::InitGoogleTest method does what the name suggests—it initializes the framework and must be called before RUN_ALL_TESTS.
- RUN_ALL_TESTS must be called only once in the code because multiple calls to it conflict with some of the advanced features of the framework and, therefore, are not supported.
- Note that RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro.
```
#include "gtest/gtest.h"
TEST(SquareRootTest, PositiveNos) { 
    EXPECT_EQ (18.0, square‑root (324.0));
    EXPECT_EQ (25.4, square‑root (645.16));
    EXPECT_EQ (50.3321, square‑root (2533.310224));
}

TEST (SquareRootTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0.0, square‑root (0.0));
    ASSERT_EQ (‑1, square‑root (‑22.0));
}

int main(int argc, char ∗∗argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
```


## TEST_F 
- is used for defining a test fixture and writing test cases that use that fixture. Here's an example:
```
#include <gtest/gtest.h>

// The fixture for testing.
class MyTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code to run before each test
    }

    void TearDown() override {
        // Code to run after each test
    }
};

// Define test cases using the TEST_F macro
TEST_F(MyTest, TestCase1) {
    // Test case 1 code here
    ASSERT_TRUE(true);
}

TEST_F(MyTest, TestCase2) {
    // Test case 2 code here
    ASSERT_EQ(5, 2 + 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

```cpp
#include <iostream>
#include <string>

class StringManipulator {
public:
    // Constructor that initializes the string
    StringManipulator(const std::string& inputString) : str(inputString) {}

    // Concatenate two strings
    std::string concatenate(const std::string& other) {
        return str + other;
    }

    // Reverse the string
    std::string reverse() {
        std::string reversedStr = str;
        std::reverse(reversedStr.begin(), reversedStr.end());
        return reversedStr;
    }

    // Get the length of the string
    int length() {
        return str.length();
    }

private:
    std::string str;
};

int main() {
    StringManipulator manipulator("Hello, ");
    std::string result = manipulator.concatenate("world!");
    std::cout << "Concatenated: " << result << std::endl;

    std::string reversed = manipulator.reverse();
    std::cout << "Reversed: " << reversed << std::endl;

    int strLength = manipulator.length();
    std::cout << "Length: " << strLength << std::endl;

    return 0;
}
```

```cpp
#include <gtest/gtest.h>
#include "StringManipulator.h"  // Include your StringManipulator class header

// Define a test fixture
class StringManipulatorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code to run before each test
    }

    void TearDown() override {
        // Code to run after each test
    }
};

TEST_F(StringManipulatorTest, ConcatenateTest) {
    StringManipulator manipulator("Hello, ");
    std::string result = manipulator.concatenate("world!");
    EXPECT_EQ(result, "Hello, world!");
}

TEST_F(StringManipulatorTest, ReverseTest) {
    StringManipulator manipulator("abcdef");
    std::string reversed = manipulator.reverse();
    EXPECT_EQ(reversed, "fedcba");
}

TEST_F(StringManipulatorTest, LengthTest) {
    StringManipulator manipulator("Testing123");
    int length = manipulator.length();
    EXPECT_EQ(length, 9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```



Good Articles:
A quick introduction to the Google C++ Testing Framework: https://developer.ibm.com/articles/au-googletestingframework/
