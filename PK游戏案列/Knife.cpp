#include "Knife.h"
//��ȡ�����˺�
//��ʼ��
Knife::Knife()
{
	FileManager fm;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("./Weapon.csv", mWeaponData);
	string id = mWeaponData["1"]["weaponId"];
	this->weaponName = mWeaponData[id]["weaponName"];
	//string תint
	this->baseDamage = atoi( mWeaponData[id]["weaponAtk"].c_str());//����������
	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str());//	����ϵ��
	this->critRate = atoi(mWeaponData[id]["weaponCritRate"].c_str());//��������
	this->suckPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str());//��Ѫϵ��
	this->suckRate= atoi(mWeaponData[id]["weaponSuckRate"].c_str()); //	��Ѫ����
	this->frozenRate= atoi(mWeaponData[id]["weaponFrozenRate"].c_str());//��������
}

int Knife::getBaseDamage()
{
	return this->baseDamage;
 }
//����Ч��
int Knife::getCrit()
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
int Knife::getSuckBlood()
{
	if (isTriggle(this->suckRate))
	{
		return this->baseDamage*this->suckPlus;
	}
	return 0;
 }
//����Ч��
int Knife::getFrozon()
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
bool Knife::isTriggle(int rate)
{
	int num = rand() % 100 + 1;
	if (num < rate)
	{
		return true;
	}
	return false;
 }