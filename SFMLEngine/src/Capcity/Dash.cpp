#include "Capacity/Dash.h"
#include "Components/Player.h"
#include <iostream>

void Dash::IsDashing(const float _delta_time, std::vector<GameObject*>* gameObjects) {
    GameObject* player = nullptr;
    Maths::Vector2f lastValidPosition; // Stocke la dernière position valide du joueur

    for (GameObject* const& gameObject : *gameObjects) {
        if (gameObject->GetType() == PlayerType) {
            player = gameObject;
            break;
        }
    }

    if (player != nullptr) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            StartClockDash.restart();
        }

        lastValidPosition = player->GetPosition(); // Stocke la position actuelle du joueur

        if (StartClockDash.getElapsedTime().asMilliseconds() < 50 && player->GetComponent<SquareCollider>()->GetCanMoving()["right"]) {
            float initialX = player->GetPosition().GetX();
            player->SetPosition(Maths::Vector2f(initialX + 3, player->GetPosition().GetY()));

            for (GameObject* const& gameObject : *gameObjects) {
                if (gameObject->GetType() != ObjectType::PlayerType && gameObject != player) {
                    Maths::Vector2f playerPos = player->GetPosition();
                    Maths::Vector2f objPos = gameObject->GetPosition();

                    // Calcul de la largeur en utilisant l'échelle (scale)
                    Maths::Vector2f playerSize = player->GetScale();
                    Maths::Vector2f objSize = gameObject->GetScale();
                }
            }
        }
    }
}






void Dash::Update(const float _delta_time, std::vector<GameObject*>* gameObjects) {
    IsDashing(_delta_time, gameObjects);
}