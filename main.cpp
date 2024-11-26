#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

#include "world.hpp"
#include "models/sphere.hpp"
#include "utilities/camera.hpp"
#include "utilities/ray.hpp"

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
Vec3<int> calcColors(const World& world, const Ray& ray) {
    RayHitResult hitResult = world.raycast(ray);
    Vec3<float> color;

    if (hitResult.isHit)
        color = (((hitResult.normal + 1.0f) * 0.5f) * 255);
    else
        color = (Math::lerpf(whiteColor, skyBlueColor, (ray.dir().normalize().y + 1.0f) * 0.5f) * 255);

    return color;
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

        World world("Main");
        world.addModel(new Sphere({ 0.0f, 0.0f, -1.0f }, 0.5f));

        Camera camera;

        Vec3<float> viewportLTv = camera.pos() - Vec3<float>(0.0f, 0.0f, focalLength);
        viewportLTv -= (viewportXv / 2.0f);
        viewportLTv -= (viewportYv / 2.0f);
        Vec3<float> pixelLTv = viewportLTv + ((dPixelXv + dPixelYv) * 0.5f);

        // Render
        for (int row{ }; row < imgH; ++row) {
            for (int col{ }; col < imgW; ++col) {
                Vec3<float> curPixelCenter = (pixelLTv + ((dPixelXv * col) + (dPixelYv * row)));
                Ray ray(camera.pos(), curPixelCenter - camera.pos());

                Vec3<int> rayColor = calcColors(world, ray);
                writer << rayColor.x << ' ' << rayColor.y << ' ' << rayColor.z;
                writer << ((col != (imgW - 1)) ? ' ' : '\n');
            }
        }
    }

    return 0;
}