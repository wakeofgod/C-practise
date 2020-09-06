#include "Hero.h"
using namespace std;
Hero::Hero(int heroId)
{
	FileManager fm;
	map<string, map<string, string>>mHeroData;
	fm.loadCSVData("./Hero.csv", mHeroData);

	string tempId = to_string(heroId);
	string id = mHeroData[tempId]["heroId"];
	this->heroName = mHeroData[id]["heroName"];
	this->heroAtk =atoi( mHeroData[id]["heroAtk"].c_str());
	this->heroDef = atoi(mHeroData[id]["heroDef"].c_str());
	this->heroHp = atoi(mHeroData[id]["heroHp"].c_str());
	this->heroInfo = mHeroData[id]["heroInfo"];
	this->pWeapon = NULL;
}
void Hero::Attack(Monster * monster)
{
	int crit = 0;
	int suck = 0;
	int frozen = 0;
	int damage = 0;
	if (this->pWeapon == NULL)
	{
		damage = this->heroAtk;
	}
	else 
	{
		damage = this->heroAtk + this->pWeapon->getBaseDamage();
		//�Ƿ񱩻�
		crit = this->pWeapon->getCrit();
		//�Ƿ���Ѫ
		suck = this->pWeapon->getSuckBlood();
		//�Ƿ����
		frozen = this->pWeapon->getFrozon();
		if (crit)
		{
			damage += crit;
			cout << "Ӣ�۵����������˱���Ч��,����" << monster->monsterName << "�ܵ��˱����˺�" << endl;
		}
		if (suck)
		{
			cout << "Ӣ�۵�������������ѪЧ��,Ӣ��" << this->heroName << "����Ѫ��:"<<suck << endl;
		}
		if (frozen)
		{
			cout << "Ӣ�۵����������˱���Ч��,����" << monster->monsterName << "ֹͣ����" << endl;
		}
		//������������Ը�ֵ
		monster->isFrozen = frozen;
		//����Թ������ʵ�˺�
		int trueDamage = damage - monster->monsterDef > 0 ? damage - monster->monsterDef : 1;
		this->heroHp += suck;
		monster->monsterHp -= trueDamage;
		cout << "Ӣ��" << this->heroName << "�����˹���" << monster->monsterName << "��ɵ��˺�Ϊ:" << trueDamage << endl;
	}
}
void Hero::EquipWeapon(Weapon *weapon)
{
	if (weapon == NULL)
	{
		return;
	}
	this->pWeapon = weapon;
	cout << "Ӣ��" << this->heroName << "װ��������" << this->pWeapon->weaponName<<"!" << endl;
}