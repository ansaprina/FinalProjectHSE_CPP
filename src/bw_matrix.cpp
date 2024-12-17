
#include "bw_matrix.h"
#include <iostream>

BWMatrix::BWMatrix(size_t rows, size_t cols) : Matrix(rows, cols) {}

BWMatrix::BWMatrix(size_t rows, size_t cols, int initVal) : Matrix(rows, cols, initVal) {}

void BWMatrix::print() const {
    std::cout << "Printing BWMatrix of size " << m_rows << "x" << m_cols << " with initial value " << m_initVal << "\n";
}

void BWMatrix::fromOpenCV(const cv::Mat& mat) {
    if (mat.channels() != 1 || mat.depth() != CV_8U)
        return;
    m_rows = mat.rows;
    m_cols = mat.cols;
    m_data.resize(mat.total());
    for (int r = 0; r < m_rows; ++r) {
        for (int c = 0; c < m_cols; ++c) {
            at(r, c) = mat.at<uchar>(r, c);
        }
    }
}

cv::Mat BWMatrix::toOpenCV() const {
    cv::Mat mat(m_rows, m_cols, CV_8UC1);
    for (size_t r = 0; r < m_rows; ++r) {
        for (size_t c = 0; c < m_cols; ++c) {
            mat.at<uchar>(r, c) = at(r, c);
        }
    }
    return mat;
}

bool BWMatrix::readImage(const std::string& path) {
    cv::Mat bwImage = cv::imread(path, cv::IMREAD_GRAYSCALE);
    if (bwImage.empty())
        return false;
    fromOpenCV(bwImage);
    return true;
}

void BWMatrix::draw(const Shape& shape) {
    shape.drawOn(*this);
}

BWMatrix BWMatrix::invert() const {
    BWMatrix inverted(m_rows, m_cols);
    for (size_t r = 0; r < m_rows; ++r) {
        for (size_t c = 0; c < m_cols; ++c) {
            inverted.at(r, c) = 255 - at(r, c);
        }
    }
    return inverted;
}
