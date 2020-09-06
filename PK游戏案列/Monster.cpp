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
	this->isFrozen = false;//Ĭ��δ������
}
void Monster::Attack(Hero *hero)
{
	//�жϹ����Ƿ񱻱���
	if (this->isFrozen)
	{
		cout << "����" << this->monsterName << "�������ˣ����غ��޷�����" << endl;
		return;
	}
	//�����Ӣ���˺�
	int damage = this->monsterAtk - hero->heroDef>0? this->monsterAtk - hero->heroDef:1;
	//Ӣ�۵�Ѫ
	hero->heroHp -= damage;
	cout << "����" << this->monsterName << "������Ӣ��" << hero->heroName << "��ɵ��˺�Ϊ" << damage << endl;
}