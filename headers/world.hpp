#pragma once

#include "utilities/ray.hpp"

#include <deque>
#include <string>
using std::deque;
using std::string;

class Model;

class World {
    World() = delete;
    World(const World&) = delete;
    World(World&&) noexcept = delete;

    World& operator=(const World&) = delete;
    World& operator=(World&&) noexcept = delete;

    public:
        World(const string&);
        ~World() noexcept;

        // Models
        void addModel(Model*);
        void clear();

        // Utilities
        RayHitResult raycast(const Ray&) const;

        // Setters
        void name(const string&);

        // Getters
        string name() const noexcept;

    private:
        string mName;

        deque<Model*> mModels;
};