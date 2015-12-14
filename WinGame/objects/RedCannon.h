
#ifndef __REDCANNON_H__
#define __REDCANNON_H__

#include "BaseEnemy.h"
#include "CollisionBody.h"
#include "Bullet.h"
#include "IComponent.h"
#include "Explosion.h"
#include "../FrameWork/Animation.h"
#include "../FrameWork/StopWatch.h"
#include <map>
#include <math.h>
#include "PlayScene.h"
using namespace std;
#define CANNON_HITPOINT 3
#define CANNON_SCORE 500
#define CANNON_SHOOTING_DELAY 2000.0f
#define CANNON_ANIMATION_SPEED 0.33f
#define CANNON_APPEAR_SPEED 0.15f
class RedCannon : public BaseEnemy
{
public:
	
	RedCannon(eStatus status, GVector2 pos);
	RedCannon(eStatus status, float x, float y);
	RedCannon(eWT_Status wtstatus, GVector2 pos);
	RedCannon(eWT_Status wtstatus, float x, float y);
	RedCannon(GVector2 pos);
	~RedCannon();
	void init();
	void update(float deltatime);

	void draw(LPD3DXSPRITE spriteHandle, Viewport*);
	void release();
	void onCollisionBegin(CollisionEventArg*);
	void onCollisionEnd(CollisionEventArg*);

	void shoot();
	void drophitpoint();
	void drophitpoint(int bulletdmg);
	void setShootingAngle(float);
	float getShootingAngle();
	void setBillAngle(float);
	float getBillAngle();
	void setStatus(eStatus);
	void setStatus(eWT_Status);
	float checkCollision(BaseObject*,float);
	eWT_Status getWT_Status();

	IComponent* getComponent(string);
private:
	map<string, IComponent*> _listComponent;
	map<int, Animation*> _animation;
	BaseObject* _explosion;
	/*BaseObject* _redcannon_inactived;*/
	eWT_Status _wtstatus;

	float _shootingAngle;
	float _billAngle;
	StopWatch* _stopwatch;
	list<Bullet*> _listBullets;

	/*void initRedcannon_inactived();
	void updateRedcannon_inactived(float);*/
	void initExplosion();
	void updateExplosion(float);

	void addStatus(eStatus);
	void addStatus(eWT_Status);
	void removeStatus(eStatus);
	void removeStatus(eWT_Status);
	bool isInStatus(eStatus);
	bool isInStatus(eWT_Status);
	void calculateBillangle();
	void rangeattack();
	
};

#endif // !__REDCANNON_H__
