#pragma once

class LaunchFunction
{
public:
	template<typename Scene>
	static void LaunchScene();

	static void LauchGame();
};

#include "LaunchFunction.inl"