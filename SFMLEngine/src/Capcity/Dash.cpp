#include "Capacity/Dash.h"
#include "Components/Player.h"

void Dash::Update(const float _delta_time, sf::RenderWindow& window, std::vector<GameObject*>* gameObjects) {
    GameObject* player = nullptr;
    float initialX = 0.0f; 

    for (GameObject* const& gameObject : *gameObjects) {
        if (gameObject->GetType() == PlayerType) {
            player = gameObject;
            break; 
        }
    }

    if (player != nullptr) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            speedMultiplier = 10.0f;
            initialX = player->GetPosition().GetX();

            player->SetPosition(Maths::Vector2f(initialX + 100, player->GetPosition().GetY()));
            speedBoostTimer.restart();
        }

        // Obtenez la vitesse actuelle du joueur
        float currentSpeed = player->GetComponent<Player>()->GetSpeed();

        // Multipliez la vitesse actuelle par speedMultiplier
        float newSpeed = currentSpeed * speedMultiplier;

        // Mettez à jour la vitesse du joueur avec la nouvelle vitesse calculée
        player->GetComponent<Player>()->SetSpeed(newSpeed);

        float currentX = player->GetPosition().GetX();
        float distanceTraveled = std::abs(currentX - initialX);

        
        if (distanceTraveled >= 100.0f) {
            speedMultiplier = 1.0f; // Revenir à la vitesse normale
        }
    }
}
