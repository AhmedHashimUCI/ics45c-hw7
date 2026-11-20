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


TEST(ArrayTests, FillInteger) {
    Array<int> a{5};
    a.fill(7);

    for (int i = 0; i < a.length(); ++i) {
        EXPECT_EQ(a[i], 7);
    }
}

TEST(ArrayTests, FillString) {
    Array<std::string> a{3};
    a.fill("hello");

    for (int i = 0; i < a.length(); ++i) {
        EXPECT_EQ(a[i], "hello");
    }
}

TEST(ArrayTests, FillWithLambda) {
    Array<int> a{5};

    a.fill_with_fn([](int i) {
        return i * i;
    });

    EXPECT_EQ(a[0], 0);
    EXPECT_EQ(a[1], 1);
    EXPECT_EQ(a[2], 4);
    EXPECT_EQ(a[3], 9);
    EXPECT_EQ(a[4], 16);
}

TEST(ArrayTests, FillWithCapture) {
    Array<int> a{4};
    int multiplier = 3;

    a.fill_with_fn([multiplier](int i) {
        return i * multiplier;
    });

    EXPECT_EQ(a[0], 0);
    EXPECT_EQ(a[1], 3);
    EXPECT_EQ(a[2], 6);
    EXPECT_EQ(a[3], 9);
}

TEST(ArrayTests, OutOfBounds) {
    Array<double> a{3};

    EXPECT_THROW(a[-1], std::string);
    EXPECT_THROW(a[3], std::string);
}

TEST(ArrayTests, DeepCopy) {
    Array<std::string> a{3};
    a.fill("original");

    Array<std::string> b{a};
    b[0] = "changed";

    EXPECT_EQ(a[0], "original");
    EXPECT_EQ(b[0], "changed");
}

