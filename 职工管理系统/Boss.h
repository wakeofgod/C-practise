#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;
class Boss :public Worker
{
public:
	Boss(int id, string name, int deptid);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ��Ϣ
	virtual string getDeptName();
};

