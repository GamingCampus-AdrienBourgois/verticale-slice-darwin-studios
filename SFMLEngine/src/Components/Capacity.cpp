#include "Components/Capacity.h"
#include <iostream>


void Capacity::SetName(std::string new_name)
{
	name = new_name;
}

void Capacity::SetDescription(std::string new_description)
{
	description = new_description;
}

void Capacity::SetEffect(float new_effect)
{
	effect = new_effect;
}