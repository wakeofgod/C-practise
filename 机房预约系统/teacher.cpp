#include <iostream>
#include "teacher.h"

//默认构造
Teacher::Teacher()
{

}
//有参构造
Teacher::Teacher(int mid, string name, string pwd)
{
	this->mEmpId = mid;
	this->mName = name;
	this->mPwd = pwd;
}
//菜单界面
void Teacher::openMenu()
{
	cout << "欢迎老师:" << this->mName << "登录!" << endl;
	cout << "\t\t--------------------------|" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		1.查看所有预约	   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		2.审核预约		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		0.注销登陆		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t--------------------------|" << endl;
	cout << "请选择你的操作:" << endl;
}
//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.mSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.mSize; i++)
	{
		cout << "预约时间:周" << of.mOrderData[i]["date"] << " ";
		cout << "时段:" << (of.mOrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号:" << of.mOrderData[i]["stuId"] << " ";
		cout << "姓名:" << of.mOrderData[i]["stuName"] << " ";
		cout << "机房:" << of.mOrderData[i]["roomId"] << " ";
		string status = "状态: ";//0 取消的预约，1 审核中 2已预约 -1 预约失败
		if (of.mOrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.mOrderData[i]["status"] == "2")
		{
			status += "预约成功!";
		}
		else if (of.mOrderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过!";
		}
		else
		{
			status += "预约已经取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.mSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下:" << endl;
	vector<int>v;
	int index=1;
	for (int i = 0; i < of.mSize; i++)
	{
		if (of.mOrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << " ,";
			cout << "预约日期:周" << of.mOrderData[i]["date"];
			cout << "时段:" << (of.mOrderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房:" << of.mOrderData[i]["roomId"];
			string status = "状态:审核中";
			//if (of.mOrderData[i]["status"] == "1")
			//{
			//	status += "审核中";
			//}
			//else if (of.mOrderData[i]["status"] == "2")
			//{
			//	status += "已预约";
			//}
			//else if (of.mOrderData[i]["status"] == "-1")
			//{
			//	status += "预约失败，审核未通过!";
			//}
			//else
			//{
			//	status += "预约已经取消";
			//}
			cout << status << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回" << endl;
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
				cout << "请输入审核结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
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
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入!" << endl;
	}
	system("pause");
	system("cls");
}