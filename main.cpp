#include <chrono> // For measuring execution time
#include "include/matrix.h"
#include "include/rgb_matrix.h"
#include "include/rgb_color.h"
#include "include/shape.h"

int main() {
    char displayChoice;
    std::cout << "Do you want to display the image? If you choose Y the execution time won't be calculated (y/n): ";
    std::cin >> displayChoice;

    bool waitForKey = (displayChoice == 'y' || displayChoice == 'Y'); // Set waitForKey based on the user's response

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();
    //std::cout << "Starting timer..." << std::endl;

    // BEGINNING OF TEST CODE
    // ADDING YOUR OWN TEST CODE PLEASE REMEMBER TO ADD waitForKey
    // AS A PARAMETER INTO DISPLAY() FUNCTION
    RGBMatrix rgbMatrix(2000, 2000, 0);

    RGBColor treeGreen(0, 153, 0);
    RGBColor trunkBrown(102, 51, 0);
    RGBColor starYellow(255, 223, 0);
    RGBColor ornamentRed(255, 0, 0);
    RGBColor ornamentBlue(0, 0, 255);
    RGBColor ornamentPurple(84, 107, 171);
    RGBColor ornamentPink(238, 71, 153);
    RGBColor ornamentOrange(218, 92, 41);
    RGBColor ornamentYellow(254, 242, 0);
    RGBColor skyBlue(46, 68, 130);
    RGBColor snowWhite(255, 255, 255);
    RGBColor moonYellow(246, 241, 213);

    Rectangle sky({0, 0}, 2000, 2000, skyBlue);
    rgbMatrix.draw(sky);

    Circle moon1({320, 320}, 300, moonYellow);
    rgbMatrix.draw(moon1);
    Circle moon2({470, 320}, 300, skyBlue);
    rgbMatrix.draw(moon2);

    Rectangle trunk({900, 1400}, 200, 300, trunkBrown);
    rgbMatrix.draw(trunk);

    Circle snow1({100, 1850}, 300, snowWhite);
    rgbMatrix.draw(snow1);
    Circle snow2({450, 1850}, 320, snowWhite);
    rgbMatrix.draw(snow2);
    Circle snow3({700, 1850}, 300, snowWhite);
    rgbMatrix.draw(snow3);
    Circle snow4({1050, 1850}, 300, snowWhite);
    rgbMatrix.draw(snow4);
    Circle snow5({1400, 1850}, 320, snowWhite);
    rgbMatrix.draw(snow5);
    Circle snow6({1700, 1850}, 300, snowWhite);
    rgbMatrix.draw(snow6);
    Circle snow7({1900, 1850}, 300, snowWhite);
    rgbMatrix.draw(snow7);

    Triangle treePart1({1000, 200}, {1300, 800}, {700, 800}, treeGreen);
    Triangle treePart2({1000, 500}, {1400, 1100}, {600, 1100}, treeGreen);
    Triangle treePart3({1000, 750}, {1500, 1400}, {500, 1400}, treeGreen);
    rgbMatrix.draw(treePart1);
    rgbMatrix.draw(treePart2);
    rgbMatrix.draw(treePart3);

    Triangle star1Part1({900, 50}, {870, 100}, {930, 100}, starYellow);
    Triangle star1Part2({900, 120}, {870, 70}, {930, 70}, starYellow);
    rgbMatrix.draw(star1Part1);
    rgbMatrix.draw(star1Part2);
    Triangle star2Part1({1170, 70}, {1140, 120}, {1200, 120}, starYellow);
    Triangle star2Part2({1170, 140}, {1140, 90}, {1200, 90}, starYellow);
    rgbMatrix.draw(star2Part1);
    rgbMatrix.draw(star2Part2);
    Triangle star3Part1({1300, 140}, {1270, 190}, {1330, 190}, starYellow);
    Triangle star3Part2({1300, 210}, {1270, 160}, {1330, 160}, starYellow);
    rgbMatrix.draw(star3Part1);
    rgbMatrix.draw(star3Part2);
    Triangle star4Part1({1430, 170}, {1400, 220}, {1460, 220}, starYellow);
    Triangle star4Part2({1430, 240}, {1400, 190}, {1460, 190}, starYellow);
    rgbMatrix.draw(star4Part1);
    rgbMatrix.draw(star4Part2);
    Triangle star5Part1({1900, 190}, {1870, 240}, {1930, 240}, starYellow);
    Triangle star5Part2({1900, 260}, {1870, 210}, {1930, 210}, starYellow);
    rgbMatrix.draw(star5Part1);
    rgbMatrix.draw(star5Part2);
    Triangle star6Part1({1470, 350}, {1440, 400}, {1500, 400}, starYellow);
    Triangle star6Part2({1470, 420}, {1440, 370}, {1500, 370}, starYellow);
    rgbMatrix.draw(star6Part1);
    rgbMatrix.draw(star6Part2);
    Triangle star7Part1({1800, 370}, {1770, 420}, {1830, 420}, starYellow);
    Triangle star7Part2({1800, 440}, {1770, 390}, {1830, 390}, starYellow);
    rgbMatrix.draw(star7Part1);
    rgbMatrix.draw(star7Part2);

    Circle ornament1({800, 1000}, 30, ornamentPink);
    Circle ornament2({1200, 950}, 30, ornamentBlue);
    Circle ornament3({1040, 1200}, 40, ornamentRed);
    Circle ornament4({900, 800}, 40, ornamentPurple);
    Circle ornament5({1100, 600}, 40, ornamentOrange);
    Circle ornament6({950, 400}, 30, ornamentYellow);
    rgbMatrix.draw(ornament1);
    rgbMatrix.draw(ornament2);
    rgbMatrix.draw(ornament3);
    rgbMatrix.draw(ornament4);
    rgbMatrix.draw(ornament5);
    rgbMatrix.draw(ornament6);

    rgbMatrix.display(waitForKey);

    // END OF TEST CODE.
    // ADDING YOUR OWN TEST CODE PLEASE REMEMBER TO ADD waitForKey
    // AS A PARAMETER INTO DISPLAY() FUNCTION

    // Stop measuring time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration in milliseconds
    std::chrono::duration<double, std::milli> executionTime = end - start;

    std::cout << "Execution time: " << executionTime.count() << " ms" << std::endl;

    return 0;
}
