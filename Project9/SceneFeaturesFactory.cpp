#include "SceneFeaturesFactory.h"


SceneFeaturesFactory::SceneFeaturesFactory()
{
}


SceneFeaturesFactory::~SceneFeaturesFactory()
{
}

std::vector<SceneFeature* > SceneFeaturesFactory::getFeatures(){
	return this->mList;
}