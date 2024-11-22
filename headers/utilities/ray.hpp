#pragma once

#include "math/vector/vec3.hpp"

class Ray {
        Ray() = delete;
        Ray(const Ray&) = delete;
        Ray(Ray&&) noexcept = delete;

        Ray& operator=(const Ray&) = delete;
        Ray& operator=(Ray&&) noexcept = delete;

    public:
        Ray(const Vec3<float>&, const Vec3<float>&) noexcept;
        ~Ray() noexcept;

    private:
        Vec3<float> mPos;
        Vec3<float> mDir;
};