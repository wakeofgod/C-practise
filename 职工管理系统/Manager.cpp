#include "Manager.h"
#include <iostream>


Manager::Manager(int id, string name, int deptid)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_DeptId = deptid;
	}
	void Manager::showInfo() {
		cout << "\tְ�����:" << this->m_Id
			<< "\tְ������:" << this->m_Name
			<< "\t��λ:" << this->getDeptName()
			<< "\t��λְ��:����ϰ彻��������,�����·������Ա��" << endl;
	}
	string Manager::getDeptName() {
		return string("����");
	}
