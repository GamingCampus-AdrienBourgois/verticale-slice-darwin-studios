#include "Capacity/Dash.h"
#include "Components/Player.h"
#include <iostream>

//Sound
Dash::Dash() {
    soundBufferDash = new sf::SoundBuffer;
    if (!soundBufferDash->loadFromFile("Assets/Sons/dash.wav")) {
        std::cout << "erreur de chargement du fichier" << std::endl;
    }
    soundDash = new sf::Sound;
}

Dash::~Dash() {
    delete soundBufferDash;
    delete soundDash;
}

void Dash::PlaySound() {
    soundDash->setBuffer(*soundBufferDash);
    soundDash->play();
}

void Dash::StopSound() {
    soundDash->stop();
}

void Dash::IsDashing(const float _delta_time, std::vector<GameObject*>* gameObjects) {
    GameObject* player = nullptr;

    for (GameObject* const& gameObject : *gameObjects) {
        if (gameObject->GetType() == PlayerType) {
            player = gameObject;
            break;
        }
    }

    if (player != nullptr) {
        if ((speed_dash > 0 && !player->GetComponent<SquareCollider>()->GetCanMoving()["right"]) || (speed_dash < 0 && !player->GetComponent<SquareCollider>()->GetCanMoving()["left"]) || (StartClockDurationDash.getElapsedTime().asMilliseconds() >= timeDash && is_dashing))
        {
            is_dashing = false;
            StartClockCooldownDash.restart();
        }

        // Si le dash est possible et n'est pas en cours
        if (StartClockCooldownDash.getElapsedTime().asMilliseconds() >= CooldownDash && !is_dashing) {
 
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player->GetComponent<SquareCollider>()->GetCanMoving()["right"]) {
                    speed_dash = 3;
                    is_dashing = true;
                    StartClockDurationDash.restart(); // Redémarre le temps du dash
                    if (!soundPlayed) {
                        PlaySound();
                        soundDash->setVolume(25);
                        soundPlayed = true; // Marquer que le son a été joué
                        std::cout << "truc" << std::endl;
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && player->GetComponent<SquareCollider>()->GetCanMoving()["left"]) {
                    speed_dash = -3;
                    is_dashing = true;
                    StartClockDurationDash.restart(); // Redémarre le temps du dash
                    if (!soundPlayed) {
                        PlaySound();
                        soundDash->setVolume(25);
                        soundPlayed = true; // Marquer que le son a été joué
                    }
                }
            }
        }

        // Si le dash est en cours et le cooldown dépasse 5 secondes
        if (is_dashing) {
            player->SetPosition(Maths::Vector2f(player->GetPosition().GetX() + speed_dash, player->GetPosition().GetY()));


        }
    }
}

void Dash::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
    soundPlayed = false;

    std::vector<GameObject*>* gameObjects = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene()->GetGameObjects();
    IsDashing(_delta_time, gameObjects);
}