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
		cout << "\tְ�����:" << this->m_Id
			<< "\tְ������:" << this->m_Name
			<< "\t��λ:" << this->getDeptName()
			<< "\t��λְ��:����˾��������" << endl;
	}
	string Boss::getDeptName() {
		return string("�ϰ�");
	}