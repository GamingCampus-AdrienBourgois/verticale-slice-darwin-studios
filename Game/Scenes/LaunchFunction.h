#pragma once
#include "Engine.h"
#include "SceneModule.h"


#include "SelectCapacityScene.h"
#include "MainMenuScene.h"
#include "CreditsScene.h"
#include "EndLevelScene.h"



class LaunchFunction {
public:
	void LaunchMainMenu() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<MainMenuScene>(); });
	}

	void LaunchCapacityMenu() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<SelectCapacityScene>(); });
	}

	void LaunchCreditsMenu() {
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module] {scene_module->SetScene<CreditsScene>(); });
	}

	void LauchGame() {
		Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
		std::vector<Capacity> params;
		params.push_back(*scene->FindGameObject("doll_button1")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		params.push_back(*scene->FindGameObject("doll_button2")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		params.push_back(*scene->FindGameObject("doll_button3")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
		SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
		scene_module->SetNextScene([scene_module, params] {scene_module->SetSceneWithParams<DefaultScene>(true, params); });
	}
};