#include "Engine.h"

#include <imgui.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Modules/SceneModule.h"


#include <iostream>


Engine* Engine::instance = nullptr;
sf::Music Engine::music;

Engine* Engine::GetInstance()
{
	if (instance == nullptr)
		instance = new Engine();

	return instance;
}

void Engine::Init() const
{
	moduleManager->CreateDefaultModules();
	moduleManager->Init();



	if (!music.openFromFile("Assets/Sons/musique_level_3.ogg")) {
		std::cout << "La musique ne charge pas" << std::endl;
	}
	music.setLoop(true);
	music.setVolume(100.f);
	music.play();
}
 
void Engine::Run() const 
{
	moduleManager->Start();

	while (!shouldQuit)
	{
		moduleManager->Update();
		moduleManager->PreRender();
		moduleManager->Render();
		moduleManager->PostRender();
		if (moduleManager->GetModule<SceneModule>()->GetNextScene()) {
			moduleManager->GetModule<SceneModule>()->GetNextScene()();
			moduleManager->GetModule<SceneModule>()->SetNextScene([] {});
		}
	}

	moduleManager->Release();
	moduleManager->Finalize();
}


void Engine::SetMusicState(bool _state) {
	if (_state && music.getStatus() != sf::Sound::Playing)
	{
		music.stop();
		music.play();
	}
	else if (!_state && music.getStatus() == sf::SoundSource::Playing)
	{
		const float fadeDuration = 2.0f; // Durée de la diminution du volume en secondes
		const float initialVolume = music.getVolume();
		const float volumeStep = initialVolume / (fadeDuration * 60.0f); // Ajustez le pas selon vos besoins

		sf::Clock fadeClock;
		while (fadeClock.getElapsedTime().asSeconds() < fadeDuration) {
			music.setVolume(std::max(0.f, music.getVolume() - volumeStep));
			sf::sleep(sf::seconds(1.0f / 60.0f)); // Attendez 1/60e de seconde (60 FPS)
		}

		// Mettez en pause après la diminution progressive du volume
		music.pause();
		music.setVolume(initialVolume); // Assurez-vous que le volume est rétabli à sa valeur initiale
	}
	
}
