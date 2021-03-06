#include <iostream>
#include "student.h"

//默认构造
Student::Student()
{

}
//有参构造
Student::Student(int mid, string name, string pwd)
{
	this->mId = mid;
	this->mName = name;
	this->mPwd = pwd;

	this->initComputer();
}
//初始化机房
void Student::initComputer()
{
	vCom.clear();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "机房文件读取失败" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.mComId &&ifs >> c.mMaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为:" << vCom.size() << endl;
	ifs.close();
}
//菜单界面
void  Student::openMenu()
{
	cout << "欢迎学生:" << this->mName << "登录!" << endl;
	cout << "\t\t--------------------------|" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		1.申请预约		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		2.查看我的预约	   |" << endl;
	cout << "\t\t						   |" << endl;
	cout << "\t\t		3.查看所有预约	   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		4.取消预约		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t		0.注销登陆		   |" << endl;
	cout << "\t\t					       |" << endl;
	cout << "\t\t--------------------------|" << endl;
	cout << "请选择你的操作:" << endl;
}
//申请预约
void Student::applyOrder()
{
	cout << "机房开房时间为周一至周五" << endl;
	cout << "请输入申请预约的时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0;			//日期
	int interval = 0;		//时间段
	int room = 0;			//机房编号
	while (true) 
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入!";
	}
	cout << "请输入申请预约的时间段:" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入时间段有误，请重新输入" << endl;
	}
	cout << "请选择机房" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].mComId << "号机房容量为:" << vCom[i].mMaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "机房输入有误,请重新输入" << endl;
	}
	cout << "预约成功，审核中" << endl;
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
//查看我的预约
void Student::showMyOrder()
{
	OrderFile orderFile;
	if (orderFile.mSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < orderFile.mSize; i++)
	{
		//atoi把string转换为int
		if (atoi(orderFile.mOrderData[i]["stuId"].c_str()) == this->mId)
		{
			cout << "预约时间:周" << orderFile.mOrderData[i]["date"]<<" ";
			cout << "时段:" << (orderFile.mOrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房:" << orderFile.mOrderData[i]["roomId"] << " ";
			string status = "状态: ";//0 取消的预约，1 审核中 2已预约 -1 预约失败
			if (orderFile.mOrderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (orderFile.mOrderData[i]["status"] == "2")
			{
				status += "已预约";
			}
			else if (orderFile.mOrderData[i]["status"] == "-1")
			{
				status += "预约失败，审核未通过!";
			}
			else
			{
				status += "预约已经取消";
			}
			cout << status << endl;
		}
	}

	system("pause");
	system("cls");
}
//查看所有预约
void Student::showAllOrder()
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
			status += "预约成功";
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
//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.mSize == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或者预约成功的记录可以取消，请输入取消的记录" << endl;

	//记录在文件中的行数
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.mSize; i++)
	{
		//判断是不是自己的记录
		if (atoi(of.mOrderData[i]["stuId"].c_str()) == this->mId)
		{
			//判断预约的状态，只有审核中或者预约成功的可以取消
			if (of.mOrderData[i]["status"] == "1" || of.mOrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ",";
				cout << "预约日期:周" << of.mOrderData[i]["date"];
				cout << "时段:" << (of.mOrderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房:" << of.mOrderData[i]["roomId"];
				string status = "状态:";
				if (of.mOrderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.mOrderData[i]["status"] == "2")
				{
					status += "已预约";
				}
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
	}
	cout << "请输入取消的记录，0代表返回" << endl;
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
				//调用更新文件的方法，所有数据全部重新录入
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误,请重新输入" << endl;
	}
	system("pause");
	system("cls");
}
