#pragma once
#include <iostream>
#include "Weapon.h"
#include "FileManager.h"
using namespace std;

class Knife :public Weapon
{
public:
	Knife();
	//��ȡ�����˺�
	virtual int getBaseDamage();
	//����Ч��
	virtual int getCrit();
	//��Ѫ
	virtual int getSuckBlood();
	//����Ч��
	virtual int getFrozon();

	//��������
	virtual bool isTriggle(int rate);
};