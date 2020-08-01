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
	//默认构造
	Student();
	//有参构造
	Student(int mid, string name, string pwd);
	//菜单界面
	virtual void openMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
	//学生学号
	int mId;
	//机房容器
	vector<ComputerRoom>vCom;
	//初始化机房
	void initComputer();
};