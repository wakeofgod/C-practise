#include <iostream>
using namespace std;
#include "workerManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {
	////���Դ���
	//Worker *worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;
	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;
	//worker = new Boss(3, "����", 3);
	//worker->showInfo();
	//delete worker;

	//ʵ�����������
	WorkerManager wm;
	int choice=0;
	while (true) {
		wm.ShowMenu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://����ְ��
			wm.AddEmp();
			break;
		case 2://��ʾְ��
			wm.ShowEmp();
			break;
		case 3://ɾ����ְԱ��
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