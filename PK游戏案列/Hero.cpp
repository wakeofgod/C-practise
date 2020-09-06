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
		//是否暴击
		crit = this->pWeapon->getCrit();
		//是否吸血
		suck = this->pWeapon->getSuckBlood();
		//是否冰冻
		frozen = this->pWeapon->getFrozon();
		if (crit)
		{
			damage += crit;
			cout << "英雄的武器出发了暴击效果,怪物" << monster->monsterName << "受到了暴击伤害" << endl;
		}
		if (suck)
		{
			cout << "英雄的武器出发了吸血效果,英雄" << this->heroName << "增加血量:"<<suck << endl;
		}
		if (frozen)
		{
			cout << "英雄的武器出发了冰冻效果,怪物" << monster->monsterName << "停止攻击" << endl;
		}
		//给怪物冰冻属性赋值
		monster->isFrozen = frozen;
		//计算对怪物的真实伤害
		int trueDamage = damage - monster->monsterDef > 0 ? damage - monster->monsterDef : 1;
		this->heroHp += suck;
		monster->monsterHp -= trueDamage;
		cout << "英雄" << this->heroName << "攻击了怪物" << monster->monsterName << "造成的伤害为:" << trueDamage << endl;
	}
}
void Hero::EquipWeapon(Weapon *weapon)
{
	if (weapon == NULL)
	{
		return;
	}
	this->pWeapon = weapon;
	cout << "英雄" << this->heroName << "装备了武器" << this->pWeapon->weaponName<<"!" << endl;
}