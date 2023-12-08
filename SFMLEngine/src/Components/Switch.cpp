#include "Components/Switch.h"
#include "Components/SquareCollider.h"
#include "Components/RectangleShapeRenderer.h"

void Switch::CreateSwitchObject(Scene* scene, const ObjectType& _type, std::string _name, const float _x, const float _y) {
    GameObject* wall = scene->CreateGameObject(_type, _name);
    wall->SetPosition(Maths::Vector2f(_x, _y));

    SquareCollider* squareCollider = wall->CreateComponent<SquareCollider>();
    squareCollider->SetWidth(50.f);
    squareCollider->SetHeight(50.f);

    RectangleShapeRenderer* shapeRenderer = wall->CreateComponent<RectangleShapeRenderer>();
    shapeRenderer->SetColor(sf::Color::Red); // Couleur du mur
    shapeRenderer->SetSize(Maths::Vector2f(50.f, 50.f)); // Taille du mur
}