#include "SpawnWall.h"
#include "SquareCollider.h"
#include "RectangleShapeRenderer.h"

void SpawnWall::CreateWallObject(Scene* scene, const ObjectName& _name, const float _x, const float _y) {
    GameObject* wall = scene->CreateGameObject(_name);
    wall->SetPosition(Maths::Vector2f(_x, _y));

    SquareCollider* squareCollider = wall->CreateComponent<SquareCollider>();
    squareCollider->SetWidth(50.f);
    squareCollider->SetHeight(50.f);

    RectangleShapeRenderer* shapeRenderer = wall->CreateComponent<RectangleShapeRenderer>();
    shapeRenderer->SetColor(sf::Color::White); // Couleur du mur
    shapeRenderer->SetSize(Maths::Vector2f(50.f, 50.f)); // Taille du mur
}