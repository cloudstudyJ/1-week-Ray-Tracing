#include "world.hpp"
#include "models/model.hpp"
#include "components/colliders/sphereCollider.hpp"

#include <iostream>

World::World(const string& name)
    : mName{name} { }
World::~World() noexcept { clear(); }

// Models
void World::addModel(Model* model) { mModels.push_back(model); }
void World::clear() {
    for (auto& model: mModels)
        delete model;

    mModels.clear();
}

// Utilities
RayHitResult World::raycast(const Ray& ray) const {
    RayHitResult closestHit;
    closestHit.distance = static_cast<float>(3.4E+38);

    for (const auto& model: mModels) {
        SphereCollider* collider = model->getComponent<SphereCollider>();
        RayHitResult hitResult = collider->intersect(ray);

        if (hitResult.isHit && hitResult.distance < closestHit.distance)
            closestHit = hitResult;
    }

    return closestHit;
}

// Setters
void World::name(const string& name) {
    mName = name;
    mName.shrink_to_fit();
}

// Getters
string World::name() const noexcept { return mName; }