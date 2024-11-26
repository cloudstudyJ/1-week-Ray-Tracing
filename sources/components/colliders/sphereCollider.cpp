#include "components/colliders/sphereCollider.hpp"
#include "models/sphere.hpp"

SphereCollider::SphereCollider() noexcept
    : Collider{componentID()} { }
SphereCollider::~SphereCollider() noexcept { }

// Intersection tests
RayHitResult SphereCollider::intersect(const Ray& ray) {
    Sphere* sphere = static_cast<Sphere*>(mOwner);

    Vec3<float> diffCA = (sphere->pos() - ray.pos());

    float a = ray.dir().lengthSquare();
    float h = ray.dir().dot(diffCA);
    float c = (diffCA.lengthSquare() - Math::square(sphere->radius()));

    float discriminant = (Math::square(h) - (a * c));
    float t = (h - std::sqrt(discriminant) / a);

    RayHitResult hitResult;

    if (t >= 0.0f) {
        hitResult.isHit = true;
        hitResult.contactPoint = (ray.pos() + (ray.dir() * t));
        hitResult.distance = hitResult.contactPoint.length();
        hitResult.normal = ((hitResult.contactPoint - sphere->pos()) / sphere->radius());
    }

    return hitResult;
}

// Getters
unsigned short SphereCollider::componentID() noexcept {
    static unsigned short id = 0x0100;

    return id;
}