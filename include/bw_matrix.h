#ifndef BW_MATRIX_H
#define BW_MATRIX_H

#include "matrix.h"

class BWMatrix : public Matrix {
public:
    BWMatrix(size_t rows, size_t cols);
    BWMatrix(size_t rows, size_t cols, int initVal);
    BWMatrix invert() const;
    void print() const override;
    void fromOpenCV(const cv::Mat& mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string& path) override;
    void draw(const Shape& shape) override;
};

#endif // BW_MATRIX_H