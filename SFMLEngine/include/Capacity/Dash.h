// Dash.h
#pragma once
#include "Capacity.h"
#include <SFML/System/Clock.hpp>
#include "GameObject.h"

class Dash : public Capacity {
public:
    void Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) override;

private:
    sf::Clock StartClockCooldownDash;
    int CooldownDash = 1000;
    sf::Clock StartClockDurationDash;
    int speed_dash = 0;
    int timeDash = 50;

    bool is_dashing = false;

    void IsDashing(const float _delta_time, std::vector<GameObject*>* gameObjects);
};
