#include "TestSceneFeaturesFactory.h"

#include "AmbientLight.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "PointLightsData.h"

TestSceneFeaturesFactory::TestSceneFeaturesFactory()
{
	this->mList.push_back(new AmbientLight(new float[]{1.0f, 1.0f, 1.0f}, 0.5));
	this->mList.push_back(new DirectionalLight(
		new float[]{-0.3f, 0.0f, -1.0f},
		new float[]{1.0f, 1.0f, 1.0f},
		0.8f, 1.0f, 1.0f
		));


	
	PointLightsData* lightsData = new PointLightsData();
	lightsData->addLight(new PointLight(new float[]{1.0f, 216.0f/255.0f, 93.0f/255.0f}, new float[]{10.0f, 1.0f, -1.0f}, new float[]{1.0f, 1.0f}, 0.3f));
	lightsData->addLight(new PointLight(new float[]{1.0f, 210.0f/255.0f, 48.0f/255.0f}, new float[]{-10.0f, 1.0f, -30.0f}, new float[]{1.0f, 1.0f}, 0.3f));
	//lightsData->addLight(new PointLight(new float[]{1,1,1}, new float[]{10.0f, 1.0f, -1.0f}, new float[]{1.0f, 1.0f}, 1.0f));
	//lightsData->addLight(new PointLight(new float[]{1,1,1}, new float[]{-10.0f, 1.0f, -30.0f}, new float[]{1.0f, 1.0f}, 1.0f));

	this->mList.push_back(lightsData);
}


TestSceneFeaturesFactory::~TestSceneFeaturesFactory()
{
}
