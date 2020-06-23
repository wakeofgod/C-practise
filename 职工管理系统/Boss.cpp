#include <iostream>
#include "Boss.h"
using namespace std;

Boss::Boss(int id, string name, int deptid)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_DeptId = deptid;
	}
	void Boss::showInfo() {
		cout << "\t职工编号:" << this->m_Id
			<< "\t职工姓名:" << this->m_Name
			<< "\t岗位:" << this->getDeptName()
			<< "\t岗位职责:管理公司所有事务" << endl;
	}
	string Boss::getDeptName() {
		return string("老板");
	}