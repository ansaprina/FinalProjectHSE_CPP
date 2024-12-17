// bw_color.h
#ifndef BW_COLOR_H
#define BW_COLOR_H

class BWColor {
public:
    BWColor(int color = 0) : m_color(color) {}
    void changeColor(int color) { m_color = color; }
    int getColor() const { return m_color; }

private:
    int m_color;
};

#endif // BW_COLOR_H