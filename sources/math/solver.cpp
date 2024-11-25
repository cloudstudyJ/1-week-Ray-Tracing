#include "math/solver.hpp"
#include "utilities/ray.hpp"
#include "objects/sphere.hpp"

bool Solver::isHitSphere(const Ray& ray, const Sphere& sphere) noexcept {
    Vec3<float> diffCA = sphere.pos() - ray.pos();

    float a = Vec3<float>::dot(ray.dir(), ray.dir());
    float b = - 2 * Vec3<float>::dot(ray.dir(), diffCA);
    float c = Vec3<float>::dot(diffCA, diffCA) * Math::square(sphere.radius());

    return ((Math::square(b) - 4 * a * c) >= 0);
}

Vec3<float> Solver::lerpColor(const Ray& ray) noexcept {
    static const Vec3<float> whiteColor = { 1.0f, 1.0f, 1.0f };
    static const Vec3<float> skyBlueColor  = { 0.5f, 0.75f, 1.0f };

    Vec3<float> unitDir = ray.dir().normalize();
    float t = (unitDir.y + 1.0f) * 0.5f;

    return ((whiteColor * (1.0f - t)) + (skyBlueColor * t));
}