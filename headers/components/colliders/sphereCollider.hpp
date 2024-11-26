#pragma once

#include "components/colliders/collider.hpp"

class SphereCollider: public Collider {
    SphereCollider(const SphereCollider&) = delete;
    SphereCollider(SphereCollider&&) noexcept = delete;

    SphereCollider& operator=(const SphereCollider&) = delete;
    SphereCollider& operator=(SphereCollider&&) noexcept = delete;

    public:
        using Super = Collider;

        // Intersection tests
        RayHitResult intersect(const Ray&) override;

    public:
        SphereCollider() noexcept;
        virtual ~SphereCollider() noexcept;

        // Getters
        static unsigned short componentID() noexcept;
};