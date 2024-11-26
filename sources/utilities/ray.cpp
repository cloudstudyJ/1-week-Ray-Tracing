#include "utilities/ray.hpp"

Ray::Ray(const Vec3<float>& pos, const Vec3<float>& dir) noexcept
    : mPos{pos}, mDir{dir} { }
Ray::~Ray() noexcept { }

// Setters
void Ray::pos(const Vec3<float>& p) noexcept { mPos = p; }
void Ray::dir(const Vec3<float>& d) noexcept { mDir = d; }
void Ray::color(const Vec3<float>& color) noexcept { mColor = color; }

// Getters
Vec3<float> Ray::pos() const noexcept { return mPos; }
Vec3<float> Ray::dir() const noexcept { return mDir; }
Vec3<float> Ray::color() const noexcept { return mColor; }