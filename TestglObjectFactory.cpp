#include "TestglObjectFactory.h"

#include "globject.h"
#include "glObjectDrawable.h"
#include "TeleportAnimation.h"
#include "MoveAnimation.h"
#include "SpinAnimation.h"
#include "texture.h"

#include "glob\maupa.h"

TestglObjectFactory::TestglObjectFactory()
{

	







	glObject* Axes = new glObject();



	Axes->BeginObject(GL_LINES);
	Axes->SetColor(1.0, 0.0, 0.0); // os X w kolorze czerwonym
	Axes->AddVertex(0.0, 0.0, 0.0);
	Axes->AddVertex(10.0, 0.0, 0.0);
	Axes->SetColor(0.0, 1.0, 0.0); // os Y w kolorze zielonym 
	Axes->AddVertex(0.0, 0.0, 0.0);
	Axes->AddVertex(0.0, 10.0, 0.0);
	Axes->SetColor(0.0, 0.0, 1.0); // os Z w kolorze niebieskim 
	Axes->AddVertex(0.0, 0.0, 0.0);
	Axes->AddVertex(0.0, 0.0, 10.0);
	Axes->EndObject();

	glObject* Cube = new glObject();
	glTexture* Face = new glTexture("textures\\happy.bmp");

	Cube->SetColor(1.0, 1.0, 1.0);

	// sciany prostopadle do OX
	Cube->SetNormal(1.0, 0.0, 0.0);
	Cube->BeginObject(GL_TRIANGLE_STRIP);
	Cube->AddVertex(0.5, 0.5, 0.5);
	Cube->AddVertex(0.5, -0.5, 0.5);
	Cube->AddVertex(0.5, 0.5, -0.5);
	Cube->AddVertex(0.5, -0.5, -0.5);
	Cube->EndObject();

	Cube->SetNormal(-1.0, 0.0, 0.0);
	Cube->BeginObject(GL_TRIANGLE_STRIP);
	Cube->AddVertex(-0.5, 0.5, 0.5);
	Cube->AddVertex(-0.5, -0.5, 0.5);
	Cube->AddVertex(-0.5, 0.5, -0.5);
	Cube->AddVertex(-0.5, -0.5, -0.5);
	Cube->EndObject();

	// sciany prostopadle do OY
	Cube->SetNormal(0.0, 1.0, 0.0);
	Cube->BeginObject(GL_TRIANGLE_STRIP);
	Cube->AddVertex(-0.5, 0.5, -0.5);
	Cube->AddVertex(-0.5, 0.5, 0.5);
	Cube->AddVertex(0.5, 0.5, -0.5);
	Cube->AddVertex(0.5, 0.5, 0.5);
	Cube->EndObject();

	Cube->SetNormal(0.0, -1.0, 0.0);
	Cube->BeginObject(GL_TRIANGLE_STRIP);
	Cube->AddVertex(-0.5, -0.5, -0.5);
	Cube->AddVertex(-0.5, -0.5, 0.5);
	Cube->AddVertex(0.5, -0.5, -0.5);
	Cube->AddVertex(0.5, -0.5, 0.5);
	Cube->EndObject();

	// sciany prostopadle do OZ
	Cube->SetNormal(0.0, 0.0, 1.0);
	Cube->BeginObject(GL_TRIANGLE_STRIP, Face->Bind());
	Cube->AddVertex(-0.5, 0.5, 0.5, 0.0, 1.0);
	Cube->AddVertex(-0.5, -0.5, 0.5, 0.0, 0.0);
	Cube->AddVertex(0.5, 0.5, 0.5, 1.0, 1.0);
	Cube->AddVertex(0.5, -0.5, 0.5, 1.0, 0.0);
	Cube->EndObject();

	Cube->SetNormal(0.0, 0.0, -1.0);
	Cube->BeginObject(GL_TRIANGLE_STRIP);
	Cube->AddVertex(-0.5, 0.5, -0.5, 0.0, 1.0);
	Cube->AddVertex(-0.5, -0.5, -0.5, 0.0, 0.0);
	Cube->AddVertex(0.5, 0.5, -0.5, 1.0, 1.0);
	Cube->AddVertex(0.5, -0.5, -0.5, 1.0, 0.0);
	Cube->EndObject();


	glTexture* tFloor = new glTexture("textures\\podloga.bmp");
	glObject* floor = new glObject();
	floor->BeginObject(GL_TRIANGLE_STRIP, Face->Bind());
	floor->SetColor(0.8, 0.8, 0.8);
	floor->SetNormal(0.0, 1.0, 0.0);
	floor->AddVertex(-1000.0, 0.0, -1000.0);
	floor->AddVertex(-1000.0, 0.0, 1000.0);
	floor->AddVertex(1000.0, 0.0, -1000.0);
	floor->AddVertex(1000.0, 0.0, 1000.0);
	floor->EndObject();


	Material* Cubem = new Material(1.0f, 1.0f, 1.0f, 1.0f);
	
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(2.0f, 0.0f, 2.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(4.0f, 0.0f, 2.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(6.0f, 0.0f, 2.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(8.0f, 0.0f, 2.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(10.0f, 0.0f, 2.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(12.0f, 0.0f, 2.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(14.0f, 0.0f, 2.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(16.0f, 0.0f, 2.0f), Cubem));

	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(2.0f, 0.0f, 4.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(4.0f, 0.0f, 4.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(6.0f, 0.0f, 4.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(8.0f, 0.0f, 4.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(10.0f, 0.0f, 4.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(12.0f, 0.0f, 4.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(14.0f, 0.0f, 4.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(16.0f, 0.0f, 4.0f), Cubem));

	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(2.0f, 0.0f, 6.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(4.0f, 0.0f, 6.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(6.0f, 0.0f, 6.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(8.0f, 0.0f, 6.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(10.0f, 0.0f, 6.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(12.0f, 0.0f, 6.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(14.0f, 0.0f, 6.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(16.0f, 0.0f, 6.0f), Cubem));

	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(2.0f, 0.0f, 8.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(4.0f, 0.0f, 8.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(6.0f, 0.0f, 8.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(8.0f, 0.0f, 8.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(10.0f, 0.0f, 8.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(12.0f, 0.0f, 8.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(14.0f, 0.0f, 8.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(16.0f, 0.0f, 8.0f), Cubem));

	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(2.0f, 0.0f, 10.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(4.0f, 0.0f, 10.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(6.0f, 0.0f, 10.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(8.0f, 0.0f, 10.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(10.0f, 0.0f, 10.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(12.0f, 0.0f, 10.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(14.0f, 0.0f, 10.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(16.0f, 0.0f, 10.0f), Cubem));

	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(2.0f, 0.0f, 12.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(4.0f, 0.0f, 12.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(6.0f, 0.0f, 12.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(8.0f, 0.0f, 12.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(10.0f, 0.0f, 12.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(12.0f, 0.0f, 12.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(14.0f, 0.0f, 12.0f), Cubem));
	this->mList.push_back(new glObjectDrawable(Cube, new TeleportAnimation(16.0f, 0.0f, 12.0f), Cubem));

	/*
	glObject* Obj = new glObject();
	Material* MaupaM = new Material(1.0f, 1.0f, 1.0f, 1.0f);
	//Obj->LoadFromFile("maupa.obj", "maupa.mtl", "maupa");
	Obj->LoadFromFile("kuko1.obj", "kuko1.mtl", "kuko1");

	this->mList.push_back(new glObjectDrawable(Obj, new TeleportAnimation(2.0f, 5.0f, 2.0f), MaupaM));
	this->mList.push_back(new glObjectDrawable(Obj, new SpinAnimation(1.0f, new float[]{1.0f, 0.8f, 0.2f}), MaupaM));


	this->mList.push_back(new glObjectDrawable(Axes, new TeleportAnimation(0.0f, 0.0f, 0.0f), Cubem));	
	this->mList.push_back(new glObjectDrawable(floor, new TeleportAnimation(0.0f, 0.0f, 0.0f), Cubem));



	//this->mList.push_back(new glObjectDrawable(Obj, new TeleportAnimation(2.0f, 2.0f, 2.0f)));

	glObjectAnimation* an = new SpinAnimation(1.0f, new float[]{1.0f, 0.0f, 0.0f});//, new float[]{
	an = new SpinAnimation(1.0f, new float[]{1.0f, 0.0f, 0.0f},
		glm::vec3(0.0f, 1.0f, -20.0f),
		60.0f, glm::vec3(1.0f, 0.5f, 0.1f),
		glm::vec3(1.0f, 1.0f, 1.0f));
	glm::mat4 mat = glm::translate(glm::mat4(), glm::vec3(1.0f, 1.0f, -15.f));
	//an = new SpinAnimation(1.0f, new float[]{1.0f, 0.0f, 0.0f}, mat);
	this->mList.push_back(new glObjectDrawable(Obj, an, MaupaM));

		//0.0f, 1.0f, -15.0f,
		//90.0f, 0.0f, 0.0f, 1.0f,
		//1.0f, 1.0f, 1.0f
	//});

	*/


	glObject* przek1 = new glObject();
	przek1->LoadFromFile("kuko1.obj", "kuko1.mtl", "kuko1");

	glObject* os1 = new glObject();
	os1->LoadFromFile("przegub4.obj", "przegub4.mtl", "przegub4");
	
	Material* metal = new Material(1.0f, 1.0f, 1.0f, 1.0f);

	this->mList.push_back(new glObjectDrawable(przek1, new SpinAnimation(1.0, new float[]{0.0, 1.0, 0.0},
		glm::vec3(0.0, 1.0, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f)), metal));
	
	this->mList.push_back(new glObjectDrawable(os1, new SpinAnimation(1.0, new float[]{0.0, 1.0, 0.0},
		glm::vec3(0.0, 1.0, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(30.0f, 1.45f, 1.45f)), metal));



}


TestglObjectFactory::~TestglObjectFactory()
{
}
