#include "shape.h"
#include "matrix.h"

Triangle::Triangle(std::pair<int, int> point1, std::pair<int, int> point2, std::pair<int, int> point3, BWColor bwColor)
    : m_point1(std::move(point1)), m_point2(std::move(point2)), m_point3(std::move(point3)), isBW(true), m_bwColor(bwColor) {}

Triangle::Triangle(std::pair<int, int> point1, std::pair<int, int> point2, std::pair<int, int> point3, RGBColor rgbColor)
    : m_point1(std::move(point1)), m_point2(std::move(point2)), m_point3(std::move(point3)), isBW(false), m_rgbColor(rgbColor) {}

void Triangle::drawOn(Matrix& matrix) const {
    if (matrix.getChannels() == 3) {  // If matrix is RGB
        int colorR = m_rgbColor.getR();
        int colorG = m_rgbColor.getG();
        int colorB = m_rgbColor.getB();

        int minX = std::min({m_point1.first, m_point2.first, m_point3.first});
        int maxX = std::max({m_point1.first, m_point2.first, m_point3.first});
        int minY = std::min({m_point1.second, m_point2.second, m_point3.second});
        int maxY = std::max({m_point1.second, m_point2.second, m_point3.second});

        for (int r = minY; r <= maxY; ++r) {
            for (int c = minX; c <= maxX; ++c) {
                if (r >= 0 && r < matrix.getRows() && c >= 0 && c < matrix.getCols()) {
                    int a = (m_point1.first - c) * (m_point2.second - m_point1.second) - (m_point2.first - m_point1.first) * (m_point1.second - r);
                    int b = (m_point2.first - c) * (m_point3.second - m_point2.second) - (m_point3.first - m_point2.first) * (m_point2.second - r);
                    int cVal = (m_point3.first - c) * (m_point1.second - m_point3.second) - (m_point1.first - m_point3.first) * (m_point3.second - r);
                    if ((a >= 0 && b >= 0 && cVal >= 0) || (a <= 0 && b <= 0 && cVal <= 0)) {
                        matrix.at(r, c, 0) = colorR;
                        matrix.at(r, c, 1) = colorG;
                        matrix.at(r, c, 2) = colorB;
                    }
                }
            }
        }
    } else {  // If matrix is BW
        int color = m_bwColor.getColor();

        int minX = std::min({m_point1.first, m_point2.first, m_point3.first});
        int maxX = std::max({m_point1.first, m_point2.first, m_point3.first});
        int minY = std::min({m_point1.second, m_point2.second, m_point3.second});
        int maxY = std::max({m_point1.second, m_point2.second, m_point3.second});

        for (int r = minY; r <= maxY; ++r) {
            for (int c = minX; c <= maxX; ++c) {
                if (r >= 0 && r < matrix.getRows() && c >= 0 && c < matrix.getCols()) {
                    int a = (m_point1.first - c) * (m_point2.second - m_point1.second) - (m_point2.first - m_point1.first) * (m_point1.second - r);
                    int b = (m_point2.first - c) * (m_point3.second - m_point2.second) - (m_point3.first - m_point2.first) * (m_point2.second - r);
                    int cVal = (m_point3.first - c) * (m_point1.second - m_point3.second) - (m_point1.first - m_point3.first) * (m_point3.second - r);
                    if ((a >= 0 && b >= 0 && cVal >= 0) || (a <= 0 && b <= 0 && cVal <= 0)) {
                        matrix.at(r, c) = color;
                    }
                }
            }
        }
    }
}

