#include "math/solver.hpp"
#include "utilities/ray.hpp"
#include "objects/sphere.hpp"

float Solver::rayCastToSphere(const Ray& ray, const Sphere& sphere) noexcept {
    Vec3<float> diffCA = sphere.pos() - ray.pos();

    float a = ray.dir().lengthSquare();
    float h = Vec3<float>::dot(ray.dir(), diffCA);      // == -(b / 2)
    float c = (diffCA.lengthSquare() - Math::square(sphere.radius()));

    float discriminant = (Math::square(h) - (a * c));

    if (discriminant < 0.0f)
        return -1.0f;

    return ((h - std::sqrt(discriminant)) / a);
}