#include "shape.h"
#include "matrix.h"


Circle::Circle(std::pair<int, int> center, int radius, BWColor bwColor)
    : m_center(std::move(center)), m_radius(radius), isBW(true), m_bwColor(bwColor) {}

Circle::Circle(std::pair<int, int> center, int radius, RGBColor rgbColor)
    : m_center(std::move(center)), m_radius(radius), isBW(false), m_rgbColor(rgbColor) {}

void Circle::drawOn(Matrix& matrix) const {
    if (matrix.getChannels() == 3) {  // If matrix is RGB
        for (int r = m_center.second - m_radius; r <= m_center.second + m_radius; ++r) {
            for (int c = m_center.first - m_radius; c <= m_center.first + m_radius; ++c) {
                if (r >= 0 && r < matrix.getRows() && c >= 0 && c < matrix.getCols()) {
                    int dx = c - m_center.first;
                    int dy = r - m_center.second;
                    if (dx * dx + dy * dy <= m_radius * m_radius) {
                        matrix.at(r, c, 0) = m_rgbColor.getR();
                        matrix.at(r, c, 1) = m_rgbColor.getG();
                        matrix.at(r, c, 2) = m_rgbColor.getB();
                    }
                }
            }
        }
    } else {  // If matrix is BW
        for (int r = m_center.second - m_radius; r <= m_center.second + m_radius; ++r) {
            for (int c = m_center.first - m_radius; c <= m_center.first + m_radius; ++c) {
                if (r >= 0 && r < matrix.getRows() && c >= 0 && c < matrix.getCols()) {
                    int dx = c - m_center.first;
                    int dy = r - m_center.second;
                    if (dx * dx + dy * dy <= m_radius * m_radius) {
                        matrix.at(r, c) = m_bwColor.getColor();
                    }
                }
            }
        }
    }
}


