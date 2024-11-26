#pragma once

class Model;

class Component {
    Component() = delete;
    Component(const Component&) = delete;
    Component(Component&&) noexcept = delete;

    Component& operator=(const Component&) = delete;
    Component& operator=(Component&&) noexcept = delete;

    public:
        virtual ~Component() noexcept;

        // Setters
        void owner(Model*) noexcept;

        // Getters
        unsigned short id() const noexcept;

        Model* owner() const noexcept;

    protected:
        Component(const unsigned short&) noexcept;

    protected:
        unsigned short mID{ };

        Model* mOwner{ };
};