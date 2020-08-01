#include <iostream>
#include "student.h"

//Ĭ�Ϲ���
Student::Student()
{

}
//�вι���
Student::Student(int mid, string name, string pwd)
{
	this->mId = mid;
	this->mName = name;
	this->mPwd = pwd;

	this->initComputer();
}
//��ʼ������
void Student::initComputer()
{
	vCom.clear();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�����ļ���ȡʧ��" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.mComId &&ifs >> c.mMaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ:" << vCom.size() << endl;
	ifs.close();
}
//�˵�����
void  Student::openMenu()
{
	cout << "��ӭѧ��:" << this->mName << "��¼!" << endl;
	cout << "\t\t--------------------------|" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		1.����ԤԼ		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		2.�鿴�ҵ�ԤԼ	   |" << endl;
	cout << "\t\t						   |" << endl;
	cout << "\t\t		3.�鿴����ԤԼ	   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		4.ȡ��ԤԼ		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		0.ע����½		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t--------------------------|" << endl;
	cout << "��ѡ����Ĳ���:" << endl;
}
//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;
	int date = 0;			//����
	int interval = 0;		//ʱ���
	int room = 0;			//�������
	while (true) 
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������!";
	}
	cout << "����������ԤԼ��ʱ���:" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "����ʱ�����������������" << endl;
	}
	cout << "��ѡ�����" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].mComId << "�Ż�������Ϊ:" << vCom[i].mMaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������,����������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "StuId:" << this->mId << " ";
	ofs << "stuName:" << this->mName << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();

	system("pause");
	system("cls");
}
//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile orderFile;
}
//�鿴����ԤԼ
void Student::showAllOrder()
{

}
//ȡ��ԤԼ
void Student::cancelOrder()
{

}
