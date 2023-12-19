#include "DefaultScene.h"

#include "EndLevelScene.h"

DefaultScene::DefaultScene(std::vector<Capacity> params): Scene("DefaultScene")
{
	GetBigCapacity()->SetName(params[0].GetName());
	GetMidCapacity()->SetName(params[1].GetName());
	GetSmallCapacity()->SetName(params[2].GetName());
	SpawnObjectLevel3();
	GameObject* player = CreatePlayer(PlayerType, "Player", Maths::Vector2f(window_size.x * 0.1, window_size.y * 0.68), sf::Color::Red);
}

GameObject* DefaultScene::CreateColliderObject(Scene* scene, const ObjectType& _type, std::string _name, Maths::Vector2f _position, Maths::Vector2f _size)
{
	GameObject* game_object = scene->CreateGameObject(_type, _name);
	game_object->SetPosition(_position);

	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	SquareCollider* squareCollider = game_object->CreateComponent<SquareCollider>();
	squareCollider->SetWidth(_size.x);
	squareCollider->SetHeight(_size.y);

	RectangleShapeRenderer* shapeRenderer = game_object->CreateComponent<RectangleShapeRenderer>();
	shapeRenderer->SetColor(sf::Color{255, 255, 255, 50}); // Couleur du mur
	shapeRenderer->SetSize(Maths::Vector2f(_size.x, _size.y)); // Taille du mur

	return game_object;
}

GameObject* DefaultScene::CreateSwitch(Scene* scene, const ObjectType& _type, std::string _name, const float _x, const float _y)
{
	GameObject* game_object = scene->CreateGameObject(_type, _name);
	game_object->SetPosition(Maths::Vector2f(_x, _y));

	sf::Vector2f window_size = Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize();

	SquareCollider* squareCollider = game_object->CreateComponent<SquareCollider>();
	squareCollider->SetWidth(window_size.x / 33);
	squareCollider->SetHeight(window_size.y / 22);

	RectangleShapeRenderer* shapeRenderer = game_object->CreateComponent<RectangleShapeRenderer>();
	shapeRenderer->SetColor(sf::Color{255, 0, 0, 50});
	shapeRenderer->SetSize(Maths::Vector2f(window_size.x / 33, window_size.y / 22));

	return game_object;
}

GameObject* DefaultScene::CreatePlayer(const ObjectType& _type, std::string _name, Maths::Vector2f _position, const sf::Color _color)
{
	GameObject* game_object = CreateGameObject(_type, _name);
	game_object->SetPosition(_position);

	int taille_persoX = window_size.x / 33;
	int taille_persoY = window_size.y / 22;

	SquareCollider* square_collider = game_object->CreateComponent<SquareCollider>();
	square_collider->SetWidth(taille_persoX);
	square_collider->SetHeight(taille_persoY);

	RectangleShapeRenderer* shape_renderer = game_object->CreateComponent<RectangleShapeRenderer>();
	shape_renderer->SetColor(_color);
	shape_renderer->SetSize(Maths::Vector2f(taille_persoX, taille_persoY));

	Player* player = game_object->CreateComponent<Player>();

	if (GetBigCapacity()->GetName() == "INVERSION DE LA GRaVITE")
	{
		InversionGravite* capacity = player->SetCapacity<InversionGravite>();
		capacity->SetName("InversionGravite");
		capacity->SetCapacityOwner(game_object);
	}
	else if (GetBigCapacity()->GetName() == "INVINCIbILITE")
	{
		Invincibilite* capacity = player->SetCapacity<Invincibilite>();
		capacity->SetName("Invincibilite");
		capacity->SetCapacityOwner(game_object);
	}
	else if (GetBigCapacity()->GetName() == "DOUbLE-SaUT")
	{
		DoubleJump* capacity = player->SetCapacity<DoubleJump>();
		capacity->SetName("DoubleJump");
		capacity->SetCapacityOwner(game_object);
		capacity->SetDoubleJump(true);
	}
	else if (GetBigCapacity()->GetName() == "DaSH")
	{
		Dash* capacity = player->SetCapacity<Dash>();
		capacity->SetName("Dash");
		capacity->SetCapacityOwner(game_object);
	}
	else if (GetBigCapacity()->GetName() == "fORCE")
	{
		Force* capacity = player->SetCapacity<Force>();
		capacity->SetName("Force");
		capacity->SetCapacityOwner(game_object);
	}

	return game_object;
}

void DefaultScene::SpawnObjectLevel3()
{
	sf::Vector2f window_size = sf::Vector2f(Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize().x, Engine::GetInstance()->GetModuleManager()->GetModule<WindowModule>()->GetWindowSize().y);

	SetTexture("background", "Assets/background/level_3_background-transformed.png");
	SetBackground("background");
	SetTexture("texture_livre", "Assets/Object/livre.png");
	SetTexture("texture_interrupteur", "Assets/Object/interrupteur.png");

	float sizeX = window_size.x / 100;
	float sizeY = window_size.y / 100;

	//Sol
	CreateColliderObject(this, ColliderType, "Sol", Maths::Vector2f(sizeX * 0.104167, sizeY * 90.5556), Maths::Vector2f(sizeX * 99.8437, sizeY * 0.462963));

	//Etagère + livres
	CreateColliderObject(this, ColliderType, "Etagere", Maths::Vector2f(sizeX * 4.6875, sizeY * 45.3704), Maths::Vector2f(sizeX * 15.8854, sizeY * 1.2963));
	CreateColliderObject(this, ColliderType, "Livre1", Maths::Vector2f(sizeX * 15.4687, sizeY * 34.9074), Maths::Vector2f(sizeX * 1.77083, sizeY * 10));
	CreateColliderObject(this, ColliderType, "Livre2", Maths::Vector2f(sizeX * 17.2396, sizeY * 31.1111), Maths::Vector2f(sizeX * 2.39583, sizeY * 13.8889));

	//Table de chevet
	CreateColliderObject(this, ColliderType, "Table_de_chevet", Maths::Vector2f(sizeX * 1.97917, sizeY * 74.1667), Maths::Vector2f(sizeX * 9.94792, sizeY * 18.6111));

	//Ours
	CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 25.8333, sizeY * 55.1852), Maths::Vector2f(sizeX * 2.70833, sizeY * 5.09259));
	CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 32.5, sizeY * 55.0926), Maths::Vector2f(sizeX * 3.17708, sizeY * 5.83333));

	CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 27.0833, sizeY * 56.0185), Maths::Vector2f(sizeX * 5.67708, sizeY * 12.8704));

	CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 26.875, sizeY * 68.9815), Maths::Vector2f(sizeX * 7.44792, sizeY * 6.66667));
	CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 24.8958, sizeY * 73.3333), Maths::Vector2f(sizeX * 11.6146, sizeY * 5.46296));

	CreateColliderObject(this, ColliderType, "Ours", Maths::Vector2f(sizeX * 26.4062, sizeY * 60.1852), Maths::Vector2f(sizeX * 8.38542, sizeY * 8.05556));

	//Fenêtre
	CreateColliderObject(this, ColliderType, "Fenetre", Maths::Vector2f(sizeX * 23.0729, sizeY * 50.463), Maths::Vector2f(sizeX * 18.0729, sizeY * 1.57407));
	//Livre mouvable
	CreateSpriteObject(this, MoveType, "LivreMove", Maths::Vector2f(sizeX * 39.7412, sizeY * 40.9), Maths::Vector2f(sizeX * 1.73684, sizeY * 13.7), "texture_livre", Maths::Vector2f(0, 0), Maths::Vector2f(0, 0));

	//Carton
	CreateColliderObject(this, ColliderType, "Carton", Maths::Vector2f(sizeX * 43.4375, sizeY * 79.1667), Maths::Vector2f(sizeX * 4.63542, sizeY * 14.4444));

	//Lampe
	CreateColliderObject(this, DeathType, "Lampe", Maths::Vector2f(sizeX * 51.4583, sizeY * 54.3519), Maths::Vector2f(sizeX * 6.875, sizeY * 4.62963));
	CreateColliderObject(this, DeathType, "Lampe", Maths::Vector2f(sizeX * 52.2396, sizeY * 50.5556), Maths::Vector2f(sizeX * 5.625, sizeY * 3.61111));

	//Cadre_du_bas
	CreateColliderObject(this, ColliderType, "Cadre_du_bas", Maths::Vector2f(sizeX * 64.8438, sizeY * 42.4074), Maths::Vector2f(sizeX * 10.6771, sizeY * 12.1296));

	//Cadre_du_haut
	CreateColliderObject(this, ColliderType, "Cadre_du_haut", Maths::Vector2f(sizeX * 71.0417, sizeY * 21.8519), Maths::Vector2f(sizeX * 11.5104, sizeY * 12.8704));

	//Bibliotheque
	CreateColliderObject(this, ColliderType, "Bibliotheque", Maths::Vector2f(sizeX * 85.3646, sizeY * 10), Maths::Vector2f(sizeX * 10.2604, sizeY * 79.0741));

	//Lit
	CreateColliderObject(this, ColliderType, "lit_pied_gauche", Maths::Vector2f(sizeX * 16.3021, sizeY * 85.2778), Maths::Vector2f(sizeX * 2.29167, sizeY * 8.7963));
	CreateColliderObject(this, ColliderType, "Lit_pied_droite", Maths::Vector2f(sizeX * 42.7083, sizeY * 85.2778), Maths::Vector2f(sizeX * 1.40625, sizeY * 9.25926));
	CreateColliderObject(this, ColliderType, "Lit_matelas", Maths::Vector2f(sizeX * 18.75, sizeY * 79.1667), Maths::Vector2f(sizeX * 23.9583, sizeY * 6.38889));
	CreateColliderObject(this, ColliderType, "Lit_appuis_tete", Maths::Vector2f(sizeX * 18.9062, sizeY * 68.4259), Maths::Vector2f(sizeX * 23.2292, sizeY * 1.11111));

	//Bureau
	CreateColliderObject(this, ColliderType, "Bureau", Maths::Vector2f(sizeX * 63.0729, sizeY * 71.3889), Maths::Vector2f(sizeX * 20.7292, sizeY * 2.7963));

	//Tabouret
	CreateColliderObject(this, ColliderType, "Tabouret", Maths::Vector2f(sizeX * 71.0938, sizeY * 80.463), Maths::Vector2f(sizeX * 4.53125, sizeY * 1.94444));

	//Trou de souris
	GameObject* hole = CreateColliderObject(this, ColliderType, "Trou_de_souris", Maths::Vector2f(sizeX * 96.5104, sizeY * 87.3333), Maths::Vector2f(sizeX * 2.96875, sizeY * 0.25));
	SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();

	hole->SetCallback([hole, scene_module] { scene_module->SetNextScene([scene_module] { scene_module->SetScene<EndLevelScene>(false); }); });

	//Interrupteur
	CreateSpriteObject(this, ColliderType, "Interrupteur", Maths::Vector2f(sizeX * 37.6562, sizeY * 65.9259), Maths::Vector2f(sizeX * 2.23958, sizeY * 2.22222), "texture_interrupteur", Maths::Vector2f(189, 294), Maths::Vector2f(0, 13));
}
