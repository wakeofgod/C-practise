#include <iostream>
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include <string>
#include "student.h"
#include "teacher.h"
#include "manager.h"
using namespace std;

//学生菜单
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
		case 1://申请预约
			student->applyOrder();
			break;
		case 2://查看我的预约
			student->showMyOrder();
			break;
		case 3://查看所有预约
			student->showAllOrder();
			break;
		case 4://取消我的预约
			student->cancelOrder();
			break;
		default://注销登录
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}
//管理员菜单
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
			cout << "添加账号" << endl;
			man->addPerson();
			break;
		case 2:
			cout << "查看账号" << endl;
			man->showPerson();
			break;
		case 3:
			cout << "查看机房" << endl;
			man->showComputer();
			break;
		case 4:
			cout << "清空预约" << endl;
			man->cleanFile();
			break;
		default:
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		}
	}
}
//老师菜单
void teacherMenu(Identity * &manager)
{
	while (true)
	{
		//教师菜单
		manager->openMenu();
		Teacher *tea =(Teacher*) manager;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select==2)
		{
			//审核预约
			tea->validOrder();

		}
		else 
		{
			delete manager;
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//登录功能 参数1 操作文件名 参数2 操作身份类型
void LoginIn(string fileName, int type)
{
	 //父类指针
	Identity *person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生的验证
		int fId;
		string fName;
		string fPwd;
		//读取一行信息
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId<<"\t" << fName << "\t" << fPwd << "\t" << endl;
			//与用户输入的信息对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//老师的验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "老师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师身份的子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员的身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);
				return;
			}
		}
	}		
	cout << "登录失败" << endl;		
	system("pause");		
	system("cls");
}
int main() {

	int select = 0;
	while (true)
	{
		cout << "==================欢迎来到机房预约系统==================" << endl;
		cout << "请输入你的身份" << endl;
		cout << "\t\t---------------------------------------------\n";
		cout << "\t\t|						|\n";
		cout << "\t\t|		1.学生代表		|\n";
		cout << "\t\t|						|\n";
		cout << "\t\t|		2.老师			|\n";
		cout << "\t\t|						|\n";
		cout << "\t\t|		3.管理员		|\n";
		cout << "\t\t|						|\n";
		cout << "\t\t|		0.退出			|\n";
		cout << "\t\t|						|\n";
		cout << "\t\t---------------------------------------------\n";
		cout << "请输入你的选择" << endl;
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}