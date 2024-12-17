#ifndef RGB_COLOR_H
#define RGB_COLOR_H

class RGBColor {
public:
    RGBColor(int r = 0, int g = 0, int b = 0) : m_r(r), m_g(g), m_b(b) {}
    void changeColor(int r, int g, int b) { m_r = r; m_g = g; m_b = b; }
    int getR() const { return m_r; }
    int getG() const { return m_g; }
    int getB() const { return m_b; }

private:
    int m_r;
    int m_g;
    int m_b;
};

#endif // RGB_COLOR_H