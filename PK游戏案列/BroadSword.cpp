#include "BroadSword.h"
//��ȡ�����˺�
//��ʼ��
BroadSword::BroadSword()
{
	FileManager fm;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("./Weapon.csv", mWeaponData);
	string id = mWeaponData["2"]["weaponId"];
	this->weaponName = mWeaponData[id]["weaponName"];
	//string תint
	this->baseDamage = atoi(mWeaponData[id]["weaponAtk"].c_str());//����������
	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str());//	����ϵ��
	this->critRate = atoi(mWeaponData[id]["weaponCritRate"].c_str());//��������
	this->suckPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str());//��Ѫϵ��
	this->suckRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str()); //	��Ѫ����
	this->frozenRate = atoi(mWeaponData[id]["weaponFrozenRate"].c_str());//��������
}

int BroadSword::getBaseDamage()
{
	return this->baseDamage;
}
//����Ч��
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
//��Ѫ
int BroadSword::getSuckBlood()
{
	if (isTriggle(this->suckRate))
	{
		return this->baseDamage*this->suckPlus;
	}
	return 0;
}
//����Ч��
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

//��������
bool BroadSword::isTriggle(int rate)
{
	int num = rand() % 100 + 1;
	if (num < rate)
	{
		return true;
	}
	return false;
}