#pragma once
#include <iostream>
#include <string>
#include "Identity.h"
using namespace std;
#include <vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"

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
	//��������
	vector<ComputerRoom>vCom;
	//��ʼ������
	void initComputer();
};