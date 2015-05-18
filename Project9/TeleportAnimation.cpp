#include "TeleportAnimation.h"

#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "scene.h"


TeleportAnimation::TeleportAnimation()
{
}


TeleportAnimation::~TeleportAnimation()
{
}

TeleportAnimation::TeleportAnimation(float* Pos, float *Rot, float* Scl){
	glm::mat4 model = glm::mat4();
	model = glm::translate(model, glm::vec3(Pos[0], Pos[1], Pos[2]));
	model = glm::scale(model, glm::vec3(Scl[0], Scl[1], Scl[2]));
	model = glm::rotate(model, Rot[0], glm::vec3(Rot[1], Rot[2], Rot[3]));
	this->mModelMatrix = model;
}

TeleportAnimation::TeleportAnimation(float aX, float aY, float aZ){
	this->mModelMatrix = glm::translate(glm::mat4(1.f), glm::vec3(aX, aY, aZ));
}

glm::mat4 TeleportAnimation::getModelMatrix(){
	return this->mModelMatrix;
}