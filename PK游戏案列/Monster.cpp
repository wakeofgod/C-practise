#include "Monster.h"
using namespace std;
Monster::Monster(int monsterId)
{
	FileManager fm;
	map<string, map<string, string>>mMonsterData;
	fm.loadCSVData("./Monster.csv", mMonsterData);
	string tempId = to_string(monsterId);
	string id = mMonsterData[tempId]["monsterId"];
	this->monsterName = mMonsterData[id]["monsterName"];
	this->monsterAtk =atoi( mMonsterData[id]["monsterAtk"].c_str());
	this->monsterDef = atoi(mMonsterData[id]["monsterDef"].c_str());
	this->monsterHp = atoi(mMonsterData[id]["monsterHp"].c_str());
	this->isFrozen = false;//默认未被冰冻
}
void Monster::Attack(Hero *hero)
{
	//判断怪物是否被冰冻
	if (this->isFrozen)
	{
		cout << "怪物" << this->monsterName << "被冰冻了，本回合无法攻击" << endl;
		return;
	}
	//计算对英雄伤害
	int damage = this->monsterAtk - hero->heroDef>0? this->monsterAtk - hero->heroDef:1;
	//英雄掉血
	hero->heroHp -= damage;
	cout << "怪物" << this->monsterName << "攻击了英雄" << hero->heroName << "造成的伤害为" << damage << endl;
}