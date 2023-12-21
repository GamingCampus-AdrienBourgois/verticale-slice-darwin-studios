#pragma once

class LaunchFunction
{
public:
	template<typename Scene>
	static void LaunchScene();

	template<typename Scene>
	static void LaunchSceneFalse();

	template<typename Scene>
	static void LaunchSceneParams(std::string params);

	static void LauchGame();

	static void resumeGame();

	
};

#include "LaunchFunction.inl"