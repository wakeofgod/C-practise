#include <iostream>
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include <string>
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

//ѧ���˵�
void studentMenu(Identity * &manager)
{
	while (true)
	{
		manager->openMenu();
		Student * student = (Student*)manager;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1://����ԤԼ
			student->applyOrder();
			break;
		case 2://�鿴�ҵ�ԤԼ
			student->showMyOrder();
			break;
		case 3://�鿴����ԤԼ
			student->showAllOrder();
			break;
		case 4://ȡ���ҵ�ԤԼ
			student->cancelOrder();
			break;
		default://ע����¼
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}
//����Ա�˵�
void managerMenu(Identity * &manager)
{
	while (true)
	{
		manager->openMenu();
		Manager *man = (Manager*)manager;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "����˺�" << endl;
			man->addPerson();
			break;
		case 2:
			cout << "�鿴�˺�" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "�鿴����" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "���ԤԼ" << endl;
			man->cleanFile();
			break;
		default:
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}
//��¼���� ����1 �����ļ��� ����2 �����������
void LoginIn(string fileName, int type)
{
	 //����ָ��
	Identity *person = NULL;
	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ������֤
		int fId;
		string fName;
		string fPwd;
		//��ȡһ����Ϣ
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId<<"\t" << fName << "\t" << fPwd << "\t" << endl;
			//���û��������Ϣ�Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//������ʦ��ݵ��Ӳ˵�

				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�������֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}		
	cout << "��¼ʧ��" << endl;		
	system("pause");		
	system("cls");
}
int main() {

	int select = 0;
	while (true)
	{
		cout << "==================��ӭ��������ԤԼϵͳ==================" << endl;
		cout << "������������" << endl;
		cout << "\t\t---------------------------------------------\n";
		cout << "\t\t|						|\n";
		cout << "\t\t|		1.ѧ������		|\n";
		cout << "\t\t|						|\n";
		cout << "\t\t|		2.��ʦ			|\n";
		cout << "\t\t|						|\n";
		cout << "\t\t|		3.����Ա		|\n";
		cout << "\t\t|						|\n";
		cout << "\t\t|		0.�˳�			|\n";
		cout << "\t\t|						|\n";
		cout << "\t\t---------------------------------------------\n";
		cout << "���������ѡ��" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADAMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}