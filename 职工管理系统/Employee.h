#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
//Ա����
class Employee :public Worker 
 {
 public:
	Employee(int id,string name,int deptid);
	//��ʾ������Ϣ
	virtual void showInfo() ;
	//��ȡ��λ��Ϣ
	virtual string getDeptName();
};