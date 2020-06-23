#pragma once
#include <iostream>
using namespace std;
#include <string>
//职工抽象基类
class Worker 
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位信息
	virtual string getDeptName() = 0;
public:
	int m_Id;
	string m_Name;
	int m_DeptId;
};
