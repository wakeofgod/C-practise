#include "BroadSword.h"
//获取基础伤害
//初始化
BroadSword::BroadSword()
{
	FileManager fm;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("./Weapon.csv", mWeaponData);
	string id = mWeaponData["2"]["weaponId"];
	this->weaponName = mWeaponData[id]["weaponName"];
	//string 转int
	this->baseDamage = atoi(mWeaponData[id]["weaponAtk"].c_str());//基础攻击力
	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str());//	暴击系数
	this->critRate = atoi(mWeaponData[id]["weaponCritRate"].c_str());//暴击几率
	this->suckPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str());//吸血系数
	this->suckRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str()); //	吸血几率
	this->frozenRate = atoi(mWeaponData[id]["weaponFrozenRate"].c_str());//冰冻几率
}

int BroadSword::getBaseDamage()
{
	return this->baseDamage;
}
//暴击效果
int BroadSword::getCrit()
{
	if (this->isTriggle(this->critRate))
	{
		return this->baseDamage* this->critPlus;
	}
	else
	{
		return 0;
	}
}
//吸血
int BroadSword::getSuckBlood()
{
	if (isTriggle(this->suckRate))
	{
		return this->baseDamage*this->suckPlus;
	}
	return 0;
}
//冰冻效果
int BroadSword::getFrozon()
{
	if (isTriggle(this->frozenRate))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//触发概率
bool BroadSword::isTriggle(int rate)
{
	int num = rand() % 100 + 1;
	if (num < rate)
	{
		return true;
	}
	return false;
}