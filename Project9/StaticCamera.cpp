#include "StaticCamera.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

StaticCamera::StaticCamera()
{
}


StaticCamera::~StaticCamera()
{
}

StaticCamera::StaticCamera(float eX, float eY, float eZ, 
						float cX, float cY, float cZ, 
						float uX, float uY, float uZ){
	this->mViewMatrix = glm::lookAt(
		glm::vec3(eX, eY, eZ),
		glm::vec3(cX, cY, cZ),
		glm::vec3(uX, uY, uZ)
		);
}