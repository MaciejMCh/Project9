#include "PointLightsData.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "common.h"
#include "glProgram.h"

PointLightsData::PointLightsData()
{
}


PointLightsData::~PointLightsData()
{
}

void PointLightsData::addLight(PointLight* aLight){
	this->mList.push_back(aLight);
}

void PointLightsData::PassData(){

	float* colors = new float[mList.size() * 3];
	float* positions = new float[mList.size() * 3];
	float* functions = new float[mList.size() * 3];
	float* speculars = new float[mList.size()];

	for (int i = 0; i <= mList.size() - 1; i++){
		colors[i * 3] = mList[i]->getColor()[0];
		colors[(i * 3) + 1] = mList[i]->getColor()[1];
		colors[(i * 3) + 2] = mList[i]->getColor()[2];

		positions[i * 3] = mList[i]->getPosition()[0];
		positions[(i * 3) + 1] = mList[i]->getPosition()[1];
		positions[(i * 3) + 2] = mList[i]->getPosition()[2];

		functions[i * 3] = mList[i]->getFunction()[0];
		functions[(i * 3) + 1] = mList[i]->getFunction()[1];
	}

	glUniform3fv(glProgram::getInstance()->getHandle("PntLightCol"), mList.size(), colors);
	glUniform3fv(glProgram::getInstance()->getHandle("PntLightPos"), mList.size(), positions);
	glUniform3fv(glProgram::getInstance()->getHandle("PntLightFnc"), mList.size(), functions);
	glUniform1fv(glProgram::getInstance()->getHandle("PntLightSpec"), mList.size(), speculars);
	glUniform1i(glProgram::getInstance()->getHandle("PntLightCnt"), mList.size());


}