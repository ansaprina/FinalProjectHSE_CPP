# 🎄 Christmas Scene Renderer

This C++ project renders a festive winter scene featuring a Christmas tree, moon, snow, stars, and ornaments using a custom shape and matrix drawing framework.

## 🌟 Features

- RGB and black-and-white matrix classes with OpenCV integration
- Shape hierarchy with `Rectangle`, `Circle`, and `Triangle`
- Color support via `RGBColor` and `BWColor` classes
- Object-oriented design for extensibility
- High-resolution image rendering (default: 2000x2000 pixels)
- Optional performance measurement
- Scene displayed with `cv::imshow`

## 📸 Sample Output

The rendered scene includes:
- A starry sky with a crescent moon
- Snow-covered ground
- A Christmas tree made of green triangles
- A brown trunk
- Colorful ornaments
- Stylized stars made of yellow triangles

> ⚠️ OpenCV must be installed for the display functionality to work.

## 📁 File Structure

```
.
├── include/
│   ├── shape.h
│   ├── matrix.h
│   ├── rgb_matrix.h
│   ├── bw_matrix.h
│   ├── rgb_color.h
│   └── bw_color.h
├── src/
│   ├── rectangle.cpp
│   ├── triangle.cpp
│   ├── circle.cpp
│   ├── matrix.cpp
│   ├── rgb_matrix.cpp
│   └── bw_matrix.cpp
├── main.cpp
└── CMakeLists.txt
```

## 🧱 Build Instructions

Make sure [OpenCV](https://opencv.org/) is installed on your system.

```bash
# Clone the project
git clone https://github.com/yourusername/christmas-renderer.git
cd christmas-renderer

# Create a build directory
mkdir build && cd build

# Run CMake and build
cmake ..
make

# Run the program
./main
```

You will be prompted to choose whether to display the image or measure performance.

## 🛠️ Dependencies

- **C++17**
- [OpenCV](https://opencv.org/) (core, imgcodecs, highgui)

## ✨ Example Usage

```bash
Do you want to display the image? If you choose Y the execution time won't be calculated (y/n): y
```

## 📌 Notes

- If display is disabled (`n`), the execution time is printed in milliseconds.
- This project is a fun example of basic computer graphics without relying on advanced rendering libraries.

---

Made with ❤️ for visual joy.