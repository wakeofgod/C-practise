#include <iostream>
using namespace std;
#include "workerManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {
	////测试代码
	//Worker *worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;
	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;
	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;

	//实例化管理对象
	WorkerManager wm;
	int choice=0;
	while (true) {
		wm.ShowMenu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://增加职工
			wm.AddEmp();
			break;
		case 2://显示职工
			wm.ShowEmp();
			break;
		case 3://删除离职员工
			wm.DelEmp();
			break;
		case 4:
			wm.ModifyEmp();
			break;
		case 5:
			wm.FindEmp();
			break;
		case 6:
			wm.SortEmp();
			break;
		case 7:
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}