// matrix.cpp
#include "matrix.h"
#include "shape.h"

Matrix::Matrix(size_t rows, size_t cols) : m_rows(rows), m_cols(cols), m_channels(1), m_initVal(0), m_data(rows * cols, 0) {}

Matrix::Matrix(size_t rows, size_t cols, int initVal) : m_rows(rows), m_cols(cols), m_channels(1), m_initVal(initVal), m_data(rows * cols, initVal) {}

Matrix::Matrix(size_t rows, size_t cols, int channels, int initVal) : m_rows(rows), m_cols(cols), m_channels(channels), m_initVal(initVal), m_data(rows * cols * channels, initVal) {}

Matrix& Matrix::operator=(const Matrix& mat) {
    if (this != &mat) {
        m_rows = mat.m_rows;
        m_cols = mat.m_cols;
        m_channels = mat.m_channels;
        m_data.assign(mat.m_data.begin(), mat.m_data.end());
    }
    return *this;
}

void Matrix::display(bool waitForKey) const {
    cv::imshow("Display image", toOpenCV());
    if (waitForKey) {
        cv::waitKey(0);  // Only wait for a key press if the user chooses 'yes'
    }
}
