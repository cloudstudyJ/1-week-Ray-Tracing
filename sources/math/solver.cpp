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