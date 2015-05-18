#pragma once

#ifndef _glProgram_h
#define _CRT_SECURE_NO_WARNINGS
#define _glProgram_h

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "common.h"
#include <map>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

class glProgram
{
public:
	glProgram();
	~glProgram();
	void Init();
	void addHandle(GLchar* aName);   
	int getHandle(GLchar* aName);
	static glProgram* getInstance();

protected:

	std::map <GLchar* , int> mHandles;
	//GLenum err;
	static glProgram* mInstance;
	char _msg[1024];
	int err;

	GLuint mProgram;
	GLuint mVertexShader;
	GLuint mFragmentShader;

	GLuint LoadShader(GLenum type, const char *file_name);
};

#endif