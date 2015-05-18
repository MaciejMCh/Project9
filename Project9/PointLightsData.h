#pragma once
#include "SceneFeature.h"

#include "PointLight.h"
#include <vector>

class PointLightsData :
	public SceneFeature
{
public:
	PointLightsData();
	~PointLightsData();
	virtual void PassData();
	void addLight(PointLight* aLight);

protected:
	std::vector<PointLight* > mList;

};

