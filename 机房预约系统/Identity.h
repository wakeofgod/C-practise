#pragma once
#include <iostream>
#include <string>
using namespace std;

class Identity
{
public:
	//操作菜单
	virtual void openMenu() = 0;

	string mName;		//用户名
	string mPwd;		//密码
};