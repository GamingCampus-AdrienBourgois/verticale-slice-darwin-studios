#pragma once

#include "DefaultScene.h"
#include "MapScene.h"

template<typename Scene>
void LaunchFunction::LaunchScene() {
	SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
	scene_module->SetNextScene([scene_module] { scene_module->SetScene<Scene>(); });
}

inline void LaunchFunction::LauchGame() {
	Scene* scene = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>()->GetMainScene();
	std::vector<Capacity> params;
	params.push_back(*scene->FindGameObject("doll_button1")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
	params.push_back(*scene->FindGameObject("doll_button2")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
	params.push_back(*scene->FindGameObject("doll_button3")->GetComponent<Button>()->has_select->GetComponent<Button>()->GetObject());
	SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
	scene_module->SetNextScene([scene_module, params] { scene_module->SetSceneWithParams<DefaultScene>(true, params); });
}