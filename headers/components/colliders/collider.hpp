#pragma once

#include "components/component.hpp"
#include "utilities/ray.hpp"

class Collider: public Component {
    Collider() = delete;
    Collider(const Collider&) = delete;
    Collider(Collider&&) noexcept = delete;

    Collider& operator=(const Collider&) = delete;
    Collider& operator=(Collider&&) noexcept = delete;

    public:
        using Super = Component;

        virtual RayHitResult intersect(const Ray&) = 0;

    protected:
        virtual ~Collider() noexcept;

    protected:
        Collider(const unsigned short&) noexcept;
};