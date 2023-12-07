#include "Components/Button.h"
#include <iostream>
#include <Engine.h>
#include "Modules/SceneModule.h"


void Button::Execute() {
	if (is_clicked) {
		Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
		if (GetOwner()->GetName() == "doll_button1" && GetOwner()->GetName() == "doll_button2" && GetOwner()->GetName() == "doll_button3") {
			bool have_capacity_button = false;
			for (GameObject* const& gameObject : *scene->GetGameObjects()) {
				if (gameObject->GetName() == "capacity_button") {
					have_capacity_button = true;
					break;
				}
			}
			if (!have_capacity_button) {

			}
		}
		else if (GetOwner()->GetName() == "capacity_button") {
			scene->FindGameObject("text_for_capacity_name")->GetComponent<TextRenderer>()->SetString(GetObject()->GetName());
			scene->FindGameObject("text_for_capacity_description")->GetComponent<TextRenderer>()->SetString(GetObject()->GetDescription());
		}
	}
}


void Button::Update(const float _delta_time, std::unordered_map<sf::Keyboard::Key, bool>* pressed_input) {
	Execute();
}