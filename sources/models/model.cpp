#include "models/model.hpp"

Model::Model() noexcept { }
Model::~Model() noexcept {
    for(auto component: mComponents) {
        delete component.second;

        mComponents.erase(component.first);
    }
}

// Components
void Model::addComponent(Component* component) { mComponents.emplace(component->id(), component); }

// Setters
void Model::pos(const Vec3<float>& pos) noexcept { mPos = pos; }
void Model::color(const Vec3<float>& color) noexcept { mColor = color; }

// Getters
Vec3<float> Model::pos() const noexcept { return mPos; }
Vec3<float> Model::color() const noexcept { return mColor; }