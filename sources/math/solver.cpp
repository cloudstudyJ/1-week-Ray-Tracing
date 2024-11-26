#include "math/solver.hpp"
#include "utilities/ray.hpp"
#include "objects/sphere.hpp"

float Solver::rayCastToSphere(const Ray& ray, const Sphere& sphere) noexcept {
    Vec3<float> diffCA = sphere.pos() - ray.pos();

    float a = Vec3<float>::dot(ray.dir(), ray.dir());
    float b = -2.0f * Vec3<float>::dot(ray.dir(), diffCA);
    float c = Vec3<float>::dot(diffCA, diffCA) - Math::square(sphere.radius());

    float discriminant = Math::square(b) - 4 * a * c;

    if (discriminant < 0.0f)
        return -1.0f;

    return ((-b - std::sqrt(discriminant)) / (2.0f * a));
}