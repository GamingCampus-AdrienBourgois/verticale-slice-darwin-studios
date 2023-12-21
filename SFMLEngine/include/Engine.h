#pragma once

#include "ModuleManager.h"

#include <SFML/Audio.hpp>

class Engine
{
public:
	static Engine* GetInstance();

	void Init() const;
	void Run() const;
	void Quit() { shouldQuit = true; }
	static void SetMusicState(bool _state);

	ModuleManager* GetModuleManager() const { return moduleManager; }

private:
	static Engine* instance;

	ModuleManager* moduleManager = new ModuleManager;
	static sf::Music music;

	bool shouldQuit = false;
};
