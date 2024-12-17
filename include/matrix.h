#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "shape.h"

class Shape; // Forward declaration to avoid circular dependency

class Matrix {
public:
    Matrix(size_t rows, size_t cols);
    Matrix(size_t rows, size_t cols, int initVal); // New constructor with initialization value
    Matrix(size_t rows, size_t cols, int channels, int initVal); // Constructor for multi-channel matrix
    virtual ~Matrix() = default;

    // Pure virtual function to draw shapes
    virtual void draw(const Shape& shape) = 0;

    // Virtual functions to be overridden by derived classes
    virtual void print() const = 0;
    virtual void fromOpenCV(const cv::Mat& mat) = 0;
    virtual cv::Mat toOpenCV() const = 0;
    virtual bool readImage(const std::string& path) = 0;
    void display(bool waitForKey) const;

    Matrix& operator=(const Matrix& mat);

    inline size_t getRows() const { return m_rows; }
    inline size_t getCols() const { return m_cols; }
    inline int& at(size_t row, size_t col, size_t channel = 0) {
        return m_data[row * m_cols * m_channels + col * m_channels + channel];
    }
    inline const int& at(size_t row, size_t col, size_t channel = 0) const {
        return m_data[row * m_cols * m_channels + col * m_channels + channel];
    }
    inline size_t getChannels() const { return m_channels; }


protected:
    size_t m_rows;
    size_t m_cols;
    int m_channels; // Stores the number of channels for the matrix
    int m_initVal; // Stores the initial value for the matrix
    std::vector<int> m_data;
};

#endif // MATRIX_H


