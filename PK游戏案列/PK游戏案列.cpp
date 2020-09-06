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
	cout << "��ӭ�������µ�һ������" << endl;
	cout << "��ѡ�����Ӣ��:" << endl;
	char buf[1024];
	sprintf_s(buf, "1,%s <%s>", mHeroData["1"]["heroName"].c_str(), mHeroData["1"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf_s(buf, "2,%s <%s>", mHeroData["2"]["heroName"].c_str(), mHeroData["2"]["heroInfo"].c_str());
	cout << buf << endl;
	sprintf_s(buf, "3,%s <%s>", mHeroData["3"]["heroName"].c_str(), mHeroData["3"]["heroInfo"].c_str());
	cout << buf << endl;

	int select = 0;
	cin >> select;
	getchar();//ȡ�߻��з�
	//ʵ����Ӣ��
	Hero hero(select);
	cout << "��ѡ���Ӣ���ǣ�" << hero.heroName << endl;
	cout << "��ѡ���������" << endl;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("./Weapon.csv", mWeaponData);
	cout << "1.���ֿ�ȭ" << endl;
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
		cout << "������" << endl;
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
	//Ӣ��װ������
	hero.EquipWeapon(weapon);
	//�����һ������
	int id = 5;
	//int id = rand() % 5 + 1;
	Monster monster(id);
	int round = 1;
	while (true)
	{
		getchar();
		//system("cls");
		cout << "��ǰ�ǵ�" << round << "�غ�" << endl;
		//Ӣ�۹�������
		if (hero.heroHp <= 0)
		{
			cout << "Ӣ��" << hero.heroName << "�Ѿ�����" << endl;
			cout << "���ٽ�����" << endl;
			break;
		}
		hero.Attack(&monster);
		//���ﷴ��Ӣ��
		if (monster.monsterHp <= 0)
		{
			cout << "����" << monster.monsterName << "�Ѿ�����" << endl;
			cout << "��ϲ��Ϸ����" << endl;
			break;
		}
		monster.Attack(&hero);
		cout << "Ӣ��" << hero.heroName << "ʣ��Ѫ��Ϊ:" << hero.heroHp << endl;
		cout << "����" << monster.monsterName << "ʣ��Ѫ��Ϊ:" << monster.monsterHp << endl;
		if (hero.heroHp <= 0)
		{
			cout << "Ӣ��" << hero.heroName << "�Ѿ�����" << endl;
			cout << "���ٽ�����" << endl;
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
	//cout << "��һ��Ӣ�۵�����:" << mHeroData["1"]["heroName"] << endl;
	//cout << "�ڶ���Ӣ�۵Ĺ���:" << mHeroData["2"]["heroAtk"] << endl;
	//cout << "������Ӣ�۵�Ѫ��:" << mHeroData["3"]["heroHp"] << endl;

	//map<string, map<string, string>>mMonsterData;
	//fm.loadCSVData("./Monster.csv", mMonsterData);
	//cout << "��һ�����������:" << mMonsterData["1"]["monsterName"] << endl;

	//map<string, map<string, string>>mWeaponData;
	//fm.loadCSVData("./Weapon.csv", mWeaponData);
	//cout << "��������������Ѫ:" << mWeaponData["3"]["weaponSuckPlus"] << endl;
	//Weapon *weapon = new Knife;
	//cout << "knife��������:" << weapon->weaponName << endl;
	//cout << "knife�˺�:" << weapon->baseDamage << endl;
	//delete weapon;
	//weapon = new BroadSword;
	//cout << "knife��������:" << weapon->weaponName << endl;
	//cout << "knife�˺�:" << weapon->baseDamage << endl;
	//delete weapon;
	//weapon = new DrogonSword;
	//cout << "knife��������:" << weapon->weaponName << endl;
	//cout << "knife�˺�:" << weapon->baseDamage << endl;
	//delete weapon;
	Fighting();
	system("pause");
	return 0;
}