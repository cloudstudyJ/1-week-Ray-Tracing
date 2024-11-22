#include "utilities/ray.hpp"

Ray::Ray(const Vec3<float>& pos, const Vec3<float>& dir) noexcept
    : mPos{pos}, mDir{dir} { }
Ray::~Ray() noexcept { }