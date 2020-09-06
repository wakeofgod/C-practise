#pragma once
#include <iostream>
using namespace std;

//武器基类
class Weapon
{
public:
	//获取基础伤害
	virtual int getBaseDamage() = 0;
	//暴击效果
	virtual int getCrit() = 0;
	//吸血
	virtual int getSuckBlood() = 0;
	//冰冻效果
	virtual int getFrozon() = 0;

	//触发概率
	virtual bool isTriggle(int rate) = 0;
public:
	int baseDamage;//基础伤害
	string weaponName;//武器名称
	int critPlus;	  //暴击系数
	int critRate;	  //暴击几率
	int suckPlus;     //吸血系数
	int suckRate;	  //吸血几率
	int frozenRate;   //冰冻几率
};