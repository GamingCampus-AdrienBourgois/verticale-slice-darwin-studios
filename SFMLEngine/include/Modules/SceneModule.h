#pragma once
#include <vector>

#include "Module.h"
#include "Scene.h"
#include "TimeModule.h"
#include "WindowModule.h"

class SceneModule final : public Module
{
public:
	SceneModule();
	~SceneModule() = default;

	void Start() override;
	void Render() override;
	void Update() override;

	template<typename T>
	Scene* SetScene(bool _replace_scenes = true);

	template<typename T, typename U>
	Scene* SetSceneWithParams(const bool _replace_scenes, std::vector<U> params);

	Scene* GetMainScene() const { return mainScene; }
	Scene* GetScene(const std::string& _scene_name) const;

	sf::Font GetFont() { return font; }

private:
	std::vector<Scene*> scenes;
	Scene* mainScene = nullptr;

	WindowModule* windowModule = nullptr;
	TimeModule* timeModule = nullptr;

	sf::Font font;
};

template<typename T>
Scene* SceneModule::SetScene(const bool _replace_scenes)
{
	if (_replace_scenes)
	{
		for (const Scene* scene : scenes)
		{
			delete scene;
		}
		scenes.clear();
	}

	Scene* scene = static_cast<Scene*>(new T());
	scenes.push_back(scene);

	if (_replace_scenes)
		mainScene = scene;

	return scene;
}

template<typename T, typename U>
Scene* SceneModule::SetSceneWithParams(const bool _replace_scenes, std::vector<U> params)
{
	if (_replace_scenes)
	{
		for (const Scene* scene : scenes)
		{
			delete scene;
		}
		scenes.clear();
	}

	Scene* scene = static_cast<Scene*>(new T(params));
	scenes.push_back(scene);

	if (_replace_scenes)
		mainScene = scene;

	return scene;
}
