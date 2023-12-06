#include "Components/Switch.h"
#include "Components/RectangleShapeRenderer.h"

void Switch::CreateSwitchObject(Scene* scene, const ObjectName& _name, const float _x, const float _y) {
    GameObject* wall = scene->CreateGameObject(_name);
    wall->SetPosition(Maths::Vector2f(_x, _y));

    RectangleShapeRenderer* shapeRenderer = wall->CreateComponent<RectangleShapeRenderer>();
    shapeRenderer->SetColor(sf::Color::Red); // Couleur du mur
    shapeRenderer->SetSize(Maths::Vector2f(50.f, 50.f)); // Taille du mur
}