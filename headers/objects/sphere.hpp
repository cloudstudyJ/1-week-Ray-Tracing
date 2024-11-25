#pragma once

#include "math/vector/vec3.hpp"

class Sphere {
    Sphere(const Sphere&) = delete;
    Sphere(Sphere&&) noexcept = delete;

    Sphere& operator=(const Sphere&) = delete;
    Sphere& operator=(Sphere&&) noexcept = delete;

    public:
        Sphere() noexcept;
        Sphere(const Vec3<float>&, const float& = 1.0f) noexcept;
        ~Sphere() noexcept;

        void radius(const float&) noexcept;
        void pos(const Vec3<float>&) noexcept;
        void color(const Vec3<float>&) noexcept;

        float radius() const noexcept;
        Vec3<float> pos() const noexcept;
        Vec3<float> color() const noexcept;

    private:
        float mRadius;

        Vec3<float> mPos;
        Vec3<float> mColor;
};