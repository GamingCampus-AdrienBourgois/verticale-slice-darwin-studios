#pragma once

class Doll
{
public:
	void SetHp(int new_hp) { hp = new_hp; }
	void SetSpeed(int new_speed) { speed = new_speed; }

	int GetHp() { return hp; }
	int GetSpeed() { return speed; }
	int GetGravity() { return gravity; }

private:
	int hp = 0;
	int speed = 100;
	int gravity = 100;
};

