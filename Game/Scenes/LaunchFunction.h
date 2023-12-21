#pragma once

class LaunchFunction
{
public:
	template<typename Scene>
	static void LaunchScene();

	template<typename Scene>
	static void LaunchSceneFalse();

	static void LauchGame();

	static void resumeGame();
};

#include "LaunchFunction.inl"