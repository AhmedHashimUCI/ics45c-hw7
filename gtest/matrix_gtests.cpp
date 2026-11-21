#include <gtest/gtest.h>

#include <string>

#include "matrix.hpp"

using namespace std;

TEST(MatrixTests, RowsAndCols) {
    Matrix<int> mat{3, 2};
    EXPECT_EQ(mat.num_rows(), 3);
    EXPECT_EQ(mat.num_cols(), 2);

    Matrix<double> mat2{5, 1};
    EXPECT_EQ(mat2.num_rows(), 5);
    EXPECT_EQ(mat2.num_cols(), 1);

    Matrix<string> mat3;
    EXPECT_EQ(mat3.num_rows(), 0);
    EXPECT_EQ(mat3.num_cols(), 0);
}


TEST(MatrixTests, DefaultConstructor) {
    Matrix<int> mat;

    EXPECT_EQ(mat.num_rows(), 0);
    EXPECT_EQ(mat.num_cols(), 0);
}

TEST(MatrixTests, ParameterizedConstructor) {
    Matrix<int> mat{3, 4};

    EXPECT_EQ(mat.num_rows(), 3);
    EXPECT_EQ(mat.num_cols(), 4);
}

TEST(MatrixTests, DifferentTypes) {
    Matrix<double> a{2, 5};
    Matrix<char> b{4, 3};

    EXPECT_EQ(a.num_rows(), 2);
    EXPECT_EQ(a.num_cols(), 5);

    EXPECT_EQ(b.num_rows(), 4);
    EXPECT_EQ(b.num_cols(), 3);
}

TEST(MatrixTests, InvalidRow) {
    Matrix<int> mat{3, 4};

    EXPECT_THROW(mat[-1][0], std::string);
    EXPECT_THROW(mat[3][0], std::string);
}

TEST(MatrixTests, InvalidColumn) {
    Matrix<int> mat{3, 4};

    EXPECT_THROW(mat[0][-1], std::string);
    EXPECT_THROW(mat[0][4], std::string);
}


TEST(MatrixTests, Fill) {
    Matrix<int> mat{3, 4};
    mat.fill(7);

    for (int i = 0; i < mat.num_rows(); ++i) {
        for (int j = 0; j < mat.num_cols(); ++j) {
            EXPECT_EQ(mat[i][j], 7);
        }
    }
}

TEST(MatrixTests, FillWithLambda) {
    Matrix<int> mat{3, 4};

    mat.fill_with_fn([](int i, int j) {
        return i * 10 + j;
    });

    EXPECT_EQ(mat[0][0], 0);
    EXPECT_EQ(mat[0][3], 3);
    EXPECT_EQ(mat[1][2], 12);
    EXPECT_EQ(mat[2][3], 23);
}

TEST(MatrixTests, FillWithCapture) {
    Matrix<double> mat{2, 3};
    double multiplier = 2.5;

    mat.fill_with_fn([multiplier](int i, int j) {
        return (i + j) * multiplier;
    });

    EXPECT_DOUBLE_EQ(mat[0][0], 0.0);
    EXPECT_DOUBLE_EQ(mat[0][2], 5.0);
    EXPECT_DOUBLE_EQ(mat[1][2], 7.5);
}

TEST(MatrixTests, FillSingleRow) {
    Matrix<int> mat{1, 4};

    mat.fill_with_fn([](int i, int j) {
        return i * 10 + j;
    });

    EXPECT_EQ(mat[0][0], 0);
    EXPECT_EQ(mat[0][3], 3);
}

TEST(MatrixTests, FillSingleColumn) {
    Matrix<int> mat{4, 1};

    mat.fill_with_fn([](int i, int j) {
        return i * 10 + j;
    });

    EXPECT_EQ(mat[0][0], 0);
    EXPECT_EQ(mat[3][0], 30);
}

