#include <iostream>
#include "Employee.h"

Employee::Employee(int id,string name,int deptid) 
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_DeptId = deptid;
	}
	void Employee::showInfo() {
		cout << "\tְ�����:" << this->m_Id
			<< "\tְ������:" << this->m_Name
			<< "\t��λ:" << this->getDeptName()
			<< "\t��λְ��:��ɾ�����������" << endl;
	}
	string Employee::getDeptName() {
		return string("Ա��");
	}
