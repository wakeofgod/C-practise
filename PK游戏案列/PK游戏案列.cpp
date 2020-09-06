#include <iostream>

using namespace std;
#include "FileManager.h"
#include <map>
#include <string>
#include "Weapon.h"
#include "Knife.h"
#include "BroadSword.h"
#include "DragonSword.h"
#include "Hero.h"
#include "Monster.h"
#include <ctime>

void Fighting()
{
	FileManager fm;
	map<string, map<string, string>>mHeroData;
	fm.loadCSVData("./Hero.csv", mHeroData);
	cout << "欢迎来到天下第一武道大会" << endl;
	cout << "请选择你的英雄:" << endl;
	char buf[1024];
	sprintf_s(buf, "1,%s <%s>", mHeroData["1"]["heroName"].c_str(), mHeroData["1"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf_s(buf, "2,%s <%s>", mHeroData["2"]["heroName"].c_str(), mHeroData["2"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf_s(buf, "3,%s <%s>", mHeroData["3"]["heroName"].c_str(), mHeroData["3"]["heroInfo"].c_str());
	cout << buf << endl;

	int select = 0;
	cin >> select;
	getchar();//取走换行符
	//实例化英雄
	Hero hero(select);
	cout << "你选择的英雄是：" << hero.heroName << endl;
	cout << "请选择你的武器" << endl;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("./Weapon.csv", mWeaponData);
	cout << "1.赤手空拳" << endl;
	sprintf_s(buf, "2,%s", mWeaponData["1"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf_s(buf, "3,%s", mWeaponData["2"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf_s(buf, "4,%s", mWeaponData["3"]["weaponName"].c_str());
	cout << buf << endl;
	cin >> select;
	getchar();
	Weapon *weapon = NULL;
	switch (select)
	{
	case 1:
		cout << "等死吧" << endl;
	default:
		break;
	case 2:
		weapon = new Knife;
		break;
	case 3:
		weapon = new BroadSword;
		break;
	case 4:
		weapon = new DrogonSword;
		break;
	}
	//英雄装备武器
	hero.EquipWeapon(weapon);
	//随机出一个怪物
	int id = 5;
	//int id = rand() % 5 + 1;
	Monster monster(id);
	int round = 1;
	while (true)
	{
		getchar();
		//system("cls");
		cout << "当前是第" << round << "回合" << endl;
		//英雄攻击怪物
		if (hero.heroHp <= 0)
		{
			cout << "英雄" << hero.heroName << "已经阵亡" << endl;
			cout << "请再接再厉" << endl;
			break;
		}
		hero.Attack(&monster);
		//怪物反击英雄
		if (monster.monsterHp <= 0)
		{
			cout << "怪物" << monster.monsterName << "已经阵亡" << endl;
			cout << "恭喜游戏过关" << endl;
			break;
		}
		monster.Attack(&hero);
		cout << "英雄" << hero.heroName << "剩余血量为:" << hero.heroHp << endl;
		cout << "怪物" << monster.monsterName << "剩余血量为:" << monster.monsterHp << endl;
		if (hero.heroHp <= 0)
		{
			cout << "英雄" << hero.heroName << "已经阵亡" << endl;
			cout << "请再接再厉" << endl;
			break;
		}
		round++;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	//FileManager fm;
	//map<string, map<string, string>>mHeroData;
	//fm.loadCSVData("./Hero.csv", mHeroData);
	//cout << "第一个英雄的名字:" << mHeroData["1"]["heroName"] << endl;
	//cout << "第二个英雄的攻击:" << mHeroData["2"]["heroAtk"] << endl;
	//cout << "第三个英雄的血量:" << mHeroData["3"]["heroHp"] << endl;

	//map<string, map<string, string>>mMonsterData;
	//fm.loadCSVData("./Monster.csv", mMonsterData);
	//cout << "第一个怪物的名字:" << mMonsterData["1"]["monsterName"] << endl;

	//map<string, map<string, string>>mWeaponData;
	//fm.loadCSVData("./Weapon.csv", mWeaponData);
	//cout << "第三把武器的吸血:" << mWeaponData["3"]["weaponSuckPlus"] << endl;
	//Weapon *weapon = new Knife;
	//cout << "knife武器名称:" << weapon->weaponName << endl;
	//cout << "knife伤害:" << weapon->baseDamage << endl;
	//delete weapon;
	//weapon = new BroadSword;
	//cout << "knife武器名称:" << weapon->weaponName << endl;
	//cout << "knife伤害:" << weapon->baseDamage << endl;
	//delete weapon;
	//weapon = new DrogonSword;
	//cout << "knife武器名称:" << weapon->weaponName << endl;
	//cout << "knife伤害:" << weapon->baseDamage << endl;
	//delete weapon;
	Fighting();
	system("pause");
	return 0;
}