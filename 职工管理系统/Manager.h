#pragma once
#include <iostream>
#include<string>
#include "Worker.h"
using namespace std;
class Manager :public Worker
{
public:
	Manager(int id, string name, int deptid);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ��Ϣ
	virtual string getDeptName();
};