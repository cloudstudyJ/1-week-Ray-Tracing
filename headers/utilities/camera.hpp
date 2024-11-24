#pragma once

#include "math/vector/vec3.hpp"

class Camera {
    Camera(const Camera&) = delete;
    Camera(Camera&&) noexcept = delete;

    Camera& operator=(const Camera&) = delete;
    Camera& operator=(Camera&&) noexcept = delete;

    public:
        Camera();
        ~Camera() noexcept;

        void pos(const Vec3<float>&) noexcept;
        void look(const Vec3<float>&) noexcept;

        Vec3<float> pos() const noexcept;
        Vec3<float> look() const noexcept;

    private:
        Vec3<float> mPos;
        Vec3<float> mLook;
};