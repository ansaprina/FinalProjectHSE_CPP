#include "shape.h"
#include "matrix.h"

Rectangle::Rectangle(std::pair<int, int> topLeft, int width, int height, BWColor bwColor)
    : m_topLeft(std::move(topLeft)), m_width(width), m_height(height), isBW(true), m_bwColor(bwColor) {}

Rectangle::Rectangle(std::pair<int, int> topLeft, int width, int height, RGBColor rgbColor)
    : m_topLeft(std::move(topLeft)), m_width(width), m_height(height), isBW(false), m_rgbColor(rgbColor) {}

void Rectangle::drawOn(Matrix& matrix) const {
    if (matrix.getChannels() == 3) {  // If matrix is RGB
        for (int r = m_topLeft.second; r < m_topLeft.second + m_height; ++r) {
            for (int c = m_topLeft.first; c < m_topLeft.first + m_width; ++c) {
                if (r >= 0 && r < matrix.getRows() && c >= 0 && c < matrix.getCols()) {
                    matrix.at(r, c, 0) = m_rgbColor.getR();  // Sets red channel
                    matrix.at(r, c, 1) = m_rgbColor.getG();  // Sets green channel
                    matrix.at(r, c, 2) = m_rgbColor.getB();  // Sets blue channel
                }
            }
        }
    } else {  // If matrix is BW
        for (int r = m_topLeft.second; r < m_topLeft.second + m_height; ++r) {
            for (int c = m_topLeft.first; c < m_topLeft.first + m_width; ++c) {
                if (r >= 0 && r < matrix.getRows() && c >= 0 && c < matrix.getCols()) {
                    matrix.at(r, c) = m_bwColor.getColor();
                }
            }
        }
    }
}

