#include <iostream>
#include <fstream>

using std::cout, std::endl;
using std::ofstream;

#include "world.hpp"
#include "models/sphere.hpp"
#include "utilities/camera.hpp"
#include "utilities/ray.hpp"
#include "utilities/random.hpp"

unsigned int imgW{ 512 };
unsigned int imgH{ };

float viewportH = 2.0f;
float viewportW{ };

constexpr float aspectRatio = 16.0f / 9;
constexpr float focalLength = 1.0f;

const Vec3<float> whiteColor   = { 1.0f, 1.0f, 1.0f };
const Vec3<float> skyBlueColor = { 0.5f, 0.75f, 1.0f };

constexpr unsigned short samplesPerPixel = 24;

Vec3<float> makeNearSampleVector() {
    return {
        Random::range<float>(-0.5f, 0.5f),
        Random::range<float>(-0.5f, 0.5f),
        0.0f
    };
}
Vec3<float> makeRandomUnitVector() {
    while (true) {
        Vec3<float> v = Random::Vec3<float>(-1.0f, 1.0f);
        float lenSQ = v.lengthSquare();

        if (1.0E-06f <= lenSQ && lenSQ <= 1.0f)
            return v.normalize();
    }
}
Vec3<float> makeRandomHemiSphereVector(const Vec3<float>& normal) {
    Vec3<float> v = makeRandomUnitVector();

    if (v.dot(normal) < 0.0f)
        return -v;

    return v;
}

void writeHeader(ofstream& writer) {
    writer << "P3" << endl;
    writer << imgW << ' ' << imgH << endl;
    writer << 255 << endl;
}
void writePixel(ofstream& writer, const Vec3<float>& color) {
    int r = static_cast<int>(255 * Math::clamp(color.r, 0.0f, 1.0f));
    int g = static_cast<int>(255 * Math::clamp(color.g, 0.0f, 1.0f));
    int b = static_cast<int>(255 * Math::clamp(color.b, 0.0f, 1.0f));

    writer << r << ' ' << g << ' ' << b;
}
Vec3<float> calcColor(const World& world, const Ray& ray, const unsigned short& depth) {
    if (depth <= 0)
        return { };

    RayHitResult hitResult = world.raycast(ray);

    if (hitResult.isHit) {
        Vec3<float> reflectionDir = makeRandomHemiSphereVector(hitResult.normal);

        return calcColor(world, { hitResult.contactPoint, reflectionDir }, depth - 1) * 0.5f;
    }

    return Math::lerpf(whiteColor, skyBlueColor, (ray.dir().normalize().y + 1.0f) * 0.5f);
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
        world.addModel(new Sphere({ 0.0f, -100.5f, -1.0f }, 100.0f));

        Camera camera;

        Vec3<float> viewportLTv = camera.pos() - Vec3<float>(0.0f, 0.0f, focalLength);
        viewportLTv -= (viewportXv / 2.0f);
        viewportLTv -= (viewportYv / 2.0f);
        Vec3<float> pixelLTv = viewportLTv + ((dPixelXv + dPixelYv) * 0.5f);

        // Render
        for (int row{ }; row < imgH; ++row) {
            for (int col{ }; col < imgW; ++col) {
                Vec3<float> curPixelCenter = (pixelLTv + ((dPixelXv * col) + (dPixelYv * row)));
                Vec3<float> color;

                for (int sample{ }; sample < samplesPerPixel; ++sample) {
                    Vec3<float> offset = makeNearSampleVector();
                    Vec3<float> samplePixel = pixelLTv + (dPixelXv * (col + offset.x)) + (dPixelYv * (row + offset.y));

                    Ray ray(camera.pos(), samplePixel - camera.pos());
                    color += calcColor(world, ray, 24);
                }
                color /= samplesPerPixel;

                writePixel(writer, color);
                writer << ((col != (imgW - 1)) ? ' ' : '\n');
            }
        }
    }

    return 0;
}