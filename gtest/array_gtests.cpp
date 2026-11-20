#include <gtest/gtest.h>

#include <string>

#include "array.hpp"

using namespace std;

TEST(ArrayTests, Length) {
    Array<int> arr{3};
    EXPECT_EQ(arr.length(), 3);

    Array<string> arr2{10};
    EXPECT_EQ(arr2.length(), 10);

    EXPECT_EQ(Array<double>{}.length(), 0);
}

TEST(ArrayTests, IntegerArray) {
    Array<int> arr{5};

    EXPECT_EQ(arr.length(), 5);
}

TEST(ArrayTests, DoubleArray) {
    Array<double> arr{3};

    EXPECT_EQ(arr.length(), 3);
}

TEST(ArrayTests, CharacterArray) {
    Array<char> arr{4};

    EXPECT_EQ(arr.length(), 4);
}

TEST(ArrayTests, StringArray) {
    Array<std::string> arr{2};

    EXPECT_EQ(arr.length(), 2);
}

TEST(ArrayTests, CopyConstructor) {
    Array<int> a{5};
    Array<int> b{a};

    EXPECT_EQ(b.length(), 5);
}

TEST(ArrayTests, MoveConstructor) {
    Array<double> a{3};
    Array<double> b{std::move(a)};

    EXPECT_EQ(b.length(), 3);
    EXPECT_EQ(a.length(), 0);
}


TEST(ArrayTests, CopyAssignment) {
    Array<int> a{5};
    Array<int> b{2};

    b = a;

    EXPECT_EQ(b.length(), 5);
    EXPECT_EQ(a.length(), 5);
}

TEST(ArrayTests, MoveAssignment) {
    Array<char> a{4};
    Array<char> b{2};

    b = std::move(a);

    EXPECT_EQ(b.length(), 4);
    EXPECT_EQ(a.length(), 0);
}

TEST(ArrayTests, Swap) {
    Array<int> a{3};
    Array<int> b{7};

    swap(a, b);

    EXPECT_EQ(a.length(), 7);
    EXPECT_EQ(b.length(), 3);
}

