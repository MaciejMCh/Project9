#include "glProgram.h"
#include "common.h"


#define _CRT_SECURE_NO_WARNINGS
glProgram* glProgram::mInstance = 0;

glProgram::glProgram()
{
	
}

glProgram::~glProgram()
{
}

GLuint glProgram::LoadShader(GLenum type, const char *file_name){
	// zmienna plikowa 
	FILE *fil = NULL;
	// sproboj otworzyc plik 
	fil = fopen(file_name, "rb");
	// sprawdz, czy plik sie otworzyl  
	sprintf(_msg, "Nie mozna otworzyc %s", file_name);
	if (fil == NULL)  ThrowException(_msg);

	// okresl rozmiar pliku
	fseek(fil, 0, SEEK_END);
	long int file_size = ftell(fil);
	// przewin na poczatek 
	rewind(fil);
	// utworzenie bufora na kod zrodlowy programu shadera
	GLchar *srcBuf = new GLchar[(file_size + 1)*sizeof(GLchar)];

	// przeczytanie kodu shadera z pliku 
	fread(srcBuf, 1, file_size, fil);

	// zamknij plik 
	fclose(fil);

	// tekst programu MUSI miec NULL na koncu
	srcBuf[file_size] = 0x00;

	// utworzenie obiektu shadera
	GLuint shader = glCreateShader(type);

	// przypisanie zrodla do shadera 
	glShaderSource(shader, 1, const_cast<const GLchar**>(&srcBuf), NULL);

	// sprzatanie 
	delete[] srcBuf;

	// proba skompilowania programu shadera 
	glCompileShader(shader);

	// sprawdzenie czy sie udalo 
	GLint compile_status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);

	if (compile_status != GL_TRUE) // nie udalo sie 
	{
		GLint logLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		char *log = new char[logLength];
		glGetShaderInfoLog(shader, logLength, NULL, log);
		sprintf(_msg, "Blad kompilacji pliku shadera %s", file_name);
		PrintLog(_msg);
		PrintLog(log);
		ThrowException("Blad kompilacji shadera");
		delete[]log;
	}
	else
	{
		sprintf(_msg, "Plik shadera %s skompilowany", file_name);
		PrintLog(_msg);
	}

	return shader; // zwroc id shadera 
}

void glProgram::Init(){
	GLenum err = glewInit();

	mProgram = glCreateProgram();
	if (!glIsProgram(mProgram)) { err = 1; ThrowException("Nie udalo sie utworzyc programu"); }
	mVertexShader = LoadShader(GL_VERTEX_SHADER, "vs.glsl");
	glAttachShader(mProgram, mVertexShader);

	mFragmentShader = LoadShader(GL_FRAGMENT_SHADER, "fs.glsl");
	glAttachShader(mProgram, mFragmentShader);

	// linkowanie programu 
	glLinkProgram(mProgram);

	GLint link_status;
	glGetProgramiv(mProgram, GL_LINK_STATUS, &link_status);
	if (link_status == GL_FALSE)
	{
		// pobranie i wyœwietlenie komunikatu b³êdu 
		GLint logLength;
		glGetProgramiv(mProgram, GL_INFO_LOG_LENGTH, &logLength);
		char *log = new char[logLength];
		glGetProgramInfoLog(mProgram, logLength, NULL, log);
		PrintLog(log);
		delete[] log;
		err = 1;
		ThrowException("Blad linkowania programu");
	}
	else
		PrintLog("Program zlinkowany");

	// walidowanie programu 
	glValidateProgram(mProgram);
	GLint validate_status;
	// sprawdzenie poprawnoœci walidacji obiektu programu 
	glGetProgramiv(mProgram, GL_VALIDATE_STATUS, &validate_status);
	if (validate_status == GL_FALSE)
	{
		// pobranie i wyœwietlenie komunikatu b³êdu 
		GLint logLength;
		glGetProgramiv(mProgram, GL_INFO_LOG_LENGTH, &logLength);
		char *log = new char[logLength];
		glGetProgramInfoLog(mProgram, logLength, NULL, log);
		PrintLog(log);
		delete[] log;
		err = 1;
		ThrowException("Blad walidacji programu");
	}
	else
		PrintLog("Program prawidlowy");

	glUseProgram(mProgram);
	err = 0; // ustaw flage bledu
}

glProgram* glProgram::getInstance(){
	if (mInstance == 0){
		mInstance = new glProgram();
	}
	return mInstance;
}

void glProgram::addHandle(GLchar* aName){
	this->mHandles[aName] = glGetUniformLocation(this->mProgram, aName);
}

int glProgram::getHandle(GLchar* aName){
	return this->mHandles[aName];
}