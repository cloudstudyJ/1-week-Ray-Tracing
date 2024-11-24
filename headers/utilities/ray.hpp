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

        void pos(const Vec3<float>&) noexcept;
        void dir(const Vec3<float>&) noexcept;
        void color(const Vec3<float>&) noexcept;

        Vec3<float> pos() const noexcept;
        Vec3<float> dir() const noexcept;
        Vec3<float> color() const noexcept;

    private:
        Vec3<float> mPos;
        Vec3<float> mDir;

        Vec3<float> mColor;
};