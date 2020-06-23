#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
//员工类
class Employee :public Worker 
 {
 public:
	Employee(int id,string name,int deptid);
	//显示个人信息
	virtual void showInfo() ;
	//获取岗位信息
	virtual string getDeptName();
};