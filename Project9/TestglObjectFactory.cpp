#include "TestglObjectFactory.h"

#include "globject.h"
#include "glObjectDrawable.h"
#include "TeleportAnimation.h"
#include "MoveAnimation.h"
#include "SpinAnimation.h"
#include "ClutchSpinAnimation.h"
#include "MatrixAnimation.h"
#include "texture.h"
#include "glObjectDrawableComposite.h"
#include "StackAnimation.h"

#include "glob\maupa.h"
#include "glob\kuko.h"

TestglObjectFactory::TestglObjectFactory()
{









	


	Material* chrome = new Material(new float[]{0.25f, 0.25f, 0.25f}, new float[]{0.4f, 0.4f, 0.4f }, new float[]{0.774597f, 0.774597f, 0.774597f}, 76.8f);
	Material* plastic = new Material(new float[]{0.0f, 0.0f, 0.0f}, new float[]{0.01f, 0.01f, 0.01f}, new float[]{0.5f, 0.5f, 0.5f}, 10.0f);
	Material* bronze = new Material(new float[]{0.2125f, 0.1275f, 0.054f}, new float[]{0.714f, 0.4284f, 0.18144f}, new float[]{0.393548f, 0.271906f, 0.166721f}, 25.6f);
	Material* ruby = new Material(new float[]{0.1745f, 0.01175f, 0.01175f}, new float[]{0.61424f, 0.04136f, 0.04136f}, new float[]{0.727811f, 0.626959f, 0.626959f}, 76.8f);
	Material* rubber = new Material(new float[]{0.02f, 0.02f, 0.02f}, new float[]{0.01f, 0.01f, 0.01f}, new float[]{0.4f, 0.4f, 0.4f}, 10.0f);
	Material* metal_lakier = new Material(new float[]{0.01f, 0.01f, 0.01f}, new float[]{0.8f, 0.8f, 0.8f}, new float[]{5.8f, 5.8f, 5.8f}, 200.0f);
	Material* gold = new Material(new float[]{0.24725f, 0.1995f, 0.0745f}, new float[]{0.75164f, 0.60648f, 0.22648f}, new float[]{0.628281f, 0.555802f, 0.366065f}, 51.2f);
	Material* tin = new Material(new float[]{ 0.105882f, 0.058824f, 0.113725f, 1.0f }, new float[]{ 0.427451f, 0.470588f, 0.541176f, 1.0f }, new float[]{ 0.333333f, 0.333333f, 0.521569f, 1.0f }, 9.84615f);
	

	Material* gearfill = plastic;
	Material* gearfield = metal_lakier;
	Material* shaftmat = chrome;
	Material* blockgearmat = plastic;

	
	glObject* gear90_corp_i = new glObject();
	gear90_corp_i->LoadFromFile("gear90_corp_i.obj", "gear90_corp_i.mtl", "gear90_corp_i");
	glObject* gear90_corp_o = new glObject();
	gear90_corp_o->LoadFromFile("gear90_corp_o.obj", "gear90_corp_o.mtl", "gear90_corp_o");

	glObject* gear110_corp_i = new glObject();
	gear110_corp_i->LoadFromFile("gear110_corp_i.obj", "gear110_corp_i.mtl", "gear110_corp_i");
	glObject* gear110_corp_o = new glObject();
	gear110_corp_o->LoadFromFile("gear110_corp_o.obj", "gear110_corp_o.mtl", "gear110_corp_o");

	glObject* gear120_corp_i = new glObject();
	gear120_corp_i->LoadFromFile("gear120_corp_i.obj", "gear120_corp_i.mtl", "gear120_corp_i");
	glObject* gear120_corp_o = new glObject();
	gear120_corp_o->LoadFromFile("gear120_corp_o.obj", "gear120_corp_o.mtl", "gear120_corp_o");

	glObject* gear140_corp_i = new glObject();
	gear140_corp_i->LoadFromFile("gear140_corp_i.obj", "gear140_corp_i.mtl", "gear140_corp_i");
	glObject* gear140_corp_o = new glObject();
	gear140_corp_o->LoadFromFile("gear140_corp_o.obj", "gear140_corp_o.mtl", "gear140_corp_o");

	glObject* gear150_corp_i = new glObject();
	gear150_corp_i->LoadFromFile("gear150_corp_i.obj", "gear150_corp_i.mtl", "gear150_corp_i");
	glObject* gear150_corp_o = new glObject();
	gear150_corp_o->LoadFromFile("gear150_corp_o.obj", "gear150_corp_o.mtl", "gear150_corp_o");

	glObject* gear170_corp_i = new glObject();
	gear170_corp_i->LoadFromFile("gear170_corp_i.obj", "gear170_corp_i.mtl", "gear170_corp_i");
	glObject* gear170_corp_o = new glObject();
	gear170_corp_o->LoadFromFile("gear170_corp_o.obj", "gear170_corp_o.mtl", "gear170_corp_o");




	glObject* tooth = new glObject();
	tooth->LoadFromFile("tooth.obj", "tooth.mtl", "tooth");

	glObject* blockgear = new glObject();
	blockgear->LoadFromFile("blockgear.obj", "blockgear.mtl", "blockgear");

	glObject* neggear = new glObject();
	neggear->LoadFromFile("neggear.obj", "neggear.mtl", "neggear");

	glObject* blockgearpart = new glObject();
	blockgearpart->LoadFromFile("blockgearpart.obj", "blockgearpart.mtl", "blockgearpart");

	glObject* countershaft = new glObject();
	countershaft->LoadFromFile("coutnershaft.obj", "coutnershaft.mtl", "coutnershaft");
	glObject* inputshaft = new glObject();
	inputshaft->LoadFromFile("inputshaft.obj", "inputshaft.mtl", "inputshaft");
	glObject* outputshaft = new glObject();
	outputshaft->LoadFromFile("outputshaft.obj", "outputshaft.mtl", "outputshaft");


	glObject* pad = new glObject();
	pad->LoadFromFile("pad.obj", "pad.mtl", "pad");

	glObject* manipulator = new glObject();
	manipulator->LoadFromFile("manipulator.obj", "manipulator.mtl", "manipulator");


	glObject* propeller = new glObject;
	propeller->LoadFromFile("propeller.obj", "propeller.mtl", "propeller");
	glObject* manipulator_metal = new glObject();
	manipulator_metal->LoadFromFile("manipulator_metal.obj", "manipulator_metal.mtl", "manipulator_metal");

	glObject* manipulator_rubber = new glObject();
	manipulator_rubber->LoadFromFile("manipulator_rubber.obj", "manipulator_rubber.mtl", "manipulator_rubber");

	glObjectDrawableComposite* blockgear1 = new glObjectDrawableComposite(new TeleportAnimation(
		new float[]{4.5f, 2.0f, -15.0f},
		new float[]{90.0f, 0.0f, 0.0f, 1.0f},
		new float[]{1.0f, 1.0f, 1.0f}));
	((glObjectDrawableComposite*)blockgear1)->addDrawable(new glObjectDrawable(neggear, new TeleportAnimation(0.0f, 0.0f, 0.0f), bronze));
	((glObjectDrawableComposite*)blockgear1)->addDrawable(new glObjectDrawable(blockgearpart, new TeleportAnimation(
		new float[]{0.0f, 0.0f, 0.0f},
		new float[]{-30.f, 0.0f, 1.0f, 0.0f},
		new float[]{1.0f, 1.0f, 1.0f}), 
		ruby));
	((glObjectDrawableComposite*)blockgear1)->addDrawable(new glObjectDrawable(countershaft, new TeleportAnimation(
		new float[]{2.8068f, -4.67f, 1.6208f},
		new float[]{0.0f, 1.0f, 0.0f, 0.0f},
		new float[]{1.0f, 0.5f, 1.0f}),
		//new float[]{1,1,1}),
		ruby));
	glObjectAnimation* an2 = new StackAnimation();
	((StackAnimation*)an2)->addAnimation(new MatrixAnimation(glm::translate(glm::mat4(), glm::vec3(3.1f, -10.0f, 1.6208f))));
	((StackAnimation*)an2)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f))));
	((StackAnimation*)an2)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
	((glObjectDrawableComposite*)blockgear1)->addDrawable(new glObjectDrawable(pad, an2, gold));	

	glObjectDrawableComposite* blockgear2 = new glObjectDrawableComposite(new TeleportAnimation(
		new float[]{9.5f, 2.0f, -15.0f},
		new float[]{90.0f, 0.0f, 0.0f, 1.0f},
		new float[]{1.0f, 1.0f, 1.0f}));
	((glObjectDrawableComposite*)blockgear2)->addDrawable(new glObjectDrawable(neggear, new TeleportAnimation(0.0f, 0.0f, 0.0f), bronze));
	((glObjectDrawableComposite*)blockgear2)->addDrawable(new glObjectDrawable(blockgearpart, new TeleportAnimation(
		new float[]{0.0f, 0.0f, 0.0f},
		new float[]{30.f, 0.0f, 1.0f, 0.0f},
		new float[]{1.0f, 1.0f, 1.0f}),
		ruby));
	((glObjectDrawableComposite*)blockgear2)->addDrawable(new glObjectDrawable(countershaft, new TeleportAnimation(
		new float[]{2.8068f, -2.24f, -1.6208f},
		new float[]{0.0f, 1.0f, 0.0f, 0.0f},
		new float[]{1.0f, 0.24f, 1.0f}),
		//new float[]{1, 1, 1}),
		ruby));
	glObjectAnimation* an = new StackAnimation();
	((StackAnimation*)an)->addAnimation(new MatrixAnimation(glm::translate(glm::mat4(), glm::vec3(3.1f, -5.0f, -1.6208f))));
	((StackAnimation*)an)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(),90.0f, glm::vec3(0.0f, 1.0f, 0.0f))));
	((StackAnimation*)an)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
	((glObjectDrawableComposite*)blockgear2)->addDrawable(new glObjectDrawable(pad, an,	gold));
	

	this->mList.push_back(blockgear1);
	this->mList.push_back(blockgear2);


	this->mList.push_back(new glObjectDrawable(countershaft,
		new SpinAnimation(1.0f, new float[]{0.0, 1.0f, 0.0},
		glm::vec3(5.5, -0.9, -15),
		90.0f, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0, 1.0, 1.0))
		, shaftmat
		));

	this->mList.push_back(new glObjectDrawable(inputshaft, new SpinAnimation(1.0f, new float[]{0.0, 1.0f, 0.0},
		glm::vec3(-2.0, 2, -15),
		90.0f, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0, 1.0, 1.0))
		, shaftmat
		));

	glObjectDrawableComposite* outputs = new glObjectDrawableComposite(new ClutchSpinAnimation(0.0f, new float[]{0.0, 1.0f, 0.0},
		glm::vec3(10.5, 2.0, -15),
		90.0f, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0, 1.0, 1.0)));
	((glObjectDrawableComposite*)outputs)->addDrawable(new glObjectDrawable(outputshaft, 
		//new TeleportAnimation(new float[]{0, 0, 0}, new float[]{ 0, 0, 0 }, new float[]{1,1,1})
		new MatrixAnimation(glm::mat4())
		, shaftmat));
	((glObjectDrawableComposite*)outputs)->addDrawable(new glObjectDrawable(propeller, new TeleportAnimation(new float[]{0, -10.0f, 0}, new float[]{180.0f, 1, 0, 0}, new float[]{1, 1, 1}), chrome));
	this->mList.push_back(outputs);


	int n;
	float r, da;
	glObjectAnimation* ani;

	glObjectDraw* gear120 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.05f, new float[]{0.0f, -1.0f, 0.0f},
		glm::vec3(0.0, 2.0, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 33;
	r = 1.3f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear120)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
	}
	((glObjectDrawableComposite*)gear120)->addDrawable(new glObjectDrawable(gear120_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear120)->addDrawable(new glObjectDrawable(gear120_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));

	this->mList.push_back(gear120);

	glObjectDraw* gear140 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.043333f, new float[]{0.0f, 1.0f, 0.0f},
		glm::vec3(0.0, -0.9, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 38;
	r = 1.5f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear140)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
	}
	((glObjectDrawableComposite*)gear140)->addDrawable(new glObjectDrawable(gear140_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear140)->addDrawable(new glObjectDrawable(gear140_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	this->mList.push_back(gear140);

	glObjectDraw* gear90 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.043333f, new float[]{0.0f, 1.0f, 0.0f},
		glm::vec3(3.0, -0.9, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 25;
	r = 1.0f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear90)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
	}
	((glObjectDrawableComposite*)gear90)->addDrawable(new glObjectDrawable(gear90_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear90)->addDrawable(new glObjectDrawable(gear90_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	this->mList.push_back(gear90);



	glObjectDraw* gear170 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.024072f, new float[]{0.0f, -1.0f, 0.0f},
		glm::vec3(3.0, 2, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 47;
	r = 1.8f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear170)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
	}
	((glObjectDrawableComposite*)gear170)->addDrawable(new glObjectDrawable(gear170_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear170)->addDrawable(new glObjectDrawable(gear170_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	((glObjectDrawableComposite*)gear170)->addDrawable(new glObjectDrawable(blockgear, new TeleportAnimation(0.0f, -0.5f, 0.0f), blockgearmat));
	this->mList.push_back(gear170);


	
	glObjectDraw* gear110 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.043333f, new float[]{0.0f, 1.0f, 0.0f},
		glm::vec3(6.0, -0.9, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
	);
	n = 31;
	r = 1.2f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n-1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear110)->addDrawable(new glObjectDrawable(tooth, ani , metal_lakier));
	}
	((glObjectDrawableComposite*)gear110)->addDrawable(new glObjectDrawable(gear110_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear110)->addDrawable(new glObjectDrawable(gear110_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	this->mList.push_back(gear110);

	
	

	
	glObjectDraw* gear150 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.0325f, new float[]{0.0f, -1.0f, 0.0f},
		glm::vec3(6.0, 2.0, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 42;
	r = 1.6f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear150)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
		((glObjectDrawableComposite*)gear150)->addDrawable(new glObjectDrawable(blockgear, new TeleportAnimation(0.0f, 0.5f, 0.0f), blockgearmat));
	}
	((glObjectDrawableComposite*)gear150)->addDrawable(new glObjectDrawable(gear150_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear150)->addDrawable(new glObjectDrawable(gear150_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	this->mList.push_back(gear150);

	
	glObjectDraw* gear110_2 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.05777f, new float[]{0.0f, -1.0f, 0.0f},
		glm::vec3(8.0, 2.0, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 31;
	r = 1.2f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear110_2)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
		((glObjectDrawableComposite*)gear110_2)->addDrawable(new glObjectDrawable(blockgear, new TeleportAnimation(0.0f, -0.5f, 0.0f), blockgearmat));
	}
	((glObjectDrawableComposite*)gear110_2)->addDrawable(new glObjectDrawable(gear110_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear110_2)->addDrawable(new glObjectDrawable(gear110_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	this->mList.push_back(gear110_2);





	glObjectDraw* gear150_2 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.043333f, new float[]{0.0f, 1.0f, 0.0f},
		glm::vec3(8.0, -0.9, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 42;
	r = 1.6f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear150_2)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
	}
	((glObjectDrawableComposite*)gear150_2)->addDrawable(new glObjectDrawable(gear150_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear150_2)->addDrawable(new glObjectDrawable(gear150_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	this->mList.push_back(gear150_2);




	glObjectDraw* gear90_2 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.077999f, new float[]{0.0f, -1.0f, 0.0f},
		glm::vec3(11.0, 2.0, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 25;
	r = 1.0f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear90_2)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
	}
	((glObjectDrawableComposite*)gear90_2)->addDrawable(new glObjectDrawable(gear90_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear90_2)->addDrawable(new glObjectDrawable(gear90_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	((glObjectDrawableComposite*)gear90_2)->addDrawable(new glObjectDrawable(blockgear, new TeleportAnimation(0.0f, 0.5f, 0.0f), blockgearmat));
	this->mList.push_back(gear90_2);



	glObjectDraw* gear170_2 = new glObjectDrawableComposite(
		new ClutchSpinAnimation(0.043333f, new float[]{0.0f, 1.0f, 0.0f},
		glm::vec3(11.0, -0.9, -15.0),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f))
		);
	n = 47;
	r = 1.8f;
	da = 2 * (float)PI / n;
	for (int i = 0; i <= n - 1; i++){
		ani = new StackAnimation();
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(r*sin(da*i), 0.0f, r*cos(da*i)));
		((StackAnimation*)ani)->addAnimation(new TeleportAnimation(new float[]{0.0f, 0.0f, 0.0f}, new float[]{i*da*180.0f / (float)PI + 180.0f, 0.0f, 1.0, 0.0}, new float[]{1.0f, 1.0f, 1.0f}));
		((glObjectDrawableComposite*)gear170_2)->addDrawable(new glObjectDrawable(tooth, ani, metal_lakier));
	}
	((glObjectDrawableComposite*)gear170_2)->addDrawable(new glObjectDrawable(gear170_corp_i, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfill));
	((glObjectDrawableComposite*)gear170_2)->addDrawable(new glObjectDrawable(gear170_corp_o, new TeleportAnimation(0.0f, 0.0f, 0.0f), gearfield));
	this->mList.push_back(gear170_2);





	this->mList.push_back(new glObjectDrawable(blockgear, new ClutchSpinAnimation(0.0f, new float[]{0.0f, -1.0f, 0.0f},
		glm::vec3(4.5f, 2.0f, -15.0f),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f)),
		blockgearmat));

	this->mList.push_back(new glObjectDrawable(blockgear, new ClutchSpinAnimation(0.0f, new float[]{0.0f, -1.0, 0.0f},
		glm::vec3(9.5f, 2.0f, -15.0f),
		90.0, glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(1.0f, 1.0f, 1.0f)),
		blockgearmat));

	
	



	


	glObjectAnimation* man = new StackAnimation();
	((StackAnimation*)man)->addAnimation(new MatrixAnimation(glm::translate(glm::mat4(), glm::vec3(14.5f, 7.0f, -15.0f))));
	((StackAnimation*)man)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
	
	
	
	glObjectDrawableComposite* manipulator_c = new glObjectDrawableComposite(man);
	((glObjectDrawableComposite*)manipulator_c)->addDrawable(new glObjectDrawable(manipulator_metal, new MatrixAnimation(glm::mat4()), chrome));
	((glObjectDrawableComposite*)manipulator_c)->addDrawable(new glObjectDrawable(manipulator_rubber, new MatrixAnimation(glm::mat4()), rubber));
	
	this->mList.push_back(manipulator_c);
}


TestglObjectFactory::~TestglObjectFactory()
{
}
