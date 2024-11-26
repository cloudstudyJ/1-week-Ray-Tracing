#include "components/component.hpp"

Component::Component(const unsigned short& id) noexcept
    : mID{id} { }
Component::~Component() noexcept { }

// Setters
void Component::owner(Model* model) noexcept { mOwner = model; }

// Getters
unsigned short Component::id() const noexcept { return mID; }

Model* Component::owner() const noexcept { return mOwner; }