#pragma once

#include <vector>
#include "SceneFeature.h"

class SceneFeaturesFactory
{
public:
	SceneFeaturesFactory();
	~SceneFeaturesFactory();

	std::vector<SceneFeature* > getFeatures();

protected:
	std::vector<SceneFeature* > mList;

};

