#pragma once
#include <iostream>
#include "Weapon.h"
#include "FileManager.h"
using namespace std;

class Knife :public Weapon
{
public:
	Knife();
	//获取基础伤害
	virtual int getBaseDamage();
	//暴击效果
	virtual int getCrit();
	//吸血
	virtual int getSuckBlood();
	//冰冻效果
	virtual int getFrozon();

	//触发概率
	virtual bool isTriggle(int rate);
};