#pragma once
#include "GameObject.h"
#include "Doll.h"


class Player : public Component
{
public:
	Player();
	~Player();

private:
	Doll* small_doll = nullptr;
	Doll* medium_doll = nullptr;
	Doll* big_doll = nullptr;

	Doll* actual_doll = small_doll;
};
