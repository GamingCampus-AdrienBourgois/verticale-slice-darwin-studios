#include "DefaultScene.h"

void DefaultScene::SpawnObjectLevel3() {
    sf::Vector2u window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

    SetTexture("background", "Assets/background.png");
    SetBackground("background");
    //sf::Texture background;
    //background.loadFromFile("Assets/background.png");
    //sf::Sprite sprite(background);
    //// Redimensionner le sprite pour qu'il remplisse la fen?tre
    //sprite.setScale((float)window_size.x / sprite.getTexture()->getSize().x, (float)window_size.y / sprite.getTexture()->getSize().y);
    //SetBackground(&sprite);

    int sizeWallX = window_size.x / 33;
    int sizeWallY = window_size.y / 22;

    //Emplacement de tous les murs de la map
    //On positionne les murs du bas vers le haut
    //Ligne 1
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 21 * sizeWallY); 
    CreateWallObject(this, WallType, "Wall", 3 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 4 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 5 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 7 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 18 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 22 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 23 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 24 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 25 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 26 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 28 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 29 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 30 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 31 * sizeWallX, 21 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 21 * sizeWallY);

    //Ligne 2
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 20 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 5 * sizeWallX, 20 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 20 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 18 * sizeWallX, 20 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 19 * sizeWallX, 20 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 20 * sizeWallX, 20 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 21 * sizeWallX, 20 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 22 * sizeWallX, 20 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 20 * sizeWallY);

    //Ligne 3
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 19 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 3 * sizeWallX, 19 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 22 * sizeWallX, 19 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 19 * sizeWallY);

    //Ligne 4
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 18 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 24 * sizeWallX, 18 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 18 * sizeWallY);

    //Ligne 5
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 17 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 26 * sizeWallX, 17 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 17 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 28 * sizeWallX, 17 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 29 * sizeWallX, 17 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 17 * sizeWallY);

    //Ligne 6
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 7 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 8 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 13 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 17 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 18 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 16 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 16 * sizeWallY);

    //Ligne 7 
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 1 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 3 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 4 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 5 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 19 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 20 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 15 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 15 * sizeWallY);

    //Ligne 8
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 14 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 21 * sizeWallX, 14 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 22 * sizeWallX, 14 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 23 * sizeWallX, 14 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 24 * sizeWallX, 14 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 25 * sizeWallX, 14 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 26 * sizeWallX, 14 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 14 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 14 * sizeWallY);

    //Ligne 9
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 13 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 13 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 28 * sizeWallX, 13 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 13 * sizeWallY);

    //Ligne 10
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 12 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 30 * sizeWallX, 12 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 31 * sizeWallX, 12 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 12 * sizeWallY);

    //Ligne 11
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 11 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 11 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 7 * sizeWallX, 11 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 8 * sizeWallX, 11 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 9 * sizeWallX, 11 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 10 * sizeWallX, 11 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 11 * sizeWallX, 11 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 11 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 11 * sizeWallY);

    //Ligne 12
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 10 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 1 * sizeWallX, 10 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 10 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 3 * sizeWallX, 10 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 10 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 10 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 10 * sizeWallY);

    //Ligne 13
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 9 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 9 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 9 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 18 * sizeWallX, 9 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 19 * sizeWallX, 9 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 9 * sizeWallY);

    //Ligne 14
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 8 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 8 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 7 * sizeWallX, 8 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 15 * sizeWallX, 8 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 16 * sizeWallX, 8 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 8 * sizeWallY);

    //Ligne 15
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 7 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 8 * sizeWallX, 7 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 7 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 28 * sizeWallX, 7 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 29 * sizeWallX, 7 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 7 * sizeWallY);

    //Ligne 16
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 1 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 3 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 4 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 5 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 10 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 11 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 6 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 6 * sizeWallY);

    //Ligne 17
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 5 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 5 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 13 * sizeWallX, 5 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 14 * sizeWallX, 5 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 15 * sizeWallX, 5 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 16 * sizeWallX, 5 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 17 * sizeWallX, 5 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 5 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 5 * sizeWallY);

    //Ligne 18
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 1 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 2 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 3 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 4 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 5 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 17 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 24 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 25 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 26 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 4 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 4 * sizeWallY);

    //Ligne 19
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 3 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 7 * sizeWallX, 3 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 8 * sizeWallX, 3 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 9 * sizeWallX, 3 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 17 * sizeWallX, 3 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 20 * sizeWallX, 3 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 3 * sizeWallY); 
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 3 * sizeWallY);

    //Ligne 20
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 10 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 13 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 14 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 28 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 29 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 30 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 31 * sizeWallX, 2 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 32 * sizeWallX, 2 * sizeWallY);

    //Ligne 21
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 1 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 1 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 1 * sizeWallY);

    //Ligne 22
    CreateWallObject(this, WallType, "Wall", 0 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 1 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 4 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 5 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 6 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 9 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 10 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 11 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, 0 * sizeWallY);
    CreateWallObject(this, WallType, "Wall", 27 * sizeWallX, 0 * sizeWallY);

    //Ligne 23 (Hors Map)
    CreateWallObject(this, WallType, "Wall", 12 * sizeWallX, -1 * sizeWallY);
}

void DefaultScene::CreateSwitch() {
    float sizeSwitch = 50.f;
    Switch::CreateSwitchObject(this, SwitchType, "Switch", 600, 1000);
}