#include <iostream>
#include <string>
#include "manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string pwd)
{
	this->mName = name;
	this->mPwd = pwd;

	//��ʼ������
	this->initVector();
}
//ѡ��˵�
void Manager::openMenu()
{
	cout << "��ӭ����Ա:" << this->mName << "��¼!" << endl;
	cout << "\t\t----------------------|" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		1.����˺�		   |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		2.�鿴�˺�	   |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		3.�鿴����	   |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		4.���ԤԼ	   |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		0.ע����½     |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t----------------------|" << endl;
	cout << "��ѡ����Ĳ���:" << endl;
}
//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;
	string fileName;
	string tip;
	string errorTip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		fileName = STUDENT_FILE;
		tip = "������ѧ��:";
		errorTip = "ѧ���ظ�,����������";
		break;
	case 2:
		fileName = TEACHER_FILE;
		tip = "������ְ�����:";
		errorTip = "ְ�����ظ�,����������";
		break;
	default:
		cout << "��������������ѡ��" << endl;
		system("pause");
		system("cls");
		return;
		break;
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	//cin >> id;
	//���ȥ���ж�
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;

	//���»�ȡ����
	this->initVector();
	system("pause");
	system("cls");
	ofs.close();
}
//��ʼ������
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Student s;
	while (ifs>>s.mId&&ifs>>s.mName&&ifs>>s.mPwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ:" << vStu.size() << endl;
	ifs.close();
	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.mEmpId&&ifs >> t.mName&&ifs >> t.mPwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ:" << vTea.size() << endl;
	ifs.close();
}
//����ظ�
bool Manager::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it !=vStu.end(); it++)
		{
			if (id == it->mId)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it !=vTea.end(); it++)
		{
			if (id == it->mEmpId)
			{
				return true;
			}
		}
	}
	return false;
}
//�鿴�˺�
void Manager::showPerson()
{

}
//�鿴������Ϣ
void Manager::showComputer()
{

}
//���ԤԼ��¼
void Manager::cleanFile()
{

}