#include "SpawnWall.h"
#include "SquareCollider.h"
#include "RectangleShapeRenderer.h"
#include "WindowModule.h"
#include "Engine.h"

void SpawnWall::CreateWallObject(Scene* scene, const ObjectName& _name, const float _x, const float _y) {
    GameObject* wall = scene->CreateGameObject(_name);
    wall->SetPosition(Maths::Vector2f(_x, _y));

    sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

    SquareCollider* squareCollider = wall->CreateComponent<SquareCollider>();
    squareCollider->SetWidth(window_size.x / 33);
    squareCollider->SetHeight(window_size.y / 22);

    RectangleShapeRenderer* shapeRenderer = wall->CreateComponent<RectangleShapeRenderer>();
    shapeRenderer->SetColor(sf::Color::White); // Couleur du mur
    shapeRenderer->SetSize(Maths::Vector2f(window_size.x / 33, window_size.y / 22)); // Taille du mur
}