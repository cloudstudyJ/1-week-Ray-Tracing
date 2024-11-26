#include "components/colliders/collider.hpp"

Collider::Collider(const unsigned short& id) noexcept
    : Component{id} { }
Collider::~Collider() noexcept { }