#include "GearChangeApplication.h"
#include "KeyboardController.h"
#include "FreezeAnimation.h"
#include "TeleportAnimation.h"
#include "MoveAnimation.h"
#include "StackAnimation.h"
#include "MatrixAnimation.h"
#include "SpinAnimation.h"
#include "ClutchSpinAnimation.h"
#include "RotationAnimation.h"

GearChangeApplication::GearChangeApplication()
{
}

GearChangeApplication::GearChangeApplication(std::vector<glObjectDraw* > aL)
{
	this->mList = aL;
	this->mGear = 0;
	this->mClutch = false;

	this->mMan0 = -15.0f;
	this->mMan1 = -16.5f;
	this->mMan2 = -13.5f;
	this->mManX = 14.5f;
	this->mManY = 7.0f;
	this->mAngle = 15.0f;

}

GearChangeApplication::~GearChangeApplication()
{
}


void GearChangeApplication::AnimationFinished(std::string aC){


	if (aC == "manzero"){
		if (mGear == 1){
			glObjectAnimation* animation = new StackAnimation();
			((StackAnimation*)animation)->addAnimation(new MoveAnimation(
				new float[]{4.5f, 2.0f, -15.0f},
				new float[]{4.0f, 2.0f, -15.0f},
				1000, MoveAnimation::SMOOTH
				));
			((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
			mList[0]->setAnimation(animation);


			glObjectAnimation* manimation = new StackAnimation();
			((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
			((StackAnimation*)manimation)->addAnimation(new RotationAnimation(0.0f, -mAngle, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
			((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
			mList[17]->setAnimation(manimation);


			return;
		}

		if (mGear == 2){
			glObjectAnimation* animation = new StackAnimation();
			((StackAnimation*)animation)->addAnimation(new MoveAnimation(
				new float[]{4.5f, 2.0f, -15.0f},
				new float[]{5.0f, 2.0f, -15.0f},
				1000, MoveAnimation::SMOOTH
				));
			((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
			mList[0]->setAnimation(animation);

			glObjectAnimation* manimation = new StackAnimation();
			((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
			((StackAnimation*)manimation)->addAnimation(new RotationAnimation(0.0f, mAngle, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
			((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
			mList[17]->setAnimation(manimation);

			return;
		}

		if (mGear == 3){
			glObjectAnimation* animation = new StackAnimation();
			((StackAnimation*)animation)->addAnimation(new MoveAnimation(
				new float[]{9.5f, 2.0f, -15.0f},
				new float[]{9.0f, 2.0f, -15.0f},
				1000, MoveAnimation::SMOOTH
				));
			((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
			mList[1]->setAnimation(animation);

			glObjectAnimation* manimation = new StackAnimation();
			((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
			((StackAnimation*)manimation)->addAnimation(new RotationAnimation(0.0f, -mAngle, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
			((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
			mList[17]->setAnimation(manimation);

			return;
		}
		if (mGear == 4){
			glObjectAnimation* animation = new StackAnimation();
			((StackAnimation*)animation)->addAnimation(new MoveAnimation(
				new float[]{9.5f, 2.0f, -15.0f},
				new float[]{10.0f, 2.0f, -15.0f},
				1000, MoveAnimation::SMOOTH
				));
			((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
			mList[1]->setAnimation(animation);

			glObjectAnimation* manimation = new StackAnimation();
			((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
			((StackAnimation*)manimation)->addAnimation(new RotationAnimation(0.0f, mAngle, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
			((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
			mList[17]->setAnimation(manimation);

			return;
		}
	}
	else if (aC == "gearzero"){
		switch (mManChange)
		{
		case 01:{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{mManX, mManY, mMan0},
						new float[]{mManX, mManY, mMan1},
						1000, MoveAnimation::SMOOTH, this, "manzero"
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(animation);
					break;
		}
		case 02:{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{mManX, mManY, mMan0},
						new float[]{mManX, mManY, mMan2},
						1000, MoveAnimation::SMOOTH, this, "manzero"
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(animation);
					break;
		}
		case 10:{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{mManX, mManY, mMan1},
						new float[]{mManX, mManY, mMan0},
						1000, MoveAnimation::SMOOTH, this, "manzero"
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(animation);
					break;
		}
		case 12:{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{mManX, mManY, mMan1},
						new float[]{mManX, mManY, mMan2},
						1000, MoveAnimation::SMOOTH, this, "manzero"
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(animation);
					break;
		}
		case 20:{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{mManX, mManY, mMan2},
						new float[]{mManX, mManY, mMan0},
						1000, MoveAnimation::SMOOTH, this, "manzero"
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(animation);
					break;
		}
		case 21:{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{mManX, mManY, mMan2},
						new float[]{mManX, mManY, mMan1},
						1000, MoveAnimation::SMOOTH, this, "manzero"
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(animation);
					break;
		}
		default:
			break;
		}
	}
}



void GearChangeApplication::KeyPressed(char aKey){



	switch (aKey)
	{
	case ' ':
	{
				if (!mClutch){
					mClutch = true;
					for (int i = 4; i <= 16; i++){
						((ClutchSpinAnimation*)mList[i]->getAnimation())->Stop(1000);
					}
				}
				else{
					mClutch = false;
					for (int i = 5; i <= 14; i++){
						((ClutchSpinAnimation*)mList[i]->getAnimation())->Start(1000);
					}
					float outputSpeed;
					switch (mGear)
					{
					case 0: {outputSpeed = 0.0f; break; }
					case 1: {outputSpeed = 0.024072f; break; }
					case 2: {outputSpeed = 0.0325f; break; }
					case 3: {outputSpeed = 0.05777f; break; }
					case 4: {outputSpeed = 0.077999f; break; }
					default:
						break;
					}
					((ClutchSpinAnimation*)mList[4]->getAnimation())->setSpeed(-1.0*outputSpeed);
					((ClutchSpinAnimation*)mList[4]->getAnimation())->Start(1000);
					((ClutchSpinAnimation*)mList[15]->getAnimation())->setSpeed(outputSpeed);
					((ClutchSpinAnimation*)mList[15]->getAnimation())->Start(1000);
					((ClutchSpinAnimation*)mList[16]->getAnimation())->setSpeed(outputSpeed);
					((ClutchSpinAnimation*)mList[16]->getAnimation())->Start(1000);					
				}
				break;
	}

	case '0':
		switch (mGear)
		{
		case 0:
		{
					break;
		}
		case 1:
		{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{4.0f, 2.0f, -15.0f},
						new float[]{4.5f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[0]->setAnimation(animation);

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(-mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1, this, "gearzero"));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					mManChange = 20;
					mGear = 0;
					break;
		}
		case 2:
		{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{5.0f, 2.0f, -15.0f},
						new float[]{4.5f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[0]->setAnimation(animation);

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1, this, "gearzero"));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					mManChange = 20;
					mGear = 0;
					break;
		}
		case 3:
		{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{9.0f, 2.0f, -15.0f},
						new float[]{9.5f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[1]->setAnimation(animation);

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(-mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1, this, "gearzero"));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					mManChange = 10;
					mGear = 0;
					break;
		}
		case 4:
		{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{10.0f, 2.0f, -15.0f},
						new float[]{9.5f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[1]->setAnimation(animation);

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1, this, "gearzero"));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					mManChange = 10;
					mGear = 0;
					break;
		}
		default:
			break;
		}

		break;
	case '1':
	{
				switch (mGear)
				{
				case 0:
				{
							mGear = 1;
							mManChange = 02;
							this->AnimationFinished("gearzero");
							break;
				}
				case 1:
				{
							break;
				}
				case 2:
				{
							glObjectAnimation* animation = new StackAnimation();
							((StackAnimation*)animation)->addAnimation(new MoveAnimation(
								new float[]{5.0f, 2.0f, -15.0f},
								new float[]{4.0f, 2.0f, -15.0f},
								1000, MoveAnimation::SMOOTH
								));
							((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
							mList[0]->setAnimation(animation);

							glObjectAnimation* manimation = new StackAnimation();
							((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
							((StackAnimation*)manimation)->addAnimation(new RotationAnimation(mAngle, -mAngle, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
							((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
							mList[17]->setAnimation(manimation);
							mGear = 1;
							break;
				}
				case 3:
				{
							glObjectAnimation* animation = new StackAnimation();
							glObjectAnimation* moveAn = new MoveAnimation(
								new float[]{9.0f, 2.0f, -15.0f},
								new float[]{9.5f, 2.0f, -15.0f},
								1000, MoveAnimation::SMOOTH
								);
							((MoveAnimation*)moveAn)->setCallback("gearzero");
							((MoveAnimation*)moveAn)->addListener(this);
							((StackAnimation*)animation)->addAnimation(moveAn);
							((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
							mList[1]->setAnimation(animation);
							mGear = 1;
							mManChange = 12;

							glObjectAnimation* manimation = new StackAnimation();
							((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
							((StackAnimation*)manimation)->addAnimation(new RotationAnimation(-mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
							((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
							mList[17]->setAnimation(manimation);

							break;
				}
				case 4:
				{
							glObjectAnimation* animation = new StackAnimation();
							glObjectAnimation* moveAn = new MoveAnimation(
								new float[]{10.0f, 2.0f, -15.0f},
								new float[]{9.5f, 2.0f, -15.0f},
								1000, MoveAnimation::SMOOTH
								);
							((MoveAnimation*)moveAn)->setCallback("gearzero");
							((MoveAnimation*)moveAn)->addListener(this);
							((StackAnimation*)animation)->addAnimation(moveAn);
							((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
							mList[1]->setAnimation(animation);
							mGear = 1;
							mManChange = 12;

							glObjectAnimation* manimation = new StackAnimation();
							((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
							((StackAnimation*)manimation)->addAnimation(new RotationAnimation(mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
							((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
							mList[17]->setAnimation(manimation);

							break;
				}
				default:
					break;
				}
				break;

	}
	case '2':
	{
				switch (mGear)
				{
				case 0:
				{
							mGear = 2;
							mManChange = 02;
							this->AnimationFinished("gearzero");
							break;
				}
				case 1:
				{
							glObjectAnimation* animation = new StackAnimation();
							((StackAnimation*)animation)->addAnimation(new MoveAnimation(
								new float[]{4.0f, 2.0f, -15.0f},
								new float[]{5.0f, 2.0f, -15.0f},
								1000, MoveAnimation::SMOOTH
								));
							((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
							mList[0]->setAnimation(animation);



							glObjectAnimation* manimation = new StackAnimation();
							((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
							((StackAnimation*)manimation)->addAnimation(new RotationAnimation(-mAngle, mAngle, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
							((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
							mList[17]->setAnimation(manimation);



							mGear = 2;
							break;
				}
				case 2:
				{
							break;
				}
				case 3:
				{
							glObjectAnimation* animation = new StackAnimation();
							glObjectAnimation* moveAn = new MoveAnimation(
								new float[]{9.0f, 2.0f, -15.0f},
								new float[]{9.5f, 2.0f, -15.0f},
								1000, MoveAnimation::SMOOTH
								);
							((MoveAnimation*)moveAn)->setCallback("gearzero");
							((MoveAnimation*)moveAn)->addListener(this);
							((StackAnimation*)animation)->addAnimation(moveAn);
							((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
							mList[1]->setAnimation(animation);

							glObjectAnimation* manimation = new StackAnimation();
							((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
							((StackAnimation*)manimation)->addAnimation(new RotationAnimation(-mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
							((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
							mList[17]->setAnimation(manimation);

							mGear = 2;
							mManChange = 12;
							break;
				}
				case 4:
				{
							glObjectAnimation* animation = new StackAnimation();
							glObjectAnimation* moveAn = new MoveAnimation(
								new float[]{10.0f, 2.0f, -15.0f},
								new float[]{9.5f, 2.0f, -15.0f},
								1000, MoveAnimation::SMOOTH
								);
							((MoveAnimation*)moveAn)->setCallback("gearzero");
							((MoveAnimation*)moveAn)->addListener(this);
							((StackAnimation*)animation)->addAnimation(moveAn);
							((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
							mList[1]->setAnimation(animation);
							

							glObjectAnimation* manimation = new StackAnimation();
							((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
							((StackAnimation*)manimation)->addAnimation(new RotationAnimation(mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
							((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
							mList[17]->setAnimation(manimation);
							
							mGear = 2;
							mManChange = 12;

							break;
				}
				default:
					break;
				}

				break;
	}
	case '3':
		switch (mGear)
		{
		case 0:
		{
					mGear = 3;
					mManChange = 01;
					this->AnimationFinished("gearzero");
					break;
		}
		case 1:
		{
					glObjectAnimation* animation = new StackAnimation();
					glObjectAnimation* moveAn = new MoveAnimation(
						new float[]{4.0f, 2.0f, -15.0f},
						new float[]{4.5f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						);
					((MoveAnimation*)moveAn)->setCallback("gearzero");
					((MoveAnimation*)moveAn)->addListener(this);
					((StackAnimation*)animation)->addAnimation(moveAn);
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[0]->setAnimation(animation);

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(-mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					mGear = 3;
					mManChange = 21;
					break;
		}
		case 2:
		{
					glObjectAnimation* animation = new StackAnimation();
					glObjectAnimation* moveAn = new MoveAnimation(
						new float[]{5.0f, 2.0f, -15.0f},
						new float[]{4.5f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						);
					((MoveAnimation*)moveAn)->setCallback("gearzero");
					((MoveAnimation*)moveAn)->addListener(this);
					((StackAnimation*)animation)->addAnimation(moveAn);
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[0]->setAnimation(animation);

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					mGear = 3;
					mManChange = 21;
					break;
		}
		case 3:
		{
					break;
		}
		case 4:
		{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{10.0f, 2.0f, -15.0f},
						new float[]{9.0f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[1]->setAnimation(animation);
					mGear = 3;

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(mAngle, -mAngle, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					break;
		}
		default:
			break;
		}

		break;
	case '4':
		switch (mGear)
		{
		case 0:
		{
					mGear = 4;
					mManChange = 01;
					this->AnimationFinished("gearzero");
					break;
		}
		case 1:
		{
					glObjectAnimation* animation = new StackAnimation();
					glObjectAnimation* moveAn = new MoveAnimation(
						new float[]{4.0f, 2.0f, -15.0f},
						new float[]{4.5f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						);
					((MoveAnimation*)moveAn)->setCallback("gearzero");
					((MoveAnimation*)moveAn)->addListener(this);
					((StackAnimation*)animation)->addAnimation(moveAn);
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[0]->setAnimation(animation);

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(-mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					mGear = 4;
					mManChange = 21;
					break;
		}
		case 2:
		{
					glObjectAnimation* animation = new StackAnimation();
					glObjectAnimation* moveAn = new MoveAnimation(
						new float[]{5.0f, 2.0f, -15.0f},
						new float[]{4.5f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						);
					((MoveAnimation*)moveAn)->setCallback("gearzero");
					((MoveAnimation*)moveAn)->addListener(this);
					((StackAnimation*)animation)->addAnimation(moveAn);
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[0]->setAnimation(animation);

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan2));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(mAngle, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					mGear = 4;
					mManChange = 21;
					break;
		}
		case 3:
		{
					glObjectAnimation* animation = new StackAnimation();
					((StackAnimation*)animation)->addAnimation(new MoveAnimation(
						new float[]{9.0f, 2.0f, -15.0f},
						new float[]{10.0f, 2.0f, -15.0f},
						1000, MoveAnimation::SMOOTH
						));
					((StackAnimation*)animation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f))));
					mList[1]->setAnimation(animation);
					mGear = 4;

					glObjectAnimation* manimation = new StackAnimation();
					((StackAnimation*)manimation)->addAnimation(new TeleportAnimation(mManX, mManY, mMan1));
					((StackAnimation*)manimation)->addAnimation(new RotationAnimation(-mAngle, mAngle, glm::vec3(0.0f, 0.0f, 1.0f), 1000, 1));
					((StackAnimation*)manimation)->addAnimation(new MatrixAnimation(glm::rotate(glm::mat4(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f))));
					mList[17]->setAnimation(manimation);

					break;
		}
		case 4:
		{
					break;
		}
		default:
			break;
		}

		break;
	default:
		break;
	}
}
