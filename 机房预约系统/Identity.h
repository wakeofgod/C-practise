#pragma once
#include <iostream>
#include <string>
using namespace std;

class Identity
{
public:
	//�����˵�
	virtual void openMenu() = 0;

	string mName;		//�û���
	string mPwd;		//����
};