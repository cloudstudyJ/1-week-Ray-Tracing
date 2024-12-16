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

    RayHitResult hitResult;

    if (discriminant >= 0.0f) {
        float sqrtDiscriminant = std::sqrt(discriminant);

        float t1 = (h - sqrtDiscriminant) / a;
        float t2 = (h + sqrtDiscriminant) / a;
        float t = (t1 >= 0.0f) ? t1 : ((t2 >= 0.0f) ? t2 : -1.0f);

        if (t >= 0.001f) {
            hitResult.isHit = true;
            hitResult.contactPoint = (ray.pos() + (ray.dir() * t));
            hitResult.distance = hitResult.contactPoint.length();
            hitResult.normal = ((hitResult.contactPoint - sphere->pos()) / sphere->radius());

            // is ray from inside of sphere
            if (ray.dir().dot(hitResult.normal) >= 0.0f)
                hitResult.normal = -hitResult.normal;
        }
    }

    return hitResult;
}

// Getters
unsigned short SphereCollider::componentID() noexcept {
    static unsigned short id = 0x0100;

    return id;
}