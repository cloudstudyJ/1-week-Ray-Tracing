#include <iostream>
#include <fstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::ofstream;

#include "utilities/camera.hpp"
#include "objects/sphere.hpp"

unsigned int imgW{ 512 };
unsigned int imgH{ };

constexpr double aspectRatio = 16.0 / 9;
constexpr float focalLength = 1.0f;

void writeHeader(ofstream& writer) {
    writer << "P3 " << imgW << ' ' << imgH << endl;
    writer << 255 << endl;
}

int main() {
    imgH = static_cast<int>(std::round(imgW / aspectRatio));

    ofstream writer("./output.ppm");
    if (writer) {
        writeHeader(writer);

        Camera camera;

        auto xAxis = Vec3<float>(1.0f, 0.0f, 0.0f);
        auto yAxis = Vec3<float>(0.0f, 1.0f, 0.0f);

        // Render
        /* for (int row{ }; row < imgH; ++row) {
            for (int col{ }; col < imgW; ++col) {
                //
            }
        } */
    }

    return 0;
}