#include <iostream>
#include "teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}
//�вι���
Teacher::Teacher(int mid, string name, string pwd)
{
	this->mEmpId = mid;
	this->mName = name;
	this->mPwd = pwd;
}
//�˵�����
void Teacher::openMenu()
{
	cout << "��ӭ��ʦ:" << this->mName << "��¼!" << endl;
	cout << "\t\t--------------------------|" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		1.�鿴����ԤԼ	   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		2.���ԤԼ		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		0.ע����½		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t--------------------------|" << endl;
	cout << "��ѡ����Ĳ���:" << endl;
}
//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.mSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.mSize; i++)
	{
		cout << "ԤԼʱ��:��" << of.mOrderData[i]["date"] << " ";
		cout << "ʱ��:" << (of.mOrderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ��:" << of.mOrderData[i]["stuId"] << " ";
		cout << "����:" << of.mOrderData[i]["stuName"] << " ";
		cout << "����:" << of.mOrderData[i]["roomId"] << " ";
		string status = "״̬: ";//0 ȡ����ԤԼ��1 ����� 2��ԤԼ -1 ԤԼʧ��
		if (of.mOrderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.mOrderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�!";
		}
		else if (of.mOrderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��!";
		}
		else
		{
			status += "ԤԼ�Ѿ�ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.mSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼����:" << endl;
	vector<int>v;
	int index=1;
	for (int i = 0; i < of.mSize; i++)
	{
		if (of.mOrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << " ,";
			cout << "ԤԼ����:��" << of.mOrderData[i]["date"];
			cout << "ʱ��:" << (of.mOrderData[i]["interval"] == "1" ? "����" : "����");
			cout << "����:" << of.mOrderData[i]["roomId"];
			string status = "״̬:�����";
			//if (of.mOrderData[i]["status"] == "1")
			//{
			//	status += "�����";
			//}
			//else if (of.mOrderData[i]["status"] == "2")
			//{
			//	status += "��ԤԼ";
			//}
			//else if (of.mOrderData[i]["status"] == "-1")
			//{
			//	status += "ԤԼʧ�ܣ����δͨ��!";
			//}
			//else
			//{
			//	status += "ԤԼ�Ѿ�ȡ��";
			//}
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.mOrderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.mOrderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "������" << endl;
				break;
			}
		}
		cout << "������������������!" << endl;
	}
	system("pause");
	system("cls");
}