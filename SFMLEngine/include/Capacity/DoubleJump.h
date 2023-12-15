#pragma once
#include "Capacity.h"

class DoubleJump : public Capacity {
public:
	void SetDoubleJump(bool _can_double_jump);

	void SetJump(bool new_bool) { secondJump = new_bool; }
	bool GetJump() { return secondJump; }

private:
	bool secondJump = false;
};