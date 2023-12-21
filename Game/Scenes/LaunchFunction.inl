#pragma once

#include "DefaultScene.h"

template<typename Scene>
void LaunchFunction::LaunchScene() {
	SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
	scene_module->SetNextScene([scene_module] { scene_module->SetScene<Scene>(); });
}

template<typename Scene>
void LaunchFunction::LaunchSceneFalse() {
	SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();
	scene_module->SetNextScene([scene_module] { scene_module->SetScene<Scene>(false); });
}

template<typename Scene, typename U>
void LaunchFunction::LaunchSceneParamsFalse(U tempParams) {
	SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();

	std::vector<U> params;
	params.push_back(tempParams);
	scene_module->SetNextScene([scene_module, params] { scene_module->SetSceneWithParams<Scene>(false, params); });
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

inline void LaunchFunction::resumeGame() {
	SceneModule* scene_module = Engine::GetInstance()->GetModuleManager()->GetModule<SceneModule>();

	std::vector<Scene*>* scenes = scene_module->GetScenesVector();
	scene_module->SetMainScene((*scenes)[scenes->size() - 2]);
	scenes->erase(scenes->end() - 1);
}