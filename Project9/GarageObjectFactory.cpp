#include "GarageObjectFactory.h"
#include "texture.h"
#include "glObjectDrawable.h"
#include "TeleportAnimation.h"
#include "Material.h"
#include "Color.h"

GarageObjectFactory::GarageObjectFactory()
{
	glObject* floor = new glObject();
	glTexture* Face = new glTexture("textures\\floor.bmp");


	float x = 30.0f;
	float y = 10.0f;
	float z = 20.0f;


	// sciany prostopadle do OZ
	floor->SetNormal(0.0, 1.0, 0.0);
	floor->BeginObject(GL_TRIANGLE_STRIP, Face->Bind());
	floor->AddVertex(-x, 0.0, z, 0.0, 1.0);
	floor->AddVertex(-x, 0.0, -z, 0.0, 0.0);
	floor->AddVertex(x, 0.0, z, 1.0, 1.0);
	floor->AddVertex(x, 0.0, -z, 1.0, 0.0);
	floor->EndObject();

	glObject* ceiling = new glObject();
	glTexture* ceiltex = new glTexture("textures\\ceiling.bmp");

	ceiling->SetNormal(0.0, -1.0, 0.0);
	ceiling->BeginObject(GL_TRIANGLE_STRIP, ceiltex->Bind());
	ceiling->AddVertex(-x, y, z, 0.0, 1.0);
	ceiling->AddVertex(-x, y, -z, 0.0, 0.0);
	ceiling->AddVertex(x, y, z, 1.0, 1.0);
	ceiling->AddVertex(x, y, -z, 1.0, 0.0);
	ceiling->EndObject();

	glObject* wall = new glObject();
	glTexture* walltex = new glTexture("textures\\wall.bmp");
	wall->SetNormal(0.0, 0.0, -1.0);
	wall->BeginObject(GL_TRIANGLE_STRIP, walltex->Bind());
	wall->AddVertex(-x, 0.0, z, 0.0, 1.0);
	wall->AddVertex(-x, y, z, 0.0, 0.0);
	wall->AddVertex(x, 0.0, z, 1.0, 1.0);
	wall->AddVertex(x, y, z, 1.0, 0.0);
	wall->EndObject();

	wall->SetNormal(0.0, 0.0, 1.0);
	wall->BeginObject(GL_TRIANGLE_STRIP, walltex->Bind());
	wall->AddVertex(-x, 0.0, -z, 0.0, 1.0);
	wall->AddVertex(-x, y, -z, 0.0, 0.0);
	wall->AddVertex(x, 0.0, -z, 1.0, 1.0);
	wall->AddVertex(x, y, -z, 1.0, 0.0);
	wall->EndObject();

	wall->SetNormal(-1.0, 0.0, 0);
	wall->BeginObject(GL_TRIANGLE_STRIP, walltex->Bind());
	wall->AddVertex(x, 0.0, -z, 0.0, 1.0);
	wall->AddVertex(x, y, -z, 0.0, 0.0);
	wall->AddVertex(x, 0.0, z, 1.0, 1.0);
	wall->AddVertex(x, y, z, 1.0, 0.0);
	wall->EndObject();

	wall->SetNormal(1.0, 0.0, 0);
	wall->BeginObject(GL_TRIANGLE_STRIP, walltex->Bind());
	wall->AddVertex(-x, 0.0, -z, 0.0, 1.0);
	wall->AddVertex(-x, y, -z, 0.0, 0.0);
	wall->AddVertex(-x, 0.0, z, 1.0, 1.0);
	wall->AddVertex(-x, y, z, 1.0, 0.0);
	wall->EndObject();

	/*this->mList.push_back(new glObjectDrawable(floor,
		new TeleportAnimation(0.0f, 0.0f, -15.0f),
		new Material(0.2f, 0.4f, 0.0f, 1.0f),
		new Color(new float[]{1.0f, 1.0f, 1.0f}, new float[]{1.0f, 1.0f, 1.0f}, new float[]{1.0f, 1.0f, 1.0f}
	)));
	this->mList.push_back(new glObjectDrawable(wall,
		new TeleportAnimation(0.0f, 0.0f, -15.0f),
		new Material(0.2f, 0.4f, 0.0f, 1.0f),
		new Color(new float[]{1.0f, 1.0f, 1.0f}, new float[]{1.0f, 1.0f, 1.0f}, new float[]{1.0f, 1.0f, 1.0f}
	)));
	this->mList.push_back(new glObjectDrawable(ceiling,
		new TeleportAnimation(0.0f, 0.0f, -15.0f),
		new Material(0.2f, 0.4f, 0.0f, 1.0f),
		new Color(new float[]{1.0f, 1.0f, 1.0f}, new float[]{1.0f, 1.0f, 1.0f}, new float[]{1.0f, 1.0f, 1.0f}
	)));*/





	
	
	Material* chrome = new Material(new float[]{0.25f, 0.25f, 0.25f}, new float[]{0.4f, 0.4f, 0.4f }, new float[]{0.774597f, 0.774597f, 0.774597f}, 76.8f);
	Material* plastic = new Material(new float[]{0.2125f, 0.1275f, 0.054f}, new float[]{0.714f, 0.4284f, 0.18144f}, new float[]{0.393548f, 0.271906f, 0.166721f}, 25.6f);
	Material* ruby = new Material(new float[]{0.1745f, 0.01175f, 0.01175f}, new float[]{0.61424f, 0.04136f, 0.04136f}, new float[]{0.727811f, 0.626959f, 0.626959f}, 76.8f);
	Material* rubber = new Material(new float[]{0.02f, 0.02f, 0.02f}, new float[]{0.01f, 0.01f, 0.01f}, new float[]{0.4f, 0.4f, 0.4f}, 10.0f);

	glObject* szlif = new glObject();
	szlif->LoadFromFile("odlew.obj", "odlew.mtl", "odlew");

	this->mList.push_back(new glObjectDrawable(szlif,
		new TeleportAnimation(
		new float[]{2.0f, 2.0f, -15.0f},
		new float[]{90.0f, 1.0f, 0.0f, 0.0f},
		new float[]{1.0f, 1.0f, 1.0f}),

		chrome
	));

	this->mList.push_back(new glObjectDrawable(szlif,
		new TeleportAnimation(
		new float[]{8.0f, 2.0f, -15.0f},
		new float[]{90.0f, 1.0f, 0.0f, 0.0f},
		new float[]{1.0f, 1.0f, 1.0f}),

		plastic
		));

	this->mList.push_back(new glObjectDrawable(szlif,
		new TeleportAnimation(
		new float[]{14.0f, 2.0f, -15.0f},
		new float[]{90.0f, 1.0f, 0.0f, 0.0f},
		new float[]{1.0f, 1.0f, 1.0f}),

		ruby
		));

	this->mList.push_back(new glObjectDrawable(szlif,
		new TeleportAnimation(
		new float[]{20.0f, 2.0f, -15.0f},
		new float[]{90.0f, 1.0f, 0.0f, 0.0f},
		new float[]{1.0f, 1.0f, 1.0f}),

		rubber
		));
}


GarageObjectFactory::~GarageObjectFactory()
{
}
