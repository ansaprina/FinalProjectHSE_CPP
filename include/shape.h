#ifndef SHAPE_H
#define SHAPE_H

#include <utility>
#include "bw_color.h"
#include "rgb_color.h"

class Matrix; // Forward declaration of Matrix class

// Abstract base class Shape
class Shape {
public:
    virtual ~Shape() = default;
    // Pure virtual function to draw the shape on a matrix
    virtual void drawOn(Matrix& matrix) const = 0;
};

// Rectangle shape class
class Rectangle : public Shape {
public:
    Rectangle(std::pair<int, int> topLeft, int width, int height, BWColor bwColor);
    Rectangle(std::pair<int, int> topLeft, int width, int height, RGBColor rgbColor);
    void drawOn(Matrix& matrix) const override;

private:
    std::pair<int, int> m_topLeft;
    int m_width;
    int m_height;
    bool isBW;
    BWColor m_bwColor;
    RGBColor m_rgbColor;
};

// Circle shape class
class Circle : public Shape {
public:
    Circle(std::pair<int, int> center, int radius, BWColor bwColor);
    Circle(std::pair<int, int> center, int radius, RGBColor rgbColor);
    void drawOn(Matrix& matrix) const override;

private:
    std::pair<int, int> m_center;
    int m_radius;
    bool isBW;
    BWColor m_bwColor;
    RGBColor m_rgbColor;
};


// Triangle shape class
class Triangle : public Shape {
public:
    Triangle(std::pair<int, int> point1, std::pair<int, int> point2, std::pair<int, int> point3, BWColor bwColor);
    Triangle(std::pair<int, int> point1, std::pair<int, int> point2, std::pair<int, int> point3, RGBColor rgbColor);
    void drawOn(Matrix& matrix) const override;

private:
    std::pair<int, int> m_point1;
    std::pair<int, int> m_point2;
    std::pair<int, int> m_point3;
    bool isBW;
    BWColor m_bwColor;
    RGBColor m_rgbColor;
};

#endif // SHAPE_H
