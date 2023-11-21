#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

struct Matrix {
    
    std::vector<std::vector<float>> mat;
    size_t rows;
    size_t cols;

    inline Matrix(size_t _rows, size_t _cols): rows(_rows), cols(_cols) {
        this->mat.assign(rows, std::vector<float>(cols, 0));
    }

    inline void display() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

inline static Matrix operator+(const Matrix& m1, const Matrix& m2) {
    if(m1.rows != m2.rows || m1.cols != m2.cols){
        throw std::invalid_argument("Invalid matrix size for operation");
    }
    Matrix result(m1.rows, m1.cols);

    for(size_t i = 0; i < m1.rows; i++){
        for(size_t j = 0; j < m1.cols; j++){
            result.mat[i][j] = m1.mat[i][j] + m2.mat[i][j];
        }
    }
    return result;
}

inline static Matrix operator-(const Matrix& m1, const Matrix& m2) {
    if(m1.rows != m2.rows || m1.cols != m2.cols){
        throw std::invalid_argument("Invalid matrix size for operation");
    }
    Matrix result(m1.rows, m1.cols);

    for(size_t i = 0; i < m1.rows; i++){
        for(size_t j = 0; j < m1.cols; j++){
            result.mat[i][j] = m1.mat[i][j] * m2.mat[i][j];
        }
    }
    return result;
}

inline static Matrix operator*(const Matrix& m1, const Matrix& m2) {
    if(m1.cols != m2.rows){
        throw std::invalid_argument("Invalid matrix size for operation");
    }
    Matrix result(m1.rows, m2.cols);

    for (size_t i = 0; i < m1.rows; ++i) {
        for (size_t j = 0; j < m2.cols; ++j) {
            for (size_t k = 0; k < m1.cols; ++k) {
                result.mat[i][j] += m1.mat[i][k] * m2.mat[k][j];
            }
        }
    }
    return result;
}