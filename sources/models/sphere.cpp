#include "models/sphere.hpp"
#include "components/colliders/sphereCollider.hpp"

Sphere::Sphere() noexcept
    : Model{} {
    SphereCollider* collider = new SphereCollider;
    collider->owner(this);

    addComponent(collider);
}
Sphere::Sphere(const Vec3<float>& pos, const float& r) noexcept
    : Model{}, mRadius{r} {
    mPos = pos;

    SphereCollider* collider = new SphereCollider;
    collider->owner(this);

    addComponent(collider);
}
Sphere::~Sphere() noexcept { }

// Setters
void Sphere::radius(const float& r) noexcept { mRadius = r; }

// Getters
float Sphere::radius() const noexcept { return mRadius; }