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
	ofs << "stuId:" << this->mId << " ";
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
	if (orderFile.mSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < orderFile.mSize; i++)
	{
		//atoi��stringת��Ϊint
		if (atoi(orderFile.mOrderData[i]["stuId"].c_str()) == this->mId)
		{
			cout << "ԤԼʱ��:��" << orderFile.mOrderData[i]["date"]<<" ";
			cout << "ʱ��:" << (orderFile.mOrderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "����:" << orderFile.mOrderData[i]["roomId"] << " ";
			string status = "״̬: ";//0 ȡ����ԤԼ��1 ����� 2��ԤԼ -1 ԤԼʧ��
			if (orderFile.mOrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (orderFile.mOrderData[i]["status"] == "2")
			{
				status += "��ԤԼ";
			}
			else if (orderFile.mOrderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��!";
			}
			else
			{
				status += "ԤԼ�Ѿ�ȡ��";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showAllOrder()
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
			status += "��ԤԼ";
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
//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.mSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	//��¼���ļ��е�����
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.mSize; i++)
	{
		//�ж��ǲ����Լ��ļ�¼
		if (atoi(of.mOrderData[i]["stuId"].c_str()) == this->mId)
		{
			//�ж�ԤԼ��״̬��ֻ������л���ԤԼ�ɹ��Ŀ���ȡ��
			if (of.mOrderData[i]["status"] == "1" || of.mOrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ",";
				cout << "ԤԼ����:��" << of.mOrderData[i]["date"];
				cout << "ʱ��:" << (of.mOrderData[i]["interval"] == "1" ? "����" : "����");
				cout << "����:" << of.mOrderData[i]["roomId"];
				string status = "״̬:";
				if (of.mOrderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.mOrderData[i]["status"] == "2")
				{
					status += "��ԤԼ";
				}
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
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int  select = 0;
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
				of.mOrderData[v[select - 1]]["status"] = "0";
				//���ø����ļ��ķ�������������ȫ������¼��
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "��������,����������" << endl;
	}
	system("pause");
	system("cls");
}
