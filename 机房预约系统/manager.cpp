#include <iostream>
#include <string>
#include "manager.h"

//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	this->mName = name;
	this->mPwd = pwd;

	//初始化容器
	this->initVector();
}
//选择菜单
void Manager::openMenu()
{
	cout << "欢迎管理员:" << this->mName << "登录!" << endl;
	cout << "\t\t----------------------|" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		1.添加账号		   |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		2.查看账号	   |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		3.查看机房	   |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		4.清空预约	   |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t		0.注销登陆     |" << endl;
	cout << "\t\t					   |" << endl;
	cout << "\t\t----------------------|" << endl;
	cout << "请选择你的操作:" << endl;
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;
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
		tip = "请输入学号:";
		errorTip = "学号重复,请重新输入";
		break;
	case 2:
		fileName = TEACHER_FILE;
		tip = "请输入职工编号:";
		errorTip = "职工号重复,请重新输入";
		break;
	default:
		cout << "输入有误，请重新选择" << endl;
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
	//添加去重判断
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
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;

	//重新获取容器
	this->initVector();
	system("pause");
	system("cls");
	ofs.close();
}
//初始化容器
void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	//读取学生文件中的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Student s;
	while (ifs>>s.mId&&ifs>>s.mName&&ifs>>s.mPwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为:" << vStu.size() << endl;
	ifs.close();
	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.mEmpId&&ifs >> t.mName&&ifs >> t.mPwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为:" << vTea.size() << endl;
	ifs.close();
}
//检查重复
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
//查看账号
void Manager::showPerson()
{

}
//查看机房信息
void Manager::showComputer()
{

}
//清空预约记录
void Manager::cleanFile()
{

}