#include "rgb_matrix.h"
#include <iostream>

RGBMatrix::RGBMatrix(size_t rows, size_t cols) : Matrix(rows, cols, 3) {}

RGBMatrix::RGBMatrix(size_t rows, size_t cols, int initVal) : Matrix(rows, cols, 3, initVal) {}

void RGBMatrix::print() const {
    std::cout << "Printing RGBMatrix of size " << m_rows << "x" << m_cols << " with " << m_channels << " channels and initial value " << m_initVal << "\n";
}

void RGBMatrix::fromOpenCV(const cv::Mat& mat) {
    if (mat.channels() != 3 || mat.depth() != CV_8U)
        return;
    m_rows = mat.rows;
    m_cols = mat.cols;
    m_data.resize(mat.total() * mat.channels());
    for (size_t r = 0; r < m_rows; ++r) {
        for (size_t c = 0; c < m_cols; ++c) {
            auto val = mat.at<cv::Vec3b>(r, c);
            at(r, c, 0) = val[2];
            at(r, c, 1) = val[1];
            at(r, c, 2) = val[0];
        }
    }
}

cv::Mat RGBMatrix::toOpenCV() const {
    cv::Mat mat(m_rows, m_cols, CV_8UC3);
    for (size_t r = 0; r < m_rows; ++r) {
        for (size_t c = 0; c < m_cols; ++c) {
            cv::Vec3b val;
            val[0] = at(r, c, 2);
            val[1] = at(r, c, 1);
            val[2] = at(r, c, 0);
            mat.at<cv::Vec3b>(r, c) = val;
        }
    }
    return mat;
}

bool RGBMatrix::readImage(const std::string& path) {
    cv::Mat rgbImage = cv::imread(path, cv::IMREAD_COLOR);
    if (rgbImage.empty())
        return false;
    fromOpenCV(rgbImage);
    return true;
}

void RGBMatrix::draw(const Shape& shape) {
    shape.drawOn(*this);
}

BWMatrix RGBMatrix::toBW() const {
    BWMatrix res(m_rows, m_cols);
    for (size_t r = 0; r < m_rows; ++r) {
        for (size_t c = 0; c < m_cols; ++c) {
            int gray = 0;
            for (size_t ch = 0; ch < m_channels; ++ch) {
                gray += at(r, c, ch);
            }
            res.at(r, c) = gray / m_channels;
        }
    }
    return res;
}