#pragma once
#include <iostream>
#include <string>
#include "Identity.h"

using namespace std;

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int mid, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();

	int mEmpId;
};