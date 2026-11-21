// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the Array of int in int_array.hpp. It is graded: the
// autograder runs it against a correct Array and against several with one bug each. A test is
// worth something only when it passes on the correct Array and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for the constructors, the copy and move
// operations, operator[] in and out of range, fill, and length.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "int_array.hpp"
#include <string>
#include <utility>

TEST(IntArrayTests, DefaultArrayIsEmpty) {
    const Array a;
    EXPECT_EQ(a.length(), 0);
}

TEST(IntArrayTests, SizedArrayReportsItsLength) {
    const Array a{5};
    EXPECT_EQ(a.length(), 5);
}




TEST(IntArrayTests, DefaultConstructor) {
    Array a;

    EXPECT_EQ(a.length(), 0);
    EXPECT_THROW(a[0], std::string);
}

TEST(IntArrayTests, FillAllElements) {
    Array a{5};
    a.fill(42);

    EXPECT_EQ(a.length(), 5);

    for (int i = 0; i < a.length(); ++i) {
        EXPECT_EQ(a[i], 42);
    }
}

TEST(IntArrayTests, FillTwice) {
    Array a{4};

    a.fill(10);
    a.fill(25);

    for (int i = 0; i < a.length(); ++i) {
        EXPECT_EQ(a[i], 25);
    }
}

TEST(StudentArray, FirstAndLastIndex) {
    Array a{5};
    a.fill(0);

    a[0] = 100;
    a[4] = 200;

    EXPECT_EQ(a[0], 100);
    EXPECT_EQ(a[4], 200);
    EXPECT_EQ(a[1], 0);
}

TEST(IntArrayTests, NegativeIndex) {
    Array a{3};

    EXPECT_THROW(a[-1], std::string);
    EXPECT_THROW(a[-10], std::string);
}

TEST(IntArrayTests, IndexAtLength) {
    Array a{3};

    EXPECT_THROW(a[3], std::string);
    EXPECT_THROW(a[100], std::string);
}

TEST(IntArrayTests, ExceptionMessage) {
    Array a{3};

    try {
        a[10] = 5;
        FAIL() << "Expected an exception";
    }
    catch (const std::string& message) {
        EXPECT_NE(
            message.find("Exception operator[](10) Out Of Range"),
            std::string::npos
        );
    }
}

TEST(IntArrayTests, ConstIndexing) {
    Array a{3};
    a.fill(7);

    const Array& b = a;

    EXPECT_EQ(b[0], 7);
    EXPECT_EQ(b[2], 7);

    EXPECT_THROW(b[-1], std::string);
    EXPECT_THROW(b[3], std::string);
}

TEST(IntArrayTests, SingleElement) {
    Array a{1};
    a.fill(99);

    EXPECT_EQ(a.length(), 1);
    EXPECT_EQ(a[0], 99);

    EXPECT_THROW(a[-1], std::string);
    EXPECT_THROW(a[1], std::string);
}

TEST(IntArrayTests, DeepCopyConstructor) {
    Array a{3};
    a.fill(10);

    Array b{a};

    b[0] = 99;

    EXPECT_EQ(a[0], 10);
    EXPECT_EQ(b[0], 99);
    EXPECT_EQ(b.length(), 3);
}

TEST(IntArrayTests, CopyAssignment) {
    Array a{3};
    a.fill(10);

    Array b{5};
    b.fill(20);

    b = a;

    EXPECT_EQ(b.length(), 3);

    for (int i = 0; i < b.length(); ++i) {
        EXPECT_EQ(b[i], 10);
    }

    b[0] = 99;
    EXPECT_EQ(a[0], 10);
}

TEST(StudentArray, SelfCopyAssignment) {
    Array a{3};
    a.fill(42);

    a = a;

    EXPECT_EQ(a.length(), 3);
    EXPECT_EQ(a[0], 42);
    EXPECT_EQ(a[2], 42);
}

TEST(IntArrayTests, MoveConstructor) {
    Array a{4};
    a.fill(15);

    Array b{std::move(a)};

    EXPECT_EQ(b.length(), 4);
    EXPECT_EQ(a.length(), 0);

    for (int i = 0; i < b.length(); ++i) {
        EXPECT_EQ(b[i], 15);
    }
}

TEST(IntArrayTests, MoveAssignment) {
    Array a{3};
    a.fill(15);

    Array b{5};
    b.fill(30);

    b = std::move(a);

    EXPECT_EQ(b.length(), 3);
    EXPECT_EQ(a.length(), 0);

    for (int i = 0; i < b.length(); ++i) {
        EXPECT_EQ(b[i], 15);
    }
}

TEST(IntArrayTests, Swap) {
    Array a{2};
    Array b{4};

    a.fill(10);
    b.fill(20);

    using std::swap;
    swap(a, b);

    EXPECT_EQ(a.length(), 4);
    EXPECT_EQ(b.length(), 2);

    EXPECT_EQ(a[0], 20);
    EXPECT_EQ(b[0], 10);
}

TEST(IntArrayTests, ExceptionPreservesArray) {
    Array a{3};
    a.fill(7);

    EXPECT_THROW(a[5], std::string);

    EXPECT_EQ(a.length(), 3);
    EXPECT_EQ(a[0], 7);
    EXPECT_EQ(a[2], 7);
}

