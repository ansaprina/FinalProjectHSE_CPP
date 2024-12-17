#ifndef RGB_MATRIX_H
#define RGB_MATRIX_H

#include "matrix.h"
#include "bw_matrix.h"

class RGBMatrix : public Matrix {
public:
    RGBMatrix(size_t rows, size_t cols);
    RGBMatrix(size_t rows, size_t cols, int initVal);
    BWMatrix toBW() const;
    void print() const override;
    void fromOpenCV(const cv::Mat& mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string& path) override;
    void draw(const Shape& shape) override;
};

#endif // RGB_MATRIX_H