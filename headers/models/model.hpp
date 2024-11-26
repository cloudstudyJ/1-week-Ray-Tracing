#pragma once

#include "math/vector/vec3.hpp"
#include "components/component.hpp"

#include <unordered_map>
using std::unordered_map;

class Model {
    Model(const Model&) = delete;
    Model(Model&&) noexcept = delete;

    Model& operator=(const Model&) = delete;
    Model& operator=(Model&&) noexcept = delete;

    public:
        virtual ~Model() noexcept;

        // Components
        void addComponent(Component*);
        template <typename T> void removeComponent();

        // Setters
        void pos(const Vec3<float>&) noexcept;
        void color(const Vec3<float>&) noexcept;

        // Getters
        Vec3<float> pos() const noexcept;
        Vec3<float> color() const noexcept;

        template <typename T> T* getComponent() const;

    protected:
        Model() noexcept;

    protected:
        Vec3<float> mPos;
        Vec3<float> mColor;

        unordered_map<unsigned short, Component*> mComponents;
};

// Components
template <typename T> void Model::removeComponent() {
    auto it = mComponents.find(T::componentID());

    if (it != mComponents.end()) {
        delete it->second;

        mComponents.erase(it);
    }
}
template <typename T> T* Model::getComponent() const {
    auto it = mComponents.find(T::componentID());

    return ((it == mComponents.end()) ? nullptr : static_cast<T*>(it->second));
}