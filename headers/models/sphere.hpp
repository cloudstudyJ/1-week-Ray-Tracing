#pragma once

#include "models/model.hpp"

class Sphere: public Model {
    Sphere(const Sphere&) = delete;
    Sphere(Sphere&&) noexcept = delete;

    Sphere& operator=(const Sphere&) = delete;
    Sphere& operator=(Sphere&&) noexcept = delete;

    public:
        using Super = Model;

    public:
        Sphere() noexcept;
        Sphere(const Vec3<float>&, const float&) noexcept;
        virtual ~Sphere() noexcept;

        // Setters
        void radius(const float&) noexcept;

        // Getters
        float radius() const noexcept;

    private:
        float mRadius{ 1.0f };
};