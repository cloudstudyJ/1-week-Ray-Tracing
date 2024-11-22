#include "objects/sphere.hpp"

Sphere::Sphere() noexcept { }
Sphere::Sphere(const Vec3<float>& pos, const float& r) noexcept
    : mPos{pos}, mRadius{r} { }
Sphere::~Sphere() noexcept { }

void Sphere::radius(const float& r) noexcept { mRadius = r; }
void Sphere::pos(const Vec3<float>& pos) noexcept { mPos = pos; }
void Sphere::color(const Vec3<float>& color) noexcept { mColor = color; }

float Sphere::radius() const noexcept { return mRadius; }
Vec3<float> Sphere::pos() const noexcept { return mPos; }
Vec3<float> Sphere::color() const noexcept { return mColor; }
