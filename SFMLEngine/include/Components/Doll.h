#pragma once

class Doll
{
public:
	Doll();
	~Doll();

	void SetHp(int new_hp) { hp = new_hp; }
	void SetSpeed(int new_speed) { speed = new_speed; }

	int GetHp() { return hp; }
	int GetSpeed() { return speed; }

private:
	int hp = 0;
	int speed = 0;

};

