#pragma once
#include "Capacity.h"

class DoubleJump : public Capacity {
public:
	~DoubleJump();

	void SetDoubleJump(bool _can_double_jump);
};