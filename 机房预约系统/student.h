#pragma once
#include <iostream>
#include <string>
#include "Identity.h"
using namespace std;

class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int mid, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int mId;
};