#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

#include "utilities/camera.hpp"
#include "utilities/ray.hpp"
#include "objects/sphere.hpp"
#include "math/solver.hpp"

unsigned int imgW{ 512 };
unsigned int imgH{ };

float viewportH = 2.0f;
float viewportW{ };

constexpr float aspectRatio = 16.0f / 9;
constexpr float focalLength = 1.0f;

const Vec3<float> whiteColor   = { 1.0f, 1.0f, 1.0f };
const Vec3<float> skyBlueColor = { 0.5f, 0.75f, 1.0f };

void writeHeader(ofstream& writer) {
    writer << "P3" << endl;
    writer << imgW << ' ' << imgH << endl;
    writer << 255 << endl;
}

int main() {
    imgH = static_cast<int>(std::round(imgW / aspectRatio));
    viewportW = viewportH * (static_cast<float>(imgW) / imgH);

    Vec3<float> viewportXv{ viewportW, 0.0f, 0.0f };
    Vec3<float> viewportYv{ 0.0f, -viewportH, 0.0f };

    Vec3<float> dPixelXv = viewportXv / imgW;
    Vec3<float> dPixelYv = viewportYv / imgH;

    ofstream writer("./output.ppm", std::ios_base::binary);
    if (writer) {
        writeHeader(writer);

        Camera camera;
        Sphere sphere({ 0.0f, 0.0f, -1.0f }, 0.5f);

        Vec3<float> viewportLTv = camera.pos() - Vec3<float>(0.0f, 0.0f, focalLength);
        viewportLTv -= (viewportXv / 2.0f);
        viewportLTv -= (viewportYv / 2.0f);

        Vec3<float> pixelLTv = viewportLTv + ((dPixelXv + dPixelYv) * 0.5f);

        // Render
        Vec3<int> rayColor;
        Ray ray(camera.pos(), { });

        for (int row{ }; row < imgH; ++row) {
            for (int col{ }; col < imgW; ++col) {
                Vec3<float> currentPixelCenter = pixelLTv + ((dPixelXv * col) + (dPixelYv * row));
                ray.dir(currentPixelCenter - camera.pos());

                Vec3<float> unitDir = ray.dir().normalize();
                float t = Solver::rayCastToSphere(ray, sphere);

                if (t >= 0.0f) {
                    Vec3<float> normal = ((ray.pos() + (ray.dir() * t)) - sphere.pos()).normalize();

                    rayColor = (Vec3<float>(normal.x + 1.0f, normal.y + 1.0f, normal.z + 1.0f) * 0.5f) * 255;
                }
                else
                    rayColor = Math::lerpf(whiteColor, skyBlueColor, (unitDir.y + 1.0f) * 0.5f) * 255;

                writer << rayColor.x << ' ' << rayColor.y << ' ' << rayColor.z;
                writer << ((col != (imgW - 1)) ? ' ' : '\n');
            }
        }
    }

    return 0;
}