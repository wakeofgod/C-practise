#pragma once
#include <iostream>
using namespace std;

//��������
class Weapon
{
public:
	//��ȡ�����˺�
	virtual int getBaseDamage() = 0;
	//����Ч��
	virtual int getCrit() = 0;
	//��Ѫ
	virtual int getSuckBlood() = 0;
	//����Ч��
	virtual int getFrozon() = 0;

	//��������
	virtual bool isTriggle(int rate) = 0;
public:
	int baseDamage;//�����˺�
	string weaponName;//��������
	int critPlus;	  //����ϵ��
	int critRate;	  //��������
	int suckPlus;     //��Ѫϵ��
	int suckRate;	  //��Ѫ����
	int frozenRate;   //��������
};