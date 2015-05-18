//--------------------------------------------------------------------------------------------
//
// File: 	scene.cpp
// Author:	P. Katarzynski (CCE)
//
// Description: Implementacja klasy sceny OpenGL
//
//--------------------------------------------------------------------------------------------
//									ZALEZNOSI 
//--------------------------------------------------------------------------------------------

#include "scene.h"

#include "TestglObjectFactory.h"
#include "GarageObjectFactory.h"
#include "TestSceneFeaturesFactory.h"
#include "glProgram.h"

#include "StaticCamera.h"
#include "FPSCamera.h"
#include "GearBoxViewCamera.h"
#include "KeyboardController.h"
#include "MouseController.h"
#include "TimerController.h"

#include "Application.h"
#include "GearChangeApplication.h"

#include "KeyListener.h"

#include "TimeMilis.h"


void Scene::Alert(char* cc){
	PrintLog(cc);
}

Scene::Scene(int new_width,int new_height)
{	
	err = 1; // ustaw flage bledu (bedzie skasowana po inicjalizacji)
	width = new_width;
	height = new_height;	
	
	
}

Scene::~Scene()
{
	if (err) return;
	// usun program przetwarzania 
	if (glIsProgram(program)) glDeleteProgram(program);
}

void Scene::PreparePrograms()
{

	glProgram::getInstance()->Init();
	glProgram::getInstance()->addHandle("modelViewMatrix");
	glProgram::getInstance()->addHandle("projectionMatrix");
	glProgram::getInstance()->addHandle("LightDirection");
	glProgram::getInstance()->addHandle("LightColor");
	glProgram::getInstance()->addHandle("LightAmbient");
	glProgram::getInstance()->addHandle("normalMatrix");
	glProgram::getInstance()->addHandle("gSampler");

	glProgram::getInstance()->addHandle("DirLightColor");
	glProgram::getInstance()->addHandle("DirLightAmp");
	glProgram::getInstance()->addHandle("DirLightDir");
	glProgram::getInstance()->addHandle("AmbLightColor");
	glProgram::getInstance()->addHandle("AmbLightAmp");

	glProgram::getInstance()->addHandle("PntLightCol");
	glProgram::getInstance()->addHandle("PntLightFnc");
	glProgram::getInstance()->addHandle("PntLightPos");
	glProgram::getInstance()->addHandle("PntLightCnt");

	glProgram::getInstance()->addHandle("ViewMatrix");
	glProgram::getInstance()->addHandle("lpos");
	glProgram::getInstance()->addHandle("ModelMatrix");
	glProgram::getInstance()->addHandle("CameraPos");

	glProgram::getInstance()->addHandle("MaterialAmbient");
	glProgram::getInstance()->addHandle("MaterialDiffuse");
	glProgram::getInstance()->addHandle("MaterialSpecular");
	glProgram::getInstance()->addHandle("MaterialShininess");

	glProgram::getInstance()->addHandle("DirLightDiff");
	glProgram::getInstance()->addHandle("DirLightSpec");

	glProgram::getInstance()->addHandle("PntLightSpec");

	glProgram::getInstance()->addHandle("DiffColor");
	glProgram::getInstance()->addHandle("SpecColor");
	glProgram::getInstance()->addHandle("AmbColor");





	
	
	program  = glCreateProgram();
	if (!glIsProgram(program)) {err = 1; ThrowException("Nie udalo sie utworzyc programu");}
	
	vertex_shader = LoadShader(GL_VERTEX_SHADER,"vs.glsl");
	glAttachShader(program,vertex_shader);

	fragment_shader = LoadShader(GL_FRAGMENT_SHADER,"fs.glsl");
	glAttachShader(program,fragment_shader);
	
	// linkowanie programu 
	glLinkProgram(program);

	GLint link_status; 
    glGetProgramiv( program, GL_LINK_STATUS, &link_status); 
    if( link_status == GL_FALSE ) 
    { 
        // pobranie i wyœwietlenie komunikatu b³êdu 
        GLint logLength; 
        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &logLength ); 
        char *log = new char[logLength]; 
        glGetProgramInfoLog( program, logLength, NULL, log ); 
        PrintLog(log);
        delete[] log; 
		err = 1;
		ThrowException("Blad linkowania programu");
    }
	else
		PrintLog("Program zlinkowany");

	// walidowanie programu 
	glValidateProgram(program); 
	GLint validate_status;
    // sprawdzenie poprawnoœci walidacji obiektu programu 
    glGetProgramiv( program, GL_VALIDATE_STATUS, &validate_status ); 
    if( validate_status == GL_FALSE ) 
    { 
        // pobranie i wyœwietlenie komunikatu b³êdu 
        GLint logLength; 
        glGetProgramiv( program, GL_INFO_LOG_LENGTH, &logLength ); 
        char *log = new char[logLength]; 
        glGetProgramInfoLog( program, logLength, NULL, log ); 
        PrintLog(log);
        delete[] log; 
		err = 1;
        ThrowException("Blad walidacji programu");
    } 
	else
		PrintLog("Program prawidlowy");
	
	glUseProgram(program);
	err = 0; // ustaw flage bledu
	
}

void Scene::PrepareObjects()
{  
	this->mSceneFeaturesFactory = new TestSceneFeaturesFactory();
	this->mObjectFactory = new TestglObjectFactory();
	//this->mObjectFactory = new GarageObjectFactory();

	//glObject::mCamera = new StaticCamera(5.0f, 0.0f, 5.0f,
	//									0.0f, 0.0f, 0.0f,
	//									0.0f, 1.0f, 0.0f);
	//FPSCamera* camera = new FPSCamera();
	GearBoxViewCamera* camera = new GearBoxViewCamera();
	glObject::mCamera = camera;
	KeyboardController::getInstance()->AddListener(camera);
	MouseController::getInstance()->addListener(camera);


	this->mSceneFeatures = mSceneFeaturesFactory->getFeatures();
	this->mObjects = mObjectFactory->getObjects();	

	KeyListener* application = new GearChangeApplication(mObjects);
	KeyboardController::getInstance()->AddListener(application);

	
}

void Scene::Resize(int new_width, int new_height)
{
	// przypisz nowe gabaryty do pol klasy 
	width = new_width;
	// uwzgledniaj obecnosc kontrolki wizualnej 
	height = new_height-100; 	
  	// rozszerz obszar renderowania do obszaru o wymiarach 'width' x 'height'
	glViewport(0, 100, width, height);	
	
	mProjection = glm::perspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,200.0f);
}

GLuint Scene::LoadShader(GLenum type,const char *file_name)
{  
  // zmienna plikowa 
  FILE *fil = NULL; 
  // sproboj otworzyc plik 
  fil = fopen(file_name,"rb");
  // sprawdz, czy plik sie otworzyl  
  sprintf(_msg,"Nie mozna otworzyc %s",file_name);
  if (fil == NULL)  ThrowException(_msg);

  // okresl rozmiar pliku
  fseek( fil, 0, SEEK_END );
  long int file_size = ftell(fil); 
  // przewin na poczatek 
  rewind(fil); 
  // utworzenie bufora na kod zrodlowy programu shadera
  GLchar *srcBuf = new GLchar[(file_size+1)*sizeof(GLchar)];

  // przeczytanie kodu shadera z pliku 
  fread(srcBuf,1,file_size,fil);

  // zamknij plik 
  fclose(fil);

  // tekst programu MUSI miec NULL na koncu
  srcBuf[file_size] = 0x00;

  // utworzenie obiektu shadera
  GLuint shader = glCreateShader(type);

  // przypisanie zrodla do shadera 
  glShaderSource(shader,1,const_cast<const GLchar**>(&srcBuf),NULL);

  // sprzatanie 
  delete[] srcBuf;

  // proba skompilowania programu shadera 
  glCompileShader(shader);

  // sprawdzenie czy sie udalo 
  GLint compile_status;
  glGetShaderiv(shader,GL_COMPILE_STATUS,&compile_status);

  if (compile_status != GL_TRUE) // nie udalo sie 
  {
	    GLint logLength; 
        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &logLength ); 
        char *log = new char[logLength]; 
        glGetShaderInfoLog( shader, logLength, NULL, log ); 
		sprintf(_msg,"Blad kompilacji pliku shadera %s",file_name);
		PrintLog(_msg);
        PrintLog(log);
		ThrowException("Blad kompilacji shadera");
	    delete []log;
  }
  else
  {
	  sprintf(_msg,"Plik shadera %s skompilowany",file_name);
	  PrintLog(_msg);
  }

  return shader; // zwroc id shadera 
}

void Scene::Init()
{
	// inicjalizacja modu³u glew
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		sprintf(_msg, "GLew error: %s\n", glewGetErrorString(err));	
		err = 1;
		ThrowException(_msg);
	}
	
	// pobierz informacje o wersji openGL 
	sprintf(_msg,"OpenGL vendor: ");
	strcat(_msg,(const char*)glGetString( GL_VENDOR ));
	PrintLog(_msg);

	sprintf(_msg,"OpenGL renderer: ");
	strcat(_msg,(const char*)glGetString( GL_RENDERER));
	PrintLog(_msg);

	sprintf(_msg,"OpenGL version: ");
	strcat(_msg,(const char*)glGetString( GL_VERSION));
	PrintLog(_msg);

	//  ustaw kolor tla sceny (RGB Z=1.0)
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	
	// przygotuj programy shaderow
	PreparePrograms();
	
	if (err) return; 

	// przygotuj obiekty do wyswietlenia 
	PrepareObjects();
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glEnable(GL_TEXTURE_2D);
}

void Scene::Animate()
{
}

void Scene::KeyPressed(unsigned char key, int x, int y) 
{            
	
	KeyboardController::getInstance()->KeyPress(key);


	if (key == 66){
		KeyboardController::getInstance()->KeyPress(65);
	}

	if (key == ESCAPE) ThrowException("Zatrzymaj program");
	switch(key)
	{
		case 37: {rot_y -= 5.0f; break;}
		case 38: {rot_x -= 5.0f; break;}
		case 39: {rot_y += 5.0f; break;}
		case 40: {rot_x += 5.0f; break;}		
		case 112: {LightAmbient += 0.1f; break;} // F1		
		case 113: {LightAmbient -= 0.1f; break;} //F2		
		
		case 114: { break;} //F3		
		case 115: { break;} //F4		

	    case 116: { break;} //F5		
		case 117: { break;} //F6		
		
		case 87: {Cam_r -= 0.5f; break;} //W
		case 83: {Cam_r += 0.5f; break;} //S		
		case 65: {Cam_angle -= 5.0f; break;} //A
		case 68: {Cam_angle += 5.0f; break;} //D
	}
	
}

void Scene::Draw()
{	
	if (err) return; // sprawdz flage bledu (np. kompilacja shadera)

	// czyscimy bufor kolorow
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUniformMatrix4fv(glProgram::getInstance()->getHandle("projectionMatrix"), 1, GL_FALSE, glm::value_ptr(mProjection));
	glUniformMatrix4fv(glProgram::getInstance()->getHandle("ViewMatrix"), 1, GL_FALSE, glm::value_ptr(glm::inverse(glObject::mCamera->getViewMatrix())));
	
	for (int i = 0; i <= this->mSceneFeatures.size() - 1; i++) mSceneFeatures[i]->PassData();
	for (int i = 0; i <= this->mObjects.size() - 1; i++) mObjects[i]->Draw();


}	