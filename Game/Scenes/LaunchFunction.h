#pragma once

class LaunchFunction
{
public:
	template<typename Scene>
	static void LaunchScene();

	template<typename Scene>
	static void LaunchSceneFalse();

	template<typename Scene, typename U>
	static void LaunchSceneParamsFalse(U params);

	static void LauchGame();

	static void resumeGame();

	
};

#include "LaunchFunction.inl"