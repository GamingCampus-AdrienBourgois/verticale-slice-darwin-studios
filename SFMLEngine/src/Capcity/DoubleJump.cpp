#include "Capacity/DoubleJump.h"
#include "Engine.h"
#include "Scene.h"
#include "Modules/SceneModule.h"
#include "Components/Player.h"

void DoubleJump::SetDoubleJump(bool _can_double_jump) {
	GetCapacityOwner()->GetComponent<Player>()->SetCanDoubleJump(_can_double_jump);
}