

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


Good Articles:
A quick introduction to the Google C++ Testing Framework: https://developer.ibm.com/articles/au-googletestingframework/
