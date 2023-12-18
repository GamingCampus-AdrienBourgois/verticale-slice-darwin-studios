#include "DefaultScene.h"

void DefaultScene::SpawnObjectLevel3() {
	sf::Vector2f window_size = sf::Vector2f(Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize().x, Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize().y);

	SetTexture("background", "Assets/background/level_3_background.png");
	SetBackground("background");

	float sizeX = window_size.x / 100;
	float sizeY = window_size.y / 100;


    //Sol
    CreateColliderObject(this, ColliderType, "Etagere", Maths::Vector2f(sizeX * 0, sizeY * 98.1), Maths::Vector2f(sizeX * 101, sizeY * -0.5));

    //Etagère + livres
    CreateColliderObject(this, ColliderType, "Etagere", Maths::Vector2f(sizeX * 4.6875, sizeY * 49.33), Maths::Vector2f(sizeX * 15.875, sizeY * 1.44));
    CreateColliderObject(this, ColliderType, "Livre1", Maths::Vector2f(sizeX * 15.6316, sizeY * 37.9), Maths::Vector2f(sizeX * 1.73684, sizeY * 10.7));
    CreateColliderObject(this, ColliderType, "Livre2", Maths::Vector2f(sizeX * 17.3158, sizeY * 33.5), Maths::Vector2f(sizeX * 2.47368, sizeY * 15.1));

    //Table de chevet
    CreateColliderObject(this, ColliderType, "Table_de_chevet", Maths::Vector2f(sizeX * 1.73684, sizeY * 80.4), Maths::Vector2f(sizeX * 10.2105, sizeY * 17.1));

    //Ours
    CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 25.2105, sizeY * 79.4), Maths::Vector2f(sizeX * 11.6316, sizeY * 8.2));
    CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 26.1053, sizeY * 60.1), Maths::Vector2f(sizeX * 9.89474, sizeY * 6.1));
                                              
    CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 26.9474, sizeY * 66.1), Maths::Vector2f(sizeX * 8.1579, sizeY * 4.8));
                                              
    CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 27.4211, sizeY * 71.3), Maths::Vector2f(sizeX * 7.26316, sizeY * 2.3));
    CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 28.6842, sizeY * 74.2), Maths::Vector2f(sizeX * 5.31579, sizeY * 1.5));
                                              
    CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 27.3158, sizeY * 77.1), Maths::Vector2f(sizeX * 7.63158, sizeY * 2));
    
       

    //Fenêtre
    CreateColliderObject(this, ColliderType, "Fenetre", Maths::Vector2f(sizeX * 22.8421, sizeY * 54.7), Maths::Vector2f(sizeX * 19.2105, sizeY * 1.8));

    //Carton
    CreateColliderObject(this, ColliderType, "Carton", Maths::Vector2f(sizeX * 43.8947, sizeY * 86.6), Maths::Vector2f(sizeX * 4.73158, sizeY * 14.6));
       
    //Lampe
    CreateColliderObject(this, ColliderType, "Lampe", Maths::Vector2f(sizeX * 53.7895, sizeY * 54.2), Maths::Vector2f(sizeX * 3.52632, sizeY * 9.5));
	CreateColliderObject(this, ColliderType, "Lampe", Maths::Vector2f(sizeX * 53.1579, sizeY * 56), Maths::Vector2f(sizeX * 0.631579, sizeY * 7.7));
	CreateColliderObject(this, ColliderType, "Lampe", Maths::Vector2f(sizeX * 52.4211, sizeY * 56.6), Maths::Vector2f(sizeX * 0.684211, sizeY * 7));
	CreateColliderObject(this, ColliderType, "Lampe", Maths::Vector2f(sizeX * 52.1053, sizeY * 59.6), Maths::Vector2f(sizeX * 0.526316, sizeY * 4));
	CreateColliderObject(this, ColliderType, "Lampe", Maths::Vector2f(sizeX * 51.7895, sizeY * 61.3), Maths::Vector2f(sizeX * 0.526316, sizeY * 2.4));
	CreateColliderObject(this, ColliderType, "Lampe", Maths::Vector2f(sizeX * 57.4737, sizeY * 55.6), Maths::Vector2f(sizeX * 0.421053, sizeY * 8.2));
	CreateColliderObject(this, ColliderType, "Lampe", Maths::Vector2f(sizeX * 58.1579, sizeY * 58.2), Maths::Vector2f(sizeX * 0.631579, sizeY * 5.6));

	//Cadre_du_bas
	CreateColliderObject(this, ColliderType, "Cadre_du_bas", Maths::Vector2f(sizeX * 65.5789, sizeY * 45.9), Maths::Vector2f(sizeX * 10.7895, sizeY * 12.9));

	//Cadre_du_haut
	CreateColliderObject(this, ColliderType, "Cadre_du_haut", Maths::Vector2f(sizeX * 71.7895, sizeY * 23.7), Maths::Vector2f(sizeX * 11.6316, sizeY * 14));

	//Bibliotheque
	CreateColliderObject(this, ColliderType, "Bibliotheque", Maths::Vector2f(sizeX * 86.3158, sizeY * 10.9), Maths::Vector2f(sizeX * 10.3684, sizeY * 85.7));

	//Lit
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 19.0526, sizeY * 73.8), Maths::Vector2f(sizeX * 23.6842, sizeY * 10.6));
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 18.5789, sizeY * 86.2), Maths::Vector2f(sizeX * 0.789474, sizeY * 1.2));
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 18.2105, sizeY * 87.32), Maths::Vector2f(sizeX * 0.789474, sizeY * 1.2));
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 17.9474, sizeY * 88.3), Maths::Vector2f(sizeX * 1, sizeY * 1.1));
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 17.6842, sizeY * 89.3), Maths::Vector2f(sizeX * 1.05263, sizeY * 1.5));
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 17.3684, sizeY * 90.4), Maths::Vector2f(sizeX * 1.42105, sizeY * 1.1));
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 17.2632, sizeY * 91.3), Maths::Vector2f(sizeX * 1.15789, sizeY * 1.2));
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 17.1053, sizeY * 91.9), Maths::Vector2f(sizeX * 1.26316, sizeY * 1.5));
	CreateColliderObject(this, ColliderType, "Lit_haut", Maths::Vector2f(sizeX * 16.6316, sizeY * 92.6), Maths::Vector2f(sizeX * 2.21053, sizeY * 10));

	//Bureau
	CreateColliderObject(this, ColliderType, "Bureau", Maths::Vector2f(sizeX * 64.1053, sizeY * 77.4), Maths::Vector2f(sizeX * 20.2632, sizeY * 20.8));

	//Trou de souris
	CreateColliderObject(this, ColliderType, "Trou_de_souris", Maths::Vector2f(sizeX * 97.5789, sizeY * 91), Maths::Vector2f(sizeX * 3.05263, sizeY * 3.2));

	//Interrupteur
	CreateColliderObject(this, ColliderType, "Interrupteur", Maths::Vector2f(sizeX * 37.6316, sizeY * 71.6), Maths::Vector2f(sizeX * 2.36842, sizeY * 2));
	   

	//Bibliothèque
	//CreateColliderObject(this, ColliderType, "Wall", 20 * sizeWallX, 12 * sizeWallY);
}