#include "FPSCamera.h"

#include "scene.h"
#include "glProgram.h"
FPSCamera::FPSCamera()
{
	this->mPosition = new float[]{0.0f, 1.0f, -5.0f};
	this->mHAngle = 0.0f;
	this->mVAngle = 0.0f;


}



FPSCamera::~FPSCamera()
{
}

glm::mat4 FPSCamera::getViewMatrix(){
	glUniform3fv(glProgram::getInstance()->getHandle("CameraPos"), 1, glm::value_ptr(glm::vec3(mPosition[0], mPosition[1], mPosition[2])));
	this->mViewMatrix = glm::lookAt(
		glm::vec3(mPosition[0], mPosition[1] ,mPosition[2] ),
		glm::vec3(mPosition[0] + sin(mHAngle), mPosition[1] + sin(mVAngle), mPosition[2] + -cos(mHAngle)),
		glm::vec3(0.0f, 0.1f, 0.0f)
		);

	return this->mViewMatrix;
}

void FPSCamera::KeyPressed(char aKey){


	switch (aKey)
	{
	case 37: {mHAngle -= 0.05f; break; }
	case 38: {mVAngle += 0.05f; break; }
	case 39: {mHAngle += 0.05f; break; }
	case 40: {mVAngle -= 0.05f; break; }
	case 112: {; break; } // F1		
	case 113: {; break; } //F2		
	case 114: { break; } //F3		
	case 115: { break; } //F4		

	case 116: { break; } //F5		
	case 117: { break; } //F6		

	case 87: {mPosition[0] += sin(mHAngle); mPosition[2] -= cos(mHAngle); break; } //W
	case 83: {mPosition[0] -= sin(mHAngle); mPosition[2] += cos(mHAngle); break; } //S		
	case 65: {mPosition[0] += sin(mHAngle + PI * 3/2); mPosition[2] -= cos(mHAngle + PI * 3/2); break; } //A
	case 68: {mPosition[0] -= sin(mHAngle-PI/2); mPosition[2] += cos(mHAngle-PI/2); break; } //D
	}
	
}