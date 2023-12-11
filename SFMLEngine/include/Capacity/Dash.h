#pragma once
#include "Capacity.h"
#include <SFML/System/Clock.hpp>

class Dash : public Capacity {
public:
    

private:
    float speedMultiplier = 1.0f;
    sf::Clock speedBoostTimer;
    const float speedBoostDuration = 1.0f;
    float initialX = 0.0f;

    void Update(const float _delta_time, sf::RenderWindow& window, std::vector<GameObject*>* gameObjects);
};
