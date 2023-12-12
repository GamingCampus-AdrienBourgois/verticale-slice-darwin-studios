// Dash.h
#pragma once
#include "Capacity.h"
#include <SFML/System/Clock.hpp>

class Dash : public Capacity {
public:
    void Update(const float _delta_time, std::vector<GameObject*>* gameObjects);

private:
    sf::Clock StartClockDash;
    float initialX = 0.0f;
    Maths::Vector2f lastValidPosition;

    void IsDashing(const float _delta_time, std::vector<GameObject*>* gameObjects);
};
